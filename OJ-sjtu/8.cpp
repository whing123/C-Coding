/* *题目：
 *  1004
 *  西西弗斯式的命运
 * *思路：
 *  
 * *技法：
 *  
 */

#include<iostream>
using namespace std;
 
int main()
{
    char ch;
    int *zh,*xh,M,T,U,F,D;
    int i=0,t=0;
    cin>>M>>T>>U>>F>>D;
    zh=new int[T];
    xh=new int[T];
    while(i<T)
    {
        cin>>ch;
        if(ch=='u')
        {
            zh[i]=U;
            xh[i]=D;
        }
        else if(ch=='f')
        {
            zh[i]=F;
            xh[i]=F;
        }
        else if(ch=='d')
        {
            zh[i]=D;
            xh[i]=U;
        }
        i++;
    }
    i=0;
    t=zh[i]+xh[i];
    while(t<=M)
    {
        i++;
        t=t+zh[i]+xh[i];
    }
 
    cout<<i;
 
    return 0;
}
