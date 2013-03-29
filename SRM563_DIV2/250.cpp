#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

#define FOR(i, init, end) for(int i=(init); i < (end); i++)
#define FOREACH(i, n) for(typeof(n.begin()) i = n.begin(); i != n.end(); i++)

class FoxAndHandleEasy {
public:
    string isPossible(string S, string T)
    {
        bool match;
        string ret = "No";

        FOR(i, 0, T.size()) {
            match = false;
            if(T.compare(i, S.size(), S)) {
                ret = "Yes";
                break;
            }
        }

        return ret;
    }
};
