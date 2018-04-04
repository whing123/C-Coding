/* *题目：
 *  包含min函数的栈
 * *思路：
 *  
 */

/*
dataStack为存储数据的栈，minStack为存储最小值的栈；
push的时候将value值与minStack中的top值比较，小则minStack push value，大则push top值
*/

class Solution {
public:
    stack<int> data, min_d;
    void push(int value) {
        data.push(value);
        if(min_d.size() == 0 || value < min_d.top()){
            min_d.push(value);
        }else{
            min_d.push(min_d.top());
        }
    }
    void pop() {
        data.pop();
        min_d.pop();
    }
    int top() {
        return data.top();
    }
    int min() {
        return min_d.top();
    }
};