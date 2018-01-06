/* *题目：
 *  1213
 *  same
 * *思路：
 *  
 * *技法：
 *  
 */

#include<iostream>
using namespace std;
 
class btree
{
   private:
       struct node{
       int lc,rc,num;
       node(int a=0,int b=0,int c=0){lc=a;rc=b;num=c;}};
       node *root;
    public:
        btree(int N){root=new node[N+1];}
        ~btree(){delete [] root;}
        void creat(int N);
        bool check(btree &a,int N1,int N2);
};
 
void btree::creat(int N)
{
    int i=1,a,b,c,j=0,k,t=0;
    node ch,*top;
    int *bag;
    bag=new int[N+1];
    for(j=0;j<N+1;j++)bag[j]=0;
    while(i<N+1)
    {
        cin>>a>>b>>c;
        bag[a]=a;
        bag[b]=b;
        ch.lc=a;
        ch.rc=b;
        ch.num=c;
        root[i]=ch;
        i++;
    }
    for(j=1;j<N+1;j++)
    {
        if(bag[j]==0)
        {k=j;break;}
    }
    delete [] bag;
 
 
    top=new node[N+1];
    top[1]=root[k];i=1;t=1;
    while(i<N+1)
    {
        i++;
        ch=top[i-1];
        if(ch.lc!=0&&ch.rc!=0){top[++t]=root[ch.lc];top[++t]=root[ch.rc];}
        else if(ch.lc==0&&ch.rc!=0)top[++t]=root[ch.rc];
        else if(ch.lc!=0&&ch.rc==0)top[++t]=root[ch.lc];
        else continue;
    }
 
    for(j=1;j<N+1;j++)
    {
        root[j]=top[j];
    }
    delete [] top;
 
}
 
bool btree::check(btree &a,int N1,int N2)
{
    if(N1!=N2)
    return false;
    int i;
    node p,q;
    for(i=1;i<N1+1;i++)
    {
        p=root[i];q=a.root[i];
        if(p.lc==0&&q.lc!=0||p.lc!=0&&q.lc==0||p.rc==0&&q.rc!=0||p.rc!=0&&q.rc==0||p.num!=q.num)
        return false;
    }
    return true;
}
 
int main()
{
    int N1,N2;
    cin>>N1;
    btree tmp(N1);
    tmp.creat(N1);
    cin>>N2;
    btree cmp(N2);
    cmp.creat(N2);
    if(tmp.check(cmp,N1,N2))
    cout<<"Y";
    else cout<<"N";
 
    return 0;
}