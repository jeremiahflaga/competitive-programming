// Jboy Flaga
// Started:		April 19, 2015
// Finished:	April 23, 2015

#ifdef _WIN32 
#define _CRT_SECURE_NO_DEPRECATE 
#endif

#include <stdio.h>
#include <iostream>

using namespace std;

int* least(int* a, int* b, int* c);
void printArray(int arr[], int length);

int main()
{

	const int N = 1500; // the max ugly number we are going to find
	int uglyNumbers[N]; // the list of ugly numbers
	int size = 0; // counter is the current position in the array that is empty

	// ptrFor2 is pointer to the current ugly number that is NOT yet multiplied by 2
	// ptrFor3 is pointer to the current ugly number that is NOT yet multiplied by 3
	int *ptrFor2, *ptrFor3, *ptrFor5;

	uglyNumbers[0] = 1; // the first ugly number is 1
	size++;
	ptrFor2 = ptrFor3 = ptrFor5 = &uglyNumbers[0];


	while (size < N)
	{
		int *ptrToLeast = least(ptrFor2, ptrFor3, ptrFor5);
		/*cout << "*ptrFor2 = " << *ptrFor2 << " *ptrFor3 = " << *ptrFor3 << " *ptrFor5 = " << *ptrFor5 << endl
			<< "*ptrToLeast = " << *ptrToLeast << endl << endl;*/

		int nextUglyNumber = 0;
		if (ptrToLeast == ptrFor2)
		{
			// multiply by 2 the current least ugly number that is not yet multiplied by 2
			nextUglyNumber = *ptrFor2 * 2;
			ptrFor2++;
		}
		else if (ptrToLeast == ptrFor3)
		{
			nextUglyNumber = *ptrFor3 * 3;
			ptrFor3++;
		}
		else if (ptrToLeast == ptrFor5)
		{
			nextUglyNumber = *ptrFor5 * 5;
			ptrFor5++;
		}

		// if next ugly number is greater than the last one we have in the list
		int positionOfCurrentLargestUglyNumber = size - 1;
		if (nextUglyNumber > uglyNumbers[positionOfCurrentLargestUglyNumber])
		{
			uglyNumbers[size++] = nextUglyNumber;
		}
	}

	cout << "The 1500'th ugly number is " << uglyNumbers[N - 1] << ".\n";
	//printArray(uglyNumbers, N);

	cin.get();
	return 0;
}

int lesser(int a, int b)
{
	if (a < b) return a;
	else return b;
}

//returns least of the three integers pointed to by the specified 3 pointers
int* least(int* ptrFor2, int* ptrFor3, int* ptrFor5)
{
	int nextValueFor2 = *ptrFor2 * 2;
	int nextValueFor3 = *ptrFor3 * 3;
	int nextValueFor5 = *ptrFor5 * 5;

	int leastValue = lesser(lesser(nextValueFor2, nextValueFor3), nextValueFor5);

	if (leastValue == nextValueFor2) return ptrFor2;
	else if (leastValue == nextValueFor3) return ptrFor3;
	else if (leastValue = nextValueFor5) return ptrFor5;
}

void printArray(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl << endl;
}