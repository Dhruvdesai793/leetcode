class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        while (i > 0 && nums[i-1] >= nums[i]) {
            i--; // 1st decreasing elem from right
        }
        
        if (i == 0) {
            reverse(nums.begin(), nums.end());
            return; // none found, reverse and return;
        }
        
        int j = nums.size() - 1;
        while (j >= i && nums[j] <= nums[i-1]) {
            j--; // smallest elem from right side that is greater that 1st decreasing elem
        }
        
        swap(nums[i-1], nums[j]);
        reverse(nums.begin() + i, nums.end());        
    }
};