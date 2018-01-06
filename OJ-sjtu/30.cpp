/* *题目：
 *  1234
 *  Kruskal
 * *思路：
 *  
 * *技法：
 *  
 */

#include<iostream>
using namespace std;
 
class djs
{
    private:
        int size;
        int *parent;
    public:
        djs(int s);
        ~djs(){delete [] parent;}
        void nion(int root1,int root2);
        int find(int x);
};
 
djs::djs(int n)
{
    size=n;
    parent=new int[size];
    for(int i=0;i<size;i++)parent[i]=-1;
}
 
int djs::find(int x)
{
    if(parent[x]<0)return x;
    return parent[x]=find(parent[x]);
}
 
void djs::nion(int root1,int root2)
{
    if(root1==root2)return;
    if(parent[root1]>parent[root2])
    {
        parent[root2]+=parent[root1];parent[root1]=root2;
    }
    else
    {
        parent[root1]+=parent[root2];parent[root2]=root1;
    }
}
 
struct edge
{
    int beg,end;
    int w;
    bool operator<(const edge &r)const {return w<r.w;}
};
 
class priorityQueue
{
    private:
        int currentSize;
        edge *array;
        int maxSize;
        void doubleSpace();
        void buildHeap();
        void percolateDown( int hole );
    public:
        priorityQueue( int capacity = 100 ){ array = new edge[capacity];maxSize = capacity;currentSize = 0;}
        priorityQueue( const edge data[], int size );
        ~priorityQueue() { delete [] array; }
        bool isEmpty() const { return currentSize == 0; }
        void enQueue( const edge & x );
        edge deQueue();
};
 
void priorityQueue::enQueue( const edge & x )
{
    if( currentSize == maxSize - 1 )doubleSpace();
    int hole = ++currentSize;
    for( ; hole > 1 && x < array[ hole / 2 ]; hole /=2 )
    array[ hole ] = array[ hole / 2 ];
    array[ hole ] = x;
}
 
edge priorityQueue::deQueue()
{
    edge minItem;
    minItem = array[ 1 ];
    array[ 1 ] = array[currentSize--];
    percolateDown( 1 );
    return minItem;
}
 
void priorityQueue::percolateDown( int hole )
{
    int child;
    edge tmp = array[ hole ];
    for( ; hole * 2 <= currentSize; hole = child )
    {
        child = hole * 2;
        if( child != currentSize && array[ child + 1 ] <array[ child ] )
        child++;
        if( array[ child ] < tmp ) array[ hole ] =array[ child ];
        else break;
    }
    array[ hole ] = tmp;
}
 
void priorityQueue::buildHeap( )
{
    for ( int i = currentSize / 2; i > 0; i-- )
    percolateDown( i );
}
 
priorityQueue::priorityQueue( const edge *items, int size ): maxSize(size + 10 ),currentSize(size)
{
    array = new edge[maxSize];
    for( int i = 0; i < size; i++ )
    array[ i + 1 ] = items[ i ];
    buildHeap();
}
 
 
void priorityQueue::doubleSpace()
{
    edge *tmp=array;
    maxSize*=2;
    array=new edge[maxSize];
    for(int i=0;i<=currentSize;++i)array[i]=tmp[i];
    delete [] tmp;
}
 
 
class alg
{
    public:
        alg(int vsize);
        void insert(int u,int v,int w);
        bool remove(int u,int v);
        bool exist(int u,int v)const;
        void kruskal()const;
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
 
void alg::kruskal()const
{
    int accepted=0,u,v,sum=0;
    enode *p;
    edge e;
    djs ds(vers);
    priorityQueue pq;
 
    for(int i=0;i<vers;++i)
        for(p=verlist[i].head;p!=NULL;p=p->next)
            if(i<p->end)
            {
               e.beg=i;e.end=p->end;e.w=p->weight;
                pq.enQueue(e);
            }
 
    while(accepted<vers-1)
    {
        e=pq.deQueue();
        u=ds.find(e.beg);
        v=ds.find(e.end);
        if(u!=v)
        {
            accepted++;
            ds.nion(u,v);
            sum+=e.w;
        }
    }
    cout<<sum;
}
 
 
int main()
{
    int n,m,a,b,p,i=0;
    cin>>n>>m;
    alg op(n);
    while(i<m)
    {
        cin>>a>>b>>p;
        op.insert(a-1,b-1,p);
        op.insert(b-1,a-1,p);
        i++;
    }
    op.kruskal();
    return 0;
}
