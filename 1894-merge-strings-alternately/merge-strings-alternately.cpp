#include <string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        int n1 = word1.size(), n2 = word2.size();
        int maxLen = max(n1, n2);
        
        for (int i = 0; i < maxLen; i++) {
            if (i < n1) result += word1[i];
            if (i < n2) result += word2[i];
        }
        
        return result;
    }
};