/* *题目：
 *  1214
 *  traverse
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
        void creat(int N,int &k);
        void pre(int op);
        void floor(int N,int op);
        void post(int op);
 
};
 
void btree::creat(int N,int &k)
{
    int i=1,a,b,c,j=0;
    node ch;
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
}
 
void btree::pre(int op)
{
        node ch;
        if(op!=0)
        {
            ch=root[op];
            cout<<ch.num<<' ';
            pre(ch.lc);
            pre(ch.rc);
        }
}
 
 
void btree::floor(int N,int op)
{
    int i,t;
    node ch,bh,*top;
    top=new node[N+1];
    top[1]=root[op];i=1;t=1;
    while(i<N+1)
    {
        i++;
        ch=top[i-1];
        bh=top[t];
        while(bh.rc!=0){top[++t]=root[bh.rc];bh=top[t];}
        if(ch.lc!=0)
        top[++t]=root[ch.lc];
 
    }
    for(i=1;i<N+1;i++)
    {
        ch=top[i];
        cout<<ch.num<<' ';
    }
    delete [] top;
 
}
 
 
void btree::post(int op)
{
        node ch;
        if(op!=0)
        {
            ch=root[op];
            post(ch.lc);
            cout<<ch.num<<' ';
            post(ch.rc);
        }
 
 
}
 
int main()
{
    int N,k;
    cin>>N;
 
    btree tmp(N);
    tmp.creat(N,k);
    tmp.pre(k);
    cout<<endl;
    tmp.post(k);
    cout<<endl;
    tmp.floor(N,k);
 
    return 0;
}

