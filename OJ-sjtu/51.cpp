/* *题目：
 *  3045
 *  大鱼
 * *思路：
 *  
 * *技法：
 *  
 */

#include<iostream>
#include<cmath>
using namespace std;
 
int main()
{
    int m,n,num;
    int i=0,j=0,t=0;
    int p,q,r;
    int **ch;
 
    cin>>m>>n>>num;
    ch=new int*[m];
    while(i<m){ch[i]=new int[n];i++;}
 
    for(i=0;i<m;i++)
    for(j=0;j<n;j++)
    ch[i][j]=0;
 
    while(t<num)
    {
        cin>>p>>q>>r;
 
        for(i=(p-1-r>=0?p-1-r:0);i<(p+r<m?p+r:m);i++)
        for(j=(q-1-r>=0?q-1-r:0);j<(q+r<n?q+r:n);j++)
        if(pow(i-p+1,2)+pow(j-q+1,2)<=pow(r,2))ch[i][j]=1;
        t++;
    }
 
    t=0;
    for(i=0;i<m;i++)
    for(j=0;j<n;j++)
    if(ch[i][j]==1)t++;
    cout<<t<<endl;
    return 0;
}

