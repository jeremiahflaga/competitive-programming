// Jboy Flaga
// Started:		May 14, 2015
// Finished:	May 14, 2015 2:45 AM

#ifdef _WIN32 
#define _CRT_SECURE_NO_DEPRECATE 
#endif

#include <iostream>
#include <map>
#include <math.h>

using namespace std;

int main()
{

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	while (true)
	{
		int durationOfMonths, numberOfDepreciationRecords;
		double downPayment, amountOfLoan;
		map<int, double> recordOfPercentageOfDepreciation;

		cin >> durationOfMonths;
		if (durationOfMonths < 0) {
			break;
		}

		cin >> downPayment >> amountOfLoan >> numberOfDepreciationRecords;

		// fill depreciation record
		int month;
		double depreciation;
		for (int i = 0; i < numberOfDepreciationRecords; i++)
		{
			cin >> month >> depreciation;
			recordOfPercentageOfDepreciation[month] = depreciation;
		}

		// compute
		int currentMonth = 0;
		double currentValueOfCar = amountOfLoan + downPayment;
		double monthlyPayment = amountOfLoan / durationOfMonths;
		double currentPercentageOfDepreciation = 0;
		double currentDepreciation = 0;
		double amountOwed = amountOfLoan;

		for (currentMonth = 0; currentMonth <= durationOfMonths; currentMonth++)
		{

			map<int, double>::const_iterator currentPercentageOfDepreciationPair = recordOfPercentageOfDepreciation.find(currentMonth);
			if (currentPercentageOfDepreciationPair != recordOfPercentageOfDepreciation.end())
			{
				currentPercentageOfDepreciation = currentPercentageOfDepreciationPair->second;
			}

			currentDepreciation = currentValueOfCar * currentPercentageOfDepreciation;
			currentValueOfCar = currentValueOfCar - currentDepreciation;

			if (amountOwed < currentValueOfCar)
			{
				break;
			}

			amountOwed = amountOwed - monthlyPayment;
		}

		if (currentMonth == 1)
		{
			cout << currentMonth << " month" << endl;
		}
		else 
		{
			cout << currentMonth << " months" << endl;
		}
		//cout << "amountOwed: " << amountOwed << endl;
		//cout << "currentValueOfCar: " << currentValueOfCar << endl << endl;
	}

	return 0;
}
