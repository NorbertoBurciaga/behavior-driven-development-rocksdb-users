#! /bin/bash

cd ../build
cmake .. && make
cd ../tests
../build/bin/UsersSteps &
cucumber
