class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        unordered_map<char, int> mp;
        int maxans = 0;

        for(int i = 0; i < s.size(); i++) {
            if(mp.count(s[i])) {
                left = max(left, mp[s[i]] + 1);
            }

            mp[s[i]] = i;
            maxans = max(maxans, i - left + 1);
        }

        return maxans;
    }
};