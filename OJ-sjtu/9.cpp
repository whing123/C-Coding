/* *题目：
 *  1024
 *  排序
 * *思路：
 *  
 * *技法：
 *  
 */

#include<iostream>
using namespace std;
 
void simpleSelectSort(int ch[],int size)
{
    int i,j,k,tmp;
    for(i=0;i<size-1;i++)
    {
        k=i;
        for(j=i+1;j<size;j++)
            if(ch[j]<ch[k])
                k=j;
        tmp=ch[i];
        ch[i]=ch[k];
        ch[k]=tmp;
        cout<<ch[i]<<' ';
    }
    cout<<ch[size-1];
 
}
 
int main()
{
    int num;
    cin>>num;
    int *numset=new int[num],i;
    for(i=0;i<num;i++)
    {
        cin>>numset[i];
    }
    simpleSelectSort(numset,num);
    delete numset;
    numset=NULL;
    return 0;
}