class Solution {
   public:
    int numDecodings(string s) {
        int n = s.length();
        if (n == 0 || s[0] == '0') return 0;
        vector<int> dp(n + 1, 0);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                dp[i] = 0;
            } else {
                dp[i] = dp[i + 1];
                if (i + 1 < n) {
                    int twoDigit = stoi(s.substr(i, 2));
                    if (twoDigit >= 10 && twoDigit <= 26) {
                        dp[i] += dp[i + 2];
                    }
                }
            }
        }

        return dp[0];
    }
};
