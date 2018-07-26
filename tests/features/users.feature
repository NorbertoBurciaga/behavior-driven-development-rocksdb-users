# language: en

Feature: Store and retrieve users from a rocksdb database

Scenario: Should be able to insert the following users
	Given "applicationdb" as the name of the database
	When the application starts
	Then it should construct the key using id/field and insert the key/value pair into the "users" table
		| Id	| Field			| Value									|
		| 1		| name			| Norberto							|
		| 1		| lastname	| Burciaga							|
		| 1		| email			| norberto@mytest.com		|
		| 1		| year			| 1971									|
		| 2		| name			|	Albert Eduard					|
		| 2		| lastname	| Meier									|
		| 2		| email			| albert@mytest.com			|
		| 2		| year			| 1937									|
		| 3		| name			| Francisco							|
		| 3		| lastname	| Burciaga							|
		| 3		| email			| Francisco@test.com		|
		| 3		| year			| 2018									|
		| 4		| name			|	Mahatma								|
		| 4		| lastname	| Gandhi								|
		| 4		| email			| mahatma@mydomain.com	|
		| 4		| year			| 1869									|
		| 5		| name			| Albert								|
		| 5		| lastname	| Einstein							|
		| 5		| email			| AlbertE@mytest.com		|
		| 5		| year			| 1879									|
		| 6		| name			|	Carl									|
		| 6		| lastname	| Sagan									|
		| 6		| email			| Carl@sagan.com				|
		| 6		| year			| 1934									|
