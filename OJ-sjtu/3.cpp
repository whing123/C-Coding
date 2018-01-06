/* *题目：
 *  1203
 *  link
 * *思路：
 *  
 * *技法：
 *  
 */

#include<iostream>
using namespace std;
 
 
template<class T>
class seqlist
{
    private:
    T *data;
    int len;
    int size;
 
    public:
 
    seqlist(int isize=20000);
    ~seqlist(){delete [] data;}
 
    void clear(){len=0;}
    int length()const{return len;}
    void insert(int i,T x);
    T visit(int i)const;
    void tra()const;
    seqlist<T> operator+(seqlist<T> &z);
    seqlist<T> &operator=(const seqlist<T> &z);
};
 
template<class T>
seqlist<T>::seqlist(int isize)
{
    data=new T[isize];
    size=isize;
    len=0;
}
 
template<class T>
void seqlist<T>::insert(int i,T x)
{
    for(int j=len;j>i;j--) data[j]=data[j-1];
    data[i]=x;
    ++len;
}
 
template<class T>
seqlist<T> seqlist<T>::operator+(seqlist<T> &z)
{
    seqlist<T> tmp;
    int i=0;
    while(i<len)
    {tmp.insert(i,data[i]);i++;}i=0;
    while(i<z.length())
    {tmp.insert(i+len,z.visit(i));i++;}
    return tmp;
}
 
template<class T>
seqlist<T> & seqlist<T>::operator=(const seqlist<T> &z)
{
 
    int i=0;
    while(i<z.length())
    {insert(i,z.visit(i));i++;}
    return *this;
}
 
 
template<class T>
T seqlist<T>::visit(int i)const
{
    return data[i];
}
 
template<class T>
void seqlist<T>::tra()const
{
   for(int i=0;i<len;i++)cout<<data[i]<<' ';
}
 
 
 
int main()
{
    char ch[7];
    int a,b,j=0,xh;
    cin>>ch;
 
    if(ch[0]=='i'&&ch[1]=='n'&&ch[2]=='t')xh=0;
    else if(ch[0]=='d'&&ch[1]=='o'&&ch[2]=='u'&&ch[3]=='b'&&ch[4]=='l'&&ch[5]=='e')xh=1;
    else if(ch[0]=='c'&&ch[1]=='h'&&ch[2]=='a'&&ch[3]=='r')xh=2;
 
 
    switch(xh){
    case 0: {   seqlist<int>  t1,t2,t3;
                int k;
                cin>>a>>b;
                while(j<a)
                {
                    cin>>k;
                    t1.insert(j,k);
                    j++;
                }
                j=0;
                while(j<b)
                {
                    cin>>k;
                    t2.insert(j,k);
                    j++;
                }
                t3=t1+t2;
                j=0;
                while(j<a+b)
                {
                    cout<<t3.visit(j)<<' ';
                    j++;
                }  } break;
    case 1:{    seqlist<double>  t1,t2,t3;
                double k;
                cin>>a>>b;
                while(j<a)
                {
                    cin>>k;
                    t1.insert(j,k);
                    j++;
                }
                j=0;
                while(j<b)
                {
                    cin>>k;
                    t2.insert(j,k);
                    j++;
                }
                t3=t1+t2;
                j=0;
                while(j<a+b)
                {
                    cout<<t3.visit(j)<<' ';
                    j++;
                }  } break;
    case 2:{    seqlist<char>  t1,t2,t3;
                char k;
                cin>>a>>b;
                while(j<a)
                {
                    cin>>k;
                    t1.insert(j,k);
                    j++;
                }
                j=0;
                while(j<b)
                {
                    cin>>k;
                    t2.insert(j,k);
                    j++;
                }
                t3=t1+t2;
                j=0;
                while(j<a+b)
                {
                    cout<<t3.visit(j)<<' ';
                    j++;
                }  } break;
 
    }
}