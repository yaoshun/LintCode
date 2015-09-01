// LintCode hard problem

// Naive DP solution will possibly use O(n^3) time and
// O(n^2) space.
class Solution {
public:
    /**
     * @param A an integer array
     * @param k an integer
     * @return an integer
     */
    int postOffice(vector<int>& A, int k) {
        // Write your code here
        // Naive DP method.
        // If dp[i][j] represents i post office between 0 - j houses included.
        // dp[i][j] = min_m(dp[i - 1][m] + w[m+1][j]), i-1<= m <=j-1
        int n = A.size();
        
        // Always remember to check the second variable.
        if (A.empty() || k >= n)
            return 0;
        
        // Necessary to make dp straightforward.
        sort(A.begin(), A.end());
        
        // cost array stores w[i][j] which represents the minimum cost
        // to build a post office between A[i] and A[j] included. 
        vector<vector<int>> cost(n, vector<int>(n, 0));
        computeMinCost(A, cost);
        
        // Here res[0][j] is actually not used at all for conveniency.
        vector<vector<int>> res(k + 1, vector<int>(n, INT_MAX));
        // starting from one post office.
        for (int i = 1; i <= k; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 1) {
                    res[i][j] = cost[0][j];
                } else {
                    for (int m = i - 1; m <= j - 1; m++)
                        res[i][j] = min(res[i][j], res[i-1][m] + cost[m + 1][j]);
                }
            }
        }
        return res[k][n - 1];
    }
    
    void computeMinCost(vector<int>& A, vector<vector<int>>& cost) {
        int n = A.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                // Should build the only office at the median position.
                int mid = i + (j - i) / 2;
                
                for (int k = i; k <= mid; k++)
                    cost[i][j] += A[mid] - A[k];
                for (int k = mid + 1; k <= j; k++)
                    cost[i][j] += A[k] - A[mid];
            }
        }
    }
};

// We can further reduce the time to O(n^2) through further optimization.
// Use an additional variable to track the optimal condition for dp[i][j] solution.
// To lower down the search space, we utilized the monoticity property of the problem.
class Solution {
public:
    /**
     * @param A an integer array
     * @param k an integer
     * @return an integer
     */
    int postOffice(vector<int>& A, int k) {
        // Write your code here
        int n = A.size();
        
        // Always remember to check the second variable.
        if (A.empty() || k >= n)
            return 0;
        
        // Necessary to make dp straightforward.
        sort(A.begin(), A.end());
        
        // cost array stores w[i][j] which represents the minimum cost
        // to build a post office between A[i] and A[j] included. 
        vector<vector<int>> cost(n, vector<int>(n, 0));
        computeMinCost(A, cost);
        
        // res[i][j] represents the minimum distance sum of building i post offices
        // between 0 and j houses.
        vector<vector<int>> res(k + 1, vector<int>(n, INT_MAX));
        
        // s[i][j] represents the number of villages covered by
        // previous i-1 post offfice, in the optimum of res[i][j].
        // s[1][j] == 0 since there is only one post office, the previous 
        // covers nothing, we set it to 0, as the starting point of dp.
        vector<vector<int>> s(n + 1, vector<int>(n, 0));
        
        for (int i = 0; i < n; i++)
            res[1][i] = cost[0][i];
        
        // starting from one post office
        for (int i = 2; i <= k; i++) {
            // Set j to n - 1 first.
            // we can get the s[i][n - 1] and res[i][n-1] in the first DP.
            for (int m = s[i - 1][n - 1]; m <= n - 2; m++) {
                int temp = res[i - 1][m] + cost[m + 1][n - 1];
                if (temp < res[i][n - 1]) {
                    res[i][n - 1] = temp;
                    s[i][n - 1] = m;
                }
            }
            
            // We used s[i][j+1] in the following loop to set the upper bound.
            // Which used the monoticity property of the problem.
            for (int j = n - 2; j >= i; j--) {
                for (int m = s[i - 1][j]; m <= s[i][j + 1]; m++) {
                    int temp = res[i - 1][m] + cost[m + 1][j];
                    if (temp < res[i][j]) {
                        res[i][j] = temp;
                        s[i][j] = m;
                    }
                }
            }
        }
        
        return res[k][n - 1];
    }
    
    void computeMinCost(vector<int>& A, vector<vector<int>>& cost) {
        int n = A.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                // Should build the only office at the median position.
                int mid = i + (j - i) / 2;
                
                for (int k = i; k <= mid; k++)
                    cost[i][j] += A[mid] - A[k];
                for (int k = mid + 1; k <= j; k++)
                    cost[i][j] += A[k] - A[mid];
            }
        }
    }
};

