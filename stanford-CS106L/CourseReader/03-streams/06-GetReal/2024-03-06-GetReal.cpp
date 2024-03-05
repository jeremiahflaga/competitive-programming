// #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
// #include "doctest.h"

#include <iostream>
#include <sstream>

using namespace std;

// copied from course reader
string GetLine() {
    string result;
    getline(cin, result);
    return result;
}

// copied from course reader
int GetInteger() {
    while(true) { // Read input until user enters valid data
        stringstream converter;
        converter << GetLine();

        /* Try reading an int, continue if we succeeded. */
        int result;
        if(converter >> result) {
            char remaining;
            if(converter >> remaining) // Something's left, input is invalid
                cout << "Unexpected character: " << remaining << endl;
            else
                return result;
        } else
            cout << "Please enter an integer." << endl;
            
        cout << "Retry: ";
    }
}

double GetReal() {
    while(true) { // Read input until user enters valid data
        stringstream converter;
        converter << GetLine();

        /* Try reading a double, continue if we succeeded. */
        double result;
        if(converter >> result) {
            char remaining;
            if(converter >> remaining) // Something's left, input is invalid
                cout << "Unexpected character: " << remaining << endl;
            else
                return result;
        } else
            cout << "Please enter a real number." << endl;
            
        cout << "Retry: ";
    }
}

int main() { 
    // Redirect input/output
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    cout << "Please enter an integer: ";
    int integer = GetInteger();
    cout << "You entered " << integer << endl;

    
    cout << "Please enter a real number: ";
    double realNumber = GetReal();
    cout << "You entered " << realNumber << endl;
}

// int main(int argc, char* argv[]) { 
//     // Redirect input/output
//     // freopen("input.txt", "r", stdin);
//     // freopen("output.txt", "w", stdout);

//     // body 
// }