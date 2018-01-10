/* *题目：
 *  filename
 * *思路：
 *  extract the filename extension
 */

#include <iostream>
#include <string>
using namespace std;
 
int main(){
    string s;
    while(getline(cin, s)){
        int pos = s.size()-1;
        while(pos >= 0 && s[pos] != '.'){
            pos--;
        }
         
        if(pos < 0)
            cout << "null" << endl;
        else
            cout << s.substr(pos+1) << endl;
    }
     
    return 0;
}