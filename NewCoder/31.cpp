/* *题目：
 *  数字翻转
 * *思路：
 *  
 */

#include <iostream>
#include <string>
#include <algorithm>
 
using namespace std;
 
// reverse a number
int rev(int n){
    string s = to_string(n);
    reverse(s.begin(), s.end());
    return stoi(s);
}
 
int main(){
    int x, y;
    while(cin >> x >> y){
        cout << rev(rev(x)+rev(y)) << endl;
    }
    return 0;
}


// reverse a number
int rev(int m)
{
    int t = 0;
    while(m > 0)
    {
        t = t*10 + m%10;
        m = m/10;
    }
    return t;
}