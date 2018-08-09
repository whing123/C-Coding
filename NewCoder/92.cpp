/*
  92
  去重排序
*/

#include <iostream>
#include <set>

using namespace std;

int main(){
    set<int> arr;
    int n;
    while(cin >> n)
    {
        int i = 0;
        while(i++ < n){
            int tmp;
            cin >> tmp;
            arr.insert(tmp);
        }
        
        set<int>::iterator it;
        for(it = arr.begin(); it != arr.end(); it++){
            cout << *it << endl;
        }
        
        arr.clear();
    }
    
    return 0;
}