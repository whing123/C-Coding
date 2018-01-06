/* *题目：
 *  165
 *  Compare Version Numbers
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int size1 = version1.size();
        int size2 = version2.size();
        
        int v1 = 0, v2 = 0;
        
        int i1 = 0, i2 = 0;
        int i;
        stack<int> vstack1, vstack2;
        while(i1 < size1 || i2 < size2){  //从左到右，每一段每一段比较，'.'相当于分隔符，每一段都是十进制数
            while(i1 < size1 && version1[i1] != '.'){
                vstack1.push(version1[i1]-'0');
                i1++;
            }
            if(version1[i1] == '.'){
                i1++;
            }
            i = 0;
            while(!vstack1.empty()){
                v1 += vstack1.top() * pow(10,i);
                vstack1.pop();
                i++;
            }
            
            while(i2 < size2 && version2[i2] != '.'){
                vstack2.push(version2[i2]-'0');
                i2++;
            }
            if(version2[i2] == '.'){
                i2++;
            }
            i = 0;
            while(!vstack2.empty()){
                v2 += vstack2.top() * pow(10,i);
                vstack2.pop();
                i++;
            }
            
            if(v1 == v2){
                v1 = 0;
                v2 = 0;
            }
            if(v1 > v2){
                return 1;
            }
            if(v1 < v2){
                return -1;
            }
        }
        return  0;
    }
};