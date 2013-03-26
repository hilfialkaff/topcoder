#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, init, end) for(int i=(init); i < (end); i++)

class NextOrPrev {
public:
    int getMinimum(int nextCost, int prevCost, string start, string goal)
    {
        int cost = 0;

        FOR(i, 0, start.size()) {
            if (start[i] > goal[i]) {
                cost += prevCost * (start[i] - goal[i]);
            }
            if (start[i] < goal[i]) {
                cost += nextCost * (goal[i] - start[i]);
            }
        }

        return cost;
    }
};
