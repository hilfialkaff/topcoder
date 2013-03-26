#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, init, end) for(int i=(init); i < (end); i++)

class EasyHomework {
public:
    string determineSign(vector <int> A)
    {
        long long result = 1;
        FOR(i, 0, A.size()) {
            if (A[i] == 0) {
                return "ZERO";
            }
            result *= A[i];
        }

        if (result > 0) {
            return "POSITIVE";
        } else if (result < 0) {
            return "NEGATIVE";
        }
    }
};
