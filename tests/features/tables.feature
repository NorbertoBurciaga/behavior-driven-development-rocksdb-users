# language: en

Feature: Store, organize and retrieve users information

Scenario: Store "users" information
	Given "applicationdb" as the name of the database
	When "users" are required to be stored into the database
	Then should insert the following users into the database
		| Id	| Email									| Lastname	| Firstname			| Year	|
		| 1		| norberto@mytest.com		| Burciaga	| Norberto			| 1971	|
		| 2		| albert@mytest.com			| Meier			| Albert Eduard	| 1937	|
		| 3		| Francisco@test.com		| Burciaga	| Francisco			| 2018	|
		| 4		| mahatma@mydomain.com	| Gandhi		| Mahatma				| 1869	|
		| 5		| AlbertE@mytest.com		| Einstein	| Albert				| 1879	|
		| 6		| Carl@sagan.com				| Sagan			| Carl					| 1934	|

Scenario: Store user "addresses" information
	Given "applicationdb" as the name of the database
	When "addresses" are required to be stored into the database
	Then should insert the following addresses into the database
		| Id	| UserId	| Address								| City					| State	| Country	|
		| 1		| 1				| 3248 My Address Dr.		| New York			| NY		| US			|
		| 2		| 2				| Av. De La Raza #3980	| Ciudad Juarez	| Chih	| Mexico	|
		| 3		| 3				| 646 Gateway West			| San Francisco	| CA		| US			|
		| 4		| 4				| 3810 Edgemere Blvd		| El Paso				| TX		| US			|
		| 5		| 5				| 4823 No Address St.		| Irwing				| TX		| US			|
		| 6		| 6				| Octavio Paz #414			| Monterrey			| NL		| Mexico	|
