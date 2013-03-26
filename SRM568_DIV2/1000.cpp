#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

#define FOR(i, init, end) for(int i=(init); i < (end); i++)
#define FOREACH(i, n) for(typeof(n.begin()) i = n.begin(); i != n.end(); i++)

class ShuffleSort {
public:
    double shuffle(vector <int> cards)
    {
        int min = 51;
        int min_occur = 0;
        int index = 0;
        int sz = cards.size();

		if (sz == 0) {
			return 1;
		}

        // Multiple min values possible.
        FOR(i, 0, sz) {
            if (cards[i] < min) {
                index = i;
                min = cards[i];
                min_occur++;
            } else if (cards[i] == min) {
                min_occur++;
            }
        }

        cards.erase(cards.begin() + index);
        return ((sz / min_occur) * shuffle(cards)); // Expected value * (begins shuffling process again).
    }
};
