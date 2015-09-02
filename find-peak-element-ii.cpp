// LintCode find-peak-element-ii
// Be careful of the complexity analysis.

class Solution {
public:
    /**
     * @param A: An integer matrix
     * @return: The index of the peak
     */
    vector<int> findPeakII(vector<vector<int> > A) {
        // write your code here
        // Both size must not be zero.
        int upper = 0, down = A.size() - 1;
        int left = 0, right = A[0].size() - 1;
        while (upper < down && left < right) {
            int height = down - upper + 1;
            int width = right - left  + 1;
            
            // T(m, n) = T(m, n / 2) + O(m) = T(m / 2, n / 2) + O(m) + O(n / 2)
            // = ... = O(2m) + O(2n) = O(max(m, n))
            if (width > height) {
                // Alternatively shrink the size of the bigger part.
                int mid = left + (right - left) / 2;
                int maxRow = upper;
                for (int j = upper + 1; j <= down; j++) {
                    if (A[j][mid] > A[maxRow][mid])
                        maxRow = j;
                }
                
                // One of the candidate is A[maxRow][j]. 
                if (A[maxRow][mid] < A[maxRow][mid + 1]) {
                    left = mid + 1;
                } else if (A[maxRow][mid] < A[maxRow][mid - 1]) {
                    right = mid - 1;
                } else {
                    return {maxRow, mid};
                }
            } else {
                int mid = upper + (down - upper) / 2;
                int maxCol = left;
                for (int j = left + 1; j <= right; j++) {
                    if (A[mid][j] > A[mid][maxCol])
                        maxCol = j;
                }
                
                if (A[mid][maxCol] < A[mid + 1][maxCol]) {
                    upper = mid + 1;
                } else if (A[mid][maxCol] < A[mid - 1][maxCol]) {
                    down = mid - 1;
                } else {
                    return {mid, maxCol};
                }
            }
        }
        return {-1, -1};
    }
};
