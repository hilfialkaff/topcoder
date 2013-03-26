#include <vector>                                                                                                                                                                                                                 
#include <string>
#include <algorithm>

using namespace std;

#define FOR(i, init, end) for(int i=(init); i < (end); i++)

class TeamContestEasy {
public:
    int worstRank(vector <int> strength)
    {
        int team_str = strength.at(0) + strength.at(1) + strength.at(2) - min(min(strength.at(0), strength.at(1)), strength.at(2)); 
        int rank = 1;
		
        FOR(i, 3, strength.size()) {
            FOR(j, i + 1, strength.size()) {
                if ((strength.at(i) + strength.at(j)) > team_str) {
                    rank++;
                }
            }
        }
        
        return rank;
    }
};
