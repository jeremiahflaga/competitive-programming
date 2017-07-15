// Jboy Flaga
// Started:		May 2, 2015
// Finished:	May 2, 2015 2:45 AM

#ifdef _WIN32 
#define _CRT_SECURE_NO_DEPRECATE 
#endif

#include <iostream>

using namespace std;

int main()
{

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int numberOfInputs = 0;
	cin >> numberOfInputs;

	long long a, b;
	while (numberOfInputs > 0)
	{
		cin >> a >> b;
		if (a < b) { cout << "<"; }
		else if (a > b)  { cout << ">"; }
		else { cout << "="; }

		cout << endl;
		numberOfInputs--;
	}
}