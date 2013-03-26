#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

	void print_vector(vector<int> v)
	{
		vector<int>::iterator it;
		for (it = v.begin(); it != v.end(); it++) {
			cout << *it << ' ';
		}
		cout << endl;
	}
	
   void try_all(long long &result, vector<int> servers, vector<int> human, vector<int> centaur, vector<int> a, vector<int> b)
    {   
        int i;
        vector<int>::iterator it; 
        vector<int>::iterator it2;
        bool add = true;

        if (servers.size() > 0) {
            i = servers.back();
            servers.pop_back();
            
            human.push_back(i);
            try_all(result, servers, human, centaur, a, b); 
            
            human.pop_back();
            centaur.push_back(i);
            
            try_all(result, servers, human, centaur, a, b); 
        } else {
            cout << "human: " << endl;
            print_vector(human);
            cout << "centaur: " << endl;
            print_vector(centaur);
            
            if (human.size() > 1) {
            for (it = human.begin(); it != human.end(); it++) {
            	cout << "finding: " << *it << endl;
                it2 = find(a.begin(), a.end(), *it);
                if (it2 != a.end()) {
                    i = it2 - a.begin();
                    cout << "case a i: " <<  i << endl;
                    if (find(human.begin(), human.end(), b.at(i)) == human.end()) {
                        add = false;
                    }   
                } else {
                    it2 = find(b.begin(), b.end(), *it);
                    if (it2 != b.end()) {
                        i = it2 - b.begin();
                        cout << "case b i: " <<  i << endl;
                        if (find(human.begin(), human.end(), a.at(i)) == human.end()) {
                            add = false;
                        }   
                    }   
                }   
            }   
            }

            if (add) {
                result++;
            }   
        }   
    }   
    
class CentaurCompanyDiv2 {
public:
    long long count (vector<int> a, vector<int> b)
    {
        int N = a.size() + 1;
        vector<int> servers, human, centaur;
        long long result = 0;

        for (int i = 1; i <= N; i++) {
            if (find(a.begin(), a.end(), i) == a.end() && find(b.begin(), b.end(), i) == b.end()) {
                continue;
            }
            servers.push_back(i);
        }

        try_all(result, servers, human, centaur, a, b);

        return result;
    }
};   
