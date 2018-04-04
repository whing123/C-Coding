/* *题目：
 *  把字符串转换成整数
 */

// 考虑了e
class Solution {
public:
    int StrToInt(string str) {
        vector<char> num1, num2; // 分别是e前后部分数字
        bool sign = false, hasE = false; // 是否出现过+-符号，e
        int sign_first = 1; // 第一位的正负
         
        for(int i = 0; i < str.length(); ++i){
            if(str[i] == 'e' || str[i] == 'E'){
                if(i == str.length()-1) return 0; // e后面一定要接数字
                if(hasE) return 0; // 已经有过E
                hasE = true;
            }else if(str[i] == '+' || str[i] == '-') {
                // 第二次出现+-符号，则必须紧接在e之后
                if (sign && str[i-1] != 'e' && str[i-1] != 'E') return 0;
                // 第一次出现+-符号，且不是在字符串开头，则也必须紧接在e之后
                if (!sign && i > 0 && str[i-1] != 'e' && str[i-1] != 'E') return 0;
                // e之后出现-符号，则不是整数
                if(i > 0 && str[i] == '-' && (str[i-1] == 'e' || str[i-1] == 'E')) return 0;
                // 记录第一次的符号
                if (i == 0 && str[i] == '-')  sign_first = -1;
                sign = true;
            } else if (str[i] < '0' || str[i] > '9'){ // 非法字符
                return 0;
            }else if(hasE && str[i] >= '0' && str[i] <= '9'){ // e后的数字
                num2.push_back(str[i]);
            }else if(str[i] >= '0' && str[i] <= '9'){ // e前的数字
                num1.push_back(str[i]);
            }
        }
         
        int res = 0;
         
        if(num1.size() > 0){
            if(num1[0] == '0') return 0; // 前部分以0开头，非法
            int j = 0;
            for(int i = num1.size()-1; i >= 0; i--){
                res += (num1[i]-'0')*((int)pow(10, j++));
            }
        }
 
        int e_part = 0; // 指数部分
        if(num2.size() > 0){
            int k = 0;
            while(num2[k] == '0') k++; // 去掉前导0
            int j = 0;
            for(int i = num2.size()-1; i >= k; i--){
                e_part += (num2[i]-'0')*((int)pow(10, j++));
            }
        }
         
        res = sign_first * res * ((int)pow(10, e_part));
        return res;
    }
     
};

// 简单考虑
class Solution {
public:
    int StrToInt(string str) {
        vector<char> num; // 数字序列
        int sign_first = 1; // 第一位的正负
        
        for(int i = 0; i < str.length(); ++i){
            if(i == 0 && (str[i] == '+' || str[i] == '-')) {
                if (str[i] == '-')  
                    sign_first = -1;
            } else if (str[i] < '0' || str[i] > '9'){ // 非法字符
                return 0;
            }else if(str[i] >= '0' && str[i] <= '9'){ // 数字
                num.push_back(str[i]);
            }
        }
        
        int res = 0;
        
        if(num.size() > 0){
            if(num[0] == '0') return 0; // 前部分以0开头，非法
            int j = 0;
            for(int i = num.size()-1; i >= 0; i--){
                res += (num[i]-'0')*((int)pow(10, j++));
            }
        }

        res = sign_first * res;
        return res;
    }
    
};