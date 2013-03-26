#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

#define FOR(i, init, end) for(int i=(init); i < (end); i++)
#define FOREACH(i, n) for(typeof(n.begin()) i = n.begin(); i != n.end(); i++)

class TheSimilarNumbers {
public:
    int find(int lower, int upper)
    {
        int count = 0;
        
        for (int i = lower; i < (upper + 1); i = (i * 10) + 1) {
            count++;
        }

        return count;
    }
};
