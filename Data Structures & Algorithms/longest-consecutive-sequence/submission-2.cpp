class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
    int current = 1;
    int longest = 1;
    sort(nums.begin(), nums.end());

    if(nums.empty()) return 0;
    for(int i = 1; i<nums.size(); i++){
        if(nums[i] == nums[i-1]+1){
            current++;
            if(current>longest){
                longest=current;
            }
        }
        else if(nums[i]==nums[i-1]){
            continue;
        }
        else{
            current = 1;
        }
      
    }
    return longest;
    }
};
