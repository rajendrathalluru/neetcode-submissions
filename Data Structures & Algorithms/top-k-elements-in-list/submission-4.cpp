class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        // Count frequencies
        for (int num : nums) {
            freq[num]++;
        }

        // Bucket: frequency -> numbers
        vector<vector<int>> bucket(nums.size() + 1);

        for (auto it : freq) {
            bucket[it.second].push_back(it.first);
        }

        vector<int> result;

        // Traverse from highest frequency
        for (int i = bucket.size() - 1; i >= 0; i--) {

            for (int num : bucket[i]) {

                result.push_back(num);

                if (result.size() == k)
                    return result;
            }
        }

        return result;
    }
};