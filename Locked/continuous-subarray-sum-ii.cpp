// LintCode continuous subarray sum ii

class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySumII(vector<int>& A) {
        // Write your code here
        int n = A.size();
        if (n == 0)
            return vector<int>{-1, -1};
        
        // Each rotation array corresponding to totalsum - (minimum subarray).    
        int totalsum = 0;
        for (int i = 0; i < n; i++) {
            totalsum += A[i];
        }
        
        // Non-wrapping case. keep track of max
        vector<int> res(2, 0);
        int max = A[0];
        int prv = A[0];
        int prv_indx = 0;
        for (int i = 1; i < n; i++) {
            int cur, cur_indx;
            if (prv < 0) {
                cur = A[i];
                cur_indx = i;
            } else {
                cur = prv + A[i];
                cur_indx = prv_indx;
            }
            
            if (cur > max) {
                max = cur;
                res[0] = cur_indx;
                res[1] = i;
            }
            
            prv = cur;
            prv_indx = cur_indx;
        }
        
        // Wrapping case. keep track of min.
        // the wrapping array max corresponding to the min
        // sub-array from A[1] to A[n-2] (cannot be empty).
        vector<int> min_res(2, 0);
        int min = A[0];
        prv = A[0];
        prv_indx = 0;
        for (int i = 1; i < n; i++) {
            int cur, cur_indx;
            // Try to make the minimum subarray as small as possible.
            if (prv >= 0) {
                cur = A[i];
                cur_indx = i;
            } else {
                cur = prv + A[i];
                cur_indx = prv_indx;
            }
            
            if (cur < min) {
                min = cur;
                min_res[0] = cur_indx;
                min_res[1] = i;
            }
            
            prv = cur;
            prv_indx = cur_indx;
        }
        
        // If the min subarray is on the edge, the complement max array
        // has already been found in the previous methods. thus
        // "min > totalsum - max" indicate that it is not on the edge.
        // we can use min_res[1] + 1 and min_res[0] - 1. 
        if (max >= totalsum - min) {
            return res;
        } else if (min_res[1] == n - 1 && min_res[0] == 0) {
            // If every number is negative, min array would cover
            // the whole array.
            return res;
        } else {
            return vector<int>{min_res[1] + 1, min_res[0] - 1};
        }
    }
};
