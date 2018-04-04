/* *题目：
 *  682
 *  Baseball Game
 */

class Solution {
public:
    int calPoints(vector<string>& ops) {
        int size = ops.size();
        
        int sum = 0;
        int j = 0;
        for(int i = 0; i < size; ++i){
            if(ops[i] == "C"){
                j = i - 1;
                while(j >= 0){
                    if(ops[j] != "C"){
                        sum -= atoi(ops[j].c_str());//stoi(ops[j]);
                        ops[j] = "C"; // invalid "C"
                        break;
                    }
                    
                    j--;
                }
            }else if(ops[i] == "D"){
                j = i - 1;
                while(j >= 0){
                    if(ops[j] != "C"){
                        int tmp = atoi(ops[j].c_str()) * 2;//stoi(ops[j]) * 2;
                        sum += tmp;
                        ops[i] = to_string(tmp);
                        break;
                    }
                    
                    j--;
                }
            }else if(ops[i] == "+"){
                int tmp = 0;
                int cnt = 0;
                j = i - 1;
                while(j >= 0){
                    if(ops[j] != "C"){
                        tmp += atoi(ops[j].c_str());//stoi(ops[j]);
                        cnt++;
                        if(cnt == 2){
                            sum += tmp;
                            ops[i] = to_string(tmp);
                            break;
                        }
                    }
                    
                    j--;
                }
            }else{
                sum += atoi(ops[i].c_str());//stoi(ops[i]);
            }
        }
        
        return sum;
    }
};