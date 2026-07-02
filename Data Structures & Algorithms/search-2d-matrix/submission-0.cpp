class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int l = 0, r = n-1;
        while(l <= r) {
            int mid = l + (r - l)/2;
            if(target >= matrix[mid][0] && target <= matrix[mid][m-1] ) {
                int left = 0, right = m - 1;
                while(left <= right) {
                    int m = left + (right-left)/ 2;
                    if(matrix[mid][m] == target) return true;
                    else if(matrix[mid][m] > target) right = m-1;
                    else left = m+1;
                }
                return false;
            }
            else if(target > matrix[mid][m-1]) l = mid+1;
            else r = mid - 1;
        }
        return false;
    }
};
