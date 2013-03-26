#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

#define FOR(i, init, end) for(int i=(init); i < (end); i++)

class MegaFactorialDiv2 {
public:
    int factorial(int N)
    {
        if (N == 1) return 1;                                                                                                                                                                                                     
        return N * factorial(N - 1);
    }

    int helper(int N, int K)
    {   
        if (!N) {
            return 1;
        }
        
        if (K == 1) {
            return factorial(N);
        }
        
        if (!K) {
            return N;
        }
        
        return helper(N, K - 1) * helper(N - 1, K);
    }
    
    int divisor(int n)
    {   
        int count = 0;
        FOR(i, 1, n + 1) {
            if (!(n % i)) {
                count++;
            }
        }
        
        return count;
    }
    
    int countDivisors(int N, int K)
    {   
        int result = helper(N, K);
        return divisor(result);
    }
};
