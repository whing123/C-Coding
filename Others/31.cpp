/*
 31
 将字符串打印成正方形
*/

#include <iostream>
using namespace std;

int getlen(char* in){
    int res = 0;
    while(in[res] != '\0'){
        res++;
    }
    return res;
}

int main() {
    char* input = new char[401];
    cin >> input;
    int len = getlen(input);

    char** tmp = new char*[4];
    for(int i = 0; i < 4; i++)
    {
        tmp[i] = new char[len/4];
        for(int j = 0; j < len/4; j++)
        {
            tmp[i][j] = input[i * len/4 + j];
        }
    }

    // first line
    for(int i = 0; i < len/4; i++)
    {
        cout << tmp[0][i];
    }
    cout << tmp[1][0] << endl;

    // mid
    for(int i = 0; i < len/4-1; i++)
    {
        cout << tmp[3][len/4-1-i];
        for(int j = 0 ; j < len/4-1; j++){
            cout << ' ';
        }
        cout << tmp[1][i+1] << endl;
    }

    // last line
    cout << tmp[3][0];
    for(int i = 0 ; i < len/4; i++){
        cout << tmp[2][len/4-1-i];
    }

    for(int i = 0; i < 4; i++){
        delete[]tmp[i];
    }
    delete[]tmp;

    return 0;
}