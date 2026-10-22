
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int shift = 0;

        while (shift < n && nums[shift] != 0)
            shift++;

        if (shift == n) return -1;

        bool forward = true, backward = true;

        for (int k = 0; k < n; k++) {
            int val = nums[(shift + k) % n];

            if (val != k)
                forward = false;

            if (val != (n - k) % n)
                backward = false;
        }

        if (forward)
            return min(shift, n - shift + 2);

        if (backward)
            return min(shift + 2, n - shift);

        return -1;
    }
};
