// Jboy Flaga
// Started:		May 2, 2015
// Finished:	May 2, 2015 2:45 AM

#ifdef _WIN32 
#define _CRT_SECURE_NO_DEPRECATE 
#endif

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int numberOfTestCases = 0;
	cin >> numberOfTestCases;

	for (int i = 0; i < numberOfTestCases; i++)
	{
		int salaries[3];
		cin >> salaries[0] >> salaries[1] >> salaries[2];
		sort(salaries, salaries + 3);
		int median = salaries[1];
		cout << "Case " << i + 1 << ": " << median << endl;
	}

	return 0;
}