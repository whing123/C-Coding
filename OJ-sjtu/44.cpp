/* *题目：
 *  1025
 *  水枪灭火
 * *思路：
 *  
 * *技法：
 *  
 */

#include<stdio.h>
#include<stdlib.h>
 
struct node{
    int start,end;
    struct node *next;
};
 
void exchange(int *a,int *b)
{
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}
 
int main()
{
    int n,i,s,e;
    struct node *head=(struct node *)malloc(sizeof(struct node)),*pnew,*p,*q;
    head->next=NULL;
 
    //输入个数
    scanf("%d",&n);
 
    //建立链表
    for(i=0;i<n;i++)
    {
        scanf("%d",&s);
        scanf("%d",&e);
        if(s>e)
            exchange(&s,&e);
        if(s==e)
            continue;
 
        p=head->next;
        q=head;
        while(p!=NULL&&p->start<s)
        {
            q=p;
            p=p->next;
        }
 
        if(p==NULL)//没有节点或走到最后一个
        {
            if(q==head||(q!=head&&q->end < s))
            {
                struct node *pnew=(struct node *)malloc(sizeof(struct node));
                pnew->start=s;
                pnew->end=e;
                pnew->next=NULL;
                q->next=pnew;
            }
            else
            {
                if(e>q->end)
                    q->end=e;
            }
        }
        else
        {
            if(p->start==s) //s == p->start
                goto back;
            else //s < p->start && s > q->start
            {
                if(q==head)
                {
             front: if(e<p->start)
                    {
                        struct node *pnew=(struct node *)malloc(sizeof(struct node));
                        pnew->start=s;
                        pnew->end=e;
                        pnew->next=p;
                        q->next=pnew;
                    }
                    else
                    {
                        p->start=s;
                   back:if(e>p->end)
                        {
                            p->end=e;
                            while(p->next!=NULL)
                            {
                                p=p->next;
                                if(p->start>e)
                                    break;
                                else
                                    p->start=e;
                                if(p->end>=e)
                                    break;
                                else
                                    p->end=e;
 
                            }
                        }
 
                    }
                }
                else
                {
                    if(e>q->end)
                    {
                        if(s<=q->end)
                        {
                            q->end=e;
                            if(e>=p->start)
                            {
                                p->start=e;
                                goto back;
                            }
                        }
                        else
                        {
                            goto front;
                        }
 
                    }
 
                }
            }
        }
 
        p=head->next;
        q=head;
        while(p!=NULL)
        {
            if(p->start == p->end)
            {
                q->next=p->next;
                free(p);
                p=q->next;
                continue;
            }
            q=p;
            p=p->next;
        }
 
    }
 
    struct node *opt;
    int sum=0;
    for(opt=head,head=head->next;head!=NULL;head=head->next)
    {
        free(opt);
        sum+=head->end-head->start;
        opt=head;
    }
 
    printf("%d",sum);
 
    free(opt);
 
    return 0;
}
