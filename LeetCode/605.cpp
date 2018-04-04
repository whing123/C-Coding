/* *题目：
 *  605
 *  Can Place Flowers
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        
        int num = 0;
        
        int start = 0;
        int end = size - 1;
        for(int i = 0 ; i < size; ++i){
            if(flowerbed[i] == 0){
                start = i;
                while(i+1 < size && flowerbed[i+1] == 0){
                    i++;
                }
                end = i;
                
                if(start == 0){
                    start--;
                }
                
                if (end == size-1){
                    end++;
                }
                
                int tmp = end-start+1;
                num += count(tmp);
            }
            
        }
        
        if(num >= n){
            return true;
        }
        
        return false;   
    }
    
    int count(int num){
        if(num < 3){
            return 0;
        }
        
        if(num % 2 == 0){
            return (num-1)/2;
        }
        
        return num/2;
    }
};