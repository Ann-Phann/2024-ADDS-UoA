#include "Finder.h"

    using namespace std;

    //reduce the number of iterations by using the last found index
    vector<int> Finder::findSubstrings(string s1, string s2) {

        vector<int> result;
        size_t last_found = 0;

        for(size_t i = 1; i <= s2.size(); i++) {
            size_t found = s1.find(s2.substr(0, i), last_found);
            if (found != string::npos) {
                //result[i-1] = found;
                result.push_back(found);
                last_found = found;
            } 
            // else {
            //     result.push_back(-1);
            //     break;
            // }
        }
        while (result.size() < s2.size())
        {
            result.push_back(-1);
        }
        return result;
    }
   