/* *题目：
 *  1994
 *  二哥的地图
 * *思路：
 *  
 * *技法：
 *  
 */

 #include<iostream>
using namespace std;
 
int k=0;//计数
 
//递归
void search(int **xh,int n,int m,int i,int j) //n,m数组规模,i,j当前位置
{
    if(i-1>=0&&xh[i-1][j]==0) {xh[i-1][j]=xh[i][j];search(xh,n,m,i-1,j);}  //上
    if(i+1<n&&xh[i+1][j]==0) {xh[i+1][j]=xh[i][j];search(xh,n,m,i+1,j);}  //下
    if(j-1>=0&&xh[i][j-1]==0) {xh[i][j-1]=xh[i][j];search(xh,n,m,i,j-1);}  //左
    if(j+1<m&&xh[i][j+1]==0) {xh[i][j+1]=xh[i][j];search(xh,n,m,i,j+1);}  //右
}
 
 
int main()
{
    int n,m,**ch;
    int i,j;
 
    cin>>n>>m;//n,m数组规模
 
    ch=new int*[n];
    for(i=0;i<n;i++)
        ch[i]=new int[m];
 
    for(i=0;i<n;i++)  //input
        for(j=0;j<m;j++)
            cin>>ch[i][j];
    /*
    for(i=0;i<n;i++){
    for(j=0;j<m;j++)
    cout<<ch[i][j]<<' ';cout<<endl;}*/
 
    for(i=0;i<n;i++) //数国家
    for(j=0;j<m;j++)
    {
        if(ch[i][j]==0)
        {
            ch[i][j]=++k;
            search(ch,n,m,i,j);
        }
    }
 
    cout<<k<<endl;//output
 
    /*
    for(i=0;i<n;i++){
    for(j=0;j<m;j++)
    cout<<ch[i][j]<<' ';cout<<endl;}*/
 
    for(i=0;i<n;i++) delete [] ch[i];//释放空间
    delete [] ch;
 
 
    return 0;
}