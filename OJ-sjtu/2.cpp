/* *题目：
 *  1202
 *  big int
 * *思路：
 *  超长整数按位相加
 * *技法：
 *  超长整数相加
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
    int min();
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
 
int linklist::min() //取第0个节点的数据
{
    node *p=head->next,*q;
    int val;
    if(p==NULL) return -1;
    val=p->data;
    q=p->next;
    head->next=q;
    delete p;
    return val;
 
}
 
int main()
{
    char ch;
    linklist a,b,c;
    int i=0,j=0,k=0,v=0;
 
    while(1)  //将第一个数据存入链表a
    {
        cin.get(ch);
        if(ch=='\n') break;
        else a.insert(ch-'0');
 
    }
    while(1)  //将第二个数据存入链表b
    {
        cin.get(ch);
        if(ch=='\n') break;
        else b.insert(ch-'0');
 
    }
    while(1)  //求和依位放入链表c
    {
       i=a.min();j=b.min();
       if(i<0&&j<0&&k==0)
       {
        while(1){
        v=c.min();
        if(v>=0)cout<<v;
        else break;}
        break;
       }
       if(i<0)i=0;if(j<0)j=0;v=i+j+k;
       if(v<10) {k=0;c.insert(v); }
       else {k=1;c.insert(v-10);}
 
    }
    return 0;
}