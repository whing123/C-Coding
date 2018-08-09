/* *题目：
 *  91
 *  汽水瓶
 */

#include <iostream>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(n == 0){
            break;
        }
        
        int sum = 0;
        while(n > 1){
            if(n == 2){
                sum++;
                break;
            }
            sum += n/3;
            n = n%3 + n/3;
        }
        cout << sum << endl;
    }
    return 0;
}

// 递归
#include <iostream>

using namespace std;

int mostBottles(int n) {
	if (n == 1) {
		return 0;
	}
	if (n == 2) {
		return 1;
	}
	int bottles = n / 3;
	return bottles + mostBottles(n % 3 + bottles);
}

int main() {
	int n;
	while (cin >> n) {
		if (n == 0) {
			break;
		}

		cout << mostBottles(n) << endl;
	}

	return 0;
}