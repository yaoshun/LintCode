// LintCode problem

class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return a list of lists of integer 
     */
    vector<vector<int> > kSumII(vector<int> A, int k, int target) {
        // write your code here
        
        vector<vector<int>> res;
        vector<int> path;
        
        // Sort is unnecessary for this problem. Since we did not limit the input values
        // to be positive. When the input value is positive, sometimes we can achieve early
        // termination during the DFS.
        sort(A.begin(), A.end());
        dfs(A, 0, k, target, path, res);
        return res;
    }
    
    void dfs(vector<int> &A, int st, int k, int target, vector<int>& path, vector<vector<int>>& res) {
        // Can have negative values, thus have to check all the possible cases (not possible to early
        // terminate the search.
        // when k == 0, we reached a possible solution.
        if (k == 0) {
            if (target == 0) {
                res.push_back(path);
                return;
            } else {
                return;
            }
        }
        
        for (int i = st; i < A.size(); i++) {
            path.push_back(A[i]);
            dfs(A, i + 1, k - 1, target - A[i], path, res);
            path.pop_back();
        }
    }
};
