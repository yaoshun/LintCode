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
        int mid = root->start + (root->end - root->start)/2;

        // Notice and learn the min max trick.
        // Why is that? for the left tree, we can use 
        // query(root->left, start, end) to also get the right results.
        // Because the above condition is covering boundary check.
        // However, min(end, mid) can help to reduce the time a little bit.
        int leftMax = query(root->left, start, min(end, mid));
        int rightMax = query(root->right, max(mid + 1, start), end);
        return max(leftMax, rightMax);
    }
};
