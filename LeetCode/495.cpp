/* *题目：
 *  495
 *  Teemo Attacking
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int size = timeSeries.size();
        int res = 0;
        
        int start, end;
        int i = 0;
        while(i < size){
            //新的起始点
            start = timeSeries[i];
            end = timeSeries[i] + duration;
            //是否可以融合下一点
            while(i+1 < size &&timeSeries[i] + duration >= timeSeries[i+1]){
                end = timeSeries[i+1] + duration;  //终点延长
                i++;
            }
            res += end - start;
            i++;
        }
        
        return res;
    }
};