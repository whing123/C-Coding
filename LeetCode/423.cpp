/* *题目：
 *  423
 *  Reconstruct Original Digits from English
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    string originalDigits(string s) {
        //string digits [10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        //按字符的特殊性，进行扫描优先级排序
        string scan_order [10] = {"zero", "wto", "ufor", "xsi", "geiht", "seven", "three", "five", "inne", "one"};
        int scan_digit [10] = {0, 2, 4, 6, 8, 7, 3, 5, 9, 1};
        
        map<char,int> table;  //统计字符及其出现次数
        for(int i = 0; i < s.length();i++){
            table[s[i]]++;
        }
        
        vector<int> result;
        map<char,int>::iterator it;
        for(int i = 0; i < 10;i++){  //按扫描顺序对10个数字依次扫描
            if(!table.empty()){  //map为空时立即退出
                while((it = table.find(scan_order[i][0])) != table.end()){  //发现特征字符，即存在该字符串
                    result.push_back(scan_digit[i]);  //保存对应数字
                    
                    for(int j = 0; j < scan_order[i].size();j++){  //逐一去掉map中统计的次数，即map中去掉该单词
                        table[scan_order[i][j]]--;
                    }
                    
                    //清理为空的字符
                    /*// 方法1
                    vector<char> discard;
                    for(it = table.begin();it != table.end();it++){
                        if(it->second == 0){  //次数为0时剔除
                            discard.push_back(it->first);
                        }
                    }
                    for(int j = 0;j < discard.size();j++){
                        table.erase(discard[j]);
                    }
                    */
                    
                    //方法2
                    for(it = table.begin();it != table.end();it++){
                        if(it->second == 0){  //次数为0时剔除
                            table.erase(it);
                        }
                    }
                    
                }
            }else{
                break;
            }
        }
        
        sort(result.begin(),result.end());  //升序排列
        
        string res;
        for(int i = 0; i < result.size();i++){
            res += to_string(result[i]);  //转化为字符串
        }
        
        return res;
    }
};

