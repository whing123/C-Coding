/* *题目：
 *  数组中出现次数超过一半的数字
 */

/*
思路一：如果有符合条件的数字，则它出现的次数比其他所有数字出现的次数和还要多。
在遍历数组时保存两个值：一是数组中一个数字，一是次数。遍历下一个数字时，若它与之前保存的数字相同，则次数加1，否则次数减1；
若次数为0，则保存下一个数字，并将次数置为1。遍历结束后，所保存的数字即为所求。然后再判断它是否符合条件即可。
*/
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int num = numbers[0];
        int count = 1;
        for(int i = 1; i < numbers.size(); ++i){
            if(numbers[i] == num){
                count++;
            }else{
                count--;
            }
            if(count == 0){
                num = numbers[i];
                count = 1;
            }
        }
        
        count = 0;
        for(int i = 0; i < numbers.size(); ++i){
            if(numbers[i] == num){
                count++;
            }
        }
        
        return count * 2 >  numbers.size() ? num : 0;
    }
};

/*
思路二：数组排序后，如果符合条件的数存在，则一定是数组中间那个数
*/

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        // 因为用到了sort，时间复杂度O(NlogN)，并非最优
        if(numbers.empty()) return 0;
         
        sort(numbers.begin(), numbers.end()); // 排序，取数组中间那个数
        int middle = numbers[numbers.size() / 2];
         
        int count=0; // 出现次数
        for(int i = 0; i < numbers.size(); ++i)
        {
            if(numbers[i] == middle) ++count;
        }
         
        return (count > numbers.size()/2) ? middle :  0;
    }
};
