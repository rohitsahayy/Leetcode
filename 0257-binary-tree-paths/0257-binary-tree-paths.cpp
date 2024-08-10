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
    bool isLeaf(TreeNode* root){
        return (root->left==nullptr && root->right==nullptr);
    }
    
    void getPath(TreeNode* root,string path,vector<string> &ans){
        path += to_string(root->val);
        
        if(isLeaf(root)){
            ans.push_back(path);
            return;
        }
        
        if(root->left !=nullptr){
            getPath(root->left,path+"->",ans);
        }
        if(root->right!=nullptr){
            getPath(root->right,path+"->",ans);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        getPath(root,"",ans);
        return ans;
    }
};