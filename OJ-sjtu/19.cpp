/* *题目：
 *  1216
 *  heap
 * *思路：
 *  
 * *技法：
 *  
 */

#include<iostream>
#include<cstring>
 
using namespace std;
 
class priorityQueue
{
    private:
        int currentSize;
        int *array;
        int maxSize;
        void doubleSpace();
        void buildHeap();
        void percolateDown( int hole );
    public:
        priorityQueue( int capacity = 100 ){ array = new int[capacity];maxSize = capacity;currentSize = 0;}
        priorityQueue( const int data[], int size );
        ~priorityQueue() { delete [] array; }
        bool isEmpty() const { return currentSize == 0; }
        void enQueue( const int & x );
        int deQueue();
        int getHead() { return array[1]; }
        int find(int op);
        void change(int j,int v);
};
 
void priorityQueue::enQueue( const int & x )
{
    if( currentSize == maxSize - 1 )doubleSpace();
    int hole = ++currentSize;
    for( ; hole > 1 && x < array[ hole / 2 ]; hole /=2 )
    array[ hole ] = array[ hole / 2 ];
    array[ hole ] = x;
}
 
int priorityQueue::deQueue()
{
    int minItem;
    minItem = array[ 1 ];
    array[ 1 ] = array[currentSize--];
    percolateDown( 1 );
    return minItem;
}
 
void priorityQueue::percolateDown( int hole )
{
    int child;
    int tmp = array[ hole ];
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
 
priorityQueue::priorityQueue( const int *items, int size ): maxSize(size + 10 ),currentSize(size)
{
    array = new int[maxSize];
    for( int i = 0; i < size; i++ )
    array[ i + 1 ] = items[ i ];
    buildHeap();
}
 
 
void priorityQueue::doubleSpace()
{
    int *tmp=array;
    maxSize*=2;
    array=new int[maxSize];
    for(int i=0;i<=currentSize;++i)array[i]=tmp[i];
    delete [] tmp;
}
 
int priorityQueue::find(int op)
{
    int i,am,t;
    for(i=1;i<=currentSize;i++)
        if(array[i]>op)
        {
            am=array[i];t=i;
            break;
        }
    for(;i<=currentSize;i++)
    {
        if(array[i]>op)
            if(am>array[i])
        {
            am=array[i];t=i;
        }
    }
    return t;
}
 
void priorityQueue::change(int j,int v)
{
    array[j]-=v;
    int x=array[j];
    int hole = j;
    for( ; hole > 1 && x < array[ hole / 2 ]; hole /=2 )
    array[ hole ] = array[ hole / 2 ];
    array[ hole ] = x;
}
 
int main()
{
    int i=0,m,n,j,v;
    char cmd[9]={};
    priorityQueue top;
 
    cin>>m;
    while(i<m)
    {
        cin>>cmd;
        if(!strcmp(cmd,"insert"))
        {
            cin>>n;
            top.enQueue(n);
            //cout<<"wanghao";
        }
        else if(!strcmp(cmd,"decrease"))
        {
            cin>>j>>v;
            top.change(j,v);
        }
        else if(!strcmp(cmd,"find"))
        {
            cin>>n;
            cout<<top.find(n)<<endl;
        }
        i++;
    }
    return 0;
}