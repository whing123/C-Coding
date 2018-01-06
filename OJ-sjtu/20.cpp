/* *题目：
 *  1217
 *  optimization
 * *思路：
 *  
 * *技法：
 *  
 */

#include<iostream>
using namespace std;
 
class arr{
    private:
        int *app;
    public:
        arr(int N){app=new int[N];}
        ~arr(){delete [] app;}
        void creat(int p);
        bool check(int n,int p);
 
};
 
void arr::creat(int p)
{
    int i;
    for(i=0;i<p;i++)
    cin>>app[i];
 
}
 
bool arr::check(int n,int p)
{
    int i;
    for(i=0;i<p;i++)
    {
        if(n==app[i])
        return true;
    }
    return false;
}
int main()
{
    int c,d,*tmp,i;
    cin>>c;
    arr p(c);
    p.creat(c);
    cin>>d;
    tmp=new int[d];
    for(i=0;i<d;i++)
        cin>>tmp[i];
    for(i=0;i<d;i++)
        if(p.check(tmp[i],c))cout<<"Y"<<endl;
        else cout<<"N"<<endl;
    return 0;
}