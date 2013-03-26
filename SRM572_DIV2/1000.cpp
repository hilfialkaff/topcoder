#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, init, end) for(int i=(init); i < (end); i++)

int mod = 1000000007;

class DistinctRemainders {
public:
    bool check_mod(vector<long long> v, int M)
    {
        vector<int> mods;
        int result;
        bool ret = true;

        FOR(i, 0, v.size()) {
            result = v[i] % M;
            if (find(mods.begin(), mods.end(), result) == mods.end()) {
                mods.push_back(result);
            } else {
                ret = false;
                break;
            }
        }

        return ret;
    }

	int permute(vector<long long> v)
	{
		int count = 0;
		do {
			count++;
		} while (next_permutation(v.begin(), v.end()));

		return count;
	}

    // last_int indicates the minimum value of the integer that can be added into the list.
    // We keep adding one to last_int so as to not double count numbers.
    int helper(long long N, int M, vector<long long> v, int last_int)
    {
        int distinct = 0;

        // last int is bigger than the remainder (N). This is invalid combination.
        // Refer to the above comment.
        if (N && last_int > N) {
            goto ret;
        }

        // Still able to choose numbers. Either add last_int into the vector or skip it.
        if (N > 0) {
            distinct += helper(N, M, v, last_int + 1);

            v.push_back(last_int);
            distinct += helper(N - last_int, M, v, last_int + 1);
        }

        // The numbers have been chosen. Check whether each of the modulos is different
        // and add the number of permutation of the vector.
        if (N == 0 && check_mod(v, M)) {
            distinct += permute(v);
        }

ret:
        return distinct;
    }

    int howMany(long long N, int M)
    {
        vector<long long> v;
        int distinct;

        distinct = helper(N, M, v, 0);
        return distinct;
    }
};
