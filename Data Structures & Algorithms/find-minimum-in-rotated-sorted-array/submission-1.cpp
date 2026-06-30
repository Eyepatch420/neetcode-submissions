class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int left =0;
        int right = n -1;
        int answer;

        if(left == right) return nums[left];

        while(left<right){
            int mid = (right + left)/2;

            if(nums[mid] > nums[right]){
                answer = nums[right];
                left = mid + 1;

            }
            else if(nums[mid] < nums[right]){
                answer = nums[mid];
                right  = mid;

            }
            else{
                return {};
            }

        }
        return answer;
    }
};
