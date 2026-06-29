class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int left = 0;
        int right = rows * cols - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Convert mid into row and column
            int r = mid/cols;
            int c = mid%cols;

            // Compare matrix[r][c] with target
            if(matrix[r][c] == target) return true;
            if(matrix[r][c] < target) left = mid+1;
            if(matrix[r][c] > target) right = mid-1;

        }
        return false;
    }
};
