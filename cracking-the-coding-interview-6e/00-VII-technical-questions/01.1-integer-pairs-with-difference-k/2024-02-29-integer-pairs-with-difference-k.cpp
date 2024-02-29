#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_map>

using namespace std;

int countIntegerPairsWithDifferenceK_BruteForce(vector<int> v, int k) {
    int count = 0;
    for (int i = 0; i < v.size(); i++) {
        int currentElem = v[i];
        for (int j = 0; j < v.size(); j++) { // search 
            if (j == i) continue; // skip currentElem

            // check that currentElem is lower than the other to avoid duplicates
            if (currentElem < v[j]) {
                int difference = abs(currentElem - v[j]);
                if (difference == k) {
                  count++;
                }
            }
        }
    }
    return count;
}

int countIntegerPairsWithDifferenceK_UsingHashTable(vector<int> v, int k) {
    unordered_map<int, int> hashTable;
    for (int x : v) {
        hashTable[x] = x;
    }
    int count = 0;
    for (int i = 0; i < v.size(); i++) {
        if(hashTable.find(v[i]+k) != hashTable.end()) {
            count++;
        }
    }
    return count;
}

int countIntegerPairsWithDifferenceK(vector<int> v, int k) {
    //return countIntegerPairsWithDifferenceK_BruteForce(v, k);
    return countIntegerPairsWithDifferenceK_UsingHashTable(v, k);
}

TEST_CASE("tests") {
    CHECK(countIntegerPairsWithDifferenceK({1, 2}, 2) == 0);
    CHECK(countIntegerPairsWithDifferenceK({1, 3}, 2) == 1);

    CHECK(countIntegerPairsWithDifferenceK({2, 1}, 2) == 0);
    CHECK(countIntegerPairsWithDifferenceK({3, 1}, 2) == 1);

    CHECK(countIntegerPairsWithDifferenceK({1, 3}, 3) == 0);
    CHECK(countIntegerPairsWithDifferenceK({1, 4}, 3) == 1);

    CHECK(countIntegerPairsWithDifferenceK({3, 1}, 3) == 0);
    CHECK(countIntegerPairsWithDifferenceK({4, 1}, 3) == 1);

    CHECK(countIntegerPairsWithDifferenceK({1, 7, 5, 9, 2, 12, 3}, 2) == 4);
}

TEST_CASE("tests negative integers") {
    CHECK(countIntegerPairsWithDifferenceK({-1, -2}, 2) == 0);
    CHECK(countIntegerPairsWithDifferenceK({-1, -3}, 2) == 1);

    CHECK(countIntegerPairsWithDifferenceK({-2, -1}, 2) == 0);
    CHECK(countIntegerPairsWithDifferenceK({-3, -1}, 2) == 1);

    CHECK(countIntegerPairsWithDifferenceK({-1, -3}, 3) == 0);
    CHECK(countIntegerPairsWithDifferenceK({-1, -4}, 3) == 1);

    CHECK(countIntegerPairsWithDifferenceK({-3, -1}, 3) == 0);
    CHECK(countIntegerPairsWithDifferenceK({-4, -1}, 3) == 1);

    CHECK(countIntegerPairsWithDifferenceK({-1, -7, -5, -9, -2, -12, -3}, 2) == 4);
}

TEST_CASE("tests with zero") {
    CHECK(countIntegerPairsWithDifferenceK({0, 1}, 2) == 0);
    CHECK(countIntegerPairsWithDifferenceK({0, 2}, 2) == 1);

    CHECK(countIntegerPairsWithDifferenceK({1, 0}, 2) == 0);
    CHECK(countIntegerPairsWithDifferenceK({2, 0}, 2) == 1);
}

// int main() { 
//     // Redirect input/output
//     // freopen("input.txt", "r", stdin);
//     // freopen("output.txt", "w", stdout);

//     // body 
// }
