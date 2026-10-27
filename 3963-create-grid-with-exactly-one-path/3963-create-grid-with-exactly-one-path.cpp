class Solution {
public:
    vector<string> createGrid(int m, int n) {
        bool flag = false;
        vector<string> ans;
        for(int i = 0; i < m; i++){
            string level ="";
            for(int j = 0; j<n; j++){
                if(j==0) level = level + ".";
                else if(i == m-1) level = level + ".";
                else level = level + "#";
            }
            ans.push_back(level);
        }
        return ans;
    }
};