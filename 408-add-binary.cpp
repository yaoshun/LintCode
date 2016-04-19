// LintCode add binary
// A lot of Edge cases to consider

class Solution {
public:
    /**
     * @param a a number
     * @param b a number
     * @return the result
     */
    string addBinary(string& a, string& b) {
        // Write your code here
        bool carry = false;
        string res = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        while (i >= 0 && j >= 0) {
            if (a[i] == '1' && b[j] == '1') {
                if (carry) {
                    res = "1" + res;
                    carry = true;
                } else {
                    res = "0" + res;
                    carry = true;
                }
            } else if (a[i] == '1' && b[j] == '0') {
                if (carry) {
                    res = "0" + res;
                    carry = true;
                } else {
                    res = "1" + res;
                    carry = false;
                }
            } else if (a[i] == '0' && b[j] == '1') {
                if (carry) {
                    res = "0" + res;
                    carry = true;
                } else {
                    res = "1" + res;
                    carry = false;
                }
            } else {
                if (carry) {
                    res = "1" + res;
                    carry = false;
                } else {
                    res = "0" + res;
                    carry = false;
                }
            }
            
            i--; j--;
        }
        
        while (i >= 0) {
            if (a[i] == '0') {
                if (carry) {
                    res = "1" + res;
                    carry = false;
                } else {
                    res = "0" + res;
                    carry = false;
                }
            } else {
                if (carry) {
                    res = "0" + res;
                    carry = true;
                } else {
                    res = "1" + res;
                    carry = false;
                }
            }
            i--;
        }
        
        while (j >= 0) {
            if (b[j] == '0') {
                if (carry) {
                    res = "1" + res;
                    carry = false;
                } else {
                    res = "0" + res;
                    carry = false;
                }
            } else {
                if (carry) {
                    res = "0" + res;
                    carry = true;
                } else {
                    res = "1" + res;
                    carry = false;
                }
            }
            j--;
        }
        
        if (carry) {
            res = "1" + res;
        }
        
        return res;
    }
};
