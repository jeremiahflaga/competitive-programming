// Jboy Flaga
// Started:		April 19, 2015
// Finished:	April 19, 2015, 12:09 PM

#ifdef _WIN32 
#define _CRT_SECURE_NO_DEPRECATE 
#endif

#include <iostream>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	bool isOpenQuotes = true;
	char ch;
	while (cin.get(ch))
	{
		if (ch == '"') {
			if (isOpenQuotes) { cout << "``"; }
			else { cout << "''"; }

			isOpenQuotes = !isOpenQuotes;
		}
		else {
			cout << ch;
		}
	}
}