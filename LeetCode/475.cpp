/* *题目：
 *  475
 *  Heaters
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int houseSize = houses.size();
        int heatSize = heaters.size();
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int j = 0;
        int dMax = 0;
        for(int i = 0;i < houseSize;i++){ //对于每个house都找离自己最近的heater，计算距离，然后更新之
            while(j < heatSize-1 && abs(heaters[j+1]-houses[i]) <= abs(heaters[j]-houses[i])){ // 高-低-高
                j++;
            }
            dMax = max(dMax,abs(heaters[j]-houses[i]));
        }
        return dMax;
    }
};