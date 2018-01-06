/* *题目：
 *  1023
 *  矩阵翻转
 * *思路：
 *  
 * *技法：
 *  
 */

#include<iostream>
using namespace std;
 
void exchange(int &a,int &b)
{
    int tmp;
    tmp=a;
    a=b;
    b=tmp;
}
 
void print(int **ch,int size)
{
    int i,j;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
            cout<<ch[i][j]<<' ';
        cout<<endl;
    }
}
 
 
void roll_0(int **ch,int size)
{
    int i,j,tmp;
    tmp=size/2;
    for(i=0;i<size;i++)
    {
        for(j=0;j<tmp;j++)
        {
            exchange(ch[i][j],ch[i][size-1-j]);
        }
    }
    print(ch,size);
}
 
void roll_1(int **ch,int size)
{
    int i,j,tmp;
    tmp=size/2;
    for(i=0;i<size;i++)
    {
        for(j=0;j<tmp;j++)
        {
            exchange(ch[j][i],ch[size-1-j][i]);
        }
    }
    print(ch,size);
}
 
void roll_2(int **ch,int size)
{
    int i,j;
    for(i=0;i<size-1;i++)
    {
        for(j=i+1;j<size;j++)
        {
            exchange(ch[i][j],ch[j][i]);
        }
    }
    print(ch,size);
 
}
 
int main()
{
    int n,size,dir,i,j,k,**ch;
 
    cin>>n;
    for(i=0;i<n;i++)
    {
        //input
        cin>>size>>dir;
        ch=new int*[size];
        for(j=0;j<size;j++)
        {
            ch[j]=new int[size];
            for(k=0;k<size;k++)
            {
                cin>>ch[j][k];
            }
        }
 
        //roll
        switch(dir)
        {
            case 0:
                roll_0(ch,size);
                for(k=0;k<size;k++)
                {
                    delete [] ch[k];
                }
                delete [] ch;
                break;
            case 1:
                roll_1(ch,size);
                for(k=0;k<size;k++)
                {
                    delete [] ch[k];
                }
                delete [] ch;
                break;
            case 2:
                roll_2(ch,size);
                for(k=0;k<size;k++)
                {
                    delete [] ch[k];
                }
                delete [] ch;
                break;
        }
 
    }
 
    return 0;
}