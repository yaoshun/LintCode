// LintCode segment tree build ii problem.

/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param A: a list of integer
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(vector<int>& A) {
        // write your code here
        if (A.size() == 0)
            return NULL;
        return buildRange(A, 0, A.size() - 1);
    }
    
    SegmentTreeNode* buildRange(vector<int>& A, int start, int end) {
        SegmentTreeNode* root = new SegmentTreeNode(start, end, INT_MIN);
        if (start == end) {
            root->max = A[start];
            return root;
        }
        
        int mid = start + (end - start) / 2;
        root->left = buildRange(A, start, mid);
        root->right = buildRange(A, mid + 1, end);
        root->max = max(root->left->max, root->right->max);
        return root;
    }
};
