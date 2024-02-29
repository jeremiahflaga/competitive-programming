# My solutions to some competitive programming problems

## NOTE: There are also READMEs in some individual folders in this repository, for example in the folder `/UVa/` and `/HackerRank/10DaysOfStatistics/`. 

https://www.hackerrank.com

https://uva.onlinejudge.org [My statistics](http://uhunt.felix-halim.net/id/52989)

## Some NOTE for running some of the C++ programs here:

If you encounter the error `'stdin' was not declared in this scope` when you run the C++ programs here, you need to add `#include <cstdio>` to the C++ program.


## Command for running python with redirected input/output:

``` terminal
$ python 00100-2024-02-08_3n+1Problem-CSE-373-Fall-2020.py < input.txt > output.txt
```

## Running Python with unit tests

`python <name of file containing tests>.py`

`python <name of file>.py`


## Running C++ file with unit tests, on Windows using g++ and [doctest](https://github.com/doctest/doctest) located in /_libraries/doctest.h

([doctest tutorial](https://github.com/doctest/doctest/blob/master/doc/markdown/tutorial.md))

Open Command Prompt (**not** Terminal)

See if the environment variable `CPLUS_INCLUDE_PATH` is already set to the `\__libraries\` directory:

``` terminal
set CPLUS_INCLUDE_PATH
```

If it is not, then set it to the `[**==change-me-to-root-dir==**]\_libraries\`

``` terminal
set CPLUS_INCLUDE_PATH=[**==change-me-to-root-dir==**]\__libraries\
g++ 2024-02-29-hello-world-with-unit-tests.cpp & a
```

Or, if you want to specify the name of the `.exe` file

``` terminal
set CPLUS_INCLUDE_PATH=[**==change-me-to-root-dir==**]\__libraries\
g++ 2024-02-29-hello-world-with-unit-tests.cpp -o hello-world
hello-world
```

It will output something like this:

```
[doctest] doctest version is "2.4.11"
[doctest] run with "--help" for options
===============================================================================
[doctest] test cases: 1 | 1 passed | 0 failed | 0 skipped
[doctest] assertions: 5 | 5 passed | 0 failed |
[doctest] Status: SUCCESS!
```

If a test fails, it outputs something like this:

```
[doctest] doctest version is "2.4.11"
[doctest] run with "--help" for options
===============================================================================
2024-02-29-hello-world-with-unit-tests.cpp:6:
TEST CASE:  testing the factorial function

2024-02-29-hello-world-with-unit-tests.cpp:7: ERROR: CHECK( factorial(0) == 0 ) is NOT correct!
  values: CHECK( 1 == 0 )

===============================================================================
[doctest] test cases: 1 | 0 passed | 1 failed | 0 skipped
[doctest] assertions: 5 | 4 passed | 1 failed |
[doctest] Status: FAILURE!
```

References:

 - [2.2  Set/Unset/Change an Environment Variable for the "Current" CMD Session](https://www3.ntu.edu.sg/home/ehchua/programming/howto/Environment_Variables.html)
 - [2.4  How to Add or Change an Environment Variable "Permanently"](https://www3.ntu.edu.sg/home/ehchua/programming/howto/Environment_Variables.html#SetEnv)