// Jboy Flaga
// Started:		June 15, 2015
// Finished:	June 15, 2015 5:50 AM

#ifdef _WIN32 
#define _CRT_SECURE_NO_DEPRECATE 
#endif

#include <iostream>
#include <bitset>

using namespace std;

// got hint from https://tausiq.wordpress.com/2012/08/22/uva-11926-multitasking/

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	const int MAX_MINUTES = 1000001;
	bitset<MAX_MINUTES> bsMinutes;

	int numOfOneTimeTasks, numOfRepeatingTasks;
	while (cin >> numOfOneTimeTasks >> numOfRepeatingTasks)
	{
		if (numOfOneTimeTasks == 0 && numOfRepeatingTasks == 0)
		{
			break;
		}

		bsMinutes.reset(); // set all bits to 0

		int startTime, endTime, currentTime, interval;
		bool hasConflict = false;

		for (size_t i = 0; i < numOfOneTimeTasks; i++)
		{
			cin >> startTime >> endTime;
						
			currentTime = startTime + 1;

			while (currentTime <= endTime && currentTime < MAX_MINUTES)
			{
				if (bsMinutes[currentTime] == 1)
				{
					hasConflict = true;
					break;
				}
				else
				{
					bsMinutes[currentTime] = 1;
				}

				currentTime++;
			}
		}

		// if the above operation already see a conflict in schedule, just display the output
		if (!hasConflict)
		{
			for (size_t i = 0; i < numOfRepeatingTasks; i++)
			{
				cin >> startTime >> endTime >> interval;

				do
				{
					currentTime = startTime + 1;

					while (currentTime <= endTime && currentTime < MAX_MINUTES)
					{
						if (bsMinutes[currentTime] == 1)
						{
							hasConflict = true;
							break;
						}
						else
						{
							bsMinutes[currentTime] = 1;
						}

						currentTime++;
					}

					startTime += interval;
					endTime += interval;

				} while (startTime < MAX_MINUTES);

			}
		}

		// output
		if (hasConflict)
		{
			cout << "CONFLICT" << endl;
		}
		else
		{
			cout << "NO CONFLICT" << endl;
		}
	}

	return 0;
}