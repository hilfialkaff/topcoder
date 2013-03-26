#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

#define FOR(i, init, end) for(int i=(init); i < (end); i++)
#define FOREACH(i, n) for(typeof(n.begin()) i = n.begin(); i != n.end(); i++)

class BallsSeparating {
public:
    int minOperations(vector <int> red, vector <int> green, vector <int> blue)
    {   
        int size = red.size();
        int r_i = 0;
        int r_max = 0;
        int g_i = 0;
        int g_max = 0;
        int b_i = 0;
        int b_max = 0;
        int min_ops = 0;

        if (size < 3) {
            return -1;
        }   

        FOR(i, 0, red.size()) {
            if (red[i] > r_max) {
                if (!(r_i == g_i && r_max > g_max) || (r_i == b_i && r_max > b_max)) {
                    r_i = i;
                    r_max = red[i];
                }   
            }   
            if (green[i] > g_max) {
                if (!(g_i == r_i && g_max > r_max) || (g_i == b_i && g_max > b_max)) {
                    g_i = i;
                    g_max = green[i];
                }   
            }   
            if (blue[i] > b_max) {
                if (!(b_i == g_i && b_max > g_max) || (b_i == r_i && b_max > r_max)) {
                    b_i = i;
                    b_max = blue[i];
                }   
            }   
        }   

        FOR(i, 0, red.size()) {
            min_ops += (i == r_i) ? 0 : red[i];
            min_ops += (i == g_i) ? 0 : green[i];
            min_ops += (i == b_i) ? 0 : blue[i];
        }   

        return min_ops;
    }                                                                                                                                                                                                                             
};
