/* *题目：
 *  字符串最后一个单词的长度
 * *思路：
 *  
 */

#include<iostream>
#include<string>
using namespace std;
 
string split(string &str) 
{ 
    string::size_type pos, pre = 0;   
    int size=str.size(); 
     
    for(int i=0; i<size; i++) 
    { 
        pos = str.find(' ',i); 
        if(pos != string::npos) 
        { 
            while(str[pos+1] == ' '){  //跳过多个空格
                pos++;
            }
            i = pos + 1;  //最后一个空格的下一个字符位置
            pre = i;
        }else{
            break;
        } 
    } 
     
    string res = str.substr(pre,string::npos);  //截取最后一个单词
    return res; 
}
 
int main(){
    string in;
    getline(cin,in); //输入整行
     
    int size = in.size();
    int i = size-1;
    while(in[i] == ' '){  //剔除末尾空格
        in.erase(i,1);
        i--;
    }
     
    cout<<split(in).size();
    return 0;
}


#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    while(getline(cin,s)){
        int n=0, flag=1;
        for(int i = s.length()-1; i >= 0; --i){//倒着计算
            if(flag && s[i]==' '){//如果末尾有空格，先清除末尾空格
                continue;
            }
            else if(s[i] != ' '){
                flag = 0;
                ++n;
            }
            else{
                break;
            }
        }
        cout << n << endl;
    }
    return 0;
}