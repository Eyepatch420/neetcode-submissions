class Solution {
   public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;

        for (int num : nums) {
            total += num;
        }

        if (abs(target) > total) {
            return 0;
        }

        int offset = total;

        vector<int> dp(2 * total + 1, 0);

        dp[offset] = 1;

        for (int num : nums) {
            vector<int> nextDp(2 * total + 1, 0);

            for (int sum = -total; sum <= total; sum++) {
                int index = sum + offset;

                if (dp[index] == 0) continue;

                nextDp[index + num] += dp[index];
                nextDp[index - num] += dp[index];
            }

            dp = nextDp;
        }

        return dp[target + offset];
    }
};