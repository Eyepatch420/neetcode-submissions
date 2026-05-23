class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> ans;
        int n = nums.size();
        
        for(int i : nums){
            ans.insert(i);
        }
        int m = ans.size();
        if(n==m){
            return false;
        } return true;
    }
};