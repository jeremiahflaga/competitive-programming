#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>

using namespace std;

void printSubsetsHelper(string soFar, string theRest, vector<string>& v) {
    if (theRest == "") {
        v.push_back(soFar);
        return;
    }

    string firstChar = theRest.substr(0, 1);
    string newRest = theRest.substr(1);

    // choose/explore with chosen character
    soFar.append(firstChar);
    printSubsetsHelper(soFar, newRest, v);

    // choose/explore without chosen character
    soFar = soFar.substr(0, soFar.size()-1);
    printSubsetsHelper(soFar, newRest, v);

    // unchoose
    theRest.insert(0, firstChar);
}

vector<string> printSubsets(string str) {
    vector<string> v;
    printSubsetsHelper("", str, v);
    return v;
}

void printVector(const vector<string>& v) {
    cout << "{ ";
    for (auto elem : v) {
        cout << "\"" << elem << "\", ";
    }
    cout << " }" << endl;
}

TEST_CASE("tests") {

    // auto v = printSubsets("abc");
    // printVector(v);

    CHECK(printSubsets("") == vector<string> {""});
    CHECK(printSubsets("a") == vector<string> {"a", ""});
    CHECK(printSubsets("ab") == vector<string> {"ab", "a", "b", ""});
    CHECK(printSubsets("abc") == vector<string> {"abc", "ab", "ac", "a", "bc", "b", "c", ""});
}


// int main() { 
//     // Redirect input/output
//     // freopen("input.txt", "r", stdin);
//     // freopen("output.txt", "w", stdout);

//     // body 
// }

// int main(int argc, char* argv[]) { 
//     // Redirect input/output
//     // freopen("input.txt", "r", stdin);
//     // freopen("output.txt", "w", stdout);

//     // body 
// }