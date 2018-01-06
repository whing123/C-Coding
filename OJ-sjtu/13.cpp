/* *题目：
 *  1207
 *  ferry
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
        int len;
 
    public:
        linkQueue(){head=new node(NULL);rear=head;len=0;}
        ~linkQueue();
        void enQueue(const int &x);
        int deQueue();
        int getLen(){return len;}
        int num(int t);
 
};
 
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
 
void linkQueue::enQueue(const int &x)
{
    rear->next=new node(x);
    rear=rear->next;
    len++;
}
 
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
 
int linkQueue::num(int t)
{
    int c=0;
    node *p=head->next;
    while(p!=NULL&&p->data<=t)
    {
        c++;
        p=p->next;
    }
    return c;
}
 
 
int main()
{
    linkQueue bus,lorry;
    int p,q,N,i=0,j=0;
    int time0=0,time1=0,time=0,num0=0,num1=0,wait0=0,wait1=0;
 
    cin>>N;
    while(i<N)
    {
        cin>>p>>q;
        if(p==0)
            bus.enQueue(q);
        else lorry.enQueue(q);
        i++;
    }
    num0=bus.getLen();num1=lorry.getLen();
 
    i=0;
 
    while(bus.getLen()!=0||lorry.getLen()!=0)
    {
        wait0=bus.num(time);wait1=lorry.num(time);
        if(wait0<=4)
        {
            while(j<wait0)
            {
                time0+=(time-bus.deQueue());
                j++;
            }
            j=0;
            while(j<10-wait0&&j<wait1)
            {
                 time1+=(time-lorry.deQueue());
                 j++;
            }
        }
        else if(wait0>4)
        {
 
            if(wait0>=8)
            {
                if(wait1>=2)
                {   while(i<8)
                    {time0+=(time-bus.deQueue());i++;}
                    time1+=(time-lorry.deQueue());
                    time1+=(time-lorry.deQueue());
                }
                else if(wait1==1)
                {
                    while(i<9&&i<wait0)
                    {time0+=(time-bus.deQueue());i++;}
                    time1+=(time-lorry.deQueue());
                }
                else
                {
                    while(i<10&&i<wait0)
                    {time0+=(time-bus.deQueue());i++;}
                }
            }
            else
            {
                while(i<wait0)
                {
                    time0 =time0+(time-bus.deQueue());i++;
                }
                i=0;
                while(i<10-wait0&&i<wait1)
                {
                    time1+=(time-lorry.deQueue());i++;
                }
            }
 
        }
        time+=10;
        i=0;j=0;
 
        }
 
    if(num1!=0&&num0!=0)
    cout<< fixed<<setprecision(3)<<double(time0)/num0<<' '<< fixed<<setprecision(3)<<double(time1)/num1;
    else if(num0==0)  cout<< fixed<<setprecision(3)<<double(num0)<<' '<< fixed<<setprecision(3)<<double(time1)/num1;
    else  cout<<fixed<< setprecision(3)<<double(time0)/num0<<' '<<fixed<< setprecision(3)<<double(num1);
    return 0;
}