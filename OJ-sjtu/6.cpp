/* *题目：
 *  1002
 *  二哥种花生
 * *思路：
 *  
 * *技法：
 *  
 */

#include<iostream>
using namespace std;
 
int main()
{
    int **ch,**bh;
    int L,W,a,b,m=0,sum=0;
    int k=0,v=0,q=0,i,j;
    cin>>L>>W;
    ch=new int*[L];
    bh=new int*[L];
    for(i=0;i<L;i++)
    {
        ch[i]=new int[W];
        for(j=0;j<W;j++)
            cin>>ch[i][j];
    }
    cin>>a>>b;
 
    for(i=0;i<L;i++)
        bh[i]=new int[W+1-b];
    for(i=0;i<L;i++)
    {
        for(j=0;j<W+1-b;j++)
           {
            bh[i][j]=0;
            for(q=0;q<b;q++)
                bh[i][j]+=ch[i][j+q];
           }
    }
 
 
    for(k=0;k<L+1-a;k++)
    {
        for(v=0;v<W+1-b;v++)
            {
                for(q=0;q<a;q++)
                    sum +=bh[k+q][v];
                if(m<=sum)m=sum;
                sum=0;
            }
    }
 
    cout<<m;
    return 0;
}