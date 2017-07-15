// Jboy Flaga
// Started:		May 17, 2015 2:15 AM
// Finished:	May 17, 2015 3:15 AM - First submission - Wraong Answer
//				May 17, 2015 4:01 AM - submission Accepted
//					the wrong answer was because I did not give notice to "If the fatigue factor drops the snail's climbing distance below zero, the snail does not climb at all that day"

#ifdef _WIN32 
#define _CRT_SECURE_NO_DEPRECATE 
#endif

#include <iostream>
#include <math.h>

using namespace std;

bool areEqual(double a, double b, double error)
{
	return fabs(a - b) < error;
}


int main()
{

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	float heightOfWell, distanceOfClimbDuringDay, distanceOfSlideDuringNight, fatigueFactor;

	while (cin >> heightOfWell >> distanceOfClimbDuringDay >> distanceOfSlideDuringNight >> fatigueFactor)
	{
		if (heightOfWell <= 0){
			break;
		}

		int currentDay = 1;
		float initialHeight = 0,
			currentDistanceTheSnailCanClimb = 0,
			heightAfterClimbing = 0,
			heightAfterSliding = 0,
			fatigueDistance;

		while (true)
		{
			initialHeight = heightAfterSliding;

			fatigueDistance = distanceOfClimbDuringDay * (fatigueFactor / 100) * (currentDay - 1);
			currentDistanceTheSnailCanClimb = distanceOfClimbDuringDay - fatigueDistance;

			// If the fatigue factor drops the snail's climbing distance below zero, 
			// the snail does not climb at all that day
			if (currentDistanceTheSnailCanClimb < 0)
			{
				heightAfterClimbing = initialHeight;
			}
			else
			{
				heightAfterClimbing = initialHeight + currentDistanceTheSnailCanClimb;
			}
			
			heightAfterSliding = heightAfterClimbing - distanceOfSlideDuringNight;

			if (heightAfterClimbing > heightOfWell)
			{
				cout << "success on day " << currentDay << endl;
				break;
			}
			else if (heightAfterSliding < 0)
			{
				cout << "failure on day " << currentDay << endl;
				break;
			}

			currentDay++;
		}
	}

	return 0;
}