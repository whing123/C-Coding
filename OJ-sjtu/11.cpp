/* *题目：
 *  1205
 *  ackerman
 * *思路：
 *  
 * *技法：
 *  
 */

#include<iostream>
using namespace std;
 
class afun
{
    public:
    int A(int i,int j);
 
};
int afun::A(int i,int j)
{
    if(i==0) return j+1;
    else if (i!=0&&j==0) return A(i-1,1);
    else if(i!=0&&j!=0) return A(i-1,A(i,j-1));
 
}
 
int main()
{
    afun bob;
    int m,n,r;
    cin>>m>>n;
    r=bob.A(m,n);
    cout<<r;
}