// LeetCode

class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsets(vector<int> &nums) {
        // write your code here
        vector<vector<int>> res;
        if (nums.size() == 0)
            return res;
        
        vector<int> r;
        dfs(nums, 0, r, res);
        return res;
    }
    
    void dfs(vector<int>& nums, int start, vector<int>& r, vector<vector<int>>& res) {
        if (start >= nums.size()) {
            res.push_back(r);
            return;
        }
        
        dfs(nums, start + 1, r, res);
        
        r.push_back(nums[start]);
        dfs(nums, start + 1, r, res);
        r.pop_back();
    }
};
