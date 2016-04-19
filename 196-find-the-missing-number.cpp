// LintCode find the missing number. 
// The major difference from finding first missing positive is that
// the number is gurranteed to be in the range of 0...N.

class Solution {
public:
    /**    
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        int res = n;
        for (int i = 0; i < n; i++) {
            res += i - nums[i];
        }
        return res;
    }
};
