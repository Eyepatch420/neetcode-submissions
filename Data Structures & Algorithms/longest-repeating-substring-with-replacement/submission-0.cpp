class Solution {
   public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char, int> mp;
        int maxfreq = INT_MIN;
        int left = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
            maxfreq = max(maxfreq, mp[s[i]]);
            while ((i - left + 1) - maxfreq > k) {
                mp[s[left]]--;
                left++;
            }
            ans= max(ans, i - left +1);
        }
        return ans;
    }
};
