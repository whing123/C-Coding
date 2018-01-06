/* *题目：
 *  4015
 *  怎么还是那个数列？！
 * *思路：
 *  
 * *技法：
 *  
 */

 #include <iostream>
using namespace std;
 
 
int f(int a,int b,int n)
{
    int data;
    if(n==1||n==2)
        return 1;
    else
    {
        int i,data1=1,data2=1;
        for(i=3;i<=n;i++)
        {
            data=((a*data2)%7+(b*data1)%7)%7;
            data1=data2;
            data2=data;
        }
    }
    return data;
}
 
int main()
{
    int a,b,n;
    cin>>a>>b>>n;
    cout<<f(a,b,n);
    return 0;
}