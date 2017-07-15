// Jboy Flaga
// Started:		June 29, 2015 3:44 AM
// Finished:	June 29, 2015 4:55 AM 


#ifdef _WIN32 
#define _CRT_SECURE_NO_DEPRECATE 
#endif

#include <iostream>
#include <string>
#include <iomanip>
#include <map>
#include <stdio.h>
#include <sstream>

using namespace std;

//template <typename T>
//T StringToNumber(const string &Text)
//{
//	istringstream ss(Text);
//	T result;
//	return ss >> result ? result : 0;
//}
// Usage: StringToNumber<Type> ( String ); 


//NOTE: this program is in C++11. It uses std::stoi()
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int numOfTestCases = 0;
	string line;

	// get number of cases
	getline(cin, line);
	numOfTestCases = stoi(line, nullptr, 10);
	//numOfTestCases = StringToNumber<int>(line);

	getline(cin, line); // get first blank line

	for (int i = 0; i < numOfTestCases; i++)
	{
		map<string, int> mapOfTrees;
		int overallNumberOfTrees = 0;

		while (!cin.eof())
		{
			getline(cin, line);
			if (line.length() == 0) { break; }

			if (mapOfTrees.find(line) == mapOfTrees.end())
			{
				mapOfTrees[line] = 1;
			}
			else
			{
				++mapOfTrees[line];
			}

			++overallNumberOfTrees;
		}

		for (map<string, int>::const_iterator p = mapOfTrees.begin(); p != mapOfTrees.end(); ++p)
		{
			double percentage = ((double)p->second / (double)overallNumberOfTrees) * 100;

			printf("%s %.4f\n", p->first.c_str(), percentage);
		}

		if (i < numOfTestCases - 1)
		{
			printf("\n");
		}
	}

	return 0;
}