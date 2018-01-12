/* *题目：
 *  集合
 * *思路：
 *  
 */

#include <iostream>
#include <set>
 
using namespace std;
 
int main(){
    int tmp;
    int n, m;
    while(cin >> n >> m){
        set<int> data;
        for(int i = 0; i < n + m; ++i){
            cin >> tmp;
            data.insert(tmp);
        }
         
        int size = data.size()-1;
        set<int>::iterator it;
        for(it = data.begin(); it != data.end(); ++it, --size){
            cout << *it;
            if(size){
                cout << ' ';
            }
        }
        cout << endl;
    }
 
    return 0;
}