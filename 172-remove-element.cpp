// LintCode easy problem

class Solution {
public:
    /** 
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        // write your code here
        int i = 0; 
        for (int j = 0; j < A.size(); j++) {
            if (A[j] != elem) {
                A[i] = A[j];
                i++;
            }
        }
        return i;
    }
};
