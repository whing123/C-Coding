/* *题目：
 *  1204
 *  edit
 * *思路：
 *  
 * *技法：
 *  
 */

#include<iostream>
#include<cstring>
using namespace std;
 
class file{
    private:
    char data[100][2000];
 
    public:
    void list(int n1,int n2);
    void ins(int i,int j,char *x);
    void del(int i,int j,int num);
    int len(int i);
    void quit(int row);
 
};
 
void file::list(int n1,int n2)
{
    for(int i=n1-1;i<=n2-1;i++)
    {
        cout<<data[i];
        cout<<endl;
    }
 
}
 
void file::ins(int i,int j,char *x)
{
    int L1=strlen(x),L2=strlen(data[i]);
    if(j==L2)
    {
        int n;
        for(n=0;n<L1;n++) data[i][j+n]=x[n];
        data[i][j+n+1] = '\0';
    }
    else{
    int n=L2-1;
    for(;n>=j;n--) data[i][n+L1]=data[i][n];
    for(n=j;n<j+L1;n++) data[i][n]=x[n-j];}
 
}
 
void file::del(int i,int j,int num)
{
    int c=strlen(data[i]);
    //for(int k=0;k<=c;k++)
    //data[i][j+k]=data[i][j+num+k];
    for (int k = 0; k <= c+1-j;++k)
        data[i][j+k] = data[i][j+k+num];
}
 
int file::len(int i)
{
    return strlen(data[i]);
}
 
void file::quit(int row)
{
    int i=0;
    cout<<data[0];
    for(i=1;i<row;i++)
    {
    cout<<endl;
    cout<<data[i];
    }
}
 
int main()
{
    file piggy;
    char ch[2000]={},xh[100]={},ord[6]={};
    int row=0,i=0,j=0;
 
    //input
    while(1)
    {
        cin.getline(ch,2000,'\n');
        if(ch[0]=='*'&&ch[1]=='*'&&ch[2]=='*'&&ch[3]=='*'&&ch[4]=='*'&&ch[5]=='*'&&ch[6]=='\0')break;
        if(row>100)break;
        piggy.ins(row,0,ch);
        row++;
 
    }
 
    while(1)
    {
    cin>>ord;
 
    if(ord[0]=='q'&&ord[1]=='u'&&ord[2]=='i'&&ord[3]=='t')
    {
        piggy.quit(row);
        break;
    }
 
    else if(ord[0]=='l'&&ord[1]=='i'&&ord[2]=='s'&&ord[3]=='t')
        {
            cin>>i>>j;
            if(i<=j&&i>0&&j>0&&j<=row)
                piggy.list(i,j);
            else cout<<"Error!"<<endl;
        }
    else if(ord[0]=='i'&&ord[1]=='n'&&ord[2]=='s')
            {
                cin>>i>>j;
                cin.getline(xh,100,'\n');
                for(int k=0;k<strlen(xh);k++) xh[k]=xh[k+1];
                if(i>0&&i<=row&&j>0&&j<=piggy.len(i-1)+1)
                    piggy.ins(i-1,j-1,xh);
                else cout<<"Error!"<<endl;
            }
    else if(ord[0]=='d'&&ord[1]=='e'&&ord[2]=='l')
            {
                int num;
                cin>>i>>j>>num;
                if(i>0&&i<=row&&j>=1&&j<=piggy.len(i-1)&&num>=0&&num<=piggy.len(i-1)-j+1)
                {
                    //if(j==1&&num>=piggy.len(i-1))
                    //{cout<<"Error!"<<endl;continue;}
                    piggy.del(i-1,j-1,num);
                }
                else cout<<"Error!"<<endl;
            }
         else  cout<<"Error!"<<endl;
    }
 
    return 0;
}