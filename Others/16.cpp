/*
安置路灯
贪心
对于一个需要照亮的位置的右边一格放置一个路灯就好了
.X. 1
...X....XX 3
*/

#include<iostream>
#include<string>

using namespace std;

int main(){
    int t, n;
    cin >> t;
    
    while(t--){
        cin >> n;
        
        string s;
        cin >> s;
        
        int res = 0;
        for(int i = 0; i < n; ++i){
            if(s[i] == 'X') continue;
            if(s[i] == '.') res++;
            i += 2;
        }
        
        cout << res << endl;
    }
    return 0;
}