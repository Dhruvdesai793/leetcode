class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> visited(n, false);
        int leftOut = 0;

        for (int start = 0; start < n; start++) {
            if (visited[start]) continue;

            leftOut++; // 
            stack<int> st;
            st.push(start);
            visited[start] = true;

            while (!st.empty()) {
                int curr = st.top();
                st.pop();

                for (int next = 0; next < n; next++) {
                    bool sharesRow = stones[curr][0] == stones[next][0];
                    bool sharesColumn = stones[curr][1] == stones[next][1];

                    if (!visited[next] && (sharesRow || sharesColumn)) {
                        visited[next] = true;
                        st.push(next);
                    }
                }
            }
        }

        return n - leftOut;
    }
};