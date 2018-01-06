/* *题目：
 *  好多鱼
 * *思路：
 *  
 */

#include<iostream>
#include<cmath>
using namespace std;
 
int main(){
    int minSize, maxSize, n, fishsize, count = 0;
    int size[1001] = { 0 };
    cin >> minSize >> maxSize >> n;
    for (int i = 1; i <= n; i++){
        cin >> fishsize;
        for (int j = 2 * fishsize; j <= maxSize && j <= 10 * fishsize; j++)
            size[j] = 1;
        for (int j = fishsize / 2; j >= minSize && j >= ceil(fishsize / 10.0); j--)
            size[j] = 1;
    }
    for (int i = minSize; i <= maxSize; i++)
        if (size[i] == 0)
            count++;
    cout << count;
    return 0;
}
