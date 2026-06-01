class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {

            int left = i - 1;
            int right = i + 1;
            int product = 1;

            while (left >= 0 || right < nums.size()) {

                if (left >= 0) {
                    product *= nums[left];
                    --left;
                }

                if (right < nums.size()) {
                    product *= nums[right];
                    ++right;
                }
            }

            ans.push_back(product);
        }

        return ans;
    }
};