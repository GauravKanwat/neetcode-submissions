class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int low = 0, high = n-1;
        while(low <= high) {
            int mid = (low + high) / 2;

            if(matrix[mid][0] <= target && matrix[mid][m-1] >= target) {
                int left = 0, right = m-1;
                while(left <= right) {
                    int mid2 = left + (right - left) / 2;
                    if(matrix[mid][mid2] == target) return true;
                    if(matrix[mid][mid2] < target) left = mid2 + 1;
                    else right = mid2 - 1;
                }
                return false;
            }
            else if(matrix[mid][0] > target) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
};
