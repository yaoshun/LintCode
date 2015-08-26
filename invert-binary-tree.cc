// LintCode invert binary tree.

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode *root) {
        // write your code here
        // No return in this case have to check NULL.
        if (!root)
            return;
        invertBinaryTree(root->left);
        invertBinaryTree(root->right);
        // Using the C++ convinient swap function.
        swap(root->left, root->right);
        return;
    }
};

