class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxvol = 0;
        int n = heights.size();
        int left = 0;
        int right = n -1;
        
        while(left<right){
            if(min(heights[left], heights[right])*(right-left) > maxvol){
                maxvol = min(heights[left], heights[right])*(right-left);
            }
            if(heights[left]< heights[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxvol;


    }
};
