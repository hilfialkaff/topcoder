#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

#define FOR(i, init, end) for(int i=(init); i < (end); i++)
#define FOREACH(i, n) for(typeof(n.begin()) i = n.begin(); i != n.end(); i++)

class SpellCardsEasy {
public:
    int helper(vector <int> level, vector <int> damage, int index)
    {
        int dmg1 = 0;
        int dmg2 = 0;

        if (index >= level.size()) {
            return 0;
        }

        dmg1 = helper(level, damage, index + 1);
        if ((index + level[index]) <= level.size()) {
			dmg2 = damage[index] + helper(level, damage, index + level[index]);
        }

        return max(dmg1, dmg2);
    }

    int maxDamage(vector <int> level, vector <int> damage)
    {
        return helper(level, damage, 0);
    }
};
