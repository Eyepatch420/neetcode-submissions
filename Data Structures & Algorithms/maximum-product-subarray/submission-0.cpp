class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int curMin = nums[0];
        int curMax = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int n = nums[i];
            
            // Because a negative number can flip min to max and max to min, 
            // we store temporary values before updating.
            int tempMax = max({n, n * curMax, n * curMin});
            curMin = min({n, n * curMax, n * curMin});
            
            curMax = tempMax;
            res = max(res, curMax);
        }
        
        return res;
    }
};