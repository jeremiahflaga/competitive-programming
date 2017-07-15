// Jboy Flaga
// Started:		May 15, 2015
// Finished:	May 15, 2015 2:47 AM

// added <limits.h> on May 16 2015 becuase when I submitted to UVA online judge the result was "compile error"

#ifdef _WIN32 
#define _CRT_SECURE_NO_DEPRECATE 
#endif

#include <iostream>
#include <map>
#include <limits.h>

using namespace std;

int main()
{

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int nParticipants, budget, nHotels, nWeeks;

	while (cin >> nParticipants >> budget >> nHotels >> nWeeks)
	{
		// for each of the hotels
		int pricePerPerson;
		int minumumCostForAllParticipants = INT_MAX;
		for (int i = 0; i < nHotels; i++)
		{
			cin >> pricePerPerson;

			// for each weekend
			int nAvailableBeds;
			for (int w = 0; w < nWeeks; w++)
			{
				cin >> nAvailableBeds;

				if (nAvailableBeds >= nParticipants)
				{
					int costForAllParticipants = nParticipants * pricePerPerson;					
					if (costForAllParticipants < minumumCostForAllParticipants)
					{
						minumumCostForAllParticipants = costForAllParticipants;
					}
				}
			}
		}

		if (minumumCostForAllParticipants <= budget)
		{
			cout << minumumCostForAllParticipants << endl;
		}
		else
		{
			cout << "stay home" << endl;
		}
	}

	return 0;
}