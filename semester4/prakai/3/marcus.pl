man(marcus).
man(ghani).

pompeian(marcus).

born(marcus, 40).
born(ghani, 2002).

current_year(2022).

current_age(Entity, CurrentAge) :- current_year(CurrentYear), born(Entity, YearBorn), CurrentAge is CurrentYear - YearBorn.

mortal(Entity) :- man(Entity).

dead(Entity) :- mortal(Entity), current_age(Entity, CurrentAge), CurrentAge > 150.

dead(Entity) :- pompeian(Entity), current_year(CurrentYear), CurrentYear > 79.