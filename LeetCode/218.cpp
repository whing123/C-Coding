/* *题目：
 *  744
 *  Find Smallest Letter Greater Than Target
 * *思路：
 *  
 */

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int size = letters.size();
        
        for(int i = 0; i < size; ++i){
            if(target < letters[i]){
                return letters[i];
            }
        }
        
        return letters[0];
    }
};