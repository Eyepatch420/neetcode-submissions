class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;

        for(int left = 0; left <= n - k; left++) {
            int maxnum = nums[left];

            for(int j = left; j < left + k; j++) {
                maxnum = max(maxnum, nums[j]);
            }

            ans.push_back(maxnum);
        }

        return ans;
    }
};