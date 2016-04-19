// LintCode problem

class Solution {
public:    
    /**
     * @param word1 & word2: Two string.
     * @return: The minimum number of steps.
     */
    int minDistance(string word1, string word2) {
        // write your code here
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        
        dp[0][0] = 0;
        // 0 represents empty string.
        for (int i = 1; i <= m; i++) {
            dp[i][0] = i;
        }
        
        for (int i = 1; i <= n; i++) {
            dp[0][i] = i;
        }
        
        // Transition function:
        // dp[i][j] = (word1[i - 1] == word2[j - 1]) ? dp[i - 1][j - 1]
        // dp[i][j] is not necessarily a monotonic array. Thus we need to consider 
        // all the conditions.
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // All three possible cases minimum.
                // Only the replace case depends on the char comparison.
                dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                } else {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
