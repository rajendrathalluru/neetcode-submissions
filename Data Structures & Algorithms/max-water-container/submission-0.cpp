class Solution {
public:
    int maxArea(vector<int>& heights) {
        int x=0;
        int y=heights.size()-1;
        int maxwat=0;
        while(x<y){
            int res=(y-x)*min(heights[x],heights[y]);
            maxwat=max(maxwat,res);
            if(heights[x]<=heights[y]){
                x++;
            }
            else{
                y--;
            }
        }
        return maxwat;
    }
};
