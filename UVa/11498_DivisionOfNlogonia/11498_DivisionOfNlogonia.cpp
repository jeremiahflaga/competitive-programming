// Jboy Flaga
// Started:		May 14, 2015
// Finished:	May 14, 2015 8:44 AM

#ifdef _WIN32 
#define _CRT_SECURE_NO_DEPRECATE 
#endif

#include <iostream>

using namespace std;

int main()
{

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	while (true)
	{
		int numberOfQueries = 0;
		cin >> numberOfQueries;

		if (numberOfQueries == 0) {
			break;
		}

		int divisionPointX, divisionPointY, residenceX, residenceY;
		cin >> divisionPointX >> divisionPointY;


		for (int i = 0; i < numberOfQueries; i++)
		{
			cin >> residenceX >> residenceY;

			if (residenceX == divisionPointX || residenceY == divisionPointY)
			{
				cout << "divisa" << endl;
			}
			else if (residenceX < divisionPointX)
			{
				if (residenceY > divisionPointY) {
					cout << "NO" << endl;
				}
				else {
					cout << "SO" << endl;
				}
			}
			else
			{
				if (residenceY > divisionPointY) {
					cout << "NE" << endl;
				}
				else {
					cout << "SE" << endl;
				}
			}
		}
	}

	return 0;
}