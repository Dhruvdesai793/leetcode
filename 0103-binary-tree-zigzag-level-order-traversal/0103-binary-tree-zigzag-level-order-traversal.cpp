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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;

        queue<TreeNode*> q;
        q.push(root);
        bool rev = false;

        while(!q.empty()){
            int size = q.size();
            vector<int> level;

            for (int i = 0; i<size; i++){
                TreeNode* tmp = q.front();
                q.pop();
                level.push_back(tmp->val);

                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
            if(rev) reverse(level.begin(), level.end());
            rev = !rev;
            res.push_back(level);
        }
        return res;
        
    }
};