#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
        int n = nums.size();
        
        if (n < 4) return result;
        
        std::sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 3; i++) {
            // 跳过重复的第一个数
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            // 剪枝：最小的四个数之和已经大于 target
            if ((long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            // 剪枝：当前数加上最大的三个数仍小于 target
            if ((long long)nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target) continue;
            
            for (int j = i + 1; j < n - 2; j++) {
                // 跳过重复的第二个数
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                
                // 剪枝
                if ((long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                if ((long long)nums[i] + nums[j] + nums[n - 1] + nums[n - 2] < target) continue;
                
                int left = j + 1;
                int right = n - 1;
                
                while (left < right) {
                    long long current_sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    
                    if (current_sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        // 跳过重复的第三个数
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        // 跳过重复的第四个数
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        
                        left++;
                        right--;
                    } else if (current_sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        
        return result;
    }
};