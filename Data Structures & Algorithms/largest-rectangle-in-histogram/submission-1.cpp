class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int idx = st.top();
                int height = heights[idx];
                int right = i;
                int left;
                st.pop();
                if(st.empty()){
                    left =-1;
                }
                else{
                    left = st.top();
                }

                int width;
                width = right - left -1;
                int area;
                area = height*width;

                if(area>maxArea){
                    maxArea = area;
                }
            }
            

            st.push(i);
        }
        while(!st.empty()){
            int idx = st.top();
            int height = heights[idx];
            int right  = n;
            st.pop();
            int left = st.empty()? -1 : st.top();
            int width = right - left -1;
            int area = height*width;
            if(area>maxArea){
                maxArea = area;
            }
            }

        

        return maxArea;
    }
};