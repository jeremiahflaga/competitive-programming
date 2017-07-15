// Jboy Flaga
// Started:		April 19, 2015
// Finished:	April 19, 2015

//It looks like Microsoft has deprecated lots of calls which use buffers to improve code security.
//if you aren't interested in using the secure version of their calls (like fopen_s), 
//you need to place a definition of_CRT_SECURE_NO_DEPRECATE before your included header files. For example:
//#define _CRT_SECURE_NO_DEPRECATE
//#include <stdio.h>
//The preprocessor directive can also be added to your project settings to effect it on all the files 
//under the project.To do this add _CRT_SECURE_NO_DEPRECATE to 
//Project Properties -> Configuration Properties -> C / C++->Preprocessor -> Preprocessor Definitions.

#ifdef _WIN32 
#define _CRT_SECURE_NO_DEPRECATE 
#endif

#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int velocity, timeVelocityIsGained, displacementInTwiceThatTime;
	while (cin >> velocity >> timeVelocityIsGained)
	{
		displacementInTwiceThatTime = velocity * (timeVelocityIsGained * 2);
		cout << displacementInTwiceThatTime << endl;
	}

	return 0;
}