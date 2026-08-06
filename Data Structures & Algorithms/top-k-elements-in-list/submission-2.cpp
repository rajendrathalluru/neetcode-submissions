class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        vector<int>res;
        vector<vector<int>>bs(n+1);
        for(int num:nums){
            mp[num]++;
        }
        for(auto &it:mp){
            bs[it.second].push_back(it.first);
        }
        for(int i=n;i>=0;i--){
            for(int r:bs[i]){
            if(res.size()<k){
                res.push_back(r);
            }
        }
        if (res.size()==k){
            break;
        }
        }
        return res;
    }
};