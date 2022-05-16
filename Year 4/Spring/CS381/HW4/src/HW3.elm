-- Programming Language Fundamentals
-- Homework 3
-- Philip Warton

module HW3 exposing (..)


----------------------------------
-- Exercise 1. A Stack Language --
----------------------------------

type Op = LD Int | ADD | MULT | DUP
type alias Prog = List Op
type alias Stack = List Int

type alias Update = Maybe Stack -> Maybe Stack


-- Function:    Execute program
-- Input:	    Program and current stack
-- Output:	    Altered stack after program is run	

semProg : Prog -> Maybe Stack -> Maybe Stack
semProg program stack = case stack of
    Nothing     -> Nothing
    Just s      -> case program of
        []          -> Just s
        op::ops     -> case (semOp op (Just s)) of
            Nothing     -> Nothing
            Just t      -> semProg ops (Just t)


-- Function:	Execute operation
-- Input:	    Operation and current stack
-- Output:	    Altered stack after operation is performed

semOp : Op -> Maybe Stack -> Maybe Stack
semOp op = \stack -> case stack of
    Nothing     -> Nothing
    Just s      -> case op of
        LD n-> Just (n::s)
        ADD -> case s of
            x1::x2::xs -> Just ((x1+x2)::xs)
            _ -> Nothing
        MULT -> case s of
            x1::x2::xs -> Just ((x1*x2)::xs)
            _ -> Nothing
        DUP -> case s of
            x::xs -> Just (x::x::xs)
            _ -> Nothing



---------------------------
-- Exercise 2. Mini Logo --
---------------------------

-- Abstract syntax
type alias Point = (Int, Int)
type Mode = Down | Up

type Cmd = Pen Mode
    | MoveTo Point
    | Seq Cmd Cmd



-- Semantic domain

type alias State = (Mode,Point)
type alias Line = (Point,Point)
type alias Lines = List Line


-- Function:    Execute commands
-- Input:       Commands, and current state
-- Output:      Tuple of post-command state, and drawn lines

semCmd : Cmd -> State -> (State,Lines)
semCmd command = \state -> case command of
    Pen Up      -> ((Up, Tuple.second state), [])
    Pen Down    -> ((Down, Tuple.second state), [])
    MoveTo (x,y)-> case (Tuple.first state) of
        Up          -> ((Up, (x,y)), [])
        Down        -> ((Down, (x,y)), [(Tuple.second state, (x,y))])
    Seq c1 c2   -> (

        -- result state =
        Tuple.first( semCmd c2 (

            -- previous state =
            Tuple.first (semCmd c1 state)
        )), 

        --lines
        (Tuple.second( semCmd c2 (
            Tuple.first (semCmd c1 state)
        )))++(Tuple.second (semCmd c1 state)))


-- Function:    Take a command and produce the list of lines to draw
-- Input:       Commands
-- Ouput:       List of lines

lines : Cmd -> Lines
lines command = Tuple.second (semCmd command (Up, (0,0)))




