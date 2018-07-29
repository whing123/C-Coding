/*
成长值 任务值
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>

using namespace std;

struct m1 {
	int start;
	int end;
	int val;
	m1(int s, int e, int v) :start(s), end(e), val(v) {}
};

struct m2 {
	int day;
	int val;
	m2(int d, int v) :day(d), val(v) {}
};

int main() {
	vector<m1> M1;
	vector<m2> M2;
	int n;
	cin >> n;
	int s, e, v, d;
	int x;

	int max_d = 0;
	int min_d = INT_MAX;
	for (int i = 0; i < n; i++) {
		cin >> x;

		if (x == 1) {
			cin >> s >> e >> v;
			M1.push_back(m1(s, e, v));
			max_d = max(max_d, e);
			min_d = min(min_d, s);
		}else {
			cin >> d >> v;
			M2.push_back(m2(d, v));
			max_d = max(max_d, d);
			min_d = min(min_d, d);
		}
	}

	vector<int> vec(max_d + 1, 0);
	for (m1 &a : M1) {
		for (int i = a.start; i <= a.end; i++) {
			if (vec[i] > 0) {
				vec[i] = max(vec[i], a.val);
			else {
				vec[i] =  a.val;
			}
		}
	}

	for (m2 &a : M2) {
		vec[a.day] += a.val;
	}

	int res = 0;
	for (int i = min_d; i <= max_d; i++) {
		res += vec[i];
	}

	cout << res << endl;

	return 0;
}


#include <iostream>
#include <map>

using namespace std;

int main(){
    map<int, int> m1;
    map<int, int> m2;
    
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int key;
        cin >> key;
        if(key == 1){
            int start, end, val;
            cin >> start >> end >> val;
            for(int i = start; i <= end; i++){
                if(m1.count(i)){
                    if(m1[i] < val) 
                    	m1[i] = val;
                }else{
                    m1[i] = val;
                }
            }
        }else{ // 2
            int day, val;
            cin >> day >> val;
            if(m2.count(day)) 
            	m2[day] += val;
            else 
            	m2[day] = val;
        }
    }
    
    int res = 0;
    for(auto &p : m1){
        res += p.second;
    }
    
    for(auto &p :m2){
        res += p.second;
    }
    cout<<res<<endl;
    
    return 0;
}