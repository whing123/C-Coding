/* *题目：
 *  1218
 *  settest
 * *思路：
 *  
 * *技法：
 *  
 */


#include<iostream>
using namespace std;
 
 
void ord(int a[],int n)
{
    int i,j,p,q;
    for(i=0;i<n;i++)
    {
        p=a[i];q=i;
        for(j=i;j<n;j++)
        if(a[j]<p){p=a[j];q=j;}
        a[q]=a[i];
        a[i]=p;
        cout<<a[i]<<' ';
    }
    cout<<endl;
}
 
class linklist  //建立单链表
{
    private:
    struct node{
    int data;
    node *next;
    node(int x,node *n=NULL){data=x;next=n;}
 
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
    void insert(int x);
    int visit(int i)const;
    int length()const{ return len;}
    bool find1(int x);
    void find2(int x);
    bool find3(int x);
};
 
linklist::node *linklist::move(int i)const  //找到第i个节点的位置
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
    head->next=NULL;
    len=0;
}
void linklist::insert(int x)
{
    node *tmp,*p=move(len-1);
    tmp=new node(x,NULL);
    p->next=tmp;
    len++;
}
 
int linklist::visit(int i)const  //访问第i个节点
{
    node *p=move(i);
    return p->data;
}
 
bool linklist::find1(int x)
{
    node *p=head->next;
    while(p!=NULL)
    {
        if(p->data==x)return true;
        p=p->next;
    }
    return false;
}
 
void linklist::find2(int x)
{
    node *p=head->next,*q=head;
    while(p!=NULL)
    {
        if(p->data==x)
        {
            q->next=p->next;
            delete p;len--;
            break;
        }
        q=p;
        p=p->next;
    }
}
 
bool linklist::find3(int x)
{
    node *p=head->next;
    while(p!=NULL)
    {
        if(p->data==x)return true;
        p=p->next;
    }
    return false;
}
 
 
int main()
{
    linklist top,tip;
    int u,m,i=0,j,num;
    char op;
    cin>>u;
    while(i<u)
    {
       cin>>op;
       if(op=='+')
       {
           j=0;
           cin>>m;
           while(j<m)
           {
               cin>>num;
               if(!top.find1(num))
               top.insert(num);
               j++;
           }
           int *ch=new int[top.length()];
           for(j=0;j<top.length();j++)
               ch[j]=top.visit(j);
           ord(ch,top.length());
           delete [] ch;
       }
       else if(op=='-')
       {
           j=0;
           cin>>m;
           while(j<m)
           {
               cin>>num;
               top.find2(num);
               j++;
           }
           int *ch=new int[top.length()];
           for(j=0;j<top.length();j++)
               ch[j]=top.visit(j);
           ord(ch,top.length());
           delete [] ch;
       }
       else if(op=='*')
       {
 
           j=0;
           cin>>m;
           while(j<m)
           {
               cin>>num;
               if(top.find3(num)) tip.insert(num);
               j++;
           }
           if(tip.length()==0) {top.clear();cout<<endl;}
           else
           {
 
               int *ch=new int[tip.length()];
               for(j=0;j<tip.length();j++)
                   ch[j]=tip.visit(j);
               ord(ch,tip.length());
               delete [] ch;
               top.clear();
               for(j=0;j<tip.length();j++)
               {num=tip.visit(j);top.insert(num);}
               tip.clear();
           }
 
       }
       i++;
    }
    return 0;
}