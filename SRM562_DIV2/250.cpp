#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

#define FOR(i, init, end) for(int i=(init); i < (end); i++)
#define FOREACH(i, n) for(typeof(n.begin()) i = n.begin(); i != n.end(); i++)

class CucumberMarket {
public:
    int helper(vector<int> price, int budget, int k, int index)
    {   
        int ret = 1;

        if (k == 0) {
            return 1;
        }   
            
        if (index == price.size()) {
            return 1;
        }

        if (budget < 0) {
            return 0;
        }

        ret &= helper(price, budget, k, index + 1); 
        ret &= helper(price, budget - price[index], k - 1, index + 1); 

        return ret;
    }   

    string check(vector <int> price, int budget, int k)
    {
        int ret = helper(price, budget, k, 0); 

        return (ret) ? "YES" : "NO";
    }
};
