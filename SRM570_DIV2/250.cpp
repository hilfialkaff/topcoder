#include <vector>
#include <algorithm>

using namespace std;

class Chopsticks {
public:
    int getmax (vector<int> length)
    {
        int count = 0;
        sort(length.begin(), length.end());

        for (int i = 0; i < length.size(); i++) {
            if (length.at(i) == length.at(i+1)) {
                count++;
                i++;
            }
        }

        return count;
    }
};
