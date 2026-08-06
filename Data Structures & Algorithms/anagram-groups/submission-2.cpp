
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
       
        for (string s : strs) {
             vector<int>freq(26,0);
            string x="";
           for (auto ch:s){
            freq[ch-'a']++;
           }
           for(int i=0;i<26;i++){
            x += to_string(freq[i]) + "#";
           }
           mp[x].push_back(s);
        }
        for (auto &i : mp) {
            ans.push_back(i.second);
        }
        return ans;
    }
};
    