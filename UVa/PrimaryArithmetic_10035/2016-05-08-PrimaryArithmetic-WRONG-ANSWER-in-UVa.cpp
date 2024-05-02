// Jboy Flaga
// Started:		May 8, 2016 1:35 AM
// Finished:	May 8, 2016 2:17 AM - wrong answer because I used int instead of "long long" (for 10 digit numbers)
//				May 8, 2016 2:30 AM - wrong answer because the output for 1 carry operation is "1 carry operation" with no "s" at the end
//				May 8, 2016 2:35 AM - wrong answer because the output has no period at the end
//				May 8, 2016 2:37 AM - Correct answer already when I submitted in codechef.com (I submitted it there because it was the page that came out of google when I searched for the problem using the "problem description" --- because I have to solve this because I gave it as a problem for Dina Bolanos to solve to be able to join the progamming club I want to start
//									- but still not correct answer in UVA Online Judge

//It looks like Microsoft has deprecated lots of calls which use buffers to improve code security.
//if you aren't interested in using the secure version of their calls (like�fopen_s), 
//you need to place a definition of_CRT_SECURE_NO_DEPRECATE�before your included header files. For example:
//#define _CRT_SECURE_NO_DEPRECATE
//#include <stdio.h>
//The preprocessor directive can also be added to your project settings to effect it on all the files 
//under the project.To do this add�_CRT_SECURE_NO_DEPRECATE�to�
//Project Properties -> Configuration Properties -> C / C++->Preprocessor -> Preprocessor Definitions.

#ifdef _WIN32 
#define _CRT_SECURE_NO_DEPRECATE 
#endif

#include <iostream>

using namespace std;

int main()
{
	/*
	freopen("C:\\__Current\\SolutionsToPogContestProblems\\10055_HashmatTheBraveWarrior\\input.txt", "r", stdin);
	freopen("C:\\__Current\\SolutionsToPogContestProblems\\10055_HashmatTheBraveWarrior\\output.txt", "w", stdout);
	*/

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	long long number1, number2;
	while (cin >> number1 >> number2)
	{
		//cerr << number1 << " " << number2;
		if (number1 == 0 && number2 == 0) { break; }

		int numberOfCarryOperations = 0;

		while (number1 > 0 && number2 > 0) {

			//1. extract rightmost digit of 1st number
			int rightmostDigitOfNumber1 = number1 % 10;
			// stop extracting if there are no more digits left
			if (number1 > 0) {
				number1 = number1 / 10;
			}

			//2. extract rightmost digit of 2nd number 
			int rightmostDigitOfNumber2 = number2 % 10;
			//stop extracting if there are no more digits left
			if (number2 > 0) {
				number2 = number2 / 10;
			}

			//3. add the extracted digits and count the number of carry operations
			int sum = rightmostDigitOfNumber1 + rightmostDigitOfNumber2;
			if (sum > 9){
				numberOfCarryOperations++;
			}
		}

		switch (numberOfCarryOperations)
		{
		case 0:
			cout << "No carry operation.\n";
			break;
		case 1:
			cout << "1 carry operation.\n";
			break;
		default:
			cout << numberOfCarryOperations << " carry operations.\n";
			break;
		}
	}

	return 0;
}

int get_rightmost_digit(int number)
{
	return number % 10;
}