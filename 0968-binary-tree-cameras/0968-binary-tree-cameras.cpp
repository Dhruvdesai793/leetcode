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
    int camera = 0;
    int dfs(TreeNode* node){
        // 0 is not covered, 1 is camera place, 2 is covered;
        if(!node) return 2;

        int l = dfs(node->left);
        int r = dfs(node->right);

        if(l==0 || r==0){
            camera++;
            return 1;
        }
        if(l==1 || r==1) return 2;
        // if(l==2 || r==2) return 0;
        return 0;

    }
    int minCameraCover(TreeNode* root) {
        if(dfs(root)==0) camera++;
        return camera;
    }
};