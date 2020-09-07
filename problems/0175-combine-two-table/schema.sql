CREATE TABLE Person (
  PersonId int,
  FirstName varchar(255),
  LastName varchar(255)
);

CREATE TABLE Address (
  AddressId int,
  PersonId int,
  City varchar(255),
  State varchar(255)
);

INSERT INTO Person (PersonId, LastName, FirstName) VALUES ('1', 'Wang', 'Allen');
INSERT INTO Address (AddressId, PersonId, City, State) VALUES ('1', '2', 'New York City', 'New York')
