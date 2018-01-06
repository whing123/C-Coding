/* *题目：
 *  矩阵转置
 * *思路：
 *  输入一个N*N的矩阵，将其转置后输出。要求：不得使用任何数组(就地逆置)
 */

#include <iostream>
 
using namespace std;
 
int main(){
    int N;
    int arr[100][100];
    while(cin>>N){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin>>arr[i][j];
            }
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cout<<arr[j][i];
                if(j < N-1)
                    cout<<' ';
            }
            cout<<endl;  
        }
         
    }
    return 0;
}