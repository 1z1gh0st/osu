color(red).
color(blue).
likes(john,red).
likes(mary,red).
likes(john,mary).
marry(X,Y) :- likes(X,Y), likes(Y,X).
marry(X,Y) :- likes(X,Y), isRich(Y).
car(bmw).
car(honda,green).
car(X,Y) :- car(X), color(Y).
faster(car,bike).
contains(house,bathroom).
contains(house,kitchen).
contains(kitchen,fridge).
contains(fridge,mouse).
inside(X,Y) :- contains(Y,X).
inside(X,Y) :- contains(Y,Z), inside(X,Z).

father(X,Y) :- parent(X,Y), male(X).
mother(X,Y) :- parent(X,Y), female(X).
grandfather(X,Y) :- father(X,Z), parent(Z,Y).
grandmother(X,Y) :- mother(X,Z), parent(Z,Y).
child(X,Y) :- parent(Y,X).
son(X,Y) :- child(X,Y), male(X).
daughter(X,Y) :- child(X,Y), female(X).
grandchild(X,Y) :- child(X,Z), child(Z,Y).
grandson(X,Y) :- grandchild(X,Y), male(X).
granddaughter(X,Y) :- grandchild(X,Y), female(X).
ancestor(X,Y) :- parent(X,Y).
ancestor(X,Y) :- parent(X,Z), ancestor(Z,Y).
sibling(X,Y) :- parent(Z,X), parent(Z,Y), X\=Y.
brother(X,Y) :- sibling(X,Y), male(X).
sister(X,Y) :- sibling(X,Y), female(X).
aunt(X,Y) :- sister(X,Z), parent(Z,Y).
uncle(X,Y) :- brother(X,Z), parent(Z,Y).
