/* *题目：
 *  1211
 *  isCBT
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
       node(int a=0,int b=0){lc=a;rc=b;}};
       node *root;
    public:
        btree(int N){root=new node[N+1];}
        ~btree(){delete [] root;}
        void creat(int N);
 
};
 
void btree::creat(int N)
{
    int i=1,a,b,j=0,k,t=0;
    node ch,*top;
    int *bag;
    bag=new int[N+1];
    for(j=0;j<N+1;j++)bag[j]=0;
    while(i<N+1)
    {
        cin>>a>>b;
        bag[a]=a;
        bag[b]=b;
        ch.lc=a;
        ch.rc=b;
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
 
    k=0;j=0;
    ch=top[N/2];
    for(j=1;j<=N/2;j++)
    {
        ch=top[j];
        if(ch.lc==0)
        {
            k++;break;
        }
    }
    for(j=1;j<=N/2-1;j++)
    {
        ch=top[j];
        if(ch.rc==0)
        {
            k++;break;
        }
    }
    for(j=N/2+1;j<=N;j++)
    {
        ch=top[j];
        if(ch.lc!=0||ch.rc!=0)
        {k++;break;}
 
    }
    if(k!=0)
    cout<<"N";
    else cout<<"Y";
    delete [] top;
 
}
 
 
int main()
{
    int N;
    cin>>N;
    btree tmp(N);
    tmp.creat(N);
 
    return 0;
}