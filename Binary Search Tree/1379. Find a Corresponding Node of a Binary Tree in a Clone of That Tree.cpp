#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* ans = nullptr;
        findTargetCopy(cloned, target, ans);
        return ans;
    }

private:
    void findTargetCopy(TreeNode* cloned, TreeNode* target, TreeNode*& ans) {
        if (cloned == nullptr) {
            return;
        }
        if (cloned->val == target->val) {
            ans = cloned;
            return;
        }
        findTargetCopy(cloned->left, target, ans);
        findTargetCopy(cloned->right, target, ans);
    }
};

// Helper function to build a sample binary tree
TreeNode* buildTree() {
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(4);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(12);
    return root;
}

int main() {
    Solution solution;

    TreeNode* originalTree = buildTree();
    TreeNode* clonedTree = buildTree();

    TreeNode* targetNode = originalTree->left->right; // Node with value 5 in the original tree

    TreeNode* clonedTargetNode = solution.getTargetCopy(originalTree, clonedTree, targetNode);

    if (clonedTargetNode) {
        cout << "Cloned tree node value: " << clonedTargetNode->val << std::endl;
    } else {
        cout << "Target node not found in the cloned tree." << std::endl;
    }

    // TODO: Clean up and delete the dynamically allocated nodes

    return 0;
}
