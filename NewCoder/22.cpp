/* *题目：
 *  身份证分组
 * *思路：
 *  
 */

#include <iostream>
#include <string>
 
using namespace std;
 
int main(){
    string str;
     
    while(getline(cin, str)){
        int cnt = 0;
        for(int i = 0; i < str.size(); ++i){
            if(str[i] != ' '){
                cout << str[i];
                ++cnt;
                if(i == str.size()-1) break;
                if(cnt == 6 || cnt == 14){
                    cout << ' ';
                }
            }
        }
        cout << endl;
    }
     
    return 0;
}