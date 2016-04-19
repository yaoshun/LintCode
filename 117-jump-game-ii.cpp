// LintCode problem

// dp solution.
// Cannot pass large cases.
class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        // wirte your code here
        int n = A.size();
        if (n <= 1)
            return 0;
        vector<int> dp(n, INT_MAX);
        
        // O(n^2) solution cannot work with the large case.
        dp[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j <= i + A[i] && j < n; j++) {
                dp[i] = min(dp[j] + 1, dp[i]);
            }
        }
        return dp[0];
    }
};

// Forward greedy solution.
class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        // wirte your code here
        int n = A.size();
        if (n <= 1)
            return 0;
        
        // If we can reach index j in 3 steps, and i < j.
        // we can reach index i in equal or less than 3 steps.
        // dp[i] <= dp[j] if i < j. Using the monoticity, we can design a 
        // greedy algorithm.
        int largest = 0;
        int steps = 0;
        for (int i = 0; i < n - 1; i++) {
            if (A[i] + i > largest) {
                steps++;
                largest = A[i] + i;
            }
            if (largest >= n - 1) {
                return steps;
            }
        }
    }
};
