/* *题目：
 *  8
 *  String to Integer (atoi)
 */

class Solution {
public:
    int myAtoi(string str) {
        int size = str.size();
        long result = 0;
        int i = 0;
        int sign = 1;
        
        //越过初始无关字符
        while(i < size && str[i] != '+' && str[i] != '-' && !(str[i] >= '0' && str[i] <= '9')){
            if(str[i] != ' '){ //无关字符且非空格，则无效
                return result;
            }
            i++;
        }
        
        //若不含有效数字和符号
        if(i == size){
            return result;
        }
        //符号
        if(str[i] == '-'){
            sign = -1;
        }
        //越过符号
        if(str[i] == '+' || str[i] == '-'){
            i++;
        }
        
        //载入数字
        stack<int> que;
        while(i < size && (str[i] >= '0' && str[i] <= '9')){
            que.push(str[i] - '0');
            i++;
        }
        
        i = 0;
        while(!que.empty()){
            //求值
            result += que.top() * pow(10,i);
            que.pop();
            i++;
            
            //早发现越界，早解决
            if(result*sign > INT_MAX){
                return INT_MAX;
            }
            if(result*sign < INT_MIN){
                return INT_MIN;
            }
        }
        
        result *= sign; //符号
        
        return result;
    }
};