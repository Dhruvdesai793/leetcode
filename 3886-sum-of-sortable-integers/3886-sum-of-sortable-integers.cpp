class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        // prefMax[i] = maximum of nums[0 ... i-1]
        vector<int> prefMax(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefMax[i + 1] = max(prefMax[i], nums[i]);
        }

        // suffMin[i] = minimum of nums[i ... n-1]
        vector<int> suffMin(n + 1, INT_MAX);
        for (int i = n - 1; i >= 0; i--) {
            suffMin[i] = min(nums[i], suffMin[i + 1]);
        }

        // prefDrop[i] = number of descents nums[j-1] > nums[j]
        // for j in [1 ... i]
        vector<int> prefDrop(n, 0);
        for (int i = 1; i < n; i++) {
            prefDrop[i] = prefDrop[i - 1] + (nums[i - 1] > nums[i]);
        }

        auto valid = [&](int k) {
            // Check every block of length k.
            for (int start = 0; start < n; start += k) {
                int end = start + k - 1;

                // Count ordinary descents inside the block.
                int drops = prefDrop[end] - prefDrop[start];

                // Also count the circular edge: end -> start.
                if (nums[end] > nums[start]) {
                    drops++;
                }

                // A block can be rotated into non-decreasing order
                // iff its circular sequence has at most one descent.
                if (drops > 1) {
                    return false;
                }

                // Everything before this block must be <=
                // everything from this block onward, so the
                // independently rotated blocks can join sorted.
                if (prefMax[start] > suffMin[start]) {
                    return false;
                }
            }

            return true;
        };

        int answer = 0;

        // Enumerate divisors in pairs.
        for (int d = 1; d <= n / d; d++) {
            if (n % d == 0) {
                if (valid(d)) {
                    answer += d;
                }

                int other = n / d;
                if (other != d && valid(other)) {
                    answer += other;
                }
            }
        }

        return answer;
    }
};