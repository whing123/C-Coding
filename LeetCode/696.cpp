/* *题目：
 *  696
 *  Count Binary Substrings
 * *思路：
 *  找两段连续的1和0，个数的最小值为符合要求的子串数目。下一次从第二段开始。
 * *技法：
 *  
 */

class Solution {
public:
    int countBinarySubstrings(string s) {
        int size = s.size();
        
        int first_part, second_part;
        int count = 0;
        int j, k;
        for(int i = 0; i < size;){
            first_part = i; // first part starts
            j = first_part;
            while(j < size && s[first_part] == s[j]){ // contiguous search
                j++;
            }
            
            second_part = j; // second part starts
            k = second_part;
            while(j < size && s[second_part] == s[k]){ // contiguous search
                k++;
            }
            
            count += min(j - first_part, k - second_part); // min of two parts. 0000111->000111,0011,01
        
            i = j; // next start
        }
        
        return count;
    }
    
    int min(int a, int b){
        return a < b ? a : b;
    }
};