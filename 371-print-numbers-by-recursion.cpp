// LintCode medium problem
//
// Use reference to save the time for copy the res.

class Solution {
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    vector<int> numbersByRecursion(int n) {
        // write your code here
        vector<int> res;
        if (n <= 0)
            return res;
        helper(n, res);
        return res;
    }
    
    void helper(int n, vector<int>& res) {
        if (n == 1) {
            res = vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9};
            return;
        } else {
            helper(n - 1, res);
            int len = res.size();
            int base = res.back() + 1;
            for (int i = 1; i <= 9; i++) {
                res.push_back(base * i);
                for (int j = 0; j < len; j++) {
                    res.push_back(res[j] + base * i);
                }
            }
            return;
        }
    }
};
