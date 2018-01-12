/* *题目：
 *  统计字符
 * *思路：
 *  找出这个字符串中首先出现三次的那个英文字符
 */

#include <iostream>
#include <string>
#include <map>
 
using namespace std;
 
int main(){
    string str;
     
    while(getline(cin, str)){
        map<char, int> data;
         
        for(int i = 0; i < str.size(); ++i){
            if(!(str[i] >= 'a'&& str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z'))
                continue;
            data[str[i]]++;
            if(data[str[i]] == 3){
                cout << str[i] << endl;
                break;
            }
        }
    }
     
    return 0;
}