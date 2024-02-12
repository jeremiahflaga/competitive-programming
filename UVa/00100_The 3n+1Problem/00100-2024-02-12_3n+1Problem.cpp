
// While solving the first part of Assignment 1 of CS106B Winter 2024, I read this:
//  As a fun aside, if you have access to a Python environment, you can attempt similarly-sized
//  searches using the Python version of the program to see just how much slower an interpreted
//  language (Python) is compared to a compiled language (C++). Check out the Python vs C++ Showdown
//  we've posted to the Ed discussion forum.
//  From <https://web.stanford.edu/class/cs106b/assignments/1-cpp/perfect>

// So I'm trying to solve this in C++ with no memoization, to see if it passes the time limit of 3 seconds.
// Because I have a solution to this problem last 2009, in C++, and it was Accepted on first try.
// But I don't have a copy of that solution in C++. SO I have to redo it now.

#include <iostream>
#include <algorithm>

using namespace std;

int computeCycleLength(int x) {
    int current_cycle_length = 1;
    while (x > 1) {
        current_cycle_length++;
        if (x % 2 == 1)
            x = (3*x)+1;
        else
            x = x/2;
    }
    return current_cycle_length;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int i, j, current_cycle_length;
    while(cin >> i >> j) {
        int max_cycle_length = 0;
        int lower = min(i,j);
        int bigger = max(i,j);
        for (int x = lower; x <= bigger; x++) {
            current_cycle_length = computeCycleLength(x);
            if (current_cycle_length > max_cycle_length)
                max_cycle_length = current_cycle_length;
        }
        cout << i << " " << j << " " << max_cycle_length << endl;
    }
    return 0;
}


// Lesson: be sure that your range is the same as that from the specification
// > For each pair of input integers i and j you should output i, j, and the maximum cycle length for integers
//        between and including i and j.
// for (int x = lower; x <= bigger; x++) {