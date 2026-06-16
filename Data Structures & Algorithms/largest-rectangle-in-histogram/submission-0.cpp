class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int height = heights[st.top()];
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int width = i - left - 1;

                maxArea = max(maxArea, height * width);
            }

            st.push(i);
        }

        while (!st.empty()) {
            int height = heights[st.top()];
            st.pop();

            int left = st.empty() ? -1 : st.top();
            int width = n - left - 1;

            maxArea = max(maxArea, height * width);
        }

        return maxArea;
    }
};