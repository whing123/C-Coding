/* *题目：
 *  求数列的和
 * *思路：
 *  数列的第一项为n，以后各项为前一项的平方根，求数列的前m项的和
 */

#include <iostream>
#include <cmath>
using namespace std;
 
int main(){
    int n, m;
     
    while (cin >> n) {
        cin >> m;
 
        double sum = 0;
        for (int i = 0; i < m; ++i) {
            sum += pow(n, 1.0 / pow(2, i));
        }
 
        printf("%.2f\n", sum);
    }
    return 0;
}