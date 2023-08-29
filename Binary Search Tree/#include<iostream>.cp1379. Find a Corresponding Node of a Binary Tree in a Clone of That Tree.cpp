#include<iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val): val(val),left(NULL),right(NULL){}

};

class Solution{
    public:
    TreeNode* getTargetCopy(TreeNode* original,TreeNode* cloned,TreeNode* target){
        TreeNode* ans;
        ans = findTargetCopy(cloned,target,ans);
        return ans;
    }

    private:
    TreeNode* findTargetCopy(TreeNode* cloned,TreeNode* target,TreeNode* ans){
        if(cloned==NULL){
            return;
        }
        if(cloned->val == target->val){
            ans = cloned;
        }
        findTargetCopy(cloned->left,target,ans);
        findTargetCopy(cloned->right,target,ans);
        return ans;        
    }
}

TreeNode* buildTree(){
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(8);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(10);
    root->left->right = new TreeNode(11);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(13);
    return root;
}

int main(){
    Solution solution;
    TreeNode* original = buildTree;
    TreeNode* cloned = original;

    TreeNode* target = original->left->left;
    TreeNode* clonedTargetNode = solution.getTargetCopy(original,cloned,target);

    if (clonedTargetNode) {
        cout << "Cloned tree node value: " << clonedTargetNode->val << std::endl;
    } else {
        cout << "Target node not found in the cloned tree." << std::endl;
    }
}