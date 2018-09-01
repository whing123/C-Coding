/* *题目：
 *  句子反转
 * *思路：
 *  将句子中的单词位置反转，单词用空格分割, 单词之间只有一个空格，前后没有空格
 */

#include <iostream>
#include <string>
#include <algorithm>
 
using namespace std;
 
int main() {
    string line;
    while (getline(cin, line)) {
        reverse(line.begin(), line.end()); // reverse
         
        int j;
        for (int i = 0; i < line.size();) {
            j = i; // start of current word
            while(j < line.size() && line[j] != ' ') // jump to the next of the end of current word
                ++j; 

            reverse(line.begin() + i, line.begin() + j); // reverse current word
            i = j + 1;
        }
 
        cout << line << endl;
    }
 
    return 0;
}