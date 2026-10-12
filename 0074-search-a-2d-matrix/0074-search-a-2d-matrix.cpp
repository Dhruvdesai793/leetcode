// originally implemented binary search per row, failed.

// this solution is using unique way of seeing the matrix, if we observe closely the matrix is a BST!!!!!!!!
// https://assets.leetcode.com/users/images/f29529fe-2398-4919-a154-60f210d92d11_1648601421.8099654.jpeg THAT TOO FAILED

// final solution, using 1 binary search for whole matrix. 


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int left = 0;
        int right = rows * cols - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            int row = mid / cols;
            int col = mid % cols;
            int guess = matrix[row][col];

            if (guess == target) {
                return true;
            } else if (guess < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;        
    }
};