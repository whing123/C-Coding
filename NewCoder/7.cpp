/* *题目：
 *  打印日期
 * *思路：
 *  给出年分m和一年中的第n天，算出第n天是几月几号
 */

#include <iostream>
using namespace std;
 
static int run [12] = {31,29,31,30,31,30,31,31,30,31,30,31};
static int nrun [12] = {31,28,31,30,31,30,31,31,30,31,30,31};
 
int main(){
    int m, n;
    int month;
    int i;
    while(cin>>m>>n){
        month = 0;
        i = 0;
        if(m%400==0 || (m%4==0 && m%100!=0)){
            while(n > run[i]){
                n -= run[i];
                i++;
            }
        }else{
            while(n > nrun[i]){
                n -= nrun[i];
                i++;
            }
        }
        month = i+1;
        printf("%d-%02d-%02d\n",m,month,n);
    }

    return 0; 
}