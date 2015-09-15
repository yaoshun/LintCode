// LintCode problem

class Solution {
private:
    static bool cmp(const string& a, const string& b) {
        return (a + b) > (b + a);
    }
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
    string largestNumber(vector<int> &num) {
        // write your code here
        vector<string> s;
        for (auto& n : num) {
            s.push_back(to_string(n));
        }
        sort(s.begin(), s.end(), cmp);
        
        string res;
        for (auto& str : s) {
            res += str;
        }
        
        // Remove trailing zero until at most one.
        while (res.size() > 1 && res[0] == '0') {
            res.erase(res.begin());
        }
        
        return res;
    }
};
