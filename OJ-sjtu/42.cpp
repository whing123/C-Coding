/* *题目：
 *  1021
 *  从前有座山
 * *思路：
 *  
 * *技法：
 *  
 */

#include <iostream>
#include <iomanip>
 
using namespace std;
 
void f(int n)
{
    int **ch,i,j,p=1;
    ch=new int*[n];
    for(i=0;i<n;i++)
    {
        ch[i]=new int[n];
    }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            ch[i][j]=0;
 
    i=0;j=0;ch[i][j]=1;
    while(1)
    {
        while((j+1)<n&&ch[i][j+1]==0)
            ch[i][++j]=++p;
        while((i+1)<n&&ch[i+1][j]==0)
            ch[++i][j]=++p;
        while((j-1)>=0&&ch[i][j-1]==0)
            ch[i][--j]=++p;
        while((i-1)>=0&&ch[i-1][j]==0)
            ch[--i][j]=++p;
        if(p==n*n)
            break;
    }
 
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<setw(6)<<ch[i][j];
        }
        cout<<endl;
    }
 
    for(i=0;i<n;i++)
        delete [] ch[i];
    delete [] ch;
}
 
int main()
{
    int n;
    cin>>n;
    f(n);
    return 0;
}