# Max_Heap_Array  <a href="https://travis-ci.org/Dragomir2020/Max_Heap_Array" rel="some text">![Foo](https://travis-ci.org/Dragomir2020/BasicUnitTest.svg?branch=master,raw=true "Build Passing")</a>    [![Coverage Status](https://coveralls.io/repos/github/Dragomir2020/Max_Heap_Array/badge.svg?branch=master)](https://coveralls.io/github/Dragomir2020/Max_Heap_Array?branch=master)
- Max Heap Array Implemented in c++
- Templated class to accept all data types and strings
## Install cxxtest
- go to https://sourceforge.net/projects/cxxtest/files/cxxtest/
- install folder in directory with code
## Make File
- Open make file and change directory path to path where code cxxtest exists
## Install valgrind
- sudo apt-get install valgrind
## Compile Code
- make
- compiles sample code in heapsandbox
- Use this as guide when using header
## Test Code
- make test
## Check for Memory Leaks
- valgrind ./testrunner
## Clean Directory of Compiled Files
- make clean
- must do this to recompile code using make test
