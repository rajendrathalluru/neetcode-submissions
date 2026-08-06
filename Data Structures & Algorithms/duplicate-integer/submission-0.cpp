class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
     map<int,int>x;
     for(int i=0;i<nums.size();i++){
        x[nums[i]]++;
     }
     for(auto it :x){
        if(it.second>1){
            return true;
        }
     }
     return false;
    }
};
