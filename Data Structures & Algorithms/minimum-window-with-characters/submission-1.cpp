class Solution {
public:

    bool valid(unordered_map<char,int>& need,
               unordered_map<char,int>& window)
    {
        for(auto &[ch,freq] : need)
        {
            if(window[ch] < freq)
                return false;
        }

        return true;
    }

    string minWindow(string s, string t) {

        int n = s.size();

        unordered_map<char,int> need;
        unordered_map<char,int> window;

        for(char c : t)
        {
            need[c]++;
        }

        int left = 0;

        int start = 0;
        int minLen = INT_MAX;

        for(int right = 0; right < n; right++)
        {
            window[s[right]]++;

            while(valid(need, window))
            {
                if(right - left + 1 < minLen)
                {
                    minLen = right - left + 1;
                    start = left;
                }

                window[s[left]]--;

                if(window[s[left]] == 0)
                {
                    window.erase(s[left]);
                }

                left++;
            }
        }

        if(minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};