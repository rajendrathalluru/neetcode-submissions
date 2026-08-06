class Solution {
public:
    vector<int> twoSum(vector<int> nums, int target) {
       map<int,int>x;
        vector<int>res;
        for (int i=0;i<nums.size();i++){
           int rem= target-nums[i];
            if (x.find(rem)==x.end()){
                 x[nums[i]]=i;

            }
            else{
             res.push_back(x[rem]);
                res.push_back(i);
                break;
            }
        }
        return res;
        }
};
