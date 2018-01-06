/* *题目：
 *  1235
 *  Dijkstra
 * *思路：
 *  
 * *技法：
 *  
 */

#include<iostream>
using namespace std;
 
struct edge
{
    int num,dis;
    bool operator<(const edge &r)const {return dis<r.dis;}
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
 
void priorityQueue::enQueue( const edge &x )
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
        void dijkstra(int start,int end)const;
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
        void printPath(int start,int end,int prev[])const;
 
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
 
void alg::dijkstra(int start,int end)const
{
    int *distance=new int[vers];
    int *prev=new int[vers];
    int *hop=new int[vers];
    bool *known=new bool[vers];
    int min;
    int u,sNo,i,j;
    enode *p;
    edge c;
 
    priorityQueue q;
 
    for(i=0;i<vers;++i)
    {
        known[i]=false;
        distance[i]=1000000;
        hop[i]=0;
    }
    for(sNo=0;sNo<vers;++sNo)
        if(sNo==start-1)break;
    if(sNo==vers)return;
 
    distance[sNo]=0;
    prev[sNo]=0;
    c.num=sNo;c.dis=0;
    q.enQueue(c);
 
    while(!q.isEmpty())
    {
        c=q.deQueue();
        u=c.num;min=c.dis;
        if(known[u])continue;
        known[u]=true;
 
        for(p=verlist[u].head;p!=NULL;p=p->next)
            if(!known[p->end]&&(distance[p->end]>min+p->weight||distance[p->end]==min+p->weight&&hop[p->end]>hop[u]+1))
            {
 
                distance[p->end]=min+p->weight;
                prev[p->end]=u;
                hop[p->end]=hop[u]+1;
                c.dis=distance[p->end];
                c.num=p->end;
                q.enQueue(c);
            }
    }
    cout<<distance[end-1]<<endl;
    printPath(sNo,end-1,prev);
 
}
 
void alg::printPath(int start,int end,int prev[])const
{
    if(start==end)
    {
        cout<<start+1;return;
    }
    printPath(start,prev[end],prev);
    cout<<" "<<end+1;
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
 
    op.dijkstra(start,end);
 
 
    return 0;
}
