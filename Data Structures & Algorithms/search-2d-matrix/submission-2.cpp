class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int i = 0; i < rows; i++) {
            vector<int>& row = matrix[i];

            int left = 0;
            int right = cols - 1;
            if (target == row[left] || target == row[right]) return true;

            if (target > row[right]) {
                continue;
            } else {
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (target == row[mid]) {
                        return true;
                    } else if (target > row[mid]) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
            }
        }

        return false;
    }
};
