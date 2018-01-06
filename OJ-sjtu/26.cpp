/* *题目：
 *  1227
 *  select
 * *思路：
 *  
 * *技法：
 *  
 */

#include<iostream>
using namespace std;
 
class linklist  //建立单链表
{
    private:
    struct node{
    int data;
    node *next;
    node(const int &x,node *n=NULL){data=x;next=n;}
 
    node():next(NULL){}
    ~node(){}
    };
 
    node *head;
    int len;
    node *move(int i)const;
 
    public:
 
    linklist();
    ~linklist(){clear();delete head;}
 
    void clear();
    int length()const{return len;}
    void insert(int x);
    int visit(int i)const;
    void selectSort(int n);
    void traverse();
};
 
linklist:: node *linklist::move(int i)const  //找到第i个节点的位置
{
   if(i<0) return head;
   node *p=head->next;
   for(int j=0;j<i;++j) p=p->next;
   return p;
}
 
linklist::linklist()
{
    head =new node;
    len=0;
}
 
void linklist::clear()   //清空链表
{
    node *p=head->next,*q;
    while(p!=NULL)
    {
        q=p->next;
        delete p;
        p=q;
    }
    len=0;
}
void linklist::insert(int x)  //将新数据插入第0个节点
{
    node *tmp;
    tmp=new node(x,head->next);
    head->next=tmp;
    len++;
}
 
int linklist::visit(int i)const  //访问第i个节点
{
    node *p=move(i);
    return p->data;
}
 
void linklist::selectSort(int n)
{
    node *p,*q,*m;
    int i,j,d,e;
    for(i=0;i<n-1;i++)
    {
        d=i;m=move(i);
        for(j=i+1;j<n;++j)
        {
            p=move(j);q=move(d);
            if(p->data<q->data)d=j;
        }
        q=move(d);
        e=m->data;m->data=q->data;q->data=e;
    }
}
 
void linklist::traverse()
{
    node *p=head->next;
    while(p!=NULL)
    {
        cout<<p->data<<' ';
        p=p->next;
    }
}
 
int main()
{
    int n,i=0,p;
    linklist top;
    cin>>n;
    while(i<n)
    {
        cin>>p;
        top.insert(p);
        i++;
    }
    top.selectSort(n);
    top.traverse();
    return 0;
}
