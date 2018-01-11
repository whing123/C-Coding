/* *题目：
 *  素数对
 * *思路：
 *  
 */

#include <iostream>
#include <cmath>
 
using namespace std;
 
bool isPrime(int a) {
    if (a < 2) {
        return false;
    }
    else {
        for (int i = 2; i <= sqrt(a); ++i) {
            if (a % i == 0) {
                return false;
            }
        }
    }
 
    return true;
}
 
int main(){
    int n;
    while(cin >> n){
        int res = 0;
        for(int i = 2; i <= n/2; ++i){
            if(isPrime(i) && isPrime(n-i)){
                res++;
            }
        }
        cout << res << endl;
    }
     
    return 0;
}