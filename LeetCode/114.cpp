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
        int i = 1;
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