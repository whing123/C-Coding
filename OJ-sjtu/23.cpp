/* *题目：
 *  1224
 *  hash
 * *思路：
 *  
 * *技法：
 *  
 */

#include<iostream>
#include<cmath>
using namespace std;
 
class OHTable
{
private:
    struct node
    {
        int data ;
        int times ;
        node * next ;
        node() {times = 0 ;next = NULL ;}
        node(const int &x) {data = x ; times = 0 ; next = NULL ;}
    };
 
    node ** array ;
 
public:
    OHTable() {
        array = new node*[100001] ;
        for (int i = 0; i < 100001; ++i)
            array[i] = new node ;
    }
    ~OHTable() ;
    int find(const int &x) ;
    void insert (const int &x) ;
};
 
int OHTable::find(const int &x)
{
    int pos ;
    node *p;
 
    pos = abs(x) ;
    pos = pos % 100001 ;
    p = array[pos]->next;
    while ((p!= NULL) && (p->data != x))
        p = p->next ;
    if (p!= NULL)
        return p->times ;
    else return 0 ;
}
 
void OHTable::insert(const int &x)
{
    int pos ;
    node * p ;
 
    pos = abs(x) ;
    pos = pos % 100001 ;
    p = array[pos]->next ;
    while(p != NULL)
    {
        if (p->data == x)
        {
            ++p->times ; break ;
        }
        p = p->next ;
    }
    if (p == NULL){
        p = new node(x) ;
        p->next = array[pos]->next ;
        array[pos]->next = p ;
        ++p->times ;
    }
}
 
OHTable::~OHTable()
{
    node *p, *q ;
    for (int i = 0; i < 100001; ++i){
        p=array[i];
        while(p!=NULL)
        {
            q=p->next;
            delete p;
            p=q;
        }
    }
    delete [] array ;
}
 
int main()
{
    int n,i=0,j=0,*a,*b,*c,*d,cnt=0,tmp;
    bool L;
 
    cin>>n;
    OHTable op;
    a=new int[n];
    b=new int[n];
    c=new int[n];
    d=new int[n];
    while(i<n)
    {
        cin>>a[i]>>b[i]>>c[i]>>d[i];
        i++;
    }
 
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            tmp=0-a[i]-b[j];
            op.insert(tmp);
        }
 
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    {
        tmp=c[i]+d[j];
        cnt+=op.find(tmp);
    }
    cout<<cnt;
}