class Solution {
public:
    bool isAnagram(string s, string t) {
       if(s.size()!=t.size()){
        return false;
       }
       unordered_map<char,int> mp;

       for(char i: s){
        mp[i]++;
       }

       for(int i = 0; i<t.size(); i++){
        if(mp.count(t[i]==0)){
            return false;
        }
        mp[t[i]]--;
        if(mp[t[i]]<0){
            return false;
        }
       }
       return true;
    }
};
