// LintCode problem

class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int>& A) {
        // Write your code here
        vector<int> res;
        int n = A.size();
        if (n == 0)
            return res;

        int max = A[0];
        res = vector<int>{0, 0};
        int prv = A[0];
        int prv_indx = 0;

        for (int i = 1; i < A.size(); i++) {
            int cur, cur_indx;
            if (prv < 0) {
                cur = A[i];
                cur_indx = i;
            } else {
                cur = prv + A[i];
                cur_indx = prv_indx;
            }
            if (cur > max) {
                res[0] = cur_indx;
                res[1] = i;
                max = cur;
            }
            prv = cur;
            prv_indx = cur_indx;
        }
        return res;
    }
};
