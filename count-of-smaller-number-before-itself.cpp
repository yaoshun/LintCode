// LintCode segment tree solution using count as the associated value.
// We did not extend the tree in empty regions but just allow it to be
// all zero.

class Solution {
public:
   /**
     * @param A: An integer array
     * @return: Count the number of element before this element 'ai' is 
     *          smaller than it and return count number array
     */
    vector<int> countOfSmallerNumberII(vector<int> &A) {
        // write your code here
        int n = A.size();
        vector<int> res(n, 0);
        if (n == 0)
            return res;
            
        SegmentTreeNode *root = new SegmentTreeNode(A[0], A[0], 1);
        for (int i = 1; i < n; i++) {
            res[i] = update(root, A[i]);
        }
        return res;
    }
private:
    class SegmentTreeNode {
    public:
        int start, end, count;
        SegmentTreeNode *left, *right;
        SegmentTreeNode(int start, int end, int count) {
            this->start = start;
            this->end = end;
            this->count = count;
            this->left = this->right =NULL;
        }
    };
    
    SegmentTreeNode *buildLeft(int start, int end) {
        SegmentTreeNode *node = new SegmentTreeNode(start, end, 1);
        if (start == end)
            return node;
        node->left = new SegmentTreeNode(start, start, 1);
        node->right = new SegmentTreeNode(start + 1, end, 0);
        return node;
    }
    
    SegmentTreeNode *buildRight(int start, int end) {
        SegmentTreeNode *node = new SegmentTreeNode(start, end, 1);
        if (start == end)
            return node;
        node->left = new SegmentTreeNode(start, end - 1, 0);
        node->right = new SegmentTreeNode(end, end, 1);
        return node;
    }
    
    int update(SegmentTreeNode *& root, int val) {
        // Insert the value and also updated the counter SegmentTree.
        if (val > root->end) {
            int res = root->count;
            SegmentTreeNode *head = new SegmentTreeNode(root->start, val, res + 1);
            head->right = buildRight(root->end + 1, val);
            head->left = root;
            root = head;
            return res;
        }
        
        if (val < root->start) {
            SegmentTreeNode *head = new SegmentTreeNode(val, root->end, root->count + 1);
            head->left = buildLeft(val, root->start - 1);
            head->right = root;
            root = head;
            return 0;
        }
        
        root->count++;
        if (root->left) {
            if (root->left->end >= val)
                return update(root->left, val);
            else
                return update(root->right, val) + root->left->count;
        } else {
            // There are two cases without children nodes in this scenario.
            // either start == end or count == 0.
            if (root->start == root->end) {
                // Do nothing here.
            } else if (root->count == 1 && val < root->end){
                root->left = buildRight(root->start, val);
                root->right = new SegmentTreeNode(val + 1, root->end, 0);
            } else {
                root->left = new SegmentTreeNode(root->start, val - 1, 0);
                root->right = new SegmentTreeNode(val, root->end, 1);
            }
            return 0;
        }
    }
};
