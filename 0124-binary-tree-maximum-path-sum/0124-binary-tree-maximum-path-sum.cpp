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
    int best = INT_MIN;
    int gain(TreeNode* node){
        if(!node) return 0;

        int leftGain = gain(node->left);
        int rightGain = gain(node->right);

        leftGain = max(leftGain, 0);
        rightGain = max(rightGain, 0);

        int pathViaNode = node->val + leftGain + rightGain;
        best = max(pathViaNode, best);

        return node->val + max(leftGain, rightGain);
    }
    int maxPathSum(TreeNode* root) {
        gain(root);
        return best;
    }
};