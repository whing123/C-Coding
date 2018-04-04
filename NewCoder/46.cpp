/* *题目：
 *  判断数组是不是某二叉搜索树的后序遍历
 * *思路：
 *  
 */

/*
BST的后序序列的合法序列是，对于一个序列S，最后一个元素是x （也就是根），
如果去掉最后一个元素的序列为T，那么T满足：T可以分成两段，前一段（左子树）小于x，
后一段（右子树）大于x，且这两段（子树）都是合法的后序序列。
*/

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size() == 0){
            return false;
        }
        
        return helper(sequence);
    }
    
    bool helper(vector<int> sequence){
        int size = sequence.size();
        if(size == 0){
            return true;
        }
        
        // 寻找大于根的第一个index
        int index = -1;
        for(int i = 0; i < size-1; ++i){
            if(sequence[i] > sequence[size-1]){
                index = i;
                break;
            }
        }
        // 出现大于根的，检查其右侧是否都大于根
        if(index > -1){
            for(int i = index; i < size-1; ++i){
                if(sequence[i] < sequence[size-1]){
                    return false;
                }
            }
        }
        
        // 都小于根的话，范围处理
        if(index == -1){
            index = size-1;
        }
        vector<int> l_seq(sequence.begin(), sequence.begin()+index);
        vector<int> r_seq(sequence.begin()+index, sequence.end()-1);
        
        return helper(l_seq) && helper(r_seq);
    }
};