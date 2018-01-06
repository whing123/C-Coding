/* *题目：
 *  383
 *  Ransom Note
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int size_m = magazine.size();
        int size_r = ransomNote.size();
        vector<int> tmp(size_m,0);
        for(int i = 0, j;i < size_r;i++){
            for(j = 0;j < size_m;j++){
                if(tmp[j] == 0 && magazine[j] == ransomNote[i]){
                    tmp[j] = 1;
                    break;
                }
            }
            if(j == size_m){
                return false;
            }
        }
        return true;
    }
};