/*
 根据四个点，判断正方形
*/


#include <iostream>
#include <map>

using namespace std;

int dis(int x1, int y1, int x2, int y2){
    int x = x1-x2;
    int y = y1-y2;
    return x*x+y*y;
}

bool check(int x[], int y[]){
    map<int,int> mp;
    for(int i = 0; i < 3; i++){
        for(int j = i+1; j < 4; j++){
            mp[dis(x[i],y[i],x[j],y[j])]++;
        }
    }
    
    if(mp.size() != 2){
        return false;
    }
    
    map<int,int>::iterator it, it1; 
    it = mp.begin();
    it1 = it;
    it1++;
    if(!(it->second == 4 && it1->second == 2)){
        return false;
    }
    if(it->first * 2 != it1->first){
        return false;
    }
    
    return true;
}

int main(){
    int t;
    cin >> t;
    int i = 0;
    
    int x[4], y[4];
    while(i++ < t){
        for(int i = 0; i < 4; ++i){
            cin >> x[i];
        }
        for(int i = 0; i < 4; ++i){
            cin >> y[i];
        }
        
        if(check(x,y)){
            cout << "Yes" << endl;
        }else{
            cout << "No" <<endl;
        }
    }
    
    return 0;
}