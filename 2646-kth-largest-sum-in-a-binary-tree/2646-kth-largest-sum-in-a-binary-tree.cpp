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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        vector<long long> v;

        while(!q.empty()){
            int size = q.size();
            
            long long sum = 0;
            for(int i = 0; i < size; i++){
                TreeNode* tmp = q.front();
                sum += tmp->val;
                q.pop();

                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);



 
            }
            v.push_back(sum);
        }
        if (v.size() <  k) return -1;
        sort(v.begin(), v.end(), greater<long long>()); // desc sort
        return v[k-1]; // 1 indexed k.

    }
};