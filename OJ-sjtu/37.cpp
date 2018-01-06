/* *题目：
 *  1006
 *  求和游戏
 * *思路：
 *  
 * *技法：
 *  
 */

#include<iostream>
using namespace std;
 
int e=0,s=0;
 
int maxSubSum4(int a[],int m)
{
    int maxSum=0;
    int thisSum=0;
    int t=0;
    for (int j=0; j<m; j++)
    {
        thisSum+=a[j];
        if(thisSum>maxSum)
        {
            maxSum=thisSum;
            s=t;
            e=j;
        }
        else if(thisSum<0)
        {
            thisSum=0;
            t=j+1;
        }
    }
    if(s<e)
    return maxSum;
    else return 0;
}
 
int main()
{
    int *ch,i=0,n,s1=0,s2=0;
    cin>>n;
    ch=new int[n];
    while(i<n)
    {
        cin>>ch[i];
        i++;
    }
 
    /*
    for(int j=0;j<n-1;j++)
        for(int k=0;k<n;k++)
        {
 
            if(j<k)
            {
                if(ch[j]<0)continue;
                for(int t=j;t<=k;t++)
                s1+=ch[t];
            }
            if(s1<=0){s1=0;continue;}
            if(s1>s2)s2=s1;
            s1=0;
        }*/
 
    s2=maxSubSum4(ch,n);
    if(s2<=0)
        cout<<"Game Over"<<endl;
    else cout<<s2<<endl;
 
    return 0;
}