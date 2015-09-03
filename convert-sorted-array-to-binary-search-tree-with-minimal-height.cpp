// LintCode Problem

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
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
    TreeNode *sortedArrayToBST(vector<int> &A) {
        // write your code here
        if (A.size() == 0)
            return NULL;
        return arrayToBST(A, 0, A.size() - 1);
    }
    
    TreeNode *arrayToBST(vector<int> &A, int start, int end) {
        if (start > end)
            return NULL;
        int mid = start + (end - start) / 2;
        TreeNode *res = new TreeNode(A[mid]);
        if (start == end) {
            return res;
        } else {
            res->left = arrayToBST(A, start, mid - 1);
            res->right = arrayToBST(A, mid + 1, end);
            return res;
        }
    }
};
