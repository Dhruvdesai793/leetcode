class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        // tried binary search per layer nlogn , tried using hash map 
        // to record rows that were negative and then each had its own loop to count -ve, n^2 .

        // STAIRCASE METHOD O(m+n)
        int i = grid.size() - 1 , j = 0;

        int res = 0;

        while(i >= 0 && j < grid[0].size()){
            if(grid[i][j] < 0){
                res += grid[0].size() - j;
                i--;
            }
            else j++;
        }
        return res;

    }
};