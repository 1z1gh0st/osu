module HW1_Elm exposing (..)
import HW1_Def exposing (..)


-- Part 1
type alias Bag a = List (a, Int)

-- a
ins : a -> Bag a -> Bag a
ins a b = case b of
    [] -> (a,1)::[]
    x::xs -> if (Tuple.first x)==a 
                then (a, (Tuple.second x)+1)::xs 
            else x::(ins a xs)

-- b
del : a -> Bag a -> Bag a
del a b = case b of
    [] -> []
    x::xs -> if (Tuple.first x)==a 
                then (
                    if (Tuple.second x)==1 
                            then xs 
                    else (a, (Tuple.second x)-1)::xs
                ) 
            else x::(del a xs)

-- c
bag : List a -> Bag a
bag l = case l of
        [] -> []
        x::xs -> ins x (bag xs)

-- d
subbag : Bag a -> Bag a -> Bool
subbag a b = case a of
    [] -> True
    x::xs -> if (Tuple.second x)==1
                then subbag xs b
        else subbag (del (Tuple.first x) a) b

-- e
isSet : Bag a -> Bool
isSet b = case b of
    [] -> True
    x::xs -> if (Tuple.second x)>1 then False else isSet xs

-- f
size : Bag a -> Int
size b = case b of
        [] -> 0
        x::xs -> (Tuple.second x) + size xs


-- Part 2
type alias Node = Int
type alias Edge = (Node,Node)
type alias Graph = List Edge

-- a
nodes : Graph -> List Node
nodes g = case g of
    [] -> []
    x::xs -> map Tuple.first (asSet (ins (Tuple.second x) (ins (Tuple.first x) (bag (nodes xs)))))

--b
suc : Node -> Graph -> List Node
suc v g = case g of
    [] -> []
    x::xs -> if (Tuple.first x)==v
                then asSet ((Tuple.second x)::(suc (Tuple.first x) xs)++(suc (Tuple.second x) xs))
            else asSet (suc v xs)

-- c
detach : Node -> Graph -> Graph
detach v g = case g of
    [] -> []
    x::xs -> if (Tuple.first x)==v
                then detach v xs
            else (
                if (Tuple.second x)==v
                    then detach v xs
                else x::(detach v xs)
            )

-- Part 3
type alias Number = Int
type alias Point = (Number,Number)
type alias Length = Number
type Shape = Pt Point
    | Circle Point Length
    | Rect Point Length Length
type alias Figure = List Shape
type alias BBox = (Point,Point)

-- a
width : Shape -> Length
width s = case s of

