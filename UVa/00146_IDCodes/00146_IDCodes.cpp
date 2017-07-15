// Jboy Flaga
// Started:		June 14, 2015 1:30 AM
// Finished:	June 14, 2015 1:55 AM

#ifdef _WIN32 
#define _CRT_SECURE_NO_DEPRECATE 
#endif

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	string code;
	string sortedCode;

	while (getline(cin, code))
	{
		if (code.compare("#") == 0)
		{
			break;
		}

		sortedCode = code;
		sort(sortedCode.begin(), sortedCode.end());

		next_permutation(code.begin(), code.end());

		// if the next permutation is equal to the first one 
		// in the set (which is represented by sortedCode)
		// then display "No Successor"
		if (code.compare(sortedCode) == 0)
		{
			cout << "No Successor" << endl;
		}
		else
		{
			cout << code << endl;
		}
	}

	return 0;
}