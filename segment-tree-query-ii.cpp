/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, count;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int count) {
 *         this->start = start;
 *         this->end = end;
 *         this->count = count;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The count number in the interval [start, end] 
     */
    int query(SegmentTreeNode *root, int start, int end) {
        // write your code here
        if (!root || start > root->end || end < root->start || start > end)
            return 0;
        
        // In this case, [start, end] totally overlap with [root->start, root->end].
        if (start <= root->start && end >= root->end)
            return root->count;
            
        // partially overlap case.
        // Similar to the reasonsing shown in segment-tree-query.cpp.
        int mid = root->start + (root->end - root->start) / 2;
        return query(root->left, start, min(end, mid)) +
            query(root->right, max(start, mid + 1), end);
    }
};
