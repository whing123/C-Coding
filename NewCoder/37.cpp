/* *题目：
 *  两个栈来实现一个队列
 * *思路：
 *  
 */

// 栈A用来作入队列
// 栈B用来出队列，当栈B为空时，栈A全部出栈到栈B，栈B再出栈

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        
        int res = stack2.top();
        stack2.pop();
        
        return res;
    }

private:
    stack<int> stack1; // 负责入队
    stack<int> stack2; // 负责出队
};