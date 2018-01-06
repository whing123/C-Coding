/* *题目：
 *  最大和
 * *思路：
 *  在一个N*N的数组中寻找所有横，竖，左上到右下，右上到左下，四种方向的直线连续D个数字的和里面最大的值
 */

#include <iostream>
#include <algorithm>
#include <limits.h>
 
using namespace std;
 
int max_arr(int a[],int n,int num) {
    int res = -1;
    if (n >= num) {
        res = 0;
        for (int i = 0; i < num; i++) {
            res += a[i];
        }
 
        int n_num = n - num;
        int tmp = res;;
        for (int j = 0; j < n_num; j++) {
            tmp += a[num + j];
            tmp -= a[j];
            if (tmp > res) {
                res = tmp;
            }
        }
    }
    return res;
}
 
int search_heng(int **a,int n,int num) {
    int res = INT_MIN;
    int tmp;
    for (int i = 0; i < n; i++) {
        //每一行
        tmp = max_arr(a[i], n, num);
        if (tmp > res) {
            res = tmp;
        }
    }
 
    return res;
}
 
int search_shu(int **a, int n, int num) {
    int res = INT_MIN;
    int tmp;
    int *new_arr = new int[n];
    for (int i = 0; i < n; i++) {
        //每一列
        for (int j = 0; j < n; j++) {
            new_arr[j] = a[j][i];
        }
        tmp = max_arr(new_arr, n, num);
        if (tmp > res) {
            res = tmp;
        }
    }
    delete[] new_arr;
    return res;
}
 
int search_zuoshang(int **a, int n, int num) {
    int res = INT_MIN;
    int *new_arr = new int[n];
 
    //对角
    for (int i = 0; i < n; i++) {
        new_arr[i] = a[i][i];
    }
    res = max_arr(new_arr, n, num);
 
    int cur = n - 1;
    int i;
    int tmp;
    //右侧
    while (cur >= num) {
        i = n - cur;
        for (int j = 0; j < cur; j++)//行
        {
            new_arr[j] = a[j][j + i];
        }
        tmp = max_arr(new_arr, cur, num);
        if (tmp > res) {
            res = tmp;
        }
        cur--;
    }
 
    //左侧
    cur = n - 1;
    while (cur >= num) {
        i = n - cur;
        for (int j = 0; j < cur; j++)//行
        {
            new_arr[j] = a[j + i][j];
        }
        tmp = max_arr(new_arr, cur, num);
        if (tmp > res) {
            res = tmp;
        }
        cur--;
    }
    delete[] new_arr;
    return res;
}
 
int search_youshang(int **a, int n, int num) {
    int res = INT_MIN;
    int *new_arr = new int[n];
 
    //对角
    for (int i = 0; i < n; i++) {
        new_arr[i] = a[i][n-1-i];
    }
    res = max_arr(new_arr, n, num);
     
    int cur = n - 1;
    int i;
    int tmp;
    //上侧
    while (cur >= num) {
        for (int j = 0; j < cur; j++)//行
        {
            new_arr[j] = a[j][cur-1-j];
        }
        tmp = max_arr(new_arr, cur, num);
        if (tmp > res) {
            res = tmp;
        }
        cur--;
    }
 
    //下侧
    cur = n - 1;
    while (cur >= num) {
        i = n - cur;
        for (int j = 0; j < cur; j++)//行
        {
            new_arr[j] = a[i+j][n-1-j];
        }
        tmp = max_arr(new_arr, cur, num);
        if (tmp > res) {
            res = tmp;
        }
        cur--;
    }
    delete[] new_arr;
    return res;
}
 
 
int main()
{
    int N, D;
    int **arr = NULL;
    cin >> N >> D;
    arr = new int*[N];
    for (int i = 0; i < N; i++) {
        arr[i] = new int[N];
    }
 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
 
    int result = max(max(max(search_heng(arr, N, D), search_shu(arr, N, D)), search_zuoshang(arr, N, D)), search_youshang(arr, N, D));
 
    cout << result;
    for (int i = 0; i < N; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}