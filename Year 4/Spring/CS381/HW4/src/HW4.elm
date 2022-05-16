module HW4 exposing (..)

------------------------------------------------------------------
-- Exercise 1: A Rank Based Type Systems for the Stack Language --
------------------------------------------------------------------
type Op = LD Int | ADD | MULT | DUP | DEC | SWAP | POP Int
type alias Prog = List Op
type alias Stack = List Int

-- Part (a)
type alias Rank = Int
type alias OpRank = (Int,Int)

-- Function: rank operation
-- Input: operation 'op'
-- Output: the rank of the operation
rankOp : Op -> OpRank
rankOp op = case op of 
    LD n    -> (0,1)
    ADD     -> (2,1)
    MULT    -> (2,1)
    DUP     -> (1,2)
    DEC     -> (1,1)
    SWAP    -> (2,2)
    POP k   -> (k,0)

-- Function: rank of program given starting rank
-- Input: program 'p', initial rank 'k'
-- Output: Error | Just [rank of stack after program executes]
rank : Prog -> Rank -> Maybe Rank
rank p k = case p of
    []      -> Just k
    op::ops -> let (n,m)=(rankOp op) in (
                if (k<n) then Nothing
                else rank ops (k-n+m)
            )

-- Function: rank of program from blank stack
-- Input: program 'p'
-- Output: Error | Just rank!
rankP : Prog -> Maybe Rank
rankP p = rank p 0 -- we assume to start with empty stack, and use helper fn 'rank'


-- Part (b)

-- Function: type checking semantics
-- Input: program 'p'
-- Output: Type error | Stack after program execution
semTC : Prog -> Maybe Stack
semTC p = case (rankP p) of
    Nothing -> Nothing
    Just _  -> Just (semProg p [])

-- Function:    Execute program
-- Input:	    Program and current stack
-- Output:	    Altered stack after program is run	
semProg : Prog -> Stack -> Stack
semProg p s = case p of
    []      -> s
    op::ops -> semProg ops (semOp op s)

-- Function:	Execute operation
-- Input:	    Operation and current stack
-- Output:	    Altered stack after operation is performed
semOp : Op -> Stack -> Stack
semOp _ _ = Debug.todo "Error"

--------------------------------
-- Exercise 2: Shape Language --
--------------------------------

type Shape = X | TD Shape Shape | LR Shape Shape
type alias BBox = (Int,Int)

-- Part (a)

-- Function: get the 'bounding box' of a given shape
-- Input: a Shape 's'
-- Ouptut: a BBox that is the bounding box of 's'
bbox : Shape -> BBox
bbox s = case s of
    X           -> (1,1)
    TD s1 s2    -> case bbox s1 of
        (x1,y1)     -> case bbox s2 of
            (x2,y2)     -> (max x1 x2,y1+y2)
    LR s1 s2    -> case bbox s1 of
        (x1,y1)     -> case bbox s2 of
            (x2,y2)     -> (x1+x2,max y1 y2)

-- Part (b)

-- Function: assign rectangle shapes their bounding box, check for rectangularity
-- Input: shape 's' built with language
-- Output: Error | BBox of our rectangle
rect : Shape -> Maybe BBox
rect s = case s of
    X           -> Just (1,1)
    TD s1 s2    -> case rect s1 of
        Nothing         -> Nothing
        Just (x1,y1)    -> case rect s2 of
            Nothing         -> Nothing
            Just (x2,y2)    -> if x1==x2 then Just (x1,y1+y2)
                               else Nothing
    LR s1 s2    -> case rect s1 of
        Nothing         -> Nothing
        Just (x1,y1)    -> case rect s2 of
            Nothing         -> Nothing
            Just (x2,y2)    -> if y1==y2 then Just (x1+x2,y1)
                               else Nothing

