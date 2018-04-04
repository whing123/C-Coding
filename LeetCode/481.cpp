/* *题目：
 *  481
 *  Magical String
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int magicalString(int n) {
        vector<int> self, cnt;
        self.push_back(1);
        cnt.push_back(1);
        cnt.push_back(2);
        
        int dir; //2 添加2； 1 添加1
        int pos = 1; //记录cnt里当前位置，表示下次往self里要添加的数量
        int i;
        while(self.size() < n){
            dir = self[self.size()-1] == 1 ? 2 : 1;  //接下来添加的数字，与self最后一个数不同
            i = cnt[pos];  //插入的数目
            while(i){
                self.push_back(dir);
                i--;
            }
            cnt.push_back(self[++pos]); //根据self中pos下一个数为cnt追加下一个数字
        }
        
        int res = 0;
        for(i = 0;i < n;i++){
            if(self[i] == 1){  //数1的个数
                res++;
            }
        }
        return res;
    }
};