class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;
        for(int i: st){
        if (st.find(i - 1) == st.end()) {
                int currentNum = i;
                int currentLength = 1;
                while (st.find(currentNum + 1) != st.end()) {
                    currentNum++;
                    currentLength++;
                }
                longest = max(longest, currentLength);
            }
    }
    return longest;
    }
};
