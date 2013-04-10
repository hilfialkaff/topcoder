#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

#define FOR(i, init, end) for(int i=(init); i < (end); i++) #define FOREACH(i, n) for(typeof(n.begin()) i = n.begin(); i != n.end(); i++)

class RandomOption {
public:
    int fact(int num)
    {
        if (num == 1) {
            return 1;
        }
        return num * fact(num - 1);
    }

    double permute(int keyCount, vector <int> badLane1, vector <int> badLane2, vector<int> combination)
    {
        vector<int> new_combination;
        int bad1_index, bad2_index;
        double total = 0;

        if (combination.size() == keyCount) {
            FOR(i, 0, badLane1.size()) {
                bad1_index = find(combination.begin(), combination.end(), badLane1[i]) - combination.begin();
                bad2_index = find(combination.begin(), combination.end(), badLane2[i]) - combination.begin();

                if (abs(bad1_index - bad2_index) == 1) {
                    return 0;
                }
            }
            return 1;
        }

        FOR(i, 0, keyCount) {
            if (find(combination.begin(), combination.end(), i) == combination.end()) {
                new_combination = combination;
                new_combination.push_back(i);
                total += permute(keyCount, badLane1, badLane2, new_combination);
            }
        }

        return total;
    }

    double getProbability(int keyCount, vector <int> badLane1, vector <int> badLane2)
    {
        double num_possible;
        vector<int> combination;

        num_possible = permute(keyCount, badLane1, badLane2, combination);

        return (num_possible / fact(keyCount));
    }
};
