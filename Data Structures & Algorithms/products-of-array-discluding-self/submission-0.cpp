class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

     int l=nums.size();
        vector<int>result(nums.size(),1);
       int prefix=1;
        for(int i=0;i<l;i++){
       
          int x= prefix;
           prefix=prefix*nums[i];
         result[i]=x;
        }
        int post=1;
        for(int i=l-1;i>=0;i--){
           
            result[i]=post*result[i];
            post=post*nums[i];
          
        }
        return result;
    }
};