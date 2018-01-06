/* *题目：
 *  1233
 *  Path
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
        void dfs()const;
        void find(int start,int m,int &c)const;
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
 
        void dfs(int start,bool visited[])const;
        void find(int start,int m,int &top,bool visited[],int st[],int &c)const;
 
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
 
void alg::dfs()const
{
    bool *visited=new bool[vers];
    int i;
    for(i=0;i<vers;i++)visited[i]=false;
 
    for(i=0;i<vers;i++)
    {
        if(visited[i]==true)continue;
        dfs(i,visited);
        cout<<endl;
    }
}
 
void alg::dfs(int start,bool visited[])const
{
    enode *p=verlist[start].head;
    cout<<start+1<<'\t';
    visited[start]=true;
    while(p!=NULL)
    {
        if(visited[p->end]==false)dfs(p->end,visited);
        p=p->next;
    }
}
 
void alg::find(int start,int m,int &c)const
{
    bool *visited=new bool[vers];
    int *stack=new int[m+1],top=0,i;
 
    for(i=0;i<vers;i++)visited[i]=false;
    find(start-1,m,top,visited,stack,c);
 
}
 
void alg::find(int start,int m,int &top,bool visited[],int st[],int &c)const
{
    enode *p=verlist[start].head;
    visited[start]=true;
    st[top++]=start;
    if(top==m+1)
    {
        //cout<<endl;
        //for(int i=0;i<top;i++)
        //   cout<<st[i]+1<<'\t';
        c++;
        visited[start]=false;
        --top;
        return;
    }
 
    while(p!=NULL)
    {
        if(!visited[p->end])
            find(p->end,m,top,visited,st,c);
        p=p->next;
    }
    visited[start]=false;
    --top;
}
 
int main()
{
    int n,m,start,M,a,b;
    cin>>n>>m>>start>>M;
 
    int i=0,cnt=0;
 
    alg op(n);
 
    while(i<m)
    {
        cin>>a>>b;
        if(!op.exist(a-1,b-1))
            op.insert(a-1,b-1);
        i++;
    }
    op.find(start,M,cnt);
 
    cout<<cnt;
 
    return 0;
}