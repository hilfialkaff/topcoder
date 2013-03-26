#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

#define FOR(i, init, end) for(int i=(init); i < (end); i++)

class TheDeviceDiv2 {
public:
    string identify(vector <string> plates)
    {
        bool possible = true;
        int c;

        FOR(i, 0, plates[0].size()) {
            c = 0;
            FOR(j, 0, plates.size()) {
                if (plates[j][i] == '0') {
                    c++;
                }
                
            }

            if (!c || (plates.size() - c) < 2) {
                possible = false;
                break;
            }
        }

        return possible ? "YES" : "NO";
    }
};
