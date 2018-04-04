
/*
0和1都是合法表达式
x是合法表达式，(!x)也是
x和y是合法表达式，(x|y)和(x&y)也都是
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

char compute(string s) {
	if (s.size() == 2) { // (!x)
		return s[1] == '0' ? '1' : '0';
	}
	else { // (x|y)和(x&y)
		if (s[1] == '&')
			return '0' + ((s[0] - '0') & (s[2] - '0'));
		if(s[1] == '|')
			return '0' + ((s[0] - '0') | (s[2] - '0'));
	}
}

int main()
{
	
	int N;
	cin >> N;

	int i = 0;
	while (i++ < N) {
		string str;
		cin >> str;

		stack<char> st;
		for (int j = 0; j < str.size(); ++j) {
			if (str[j] == ')') { // 弹出该括号的表达式并计算
				string tmp;
				while (st.top() != '(') {
					tmp = st.top() + tmp;
					st.pop();
				}
				st.pop();
				char ch = compute(tmp);
				st.push(ch); // 压入计算结果
			}
			else { // 正常压栈
				st.push(str[j]);
			}
		}

		cout << st.top() << endl;
	}

	return 0;
}
