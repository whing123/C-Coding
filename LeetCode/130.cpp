/* *题目：
 *  155
 *  Min Stack
 * *思路：
 *  
 * *技法：
 *  
 */

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        head = NULL;
    }
    
    void push(int x) {
        if(!head){
            head = new node(x,x);
            return;
        }
        int m;
        if(x < head->min_val){
            m = x;
        }else{
            m = head->min_val;
        }
        node *tmp = new node(x,m);
        tmp->next = head;
        head = tmp;
    }
    
    void pop() {
        if(head){
            node *tmp = head;
            head = head->next;
            delete tmp;
        }
    }
    
    int top() {
        return head->val; 
    }
    
    int getMin() {
        return head->min_val;
    }
private:
    struct node{
        int val;
        int min_val;
        node *next;
        node(int a, int b):val(a),min_val(b){ 
            next = NULL;
        }
        ~node(){}
    };
    node *head;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */