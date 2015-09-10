// LintCode hard problem
//

class Solution {
public:
    /**
     *@param n: Given a decimal number that is passed in as a string
     *@return: A string
     */
    string binaryRepresentation(string n) {
        // wirte your code here
        int int_p = stoi(n.substr(0, n.find('.')));
        double dec_p = stod(n.substr(n.find('.')));
        string int_str;
        string dec_str;
        
        if (int_p == 0) {
            int_str.push_back('0');
        }
        
        while (int_p > 0) {
            int c = int_p % 2;
            int_str.push_back('0' + c);
            int_p = int_p >> 1;
        }
        reverse(int_str.begin(), int_str.end());
        
        while (dec_p > 0) {
            if (dec_str.size() > 32) {
                return "ERROR";
            }
            double remain = dec_p * 2;
            if (remain >= 1.0) {
                dec_str.push_back('1');
                dec_p = remain - 1.0;
            } else {
                dec_str.push_back('0');
                dec_p = remain;
            }
        }
        
        return dec_str.size() > 0 ? int_str + "." + dec_str : int_str;
    }
};
