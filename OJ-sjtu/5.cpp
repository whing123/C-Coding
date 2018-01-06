/* *题目：
 *  1001
 *  二哥摘苹果
 * *思路：
 *  
 * *技法：
 *  
 */

#include<iostream>
using namespace std;
 
int main()
{
    int height,chair,num,app[1000];
    int i=0,j=0,max=0;
    cin>>height>>chair>>num;
    while(i<num)
    {
        cin>>app[i];
        i++;
    }
    for(i=0;i<num;i++)
    {
        if(height>=app[i]||height+chair>=app[i])
        j++;
    }
    cout<<j;
    return 0;
}