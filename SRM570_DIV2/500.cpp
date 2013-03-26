#include <vector>
#include <cstdlib>

using namespace std;

class RobotHerbDiv2 {
public:
    int getdist (int T, vector<int> a)
    {
        int x = 0;
        int y = 0;
        int face = 0;
        vector<int>::iterator it;

		for (int i = 0; i < T; i++) {
            for (it = a.begin(); it != a.end(); it++) {
                switch(face % 4) {
                case 0:
                    y += *it;
                    break;
                case 1:
                    x += *it;
                    break;
                case 2:
                    y -= *it;
                    break;
                case 3:
                    x -= *it;
                    break;
                }

                face += *it;
            }
        }

        return abs(x) + abs(y);
    }
};
