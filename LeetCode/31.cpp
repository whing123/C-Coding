/* *题目：
 *  492
 *  Construct the Rectangle
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> res;
        int length = sqrt(area);  //从平方根作为起点
        while(area % length != 0){  //找到第一个能整除的
            length++;
        }
        int width = area / length;
        if(length < width){  //检查长宽大小
            int tmp = length;
            length = width;
            width = tmp;
        }
        res.push_back(length);
        res.push_back(width);
        return res;
    }
};