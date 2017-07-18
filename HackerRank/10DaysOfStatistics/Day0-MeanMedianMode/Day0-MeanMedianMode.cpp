#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <iomanip>
using namespace std;

/***
# Jeremiah Flaga
# July 10, 2017
*/

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long nItems = 0;
    cin >> nItems;
    
    if (nItems > 0) {
        vector<long> items(nItems);
        map<long, long> mapOfItemToNumberOfOccurrences;
        double sum = 0;
        long maxNumOfOccurences = 0;
        long mode = 0;

        for (long i = 0; i < nItems; i++) {
            long item;;
            cin >> item;
            items[i] = item;

            sum += item;

            mapOfItemToNumberOfOccurrences[item]++;
            if (mapOfItemToNumberOfOccurrences[item] > maxNumOfOccurences) {
                maxNumOfOccurences = mapOfItemToNumberOfOccurrences[item];
                mode = item;
            } else if (mapOfItemToNumberOfOccurrences[item] == maxNumOfOccurences && item < mode) {
                    mode = item;
            }
        }

        cout << setprecision(1) << fixed;

        //mean
        double mean = sum/nItems;
        cout << sum/nItems << endl;

        //median
        double median = 0.0;
        sort(items.begin(), items.end());
        bool isNumberOfItemsOdd = nItems % 2 != 0;
        if (isNumberOfItemsOdd)
            median = items[(nItems/2)];
        else
            median = (items[(nItems/2) - 1]  + items[(nItems/2)]) / 2.0;

        cout << median << endl;

        //mode
        cout << mode;
    }
}
