# Behavior Driven Development (BDD) and RocksDB key/value storage for users

## Contents

* [Introduction](#introduction)
* [Project Hierarchy](#project-hierarchy)
* [Getting Started](#getting-started)
* [Support](#support)
* [FAQ](#faq)
* [Development](#development)
* [License](#license)
* [References](#references)

## Introduction

Project to test behavior driven development (BDD) using cucumber-cpp, and the rocksdb key/value storage to store users data

[Contents](#contents)

## Project Hierarchy

```console

.
├── CMakeLists.txt
├── LICENSE
├── README.md
└── tests
    ├── execute_tests.sh
    └── features
        ├── CMakeLists.txt
        ├── step_definitions
        │   ├── cucumber.wire
        │   └── UsersSteps.cpp
        ├── support
        │   └── env.rb
        └── users.feature
```

[Contents](#contents)

## Getting Started

### Requirements
* Cmake
* Boost
* Google Test
* Cucumber
* Ruby
* RocksDB

### Installation

#### Install cmake
```console
$ wget https://cmake.org/files/v3.11/cmake-3.11.1-Linux-x86_64.sh
$ chmod +x cmake-3.11.1-Linux-x86_64.sh
$ sudo mv cmake-3.11.1-Linux-x86_64 /opt
$ sudo rm /usr/bin/cmake
cd /usr/local/bin
$ sudo ln -s /opt/cmake-3.11.1-Linux-x86_64/bin/ccmake
$ sudo ln -s /opt/cmake-3.11.1-Linux-x86_64/bin/cmake
$ sudo ln -s /opt/cmake-3.11.1-Linux-x86_64/bin/cmake-gui
$ sudo ln -s /opt/cmake-3.11.1-Linux-x86_64/bin/cpack
$ sudo ln -s /opt/cmake-3.11.1-Linux-x86_64/bin/ctest
```

#### Install ruby
```console
$ sudo apt install ruby-full ruby-dev ruby-rspec rake rubygems bundler
```

#### Install Cucumber pre-requisites
```console
$ sudo gem install bundler
$ cd /var/lib/gems/2.5.0/gems/bundler-1.16.2/lib/bundler/templates/
$ bundle install
```

#### Install Cucumber
```console
$ sudo gem install cucumber --version 2.99.0   NOTE: The newest version has conflicts with cucumber-cpp
$ git clone https://github.com/cucumber/cucumber-cpp.git
$ cd cucumber-cpp/
$ git submodule init
$ git submodule update
$ cmake -E make_directory build
$ cmake -E chdir build cmake -DCUKE_ENABLE_EXAMPLES=on ..
it sent the following error but it created the Makefiles:
install(EXPORT "CucumberCpp" ...) includes target "cucumber-cpp-nomain" which requires target "json_spirit.header" that is not in the export set.
$ cmake --build build
$ cmake --build build --target test
$ sudo cmake --build build --target install
$ cmake --build build --target features
$ build/examples/Calc/BoostCalculatorSteps >/dev/null &
$ cucumber examples/Calc
```

#### Install RocksDB Pre-requisites
RocksDB works with diferent compression libraries:
Snappy:   $ sudo apt-get install libsnappy-dev
it says it is already installed on its latest version (that's odd)
ZLib:   $ sudo apt-get install zlib1g-dev
zlib1g-dev is already the newest version (1:1.2.11.dfsg-0ubuntu2).
bzip2:   $ sudo apt-get install libbz2-dev
lz4:   $ sudo apt-get install liblz4-dev
zstandard:   $ sudo apt-get install libzstd-dev

Rocksdb
$ git clone https://github.com/facebook/rocksdb.git
$ mkdir build; cd build
$ cmake .. && make
$ sudo make install


#### Install project
```console
$ git clone https://github.com/NorbertoBurciaga/behavior-driven-development-rocksdb-users.git
$ cd behavior-driven-development-rocksdb-users
$ mkdir build
$ cd build
$ cmake .. && make
```

### Testing

```console

```


### Documentation

[Contents](#contents)

## Support
Technical support is available in 

[Contents](#contents)

## FAQ

[Contents](#contents)

## Development
If you want to contribute....

[Contents](#contents)

## License

Copyright (c) 2018, Respective Authors all rights reserved.

The MIT License

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

[Contents](#contents)

## References

1 Expect C++ Programming, Authors: Jeganathan Swaminathan, Maya Posch, Jacek Galowicz, 2018

[Contents](#contents)
