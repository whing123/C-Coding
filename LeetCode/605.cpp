/* *题目：
 *  605
 *  Can Place Flowers
 * *思路：
    贪心 
 */

// better
// 如果有k个连续0，那么就可以通过(k-1)/2来快速计算出能放的花的数量
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (flowerbed.size() <= 0)
            return false;
        if (flowerbed[0] == 0)
            flowerbed.insert(flowerbed.begin(),0);
        if (flowerbed[flowerbed.size() - 1] == 0)
            flowerbed.push_back(0);

        int sum = 0, count = 0;
        for (int i = 0; i < flowerbed.size(); i++){
            if (flowerbed[i] == 1){
                sum += (count - 1) / 2;
                count = 0;
            }
            else
                count++;
        }
        if(count > 0)
            sum += (count - 1) / 2;

        return sum >= n;
    }
};

// better
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sum = 0;
        int i = 0;
        while(i < flowerbed.size()){
            if(i == 0 && i+1 < flowerbed.size() && flowerbed[i] == 0 && flowerbed[i+1] == 0){ // head
                sum ++;
                i += 2;
            }else if(i > 0 && i+1 < flowerbed.size() && flowerbed[i] == 0 && flowerbed[i+1] == 0 && flowerbed[i-1] == 0 ){ // mid
                sum ++;
                i += 2;
            }else if(i == flowerbed.size()-1 && flowerbed[i] == 0 && flowerbed[i-1] == 0){ // rear
                sum ++;
                i += 2;
            }else {
                i++;
            }
        }
        
        if(flowerbed.size() == 1 && flowerbed[0] == 0){
            sum++;
        }
        
        return sum >= n;
    }
};

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