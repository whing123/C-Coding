/* *题目：
 *  22
 *  Generate Parentheses
 */

/*
 ‘left’, represents how many left parentheses remains; 
 ‘right’ represents how many right parentheses remains. 
 The remaining right parentheses should be larger than left ones.
 */

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        helper(ret, "", n, n);
        return ret;
    }
    void helper(vector<string> & res, string str, int left, int right){
        if(left == 0 && right == 0){
            res.push_back(str);
            return;
        }
        if(left > 0) helper(res, str + "(", left - 1, right);
        if(right > left) helper(res, str + ")", left, right - 1);
    }
};