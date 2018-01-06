/* *题目：
 *  1237
 *  Courses
 * *思路：
 *  
 * *技法：
 *  
 */

#include<iostream>
using namespace std;
 
class alg
{
    public:
        alg(int vsize);
        void insert(int u,int v);
        bool remove(int u,int v);
        bool exist(int u,int v)const;
        void topsort()const;
        ~alg();
    private:
        struct enode
        {
            int end;
            enode *next;
            enode(int e,enode *n=NULL){end=e;next=n;}
        };
 
        struct vnode
        {
            enode *head;
            vnode(enode *h=NULL){head=h;}
        };
        vnode *verlist;
        int vers,edges;
        bool sum(int a[])const;
 
};
 
alg::alg(int vsize)
{
    vers=vsize;
    verlist=new vnode[vsize];
}
 
alg::~alg()
{
    int i;
    enode *p;
    for(i=0;i<vers;i++)
    {
        while((p=verlist[i].head)!=NULL)
        {
            verlist[i].head=p->next;
            delete p;
        }
    }
    delete [] verlist;
}
 
void alg::insert(int u,int v)
{
    verlist[u].head=new enode(v,verlist[u].head);
    ++edges;
}
 
bool alg::exist(int u,int v)const
{
    enode *p=verlist[u].head;
    while(p!=NULL&&p->end!=v)p=p->next;
    if(p==NULL)return false;else return true;
}
 
void alg::topsort()const
{
    enode *p;
    int *degree=new int[vers],i,cnt=1;
    bool *over=new bool[vers];
    for(i=0;i<vers;i++)
    {
        degree[i]=0;
        over[i]=false;
    }
 
    for(i=0;i<vers;i++)
        for(p=verlist[i].head;p!=NULL;p=p->next)
            ++degree[p->end];
 
    while(sum(degree))
    {
        for(i=0;i<vers;i++)
            if(degree[i]==0&&over[i]==false)
            {
                over[i]=true;
                for(p=verlist[i].head;p!=NULL;p=p->next)
                    --degree[p->end];
            }
        cnt++;
    }
    cout<<cnt;
 
}
 
bool alg::sum(int a[])const
{
    int s=0;
    for(int i=0;i<vers;i++)s+=a[i];
    return s!=0;
}
 
int main()
{
    int n,m,a,b,i=0;
    cin>>n>>m;
    alg op(n);
 
    while(i<m)
    {
        cin>>a>>b;
        op.insert(b-1,a-1);
        i++;
    }
    op.topsort();
    return 0;
}