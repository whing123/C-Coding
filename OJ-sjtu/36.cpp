/* *题目：
 *  1005
 *  数独
 */

#include<iostream>
using namespace std;
 
int divide(int a[],int low,int high)
{
    int k=a[low];
    do{while(low<high&&a[high]>=k)--high;
        if(low<high){a[low]=a[high];++low;}
        while(low<high&&a[low]<=k)++low;
        if(low<high){a[high]=a[low];--high;}
    }while(low!=high);
    a[low]=k;
    return low;
}

void quickSort(int a[],int low,int high)
{
    int mid;
    if(low>=high)return;
    mid=divide(a,low,high);
    quickSort(a,low,mid-1);
    quickSort(a,mid+1,high);
}
 
void quickSort(int a[],int size)
{
    quickSort(a,0,size-1);
}
 
void check(int a[9][9])
{
    int xh[9];
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
            xh[j]=a[i][j];
        quickSort(xh,9);
        for(int k=0;k<8;k++)
            if(xh[k]==xh[k+1])
            {
                cout<<"Wrong"<<endl;
                return;
            }
    }
 
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
            xh[j]=a[j][i];
        quickSort(xh,9);
        for(int k=0;k<8;k++)
            if(xh[k]==xh[k+1])
            {
                cout<<"Wrong"<<endl;
                return;
            }
    }
 
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            xh[0]=a[3*i][3*j];xh[1]=a[3*i][3*j+1];xh[2]=a[3*i][3*j+2];
            xh[3]=a[3*i+1][3*j];xh[4]=a[3*i+1][3*j+1];xh[5]=a[3*i+1][3*j+2];
            xh[6]=a[3*i+2][3*j];xh[7]=a[3*i+2][3*j+1];xh[8]=a[3*i+2][3*j+2];
            quickSort(xh, 9);
            for(int k=0;k<8;k++)
            if(xh[k]==xh[k+1])
            {
                cout<<"Wrong"<<endl;
                return;
            }
        }
 
 
    cout<<"Right"<<endl;
}
 
 
int main()
{
    int n,i=0,j=0,k=0,ch[9][9];
 
    cin>>n;
    while(i<n)
    {
        for(j=0;j<9;j++)
            for(k=0;k<9;k++)
                cin>>ch[j][k];
        check(ch);
        i++;
        cout<<endl;
 
    }
 
    return 0;
}