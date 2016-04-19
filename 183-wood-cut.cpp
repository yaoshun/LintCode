// LintCode problem

class Solution {
public:
    /** 
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int woodCut(vector<int> L, int k) {
        // write your code here
        // We can check in O(n) time on whether a length could work.
        if (L.size() == 0) {
            return 0;
        }
        
        int st = 1;
        int ed = 0;
        
        for (auto& len : L) {
            ed = max(ed, len);
        }
        
        // In case everything in the array is zero.
        if (ed < st) {
            ed = st;
        }
        
        // Find the first length that is not a solution.
        // Be careful of the binary search.
        while (st < ed) {
            int mid = st + (ed - st) / 2;
            int pieces = 0;
            for (auto& len : L) {
                pieces += len / mid;
            }
            if (pieces >= k) {
                st = mid + 1;
            } else {
                ed = mid;
            }
        }
        return st - 1;
    }
};
