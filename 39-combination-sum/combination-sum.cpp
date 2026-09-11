#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        
        // 排序有助于剪枝（可选，但推荐）
        std::sort(candidates.begin(), candidates.end());
        
        backtrack(candidates, target, 0, current, result);
        
        return result;
    }
    
private:
    void backtrack(std::vector<int>& candidates, int target, int start,
                   std::vector<int>& current,
                   std::vector<std::vector<int>>& result) {
        // 找到有效组合
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        for (int i = start; i < candidates.size(); i++) {
            // 剪枝：如果当前数已经大于 target，后面的数更大，直接跳过
            if (candidates[i] > target) break;
            
            // 选择当前数
            current.push_back(candidates[i]);
            
            // 递归：注意这里传 i 而不是 i+1，因为同一个数可以重复使用
            backtrack(candidates, target - candidates[i], i, current, result);
            
            // 回溯：撤销选择
            current.pop_back();
        }
    }
};