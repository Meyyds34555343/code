#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int closest_sum = nums[0] + nums[1] + nums[2];  // 初始化为第一个三数之和
        
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int current_sum = nums[i] + nums[left] + nums[right];
                
                // 如果当前和更接近 target，更新 closest_sum
                if (std::abs(current_sum - target) < std::abs(closest_sum - target)) {
                    closest_sum = current_sum;
                }
                
                // 根据与 target 的比较移动指针
                if (current_sum < target) {
                    left++;
                } else if (current_sum > target) {
                    right--;
                } else {
                    // 如果正好等于 target，直接返回
                    return current_sum;
                }
            }
        }
        
        return closest_sum;
    }
};