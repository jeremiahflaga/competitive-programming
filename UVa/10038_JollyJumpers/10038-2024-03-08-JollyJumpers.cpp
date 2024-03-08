// #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
// #include "doctest.h"

#include <iostream>
#include <vector>
#include <bitset>
#include "math.h"
#include <sstream>

using namespace std;

bool isJollyJumper(const int n, vector<int> v) {
	// cout << "entered isJollyJumper" << endl;
	bitset<3001> bset;
	for (int i = 0; i < n - 1; i++) {
		int difference = abs(v[i] - v[i+1]);

		// sort of short-circuiting like this, idea taken from Cracking the Coding Interview 6e chapter 1
		if (bset.test(difference))
			return false;
		
		bset.set(difference);
		// cout << "bset.set(difference) => " << difference << endl;
	}
	
	// cout << "reached here" << endl;
	for (size_t i = 1; i < n; i++)
	{
		// cout << "bset.test(i) => " << bset.test(i) << endl;
		if (!bset.test(i))
			return false;
	}
	
    return true;
}

// TEST_CASE("tests") {
// 	cout << "----------------------------------------------------------------------" << endl;
//     CHECK(isJollyJumper(4, {1, 4, 2, 3}) == true);
//     CHECK(isJollyJumper(5, {1, 4, 2, -1, 6}) == false);
	
//     CHECK(isJollyJumper(2, {1, 3}) == false);
// 	cout << "----------------------------------------------------------------------" << endl;
// }


int main() { 
    // // Redirect input/output
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

	int n;
	string line;
	while(getline(cin, line, '\n')) {
		istringstream iss(line);
		iss >> n;
		vector<int> v(n);
		for (size_t i = 0; i < n; i++)
		{
			iss >> v[i];
		}
		
		if (isJollyJumper(n, v)) {
			cout << "Jolly" << endl;
		} else {
			cout << "Not jolly" << endl;
		}		
	}
}

// int main(int argc, char* argv[]) { 
//     // Redirect input/output
//     // freopen("input.txt", "r", stdin);
//     // freopen("output.txt", "w", stdout);

//     // body 
// }