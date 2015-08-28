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
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The maximum number in the interval [start, end]
     */
    int query(SegmentTreeNode *root, int start, int end) {
        // write your code here
        // root has its own root->start and root->end.
        // In this case, we need to find the overlapping betweent them.
        if (!root)
            return INT_MIN;
        if (root->end < start || root->start > end || start > end)
            return INT_MIN;
        
        if (start <= root->start && end >= root->end)
            return root->max;
        
        // By definition, the left side of segment tree is leftWall
        // in the following format.
        int leftWall = root->start + (root->end - root->start)/2;
        int leftMax = query(root->left, start, min(end, leftWall));
        int rightMax = query(root->right, max(leftWall + 1, start), end);
        return max(leftMax, rightMax);
    }
};
