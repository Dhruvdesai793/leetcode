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
    int widthOfBinaryTree(TreeNode* root) {
        //using bin tree's prop of 2*i+1 & 2*i+2;
        // last - first idx per each lvl;
        if(!root) return 0;
        using nodeindex = pair<TreeNode*, unsigned long long>;

        queue<nodeindex> q;
        q.push({root, 0});
        int maxCount = 0;

        while(!q.empty()){
            unsigned long long first = q.front().second;
            auto last = first;
            int size = q.size();

            for(int i = 0; i<size;  i++){
                auto [node, rawIndex]  =q.front();
                q.pop();

                auto idx = rawIndex - first;
                last = idx;

                if ( node->left) q.push({node->left, 2*idx + 1});
                if(node->right) q.push({node->right, 2*idx + 2});

            }
            maxCount = max(maxCount, static_cast<int>(last+1));
        }
        return maxCount;

    }
};