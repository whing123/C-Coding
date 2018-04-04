/* *题目：
 *  551
 *  Student Attendance Record I
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    bool checkRecord(string s) {
        short num_a = 0, num_l = 0;
        for(int i = 0; i < s.size();++i){
            if(s[i] == 'A'){
                num_l = 0;
                num_a++;
                if(num_a > 1){
                    return false;
                }
            }else if(s[i] == 'L'){
                num_l++;
                if(num_l > 2){
                    return false;
                }
            }else{
                num_l = 0;
            }
        }
        
        return true;
    }
};