/*
微软
来信通知
*/

void dfs(int n, char* s, vector<int>& v, vector<int>& vc, int i){
	if(i-1 >= 0 && v[i-1] == 0){
		v[i-1] = 1;
	}
	if(i-2 >= 0 && v[i-2] == 0){
		v[i-2] = 1;
	}
	if(i+1 < n && v[i+1] == 0){
		v[i+1] = 1;
	}
	if(i+2 < n && v[i+2] == 0){
		v[i+2] = 1;
	}

	if(i-1 >= 0 && s[i-1] == 'c' && vc[i-1] == 0){
		vc[i-1] = 1;
		dfs(n,s,v,vc,i-1);
	}
	if(i-2 >= 0 && s[i-2] == 'c' && vc[i-2] == 0){
		vc[i-2] = 1;
		dfs(n,s,v,vc,i-2);
	}
	if(i+1 < n && s[i+1] == 'c' && vc[i+1] == 0){
		vc[i+1] = 1;
		dfs(n,s,v,vc,i+1);
	}
	if(i+2 < n && s[i+2] == 'c' && vc[i+2] == 0){
		vc[i+2] = 1;
		dfs(n,s,v,vc,i+2);
	}
}

char* annoncement(int numOfNeighbors, string c){
	int n = numOfNeighbors;
	char* s = new char[n+1];
	strcpy(s, c.c_str());

	vector<vector<int>> res;
	int index = 0;
	int max_index = 0;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == 'c'){
			index++;

			vector<int> v(n,0);
			vector<int> vc(n,0);
			v[i] = 1;
			vc[i] = 1;
			dfs(n,s,v,vc,i);

			int sum = 0;
			for(int j = 0; j < n; j++){
				if(v[j] == 1){
					sum++;
				}
			}
			if(sum > cnt){
				cnt = sum;
				max_index = index;
			}
			res.push_back(v);
		}
	}

	s[n] = '\0';
	if(index == 0){
		for(int i = 1; i < n; i++){
			r[i] = 'U';
		}
		r[0] = 'I';
	}else{
		for(int i = 0; i < n; i++){
			r[i] = (res[max_index-1][i] == 1) ? 'I' : 'U';
		}
	}

	return s;
}