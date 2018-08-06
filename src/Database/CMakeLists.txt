# Declare the library
set ( database_sources
   Table.cpp
   User.cpp
   Address.cpp
)

add_library(database STATIC ${database_sources})