/* *题目：
 *  412
 *  Fizz Buzz
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> fB;
        for(int i = 1;i <= n;i++){
            if(i % 3 == 0 && i % 5 == 0){
                fB.push_back("FizzBuzz");
            }else if(i % 3 == 0){
                fB.push_back("Fizz");
            }else if(i % 5 == 0){
                fB.push_back("Buzz");
            }else{
                fB.push_back(to_string(i));
            }
        }
        return fB;
    }
};