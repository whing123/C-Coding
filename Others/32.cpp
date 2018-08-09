/*
 32
 分割整数，可以加小数点
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

int getcnt(char* in, int l)
{
    if(l == 1){
        return 1;
    }
    if(in[0] == '0' && in[l-1] == '0'){
        return 0;
    }
    if(in[0] != '0' && in[l-1] != '0'){
        return l;
    }

    // one '0' either front or back
    return 1;
}

int main() {
    char* input = new char[11];
    cin >> input;
    int len = getlen(input);
    int res = 0;
    for(int i = 1; i <= len-1; i++){
        char* a = new char[i];
        for(int j = 0; j < i; j++){
            a[j] = input[j];
        }
        char * b = new char[len - i];
        for(int j = i; j < len; j++)
        {
            b[j-i] = input[j];
        }
        res += getcnt(a, i) * getcnt(b, len-i);
        delete[]a;
        delete[]b;
    }
    cout << res;
    return 0;
}