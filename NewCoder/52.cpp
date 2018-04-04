/* *题目：
 *  第N个丑数
 * *思路：
 *  
 */

/*
后面的丑数是由前一个丑数乘以2，3，5中的一个得来。因此可以用动态规划去解
*/

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index < 7){
            return index;
        }
        
        vector<int> res(index, 0);
        res[0] = 1;
        int t2, t3, t5;
        t2 = t3 = t5 = 0;
        for(int i = 1; i < index; ++i){
            res[i] = min(2*res[t2], min(3*res[t3], 5*res[t5]));
            
            if(res[i] == 2*res[t2]) ++t2;
            if(res[i] == 3*res[t3]) ++t3;
            if(res[i] == 5*res[t5]) ++t5;
        }
        
        return res[index-1];
    }
};

/*
1）初始化array和队列：Q2 Q3 Q5
2）将1插入array
3）分别将1*2、1*3 、1*5插入Q2 Q3 Q5
4）令x为Q2 Q3 Q5中的最小值，将x添加至array尾部
5）若x存在于：
    Q2：将 x * 2、x * 3、x*5 分别放入Q2 Q3 Q5，从Q2中移除x
    Q3：将 x * 3、x*5 分别放入Q3 Q5，从Q3中移除x
    Q5：将 x * 5放入Q5，从Q5中移除x
6）重复步骤4~6，until 找到第k个元素
*/

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index < 7){
            return index;
        }
        
        int minVal;
        queue<int> q2, q3, q5;
        q2.push(1);
        
        int min2, min3, min5;
        for(int i = 0; i < index; ++i){
            min2 = q2.empty()? INT_MAX : q2.front();
            min3 = q3.empty()? INT_MAX : q3.front();
            min5 = q5.empty()? INT_MAX : q5.front();
            
            minVal = min(min2, min(min3, min5));
            if(minVal == min2){
                q2.pop();
                q2.push(2 * minVal);
                q3.push(3 * minVal);
            } else if(minVal == min3){
                q3.pop();
                q3.push(3 * minVal);
            } else if(minVal == min5){
                q5.pop();
            }
            q5.push(5 * minVal);
        }
        
        return minVal;
    }
};