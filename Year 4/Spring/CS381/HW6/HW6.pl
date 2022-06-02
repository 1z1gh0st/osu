% CS381 - HW5
% Philip Warton
% 6/2/2022

% Facts given in assignment
when(275,10).
when(261,12).
when(381,11).
when(398,12).
when(399,12).
where(275,owen102).
where(261,dear118).
where(381,cov216).
where(398,dear118).
where(399,cov216).
enroll(mary,275).
enroll(john,275).
enroll(mary,261).
enroll(john,381).
enroll(jim,399).

% Exercise 1. Database Application

% (a)
schedule(PERSON,ROOM,TIME) :- enroll(PERSON,CLASS), when(CLASS,TIME), where(CLASS,ROOM).

% (b)
usage(ROOM,TIME) :- when(CLASS,TIME), where(CLASS,ROOM).

% (c)
conflict(CLASS_A,CLASS_B) :- when(CLASS_A,TIME), when(CLASS_B,TIME), where(CLASS_A,ROOM), where(CLASS_B,ROOM), CLASS_A \= CLASS_B.

% (d)
meet(PERSON_A,PERSON_B) :- enroll(PERSON_A,CLASS), enroll(PERSON_B,CLASS), PERSON_A \= PERSON_B.
meet(PERSON_A,PERSON_B) :- schedule(PERSON_A,ROOM,10), schedule(PERSON_B,ROOM,11), PERSON_A \= PERSON_B.
meet(PERSON_A,PERSON_B) :- schedule(PERSON_A,ROOM,11), schedule(PERSON_B,ROOM,12), PERSON_A \= PERSON_B.

% Exercise 2. List Predicates and Arithmetic
rdup([],[]).
rdup([X,X|InListTail],OutList) :- rdup([X|InListTail],OutList), !.
rdup([X|InListTail],[X|OutListTail]) :- rdup(InListTail,OutListTail).

flat([],[]).
flat([HEAD|TAIL],FLAT) :- append(HEAD_FLAT,TAIL_FLAT,FLAT), flat(HEAD,HEAD_FLAT), flat(TAIL,TAIL_FLAT).
flat(X,[X]).

elem(1,[HEAD|_],HEAD).
elem(1,[X],X).
elem(N,[_|TAIL],ELEM) :- elem(M, TAIL, ELEM), M is N-1.

%TODO: FIX 'elem'

project([I|IS],LIST,PROJECT) :- append(PROJECT_HEAD,PROJECT_TAIL,PROJECT), project([I],LIST,PROJECT_HEAD), project([IS],LIST,PROJECT_TAIL).