#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

class FoxAndMp3Easy{
public:
    string convertInt(int number)
    {
        stringstream ss;
        ss << number;
        return ss.str();
    }

    vector<string> playList(int n)
    {   
        vector<string> ret;
        for (int i = 1; i <= n; i++) {
            ret.push_back(convertInt(i) + ".mp3");
        }   
        sort(ret.begin(), ret.end());            
        return ret;
    }   
};
