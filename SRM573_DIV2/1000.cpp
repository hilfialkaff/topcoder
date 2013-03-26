#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define FOR(i, init, end) for(int i=(init); i < (end); i++)

const int MOD = 1000000007;

class WolfPackDivTwo {
public:
	
	int helper(vector<int>& x, vector <int>& y, int m, int index)
    {
        int x_orig, y_orig;
        int numWays = 0;
        bool add = true;
        int i = index % x.size();
        int next_m = ((index + 1) % x.size()) ?  (m) : (m - 1);
        
        if (m > 0) { /* Move wolves. Only decrement m after you move all wolves. */
                x_orig = x.at(i);
                y_orig = y.at(i);

                x.at(i) = x_orig + 1;
                numWays += helper(x, y, next_m, index+1);

                x.at(i) = x_orig - 1;
                numWays += helper(x, y, next_m, index+1);

                x.at(i) = x_orig;
                y.at(i) = y_orig + 1;
                numWays += helper(x, y, next_m, index+1);

                y.at(i) = y_orig - 1;
                numWays += helper(x, y, next_m, index+1);
        } else { /* Done moving. Check whether all wolves are present in the same point */
            FOR(i, 0, x.size() - 1) {
                if (x.at(i) != x.at(i + 1) || y.at(i) != y.at(i + 1)) {
                    add = false;
                }
            }

            if (add) {
                numWays++;
            }
        }
        
        return numWays % MOD;
    }


    int calc(vector <int> x, vector <int> y, int m)
    {   
        int numWays;
        numWays = helper(x, y, m, 0); 

        return numWays % MOD;
    }   
};
