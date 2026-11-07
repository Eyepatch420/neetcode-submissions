class Solution {
public:
    int start = 0, maxLen = 0;
    void expandAroundCentre(string s, int left, int right){
        while(left>=0 && right < s.length() && s[left] == s[right]){
            if(right - left + 1 > maxLen){
                maxLen = right - left + 1;
                start = left;
            }
            left--;
            right++;
        }
    }
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        for (int i = 0; i < s.length(); i++) {
            // Case 1: Odd length palindromes (center is character at index i)
            expandAroundCentre(s, i, i);
            
            // Case 2: Even length palindromes (center is between index i and i+1)
            expandAroundCentre(s, i, i + 1);
        }

        return s.substr(start, maxLen);
    }
};
