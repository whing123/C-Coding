/* *题目：
 *  1225
 *  distinct
 * *思路：
 *  
 * *技法：
 *  
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
 
int main()
{
    int n,i=0,*ch,s,p;
    cin>>n;
    ch=new int[n];
    while(i<n)
    {
        cin>>ch[i];
        i++;
    }
    quickSort(ch,n);
 
    p=ch[0];s=1;
    for(i=0;i<n-1;i++)
    {
        if(ch[i+1]>p)
        {s++;p=ch[i+1];}
    }
    cout<<s;
    return 0;
}