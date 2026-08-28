class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
    
private:
    void backtrack(vector<string>& result, string current, int openCount, int closeCount, int n) {
        // Base case: if we've used all pairs
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }
        
        // Add opening parenthesis if we haven't used all n
        if (openCount < n) {
            backtrack(result, current + '(', openCount + 1, closeCount, n);
        }
        
        // Add closing parenthesis if it won't make the string invalid
        if (closeCount < openCount) {
            backtrack(result, current + ')', openCount, closeCount + 1, n);
        }
    }
};