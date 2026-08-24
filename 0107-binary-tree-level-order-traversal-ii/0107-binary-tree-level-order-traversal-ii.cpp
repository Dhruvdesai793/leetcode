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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;

        if(!root) return ans;
        queue <TreeNode*> treeQueue;
        treeQueue.push(root);


        while(!treeQueue.empty()){
            int lSize = treeQueue.size();
            vector<int> level;

            for(int i = 0; i<lSize; i++){
                TreeNode* currNode = treeQueue.front();
                treeQueue.pop();

                level.push_back(currNode->val);

                if(currNode->left){
                    treeQueue.push(currNode->left);
                }
                if(currNode->right){
                    treeQueue.push(currNode->right);
                }
            }
            ans.insert(ans.begin(), level);

        }

        return ans;
    }
};