// LintCode House Robber
// Easy DP problem

class Solution {
public:
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> A) {
        // write your code here
        if (A.size() == 0)
            return 0;
        if (A.size() == 1)
            return A[0];
        
        // If dp[i] represents the max money we can get
        // from index 0 to i. The transition equation is
        // dp[i] = max(dp[i - 1], A[i] + dp[i - 2]).
        // dp[0] and dp[1].
        long long pre = A[0];
        long long cur = max(A[0], A[1]);

        for (int i = 2; i < A.size(); i++) {
            long long temp = cur;
            cur = max(cur, pre + A[i]);
            pre = temp;
        }
        return cur;
    }
};

