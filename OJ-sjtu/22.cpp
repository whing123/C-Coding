/* *题目：
 *  1221
 *  bst
 * *思路：
 *  
 * *技法：
 *  
 */

#include<iostream>
#include<cstring>
using namespace std;
 
int N=0;
 
class BSTree
{
    private:
        struct BiNode{
        int data;
        BiNode *lc,*rc;
        BiNode(const int & thedata,BiNode *lt,BiNode *rt):data(thedata),lc(lt),rc(rt){}
        };
 
        BiNode *root;
        void insert(const int &x,BiNode * &t);
        bool find(const int &x,BiNode *t)const;
        void remove(const int &x,BiNode * &t);
        void makeEmpty(BiNode * &t);
        bool findith(int i,int &x,BiNode *t)const;
        int sizes(BiNode *t)const{if(t==NULL)return 0;return 1+sizes(t->lc)+sizes(t->rc);}
        void delless(const int x,BiNode * &t);
        void delgreat(const int x,BiNode * &t);
        void delrange(int x,int y,BiNode * &t);
        /*bool mid(int j,BiNode * t)const{
            if(t!=NULL)
            {mid(j,t->lc);
            s++;if(s==j){cout<<t->data<<endl;return true;}
            mid(j,t->rc);}
            else return false;}*/
        /*bool find_ith(const int &x, bool judge, BiNode *t)
        {
            if (t != NULL)
            {
                judge = find_ith(x, judge, t->lc) ;
                if (N == x) {
                cout<< t->data <<endl;
                ++N;judge = true;}
                ++N ;
                judge = find_ith(x, judge, t->rc) ;
            }
            return judge ;
        }*/
 
 
 
    public:
        BSTree(BiNode *t=NULL){root=t;}
        ~BSTree(){ makeEmpty(root); }
        bool find(const int &x)const;
        void insert(const int &x);
        void remove(const int &x);
        int min();
        int max();
        bool findith(int i,int &x)const{return findith(i,x,root);}
        bool isEmpty(){return root==NULL;}
        void delless(const int x){delless(x,root);}
        void delgreat(const int x){delgreat(x,root);}
        void delrange(int x,int y){if(x<=y)delrange(x,y,root);}
        //bool mid(int j)const{return mid(j,root);}
        /*void find_ith(const int &x)
        {
            N = 1 ; bool judge = false ;
            if (root != NULL)
            if (!find_ith(x, judge, root))
            cout << "N\n" ;
        }*/
};
 
void BSTree::delrange(int x,int y,BiNode * &t)
{
    if(t==NULL)return;
    if(t->data<x)delrange(x,y,t->rc);
    else if(t->data>y)delrange(x,y,t->lc);
    else
    {
        remove(t->data,t);
        delrange(x,y,t);
    }
}
 
void BSTree::delless(const int x,BiNode * &t)
{
    if(t==NULL)return;
    if(t->data<x)
    {
        BiNode *tmp=t;
        t=t->rc;
        makeEmpty(tmp->lc);
        delete tmp;
        delless(x,t);
    }
    else delless(x,t->lc);
}
 
void BSTree::delgreat(const int x,BiNode * &t)
{
    if(t==NULL)return;
    if(t->data>x)
    {
        BiNode *tmp=t;
        t=t->lc;
        makeEmpty(tmp->rc);
        delete tmp;
        delgreat(x,t);
    }
    else delgreat(x,t->rc);
}
 
void BSTree::makeEmpty(BiNode * &t)
{
    if(t==NULL)return;
    makeEmpty(t->lc);
    makeEmpty(t->rc);
    delete t;
}
 
bool BSTree::find(const int &x,BiNode *t)const
{
    while(t!=NULL&&t->data!=x)
    {
        if(t->data>x) t=t->lc;
        else t=t->rc;
    }
    if(t==NULL) return false;
    else return true;
}
/*
bool BSTree::find(const int &x,BiNode *t)const
{
    if(t==NULL)return false;
    else if(x<t->data) return find(x,t->lc);
    else if(x>t->data) return find(x,t->rc);
    else return true;
}
*/
bool BSTree::find(const int &x)const
{
    return find(x,root);
}
 
void BSTree::insert(const int &x)
{
    insert(x,root);
}
 
void BSTree::insert(const int &x,BiNode * &t)
{
    BiNode *p=new BiNode(x,NULL,NULL);
    if(t==NULL){t=p;return;}
    BiNode *now=t;
    while(1)
    {
        if(x>now->data)
        {
            if(now->rc==NULL){now->rc=p;break;}
            now=now->rc;
        }
        else if(now->lc==NULL){now->lc=p;break; }
        else now=now->lc;
    }
}
 
/*
void BSTree::insert(const int &x,BiNode * &t)
{
    if(t==NULL)t=new BiNode(x,NULL,NULL);
    else if(x<=t->data) insert(x,t->lc);
    else if(x>t->data) insert(x,t->rc);
}
*/
void BSTree::remove(const int &x)
{
    remove(x,root);
}
/*
void BSTree::remove(const int &x,BiNode * &t)
{
    BiNode *now=t;
    BiNode *parent;
    int lor;
    while(now!=NULL)
    {
        if(x>now->data)
        {
            lor=2;
            parent=now;
            now=now->rc;
        }
        else if(x<now->data)
        {
            lor=1;
            parent=now;
            now=now->lc;
        }
        else break;
    }
    if(now->lc!=NULL&&now->rc!=NULL)
    {
        BiNode *tmp=now->rc;
        if(tmp->lc==NULL)
        {
            now->data=tmp->data;
            now->rc=tmp->rc;
            delete tmp;
            return;
        }
        while(tmp->lc->lc!=NULL)tmp=tmp->lc;
        BiNode *deleted=tmp->lc;
        now->data=deleted->data;
        tmp->lc=deleted->rc;
        delete deleted;
        return;
    }
    if(now==t)
    {
        if(t->lc==NULL)t=t->rc;
        else t=t->lc;
        delete now;
        return;
    }
    if(lor==1)
    parent->lc=(now->lc==NULL?now->rc:now->lc);
    else parent->rc=(now->lc==NULL?now->rc:now->lc);
    delete now;
    return;
}
*/
void BSTree::remove(const int &x,BiNode * &t)
{
    if(t==NULL)return;
    if(x<t->data)remove(x,t->lc);
    else if(x>t->data)remove(x,t->rc);
    else if(t->lc!=NULL && t->rc!=NULL)
    {
        BiNode *tmp=t->rc;
        while(tmp->lc!=NULL)tmp=tmp->lc;
        t->data=tmp->data;
        remove(t->data,t->rc);
    }
    else{
        BiNode *old=t;
        t=(t->lc!=NULL)?t->lc:t->rc;
        delete old;
    }
}
 
int BSTree::min()
{
    BiNode *p=root,*q;
    while(p!=NULL)
    {
        q=p;
        p=p->lc;
    }
    return q->data;
 
}
 
int BSTree::max()
{
    BiNode *p=root,*q;
    while(p!=NULL)
    {
        q=p;
        p=p->rc;
    }
    return q->data;
 
}
 
bool BSTree::findith(int i,int &x,BiNode *t)const
{
    if(t==NULL)return false;
    int ls=sizes(t->lc);
    if(ls==i-1){x=t->data;return true;}
    if(ls>=i) return findith(i,x,t->lc);
    else return findith(i-1-ls,x,t->rc);
}
 
int main()
{
    int m,i=0,n,k,j,x;
    char cmd[30]={};
 
    BSTree top;
 
    cin>>m;
    while(i<m)
    {
        cin>>cmd;
        if(!strcmp(cmd,"insert"))
        {
            cin>>n;
            top.insert(n);
        }
        else if(!strcmp(cmd,"find"))
        {
            cin>>n;
            if(top.find(n))
            cout<<'Y'<<endl;
            else cout<<'N'<<endl;
        }
        else if(!strcmp(cmd,"find_ith"))
        {
            cin>>n;
            /*if(top.mid(n));
            else cout<<'N'<<endl;*/
            //top.find_ith(n);
            if(top.findith(n,x))
                cout<<x<<endl;
            else cout<<'N'<<endl;
        }
        else if(!strcmp(cmd,"delete"))
        {
            cin>>n;
            top.remove(n);
        }
        else if(!strcmp(cmd,"delete_less_than"))
        {
            cin>>n;
            //top.delless(n);
 
            if(!top.isEmpty()){
            int z=top.min();
            if(n>z)
            {
                int q=top.max();
                int p=(n-1<q?n-1:q);
                for(j=z;j<=p;j++)
                while(top.find(j))top.remove(j);
            }}
        }
        else if(!strcmp(cmd,"delete_greater_than"))
        {
            cin>>n;
            //top.delgreat(n);
 
            if(!top.isEmpty()){
            int z=top.max();
            if(n<z)
            {
                int q=top.min();
                int p=(n+1>q?n+1:q);
                for(j=p;j<=z;j++)
                while(top.find(j))top.remove(j);
            }}
        }
        else if(!strcmp(cmd,"delete_interval"))
        {
            cin>>n>>k;
            //top.delrange(n+1,k-1);
 
            int c=top.min(),d=top.max();
            int p=(n+1>c?n+1:c),q=(k-1<d?k-1:d);
            for(j=p;j<=q;j++)
                while(top.find(j))top.remove(j);
        }
        i++;
 
    }
    return 0;
}