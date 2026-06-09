class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if(n > m) return false;

        unordered_map<char, int> need;
        unordered_map<char, int> window;

        for(char i: s1){
            need[i]++;
        }

        for(int i =0; i<n; i++){
            window[s2[i]]++;
        }

        if(window == need){
            return true;
        }

        int left = 0;

        for(int right = n; right<m; right++){
            window[s2[left]]--;
            window[s2[right]]++;

            if(window[s2[left]]==0){
                window.erase(s2[left]);
            }

            left++;

            if(window == need){
                return true;
            }
        }
        return false;

    }
};
