/* *题目：
 *  1003
 *  二哥养细菌
 * *思路：
 *  
 * *技法：
 *  
 */

#include<iostream>
using namespace std;
 
bool check0(int xh[100][100],int k)
{
    int p,q,c=0;
    for(p=0;p<k;p++)
        for(q=0;q<k;q++)
            if(xh[p][q]==0)
                c++;
    return c!=0;
}
 
int main()
{
    int L,m=0,ch[100][100];
    int i,j;
 
 
    cin>>L;
    for(i=0;i<L;i++)
        for(j=0;j<L;j++)
            cin>>ch[i][j];
 
    while(check0(ch,L))
    {
        for(i=0;i<L;i++)
        {
            for(j=0;j<L;j++)
            {
                if(ch[i][j]==1)
                {
                    if(j-1>=0&&ch[i][j-1]==0)
                    ch[i][j-1]=3;
                    if(j+1<L&&ch[i][j+1]==0)
                    ch[i][j+1]=3;
                    if(i+1<L&&ch[i+1][j]==0)
                    ch[i+1][j]=3;
                    if(i-1>=0&&ch[i-1][j]==0)
                    ch[i-1][j]=3;
                }
            }
        }
        for(i=0;i<L;i++)
            for(j=0;j<L;j++)
                if(ch[i][j]==3)
                    ch[i][j]=1;
        m++;
 
    }
 
    cout<<m;
    return 0;
}