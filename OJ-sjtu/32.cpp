/* *题目：
 *  1236
 *  spath
 * *思路：
 *  
 * *技法：
 *  
 */

#include<iostream>
#include<iomanip>
using namespace std;
 
class linkQueue
{
    private:
        struct node{
            int data;
            node *next;
            node(const int &x,node *N=NULL){data=x;next=N;}
            node():next(NULL){}
            ~node(){}
        };
        node *head,*rear;
        //int len;
 
    public:
        //linkQueue(){head=new node(0,NULL);rear=head;len=0;}
        linkQueue(){head=rear=NULL;}
        ~linkQueue();
        void enQueue(const int &x);
        int deQueue();
        //int getLen(){return len;}
        //bool isEmpty(){return len==0;}
        bool isEmpty(){return head==NULL;}
 
};
/*
linkQueue::~linkQueue()
{
    node *tmp;
    while(head->next!=NULL)
    {
        tmp=head->next;
        head->next=head->next->next;
        delete tmp;
    }
    delete head;
}
*/
linkQueue::~linkQueue()
{
    node *tmp;
    while(head!=NULL)
    {
        tmp=head;
        head=head->next;
        delete tmp;
    }
}
 
void linkQueue::enQueue(const int &x)
{
    if(rear==NULL)head=rear=new node(x);
    else
    {rear->next=new node(x);
    rear=rear->next;}
}
/*
int linkQueue::deQueue()
{
    node *tmp=head->next;
    head->next=head->next->next;
    int value;
    value=tmp->data;
    delete tmp;
    len--;
    return value;
}
*/
int linkQueue::deQueue()
{
    node *tmp=head;
    int value=head->data;
    head=head->next;
    if(head==NULL)rear=NULL;
    delete tmp;
    return value;
}
 
 
class alg
{
    public:
        alg(int vsize);
        void insert(int u,int v,int w);
        //bool remove(int u,int v);
        bool exist(int u,int v)const;
        void msd(int start,int ends)const;
        ~alg();
    private:
        struct enode
        {
            int end;
            enode *next;
            int weight;
            enode(int e,int w,enode *n=NULL){end=e;next=n;weight=w;}
        };
 
        struct vnode
        {
            enode *head;
            vnode(enode *h=NULL){head=h;}
        };
        vnode *verlist;
        int vers,edges;
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
 
void alg::insert(int u,int v,int w)
{
    verlist[u].head=new enode(v,w,verlist[u].head);
    ++edges;
}
 
bool alg::exist(int u,int v)const
{
    enode *p=verlist[u].head;
    while(p!=NULL&&p->end!=v)p=p->next;
    if(p==NULL)return false;else return true;
}
 
void alg::msd(int start,int ends)const
{
    int *distance=new int[vers];
    int u,sNo,i;
    enode *p;
    linkQueue q;
 
    for(sNo=0;sNo<vers;++sNo)
        if(sNo==start-1)break;
 
    for(i=0;i<vers;i++)distance[i]=100000;
 
    distance[sNo]=0;
    q.enQueue(sNo);
 
    while(!q.isEmpty())
    {
 
        u=q.deQueue();
        for(p=verlist[u].head;p!=NULL;p=p->next)
            if(distance[p->end]>distance[u]+p->weight)
            {
                distance[p->end]=distance[u]+p->weight;
                q.enQueue(p->end);
            }
    }
    cout<<distance[ends-1];
 
}
 
int main()
{
    int n,m,start,end,a,b,p,i=0;
    cin>>n>>m>>start>>end;
    alg op(n);
 
    while(i<m)
    {
        cin>>a>>b>>p;
        op.insert(a-1,b-1,p);
        i++;
    }
    op.msd(start,end);
}