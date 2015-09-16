// LintCode medium problem

class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        // write you code here
        if (A.size() <= 1)
            return true;
        
        int n = A.size();
        
        // lowest records the lowest index that can be backtracked from n - 1;
        // DP would check whether any node that the current cover range is already set
        // true, however we realized that only need to keep track of the lowest.
        int lowest = n - 1;
        
        for (int i = n - 2; i >= 0; i--) {
            if (A[i] + i >= lowest) {
                lowest = i;
            }
        }
        
        return lowest == 0;
    }
};
