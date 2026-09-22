#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if (s.length() != t.length()) return false;
        
        // Count frequency of each character
        vector<int> count(26, 0);
        
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;   // increment for s
            count[t[i] - 'a']--;   // decrement for t
        }
        
        
        for (int c : count) {
            if (c != 0) return false;
        }
        
        return true;
    }
};