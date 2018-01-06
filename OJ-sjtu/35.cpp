/* *题目：
 *  1318
 *  subset
 * *思路：
 *  
 * *技法：
 *  
 */

/*
ID: whpiggy1
PROG: subset
LANG: C++
*/
 
 
#include<iostream>
#include <fstream>
using namespace std;
 
//一个迭代，一个递归
 
int main()
{
    /*
    ofstream fout ("subset.out");
    ifstream fin ("subset.in");*/
 
    int N,s,i,j;
    int **ch;
    cin>>N;
    if(N*(N+1)%4!=0)cout<<'0'<<endl;
    else{
    s=N*(N+1)/4;
    ch=new int*[N+1];
    for(i=0;i<=N;i++)
    {
        ch[i]=new int[s+1];
        for(j=0;j<=s;j++)
            ch[i][j]=0;
    }
    ch[0][0]=1;
    for(i=1;i<=N;i++)
    for(j=1;j<=s;++j)
    {
        if(j>i)ch[i][j]=ch[i-1][j-i]+ch[i-1][j-1];
        else ch[i][j]=ch[i-1][j-1];
 
    }
    cout<<ch[N][s]<<endl;}
 
 
    return 0;
}