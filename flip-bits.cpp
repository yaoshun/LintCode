// LintCode easy problem

class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        // write your code here
        int num = a ^ b;
        int res = 0;
        while (num) {
            num = num & (num - 1);
            res++;
        }
        return res;
    }
};
