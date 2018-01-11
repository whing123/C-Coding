/* *题目：
 *  头条校招
 * *思路：
 *  
 */

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main(){
    int n;
    while(cin >> n){
        vector<int> tmp(n,0);
        for(int i = 0; i < n; ++i){
            cin >> tmp[i];
        }
         
        sort(tmp.begin(), tmp.end());
        int res = 0;
        for(int i = 0; i < n-1;){
            if(tmp[i+1] - tmp[i] <= 10){
                if(i+2 < n && tmp[i+2] - tmp[i+1] <= 10){ // ok
                    i += 3;
                }else{ // need one
                    res += 1;
                    i += 2;
                }
                 
            }else{ // i-th, need two
                i += 1;
                res += 2;
            }
             
            if(i == n-1){ // if last one -> n-1
                 res += 2;
                 break;
            }
        }
         
        cout << res << endl;
    }
     
    return 0;
}