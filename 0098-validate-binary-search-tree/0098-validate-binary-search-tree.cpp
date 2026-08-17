class Solution {
public:
    long long prev = LLONG_MIN;

    bool isValidBST(TreeNode* root) {
        if (!root) return true;

        if (!isValidBST(root->left))
            return false;

        if (root->val <= prev)
            return false;

        prev = root->val;

        return isValidBST(root->right);
    }
};