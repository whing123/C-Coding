/* *题目：
 *  169
 *  Majority Element
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
    struct NumCount{
        int num;
        int count;
        NumCount(int n = 0, int c = 0):num(n),count(c){}
        ~NumCount(){}
    };
public:
    int majorityElement(vector<int>& nums) {
        vector<NumCount> counter;
        int size = nums.size();
        for(int i = 0;i < size;i++){
            if(!exist(counter,nums[i])){
                counter.push_back(NumCount(nums[i],1));
            }
        }
        
        size = counter.size();
        int maxIndex, maxCount = 0;
        for(int i = 0;i < size;i++){
            if(counter[i].count > maxCount){
                maxCount = counter[i].count;
                maxIndex = i;
            }
        }
        return counter[maxIndex].num;
    }
    
    bool exist(vector<NumCount> &c,int number){
        int size = c.size();
        for(int i = 0;i < size;i++){
            if(number == c[i].num){
                c[i].count++;
                return true;
            }
        }
        return false;
    }
};