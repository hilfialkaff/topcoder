#include <vector>
#include <string>
#include <algorithm>                                                                                             

using namespace std;

#define FOR(i, init, end) for(int i=(init); i < (end); i++)

class SkiResortsEasy {
public:
    int minCost(vector <int> altitude)
    {
        int cost = 0;
        vector<int>::iterator it;

        FOR(i, 0, (altitude.size() - 1)) {
            if (altitude.at(i) < altitude.at(i+1)) {
                cost += (altitude.at(i+1) - altitude.at(i));                                                                                                                                                                      
                altitude.at(i+1) = altitude.at(i);
            }
        }
        
        return cost;
    }
};
