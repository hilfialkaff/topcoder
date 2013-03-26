#include <vector>
#include <string>

using namespace std;

class FoxAndGame {
public:
    int countStars(vector<string> result)
    {
        int count = 0;
        vector<string>::iterator it;

        for (it = result.begin(); it != result.end(); it++) {
            const char* ch = (*it).c_str();
            if (ch[0] == 'o') {
                count++;
            }
            if (ch[1] == 'o') {
                count++;
            }
            if (ch[2] == 'o') {
                count++;
            }
        }

        return count;
    }
};
