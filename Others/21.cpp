/* *题目：
 *  滑动窗口最大值最小值
 */

#include<iostream>
#include<vector>
#include<deque>
using namespace std;

// size 区间长度
vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
    vector<int> maxValue;
    if (num.size() >= size && size >= 1)
    {
        deque<int> index;
        // 初始化
        for (unsigned int i = 0; i < size; i++)
        {
            while (!index.empty() && num[i] >= num[index.back()])      
                index.pop_back();
            index.push_back(i);
        }
        for (unsigned int i = size; i < num.size(); ++i)
        {
            maxValue.push_back(num[index.front()]);             
            while (!index.empty() && num[i] >= num[index.back()])     
                index.pop_back();
            if (!index.empty() && index.front() <= (int)(i - size))  
                index.pop_front();
            index.push_back(i);
        }
        maxValue.push_back(num[index.front()]);              
    }
    return maxValue;
}

vector<int> minInWindows(const vector<int>& num, unsigned int size)
{
    vector<int> maxValue;
    if (num.size() >= size && size >= 1)
    {
        deque<int> index;
        // 初始化
        for (unsigned int i = 0; i < size; i++)
        {
            while (!index.empty() && num[i] <= num[index.back()])    
                index.pop_back();
            index.push_back(i);
        }
        for (unsigned int i = size; i < num.size(); ++i)
        {
            maxValue.push_back(num[index.front()]);             
            while (!index.empty() && num[i] <= num[index.back()])    
                index.pop_back();
            if (!index.empty() && index.front() <= (int)(i - size))  
                index.pop_front();
            index.push_back(i);
        }
        maxValue.push_back(num[index.front()]);                          
    }
    return maxValue;
}


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> max_ = maxInWindows(v, k);
    vector<int> min_ = minInWindows(v, k);

    for (int i = 0; i < max_.size(); i++) {
        cout << max_[i] - min_[i];
        if (i < max_.size()-1) {
            cout << ' ';
        }
        else {
            cout << endl;
        }
    }
    
    return 0;
}