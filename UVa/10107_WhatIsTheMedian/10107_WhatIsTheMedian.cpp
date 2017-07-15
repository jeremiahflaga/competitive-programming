// Jboy Flaga
// Started:		June 14, 2015 2:54 AM
// Finished:	June 14, 2015 3:52 AM

#ifdef _WIN32 
#define _CRT_SECURE_NO_DEPRECATE 
#endif

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

unsigned int getMedian(vector<unsigned int> listOfNumbers)
{
	int length = listOfNumbers.size();
	bool isLengthEven = length % 2 == 0;
	if (isLengthEven)
	{		
		nth_element(listOfNumbers.begin(), listOfNumbers.begin() + length / 2, listOfNumbers.end());
		unsigned int middle_1 = listOfNumbers[length / 2];

		nth_element(listOfNumbers.begin(), listOfNumbers.begin() + (length / 2) - 1, listOfNumbers.end());
		unsigned int middle_2 = listOfNumbers[(length / 2) - 1];


		return (middle_1 + middle_2) / 2;
	}
	else
	{
		int middleIndex = (length / 2);
		nth_element(listOfNumbers.begin(), listOfNumbers.begin() + middleIndex, listOfNumbers.end());
		return listOfNumbers[middleIndex];
	}
}

int main()
{

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	unsigned int n;
	vector<unsigned int> listOfNumbers;

	while (cin >> n)
	{
		listOfNumbers.push_back(n);
		unsigned int median = getMedian(listOfNumbers);
		cout << median << endl;
	}


	return 0;
}