/* *题目：
 *  447
 *  Number of Boomerangs
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int sizeP = points.size();
        int res = 0;
        for(int i = 0;i < sizeP;i++){
            unordered_map<int,int> distMap;
            for(int j = 0;j < sizeP;j++){
                if(i != j){
                    distMap[getDist(points[i],points[j])]++;
                }
            }
            for(auto x:distMap){
                if(x.second > 1){
                    res += x.second * (x.second - 1);
                }
            }
        }
        return res;
    }
    
    int getDist(pair<int, int>& a, pair<int, int>& b){
        int t1 = a.first - b.first;
        int t2 = a.second - b.second;
        return t1 * t1 + t2 * t2;
    }
};