// LintCode easy problem.

class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        // Write your code here
        if (!string)
            return 0;
        int cnt = 0;
        for (int i = 0; i < length; i++) {
            if (string[i] == ' ') {
                cnt++;
            }
        }
        
        int newLen = length + 2 * cnt;
         
        string[newLen] = '\0';
        for (int i = length - 1; i >= 0; i--) {
            if (string[i] == ' ') {
                string[newLen - 1] = '0';
                string[newLen - 2] = '2';
                string[newLen - 3] = '%';
                newLen -= 3;
            } else {
                string[newLen - 1] = string[i];
                newLen--;
            }
        }
        return (length + 2 * cnt);
    }
};  
