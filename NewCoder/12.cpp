/* *题目：
 *  数串
 * *思路：
 *  
 */

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
 
bool myFunc(string a, string b){
    return a+b > b+a;
}
 
string doIt(vector<string> &tmp){
    sort(tmp.begin(), tmp.end(), myFunc);
    string res;
    for(int i = 0; i < tmp.size(); ++i){
        res += tmp[i];
    }
     
    return res;
}
 
 
int main(){
    int N;
    string num;
     
    while(cin>>N){
        vector<string> nums;
        for(int i = 0; i < N; ++i){
            cin>>num;
            nums.push_back(num);
        }
         
        cout<<doIt(nums)<<endl;
    }
     
    return 0;
}