/* *题目：
 *  温度置信区间
 */

#include<iostream>
using namespace std;

int main(){
    int n, k;
    cin >> n >>k;

    int arr[101]={0};
    int i = 0;
    while(i++ < n){
        int a, b;
        cin >> a >> b;
        for(int j = a; j <= b; j++){
            arr[j+50]++;
        }
    }
    
    bool find=false;
    for(int i = 0; i < 101; i++){
        if(arr[i] >= k){
            cout << i-50 <<' ';
            find = true;
            break;
        }
    }
    
    if(!find){
        cout << "error"<<endl;
    }else{
        for(int i = 100; i >= 0;i--){
            if(arr[i] >= k){
                cout << i-50 << endl;
                break;
            }
        }
    }
    
    return 0;
}
