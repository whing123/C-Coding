/* *题目：
 *  A+B
 * *思路：
 *  给定两个整数A和B，其表示形式是：从个位开始，每三位数用逗号","隔开。 现在请计算A+B的结果，并以正常形式输出
 */

#include <iostream>
#include <string>
using namespace std;
 
int main(){
    string Astr, Bstr;
    while(cin>>Astr>>Bstr){
        for(int i = 0;i < Astr.size();i++){
            if(Astr[i] == ','){
                Astr.erase(i,1);
            }
        }
        for(int i = 0;i < Bstr.size();i++){
            if(Bstr[i] == ','){
                Bstr.erase(i,1);
            }
        }
         
        int A = stoi(Astr);
        int B = stoi(Bstr);
         
        cout<<A+B<<endl;
    }
    return 0;
}