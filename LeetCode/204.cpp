/* *题目：
 *  443
 *  String Compression
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int compress(vector<char>& chars) {
        int size = chars.size();
        
        int len = 0;
        for(int i = 0 ; i < size;){
            int start = i;
            while(i < size && chars[i] == chars[start]){
                ++i;
            }
            
            chars[len] = chars[start]; // 保存当前字符
            len++;
            
            int tmp = i - start;
            if(tmp > 1){ // 长度超过1时
                len += numOfDigits(chars, tmp, len); // 长度字符化，并存储
            }
        }
        
        return len;
    }
    
    int numOfDigits(vector<char>& chars, int number, int start){
        int res = 0; // number位数
        
        // number提取每一位并字符化
        vector<char> tmp;
        while(number > 9){
            ++res;
            tmp.push_back('0' + number % 10);
            number /= 10;
        }
        ++res;
        tmp.push_back('0' + number);
        
        // 存在chars里，要反转tmp
        int j = 0;
        for(int i = tmp.size()-1; i >= 0; --i, ++j){
            chars[start + j] = tmp[i];
        }
        
        return res;
    }
};