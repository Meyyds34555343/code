#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        
        
        if (n <= 2) return true;
        
        int x0 = coordinates[0][0], y0 = coordinates[0][1];
        int x1 = coordinates[1][0], y1 = coordinates[1][1];
        
        
        int dx = x1 - x0;
        int dy = y1 - y0;
        
        // Check if every other point lies on the same line
        // Using cross product: (x - x0) * dy == (y - y0) * dx
        for (int i = 2; i < n; i++) {
            int x = coordinates[i][0];
            int y = coordinates[i][1];
            
            
            if ((x - x0) * dy != (y - y0) * dx) {
                return false;
            }
        }
        
        return true;
    }
};