/* *题目：
 *  1315
 *  frac1
 * *思路：
 *  
 * *技法：
 *  
 */

#include<iostream>
using namespace std;
 
class frac
{
    private:
        struct node{
        int a,b;
        double c;
        node(int x=0,int y=0,double z=0){a=x;b=y;c=z;}
        ~node(){}
        };
        node *head;
    public:
        frac(int k){head=new node[k];}
        ~frac(){delete [] head;}
        void creat(int N);
        bool out(int N,int k);
};
 
void frac::creat(int N)
{
    int i,j,n=0,q;
    node ch;
    double p;
    for(i=1;i<=N;i++)
    for(j=1;j<=N;j++)
    if(i<j)
    if(out(i,j))
    {
        ch.a=i;ch.b=j;ch.c=double(i)/j;
        head[n]=ch;
        n++;
    }
    ch=head[0];
    p=ch.c;
    for(i=0;i<n;i++){
    q=i;
    for(j=i;j<n;j++)
    {
    ch=head[j];
    if(p>ch.c){p=ch.c;q=j;}}
    ch=head[i];
    head[i]=head[q];
    head[q]=ch;
    ch=head[i+1];
    p=ch.c;
    }
    cout<<'0'<<'/'<<'1'<<endl;
    for(i=0;i<n;i++)
    {
        ch=head[i];
        cout<<ch.a<<'/'<<ch.b<<endl;
    }
    cout<<'1'<<'/'<<'1';
 
 
}
 
bool frac::out(int m,int n)
{
    int i,j=0;
    for(i=2;i<=m;i++)
    {
        if(m%i==0&&n%i==0)
           j++;
    }
    if(j>0)return false;
    else return true;
 
}
 
bool outs(int m,int n)
{
    int i,j=0;
    for(i=2;i<=m;i++)
    {
        if(m%i==0&&n%i==0)
           j++;
    }
    if(j>0)return false;
    else return true;
 
}
 
int main()
{
    int i,j,k=0,N;
 
    cin>>N;
    for(i=1;i<=N;i++)
    for(j=1;j<=N;j++)
    if(i<j)
    if(outs(i,j))k++;
 
    frac abs(k);
    abs.creat(N);
 
    return 0;
}
