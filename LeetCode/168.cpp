/* *题目：
 *  539
 *  Minimum Time Difference
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(),timePoints.end());  //排序
        int diff = timediff(timePoints[0],timePoints[timePoints.size()-1]);  //比较首尾
        for(int i = 0;i < timePoints.size()-1;i++){  //比较相邻时间点
            int tmp = timediff(timePoints[i],timePoints[i+1]);
            if(tmp < diff){
                diff = tmp;
            }
        }
        
        return diff;
    }
    
    //相邻时间点差异
    int timediff(string &time1, string &time2){
        int hour1,min1,hour2,min2;
        hour1 = stoi(time1.substr(0,2));
        min1 = stoi(time1.substr(3,2));
        hour2 = stoi(time2.substr(0,2));
        min2 = stoi(time2.substr(3,2));
        
        int diff = 0;
        if(hour1 == hour2){
            diff =  abs(min1-min2);
        }else if(hour1 > hour2){
            hour1--;
            min1 += 60;
            diff = (hour1-hour2)*60+(min1-min2);
        }else{
            hour2--;
            min2 += 60;
            diff = (hour2-hour1)*60+(min2-min1);
        }
        
        return min(diff, 1440 - diff);
    }
};