#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>

using namespace std;

string hello(string name) {
    if (name == "")
        return "Hello, World!";
    else
        return "Hello, " + name + "!";
}

TEST_CASE("testing hello") {
    CHECK(hello("") == "Hello, World!");
    CHECK(hello("jboy") == "Hello, jboy!");

    string name;
    CHECK(hello(name) == "Hello, World!");
    
    CHECK(hello("Jürgen") == "Hello, Jürgen!");
}
