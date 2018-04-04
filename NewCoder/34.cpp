/* *题目：
 *  替换空格
 * *思路：
 *  
 */

class Solution {
public:
    void replaceSpace(char *str,int length) {
         for(int i = 0; i < length; ++i){
             if(str[i] == ' '){
                 str[i] = '\0'; // 当前结束
                  
                 // 拆出后一段
                 char *tmp = new char[length-i];
                 strcpy(tmp, str + i+1);
                 tmp[length-i-1] = '\0';
                  
                 // 拼接
                 strcat(str, "%20");
                 strcat(str, tmp);
                 delete [] tmp;
                  
                 // 递归进行
                 replaceSpace(str+i+3, length-i-3);
                 return;
             }
         }
    }
};