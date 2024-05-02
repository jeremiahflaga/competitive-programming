// Jboy Flaga
// Started:		May 18, 2015 1:18 AM
// Finished:	May 18, 2015 1:47 AM

#ifdef _WIN32 
#define _CRT_SECURE_NO_DEPRECATE 
#endif

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	while (cin >> n)
	{
		vector<bool> sequence(n, false); //initialize all values in sequence to false
		int first, second, difference;

		cin >> first;
		for (int i = 1; i < n; i++)
		{
			cin >> second;
			
			difference = abs(first - second);
			if (difference < n)
			{
				sequence[difference] = true;
			}

			first = second;
		}

		int numberOfFalseSlots = count(sequence.begin() + 1, sequence.end(), false);

		if (numberOfFalseSlots > 0)
		{
			cout << "Not jolly" << endl;
		}
		else 
		{
			cout << "Jolly" << endl;
		}
	}

	return 0;
}