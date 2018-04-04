/* *题目：
 *  225
 *  Implement Stack using Queues
 * *思路：
 *  
 * *技法：
 *  
 */

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        que.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        int size = que.size();
        queue<int> tmp;
        int i = 1; // 从1开始，所以少了最后一个元素
        while(i < size){
            tmp.push(que.front());
            que.pop();
            i++;
        }
        que = tmp;
    }

    // Get the top element.
    int top() {
        return que.back();
    }

    // Return whether the stack is empty.
    bool empty() {
        return que.empty();
    }
private:
    queue<int> que;
};


// best solution
class Stack {
public:
    queue<int> que;
    // Push element x onto stack.
    void push(int x) {
        que.push(x);
        for(int i=0;i<que.size()-1;++i){ // 最新在头，最旧在尾
            que.push(que.front());
            que.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        que.pop();
    }

    // Get the top element.
    int top() {
        return que.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return que.empty();
    }
};