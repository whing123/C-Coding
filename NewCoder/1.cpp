/* *题目：
 *  懂二进制
 * *思路：
 *  求两整数有多少个bit不同
 */


class Solution {
public:
    /**
     * 获得两个整形二进制表达位数不同的数量
     *
     * @param m 整数m
     * @param n 整数n
     * @return 整型
     */
    int countBitDiff(int m, int n) {
        int res = m ^ n;
        int cnt = 0;
        for(int i = 0;i < 32;i++){
            if(((0x01 << i) & res) != 0){
                cnt++;
            }
        }
         
        return cnt;
    }
};

public int countBitDiff(int m, int n) {
 
    int dif=m^n;//先将二者做异或运算，得到结果；
    int cnt=0;
    while(dif!=0){
        dif=dif&(dif-1);
        cnt++;
    }             //统计一个整数dif含有多少个1；
    return cnt;
}

/*
1、异或
2、转为二进制字符串
3、替换字符串中的0
*/


public class Solution {
    /**
     * 获得两个整形二进制表达位数不同的数量
     *
     * @param m 整数m
     * @param n 整数n
     * @return 整型
     */
    public int countBitDiff(int m, int n) {
        String str=Integer.toBinaryString(m^n);
        str=str.replaceAll("0","");
        return str.length();
    }
}


