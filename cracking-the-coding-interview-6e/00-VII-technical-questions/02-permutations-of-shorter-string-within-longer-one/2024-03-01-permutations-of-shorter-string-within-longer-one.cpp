#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;


// Given a smaller string s and a bigger string b, design an algorithm to find all permutation of the shorter string within the longer one. Print the location of each permutation
vector<int> findLocationsOfPermutationOfShorterStringWithinLongerString(string shorter, string longer) {
    if (shorter == "")
        return vector<int>{};
        
    vector<int> locations;
    sort(shorter.begin(), shorter.end());
    int indexToEnd = longer.size() - shorter.size() + 1;
    for (int i = 0; i < indexToEnd; i++) {
        string substr = longer.substr(i, shorter.size());
        sort(substr.begin(), substr.end());
        if(shorter == substr) {
            locations.push_back(i);
        }
    }
    return locations;
}   

TEST_CASE("tests") {
    CHECK(findLocationsOfPermutationOfShorterStringWithinLongerString("a", "aaa") == vector<int>{0, 1, 2});
    CHECK(findLocationsOfPermutationOfShorterStringWithinLongerString("ab", "aba") == vector<int>{0, 1});
    CHECK(findLocationsOfPermutationOfShorterStringWithinLongerString("abc", "bac") == vector<int>{0});
    
    CHECK(findLocationsOfPermutationOfShorterStringWithinLongerString(
        "abbc", 
        "cbabadcbbabbcbabaabccbabc") 
        == vector<int>{0, 6, 9, 11, 12, 20, 21,});
    
    // empty
    CHECK(findLocationsOfPermutationOfShorterStringWithinLongerString("", "bac") == vector<int>{});
}


// #include <stdio.h>
// int main() { 
//     // Redirect input/output
//     // freopen("input.txt", "r", stdin);
//     // freopen("output.txt", "w", stdout);

//     // body 
//     printf("%ld\n", __cplusplus);
// }
