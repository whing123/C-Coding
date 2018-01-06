/* *题目：
 *  1212
 *  levelOrder
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
        void outcome(int N);
 
};
 
void btree::outcome(int N)
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
 
    //cout<<endl<<k<<endl;
 
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
 
    /*
    cout<<endl;
    for(j=1;j<N+1;j++)
    {
        ch=top[j];
        cout<<ch.lc<<'\0'<<ch.rc<<'\0'<<ch.num<<endl;
    }
    */
 
    for(j=1;j<N+1;j++)
    {
        ch=top[j];
        cout<<ch.num<<' ';
    }
    delete [] top;
 
}
 
int main()
{
    int N;
    cin>>N;
    //cout << "good"<<'\0'<<"nimei\n";
    btree tmp(N);
    tmp.outcome(N);
 
    return 0;
}

