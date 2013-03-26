#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

#define FOR(i, init, end) for(int i=(init); i < (end); i++)

class TheJediTestDiv2 {
public:
    int countSupervisors(vector <int> students, int Y, int J)
    {   
        int num = 0;
        int yoda_floor = 0;
        int max_student = 0;

        FOR(i, 0, students.size()) {
        	if (abs(students[i] - Y) < abs(max_student - Y)) {
        		yoda_floor = i;
        		max_student = students[i];
        	}
        }   
        
        students[yoda_floor] = max(0, students[yoda_floor] - Y);

        FOR(i, 0, students.size()) {
            num += ceil(float(students[i]) / J);
        }

        return num;                                                                                                                                                                                                               
    }
};
