class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // centre node appears in every edge 
        // sooooo it must be present in both the first and second edge
        int u = edges[0][0];
        int v = edges[0][1];
        
        if (u == edges[1][0] || u == edges[1][1]) {
            return u;
        }
        return v;
    }
};