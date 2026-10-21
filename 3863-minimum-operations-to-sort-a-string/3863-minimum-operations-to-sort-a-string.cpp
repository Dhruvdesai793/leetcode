class Solution {
public:
    int minOperations(string s) {
        if(is_sorted(s.begin(), s.end())) return 0; // already sorted
        
        if (s.size() ==2) return -1; // sorting single letter does nothing;

        auto [lo, hi] = minmax_element(s.begin() + 1, s.end() -1);

        if( s[0] <= min(*lo, s.back()) //Is the first character less than or equal to every other character?
        || max(s[0], *hi) <= s.back() //Is the last character greater than or equal to every other character?
        ) return 1; // if yes, then sort other n-1 terms that req 1 operation.

        return s.back() < *lo && *hi < s[0] ? 3:2;
    }
};