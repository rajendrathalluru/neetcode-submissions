class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> current;

        backtrack(nums, target, 0, current, result);

        return result;
    }

private:
    void backtrack(vector<int>& nums, int target, int start,
                   vector<int>& current,
                   vector<vector<int>>& result) {

        // Found a valid combination
        if (target == 0) {
            result.push_back(current);
            return;
        }

        // Target exceeded
        if (target < 0) {
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            // Choose
            current.push_back(nums[i]);

            // We pass i, not i + 1, because we can reuse nums[i]
            backtrack(nums, target - nums[i], i, current, result);

            // Undo choice
            current.pop_back();
        }
    }
};