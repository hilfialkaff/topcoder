#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

#define FOR(i, init, end) for(int i=(init); i < (end); i++)
#define FOREACH(i, n) for(typeof(n.begin()) i = n.begin(); i != n.end(); i++)

class PastingPaintingDivTwo {
public:
    long long countColors(vector <string> clipboard, int T)
    {
        map<pair<int, int>, bool> result;
        pair<int, int> p;

        FOR(i, 0, T) {
            FOR(j, 0, clipboard.size()) {
                FOR(k, 0, clipboard[j].size()) {
                	if (clipboard[j][k] != 'B') continue;
                	p = pair<int, int>(i + j, i + k);
                    result.insert(pair<pair<int, int>, bool>(p, true));
                }
            }
        }

        return result.size();
    }
};
