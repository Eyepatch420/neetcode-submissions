class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int left =0;
        int right = n -1;

        if(left == right) return nums[left];

        while(left<right){
            int mid = (right + left)/2;

            if(nums[mid] > nums[right]){
                left = mid + 1;

            }
            else if(nums[mid] < nums[right]){
                right  = mid;

            }
            

        }
        return nums[left];
    }
};
