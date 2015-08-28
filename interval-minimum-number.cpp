// Lintcode: Implement a min number segment tree to solve
// the problem.
// The height of the tree is guranteed to be Log(n).
// The reason is that when we build the tree, we break it in the middle.
// Which roughly guranttees it to be balanced tree.

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    vector<int> intervalMinNumber(vector<int> &A, vector<Interval> &queries) {
        // write your code here
        // To solve the problem efficiently we need to store the array A in an
        // efficient data structure.
        vector<int> res;
        if (A.size() == 0)
            return res;
        SegmentTreeNode *root = build(A, 0, A.size() - 1);
        
        for (auto q : queries) {
            res.push_back(query(root, q.start, q.end));
        }
        return res;
    }
private:
    class SegmentTreeNode {
    public:
        int start, end, min;
        SegmentTreeNode *left, *right;
        SegmentTreeNode(int start, int end, int min) {
            this->start = start;
            this->end = end;
            this->min = min;
            this->left = NULL;
            this->right = NULL;
        }
    };
    
    SegmentTreeNode* build(vector<int> &A, int start, int end) {
        if (start > end || start < 0 || end > A.size() - 1) {
            return NULL;
        }
        
        SegmentTreeNode *root = new SegmentTreeNode(start, end, 0);
        if (start == end) {
            root->min = A[start];
            return root;
        }
        
        int mid = start + (end - start) / 2;
        root->left = build(A, start, mid);
        root->right = build(A, mid + 1, end);
        root->min = min(root->left->min, root->right->min);
        return root;
    }
    
    int query(SegmentTreeNode* root, int start, int end) {
        if (!root || start > root->end || end < root->start || start > end)
            return INT_MAX;
        
        if (start <= root->start && end >= root->end) {
            return root->min;
        }
        
        int mid = root->start + (root->end - root->start) / 2;
        int leftMin = query(root->left, start, min(mid, end));
        int rightMin = query(root->right, max(mid + 1, start), end);
        return min(leftMin, rightMin);
    }
};

