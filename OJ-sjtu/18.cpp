/* *题目：
 *  1215
 *  bernoulli
 * *思路：
 *  
 * *技法：
 *  
 */

#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
 
 
class bi{
    private:
        struct node{
        int data;
        node *son,*brother;
        node(int d,node *s=NULL,node *b=NULL){data=d;son=s;brother=b;}
        node(){}
        };
        node **forest;
        int no;
        int findmins();
        node *merges(node *t1,node *t2);
        void deltree(node *rt)
        {
            node *son=rt->son,*t;
            while(son!=NULL)
            {
                t=son;son=son->brother;
                deltree(t);
            }
            delete rt;
        }
 
    public:
        bi(int n=100)
        {
            no=int(log(n)/log(2))+1;
            forest=new node*[no];
            for(int i=0;i<no;++i)forest[i]=NULL;
        }
        ~bi()
        {
            for(int i=0;i<no;i++)
            if(forest[i]!=NULL)deltree(forest[i]);
            delete [] forest;
        }
        void enQue(int x);
        int deQue();
        bool isEmpty();
        int getHead();
        void merges(bi &other);
};
 
void bi::merges(bi &other)
{
    node **tmp=forest,*carry;
    int tmpsize=no;
    int mins=no<other.no?no:other.no;
    int i;
 
    if(no<other.no){no=other.no;if(other.forest[no]!=NULL)++no;}
    else if(forest[no]!=NULL)++no;
    forest=new node *[no];
    for(i=0;i<no;++i)forest[i]=NULL;
    carry=NULL;
    for(i=0;i<mins;i++){
        if(carry==NULL){
            if(tmp[i]==NULL)forest[i]=other.forest[i];
            else{if(other.forest[i]==NULL)forest[i]=tmp[i];
                else carry=merges(other.forest[i],tmp[i]);}}
        else {
            if(tmp[i]!=NULL&&other.forest[i]!=NULL){
                forest[i]=carry;
                carry=merges(other.forest[i],tmp[i]);
            }
            else{
                if(tmp[i]==NULL&&other.forest[i]==NULL){forest[i]=carry;carry=NULL;}
                else if(tmp[i]==NULL)carry=merges(other.forest[i],carry);
                    else carry=merges(tmp[i],carry);
            }
        }
        }
 
    if(other.no==mins){
        for(;i<tmpsize;++i)
        if(carry==NULL)forest[i]=tmp[i];
        else if(tmp[i]==NULL){forest[i]=carry;carry=NULL; }
            else carry=merges(tmp[i],carry);}
    else {
        for(;i<no;++i)
        if(carry==NULL)forest[i]=other.forest[i];
        else if(other.forest[i]==NULL){forest[i]=carry;carry=NULL; }
            else carry=merges(other.forest[i],carry);}
 
    if(carry!=NULL)forest[i]=carry;
    for(i=0;i<other.no;i++)other.forest[i]=NULL;
    delete [] tmp;
 
}
 
bi::node *bi::merges(node *t1,node *t2)
{
    node *mins,*maxs;
 
    if(t1->data<t2->data){mins=t1;maxs=t2; }
    else {mins=t2;maxs=t1;}
    if(mins->son==NULL)mins->son=maxs;
    else{
        node *t=mins->son;
        while(t->brother!=NULL)t=t->brother;
        t->brother=maxs;
    }
    return mins;
}
 
void bi::enQue(int x)
{
    bi tmp(1);
    tmp.forest[0]=new node(x);
    merges(tmp);
}
 
int bi::deQue()
{
    int val;
    int mins=findmins();
    if(mins==0)
    {
        val=forest[0]->data;
        delete forest[0];
        forest[0]=NULL;
        return val;
    }
 
    node *t=forest[mins],*son,*brother;
    int sizeofQue=int(pow(2,mins)-1);
    bi tmp(sizeofQue);
    val=t->data;
    forest[mins]=NULL;
 
    son=t->son;
    delete t;
    int i=0;
 
    do{
        tmp.forest[i++]=son;
        brother=son->brother;
        son->brother=NULL;
    }while((son=brother)!=NULL);
    merges(tmp);
    return val;
}
 
int bi::findmins()
{
    int mins,i;
    for(i=0;i<no&&forest[i]==NULL;++i);
    mins=i;
    for(;i<no;++i)
        if(forest[i]!=NULL&&forest[i]->data<forest[mins]->data)mins=i;
    return mins;
}
 
bool bi::isEmpty()
{
    for(int i=0;i<no;++i)
        if(forest[i]!=NULL) return false;
    return true;
}
 
int bi::getHead()
{
    int pos=findmins();
    return forest[pos]->data;
}
 
int main()
{
    int m,i=0,n;
    char cmd[7]={};
    cin>>m;
    bi top(m);
    while(i<m)
    {
        cin>>cmd;
        if(!strcmp(cmd,"insert"))
        {
            cin>>n;
            top.enQue(n);
        }
        else if(!strcmp(cmd,"delete"))
        {
            top.deQue();
        }
        else if(!strcmp(cmd,"min"))
        {
            cout<<top.getHead()<<endl;
        }
        i++;
 
    }
 
    return 0;
}