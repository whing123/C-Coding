/* *题目：
 *  1007
 *  二哥领工资
 * *思路：
 *  
 * *技法：
 *  
 */

#include<iostream>
using namespace std;
 
class linklist
{
	private:
		struct node
		{
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
		linklist(){head=new node;len=0;}
		~linklist();
		void insert(int x);
		int remove(int i);
};
 
linklist::~linklist()
{
	node *p=head,*q;
	while(p!=NULL)
	{
		q=p;
		p=p->next;
		delete q;
	}
}
 
void linklist::insert(int x)
{
	node *p=new node(x,head->next);
	head->next=p;
	len++;
}
 
int linklist::remove(int i)
{
	node *p=move(i-1),*q;
	int v;
	if(p->next==NULL)return -1;
	q=p->next;
	v=q->data;
	p->next=q->next;
	delete q;
	return v;
}
 
linklist::node *linklist::move(int i)const
{
	node *p=head->next;
	if(i==0) return head;
	for(int j=1;j<i;j++)
		p=p->next;
	return p;
}
 
int main()
{
    char ch;
    linklist a,b,c;
    int i=0,j=0,k=0,s;
    while(1)
    {
        cin.get(ch);
        if(ch!='\n'&&ch!='.')
            a.insert(ch-'0');
        else if(ch=='.')
                continue;
        else break;
    }
    while(1)
    {
        cin.get(ch);
        if(ch!='\n'&&ch!='.')
            b.insert(ch-'0');
        else if(ch=='.')
                continue;
        else break;
    }
    int count=0;
    while(1)
    {
        i=a.remove(1);j=b.remove(1);
        if(i<0&&j<0&&k==0)
        {
            int cnt=0;
            while((s=c.remove(1))>=0)
            {
                cout<<s;cnt++;
                if(cnt==count-2)cout<<'.';
            }
            break;
        }
        if(i<0)i=0;
        if(j<0)j=0;
        s=i+j+k;
        if(s>9)
        {
            s=s-10;
            k=1;
        }
        else k=0;
        c.insert(s);
        count++;
    }
    return 0;
}