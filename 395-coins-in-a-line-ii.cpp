// LintCode coins in a line ii

class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        // Use DP, we change the problem to get the most 
        // value out of the remaining coins.
        int n = values.size();
        if (n <= 2)
            return true;

        // dp[i] represents the case with i to n - 1 coins
        // what is the optimum you can get.
        vector<int> dp(n + 1, 0);
        dp[n] = 0;
        dp[n - 1] = values[n - 1];
        dp[n - 2] = values[n - 2] + values[n - 1];
        dp[n - 3] = values[n - 3] + values[n - 2];

        for (int i = n - 4; i >= 0; i--) {
            // Two strategies are compared here.
            // Grab one coin: the other player will choose the 
            // strategy that will minimize you gainings.
            dp[i] = values[i] + min(dp[i + 2], dp[i + 3]);
            // Grab two coins
            dp[i] = max(dp[i], values[i] + values[i + 1] + min(dp[i + 3], dp[i + 4]));
        }

        // No need to use sum to check. min(dp[1], dp[2]) is what
        // the other player will get.
        return dp[0] > min(dp[1], dp[2]);
    }
};
