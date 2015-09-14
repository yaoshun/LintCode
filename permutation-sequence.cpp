// LintCode Problem

class Solution {
public:
    /**
      * @param n: n
      * @param k: the kth permutation
      * @return: return the k-th permutation
      */
    string getPermutation(int n, int k) {
        vector<int> nums;
        int total = 1;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
            total *= i;
        }
        
        int group = total;
        string res;
        while (n > 0) {
            group /= n;
            int indx = (k - 1) / group;
            res.push_back(nums[indx] + '0');
            nums.erase(nums.begin() + indx);
            k = (k - 1) % group + 1;
            n--;
        }
        
        return res;
    }
};
