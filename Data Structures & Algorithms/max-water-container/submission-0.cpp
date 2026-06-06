class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxvol = INT_MIN;
        for(int i = 0; i<heights.size() - 1; i++){
            for(int j=i+1; j<heights.size(); j++){
                if(min(heights[j] , heights[i])*(j - i) > maxvol){
                    maxvol = min(heights[j],  heights[i])*(j - i);
                }
            }
        }
        return maxvol;


    }
};
