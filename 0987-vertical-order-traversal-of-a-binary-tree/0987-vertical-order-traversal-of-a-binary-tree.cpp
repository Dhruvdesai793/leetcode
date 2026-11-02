/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* node, int row, int col, vector<tuple<int, int, int>> &res){
        if(!node) return ;
        res.push_back({col, row, node->val});
        dfs(node->left, row+1, col-1, res);
        dfs(node->right, row+1, col+1, res);

    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int, int, int>> nodes;
        dfs(root, 0,0, nodes);

        sort(nodes.begin(), nodes.end());
        int prevCol = INT_MIN;
        
        vector<vector<int>> result;
        for(auto [col, row, val]: nodes){
            if(col != prevCol){
                result.push_back({});
                prevCol = col;
            }
            result.back().push_back(val);
        }

        return result;
    }
};