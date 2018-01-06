/* *题目：
 *  1206
 *  pascal
 * *思路：
 *  
 * *技法：
 *  
 */

#include<iostream>
#include<cstring>
 
 
using namespace std;
 
class seqStack              //顺序栈的定义
{
    private:
    int *le;
    int top_p;
    int max;
 
    public:
    seqStack(int init=1000) {le=new int[init];max=init;top_p=-1;}
    ~seqStack() {delete [] le;}
    bool isEmpty()const {return top_p==-1;}
    void push(const int &x) {le[++top_p]=x;}
    int pop() {return le[top_p--];}
    int top()const {return le[top_p];}
};
 
 
 
int main()
{
 
    seqStack st;
    int result,out;
 
    char ch[100];
    int i=0;
 
    while(cin>>ch)
    {
        i=0;
        result =0;
 
        if(strncmp(ch,"begin",5)==0) result=1;
        else if(strncmp(ch,"if",2)==0) result=2;
        else if(strncmp(ch,"then",4)==0) result=3;
        else if(strncmp(ch,"end",3)==0) result=4;
        else if(strncmp(ch,"else",4)==0)result=5;
 
        switch(result)
        {
            case 1:case 2:st.push(result);break;
            case 3:
                   if(st.isEmpty()){cout<<"Error!";return 0;}
                   else
                   {out=st.pop();
                   if(out==2){st.push(2);st.push(result);}
                   else {cout<<"Error!";return 0;}}
                   break;
            case 4:case 5:
            if(st.isEmpty())
                {cout<<"Error!";return 0;}
            else
                {
                    out=st.pop();
                    if(result==4)
                    {
                        if(out==2){cout<<"Error!";return 0;}
                        if(out*result==4) continue;
                        else {
                                while(out!=1)
                                {
                                if(st.isEmpty()){cout<<"Error!";return 0;}
                                out=st.pop();
                                }
                                continue;
                              }
 
                    }
                    if(result==5)
                    {
                    if(out==1||out==2) {cout<<"Error!";return 0;} //else之前是 begin或if
 
                    if(out*result==15) //else之前是then
                    {
                        out=st.pop();
                        if(out==2)
                            continue;
                        else  {cout<<"Error!";return 0;}
                    }}
                }
            break;
        }
 
    }
 
 
     if(st.isEmpty()) cout<<"Match!";
     else cout<<"Error!";
 
    return 0;
}