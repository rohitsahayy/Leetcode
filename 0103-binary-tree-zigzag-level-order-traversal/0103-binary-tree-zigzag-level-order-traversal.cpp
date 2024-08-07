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
        vector<vector<int>> answer;
        if(root==nullptr) return answer;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        while(!q.empty()){
            int size = q.size();
            vector<int> level(size);
            for(int i=0;i<size;i++){
                TreeNode* front = q.front();
                q.pop();

                int index = (leftToRight) ? i : (size-i-1);
                level[index] = front->val;

                if(front->left!=nullptr) q.push(front->left);
                if(front->right!=nullptr) q.push(front->right);
            }
            answer.push_back(level);
            leftToRight = !leftToRight;
        }
        return answer;
    }
};