class Solution {
public:
    vector<int> twoSum(vector<int> nums, int target) {
         unordered_set<int> seen;  // Set to store seen numbers
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        // Check if the complement is already in the set
        if (seen.find(complement) != seen.end()) {
            // If found, return the indices
            
            // You would also need to find the index of the complement in the original array.
            // For simplicity, here we are just showing how to find one index.
            for (int j = 0; j < i; j++) {
                if (nums[j] == complement) {
                    result.push_back(j);
                    result.push_back(i);
                    break;
                }
            }
            break;  // If you only want one pair, break the loop
        }

        // Add current element to the set
        seen.insert(nums[i]);
    }

    return result;
        }
};
