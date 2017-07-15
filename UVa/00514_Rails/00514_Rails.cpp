// Jboy Flaga
// Started:		June 26, 2015 3:35 AM
// Finished:	June 26, 2015 4:12 AM

#ifdef _WIN32 
#define _CRT_SECURE_NO_DEPRECATE 
#endif

#include <iostream>
#include <stack>
#include <queue>

using namespace std;


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int numOfCoaches;

	while (cin >> numOfCoaches && numOfCoaches != 0)
	{
		bool readInputForNextBlock = false;
		while (!readInputForNextBlock){
			queue<int> qExpectedOrderOfCoaches;

			int nextCoachNumber;
			for (int i = 0; i < numOfCoaches; i++)
			{
				cin >> nextCoachNumber;
				if (nextCoachNumber == 0)
				{
					readInputForNextBlock = true; // move on to read the next block
					break;
				}
				qExpectedOrderOfCoaches.push(nextCoachNumber);
			}

			if (readInputForNextBlock)
			{
				cout << endl;
				break; // move on to read the next block
			}

			stack<int> stkCoachesInStation;
			for (int i = 1; i <= numOfCoaches; i++)
			{
				stkCoachesInStation.push(i);

				while (!stkCoachesInStation.empty()
					&& !qExpectedOrderOfCoaches.empty()
					&& stkCoachesInStation.top() == qExpectedOrderOfCoaches.front())
				{
					stkCoachesInStation.pop();
					qExpectedOrderOfCoaches.pop();
				}
			}

			if (stkCoachesInStation.empty())
			{
				cout << "Yes" << endl;
			}
			else
			{
				cout << "No" << endl;
			}
		}
	}

	return 0;
}