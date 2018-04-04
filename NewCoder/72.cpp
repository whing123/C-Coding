/* *题目：
 *  数组中重复的数字
 * *思路：
 *  
 */

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    
    /*
    利用现有数组设置标志，当一个数字被访问过后，可以设置对应位上的数 + n，
    之后再遇到相同的数时，会发现对应位上的数已经大于等于n了，那么直接返回这个数即可
    */
    bool duplicate(int numbers[], int length, int* duplication) {
        for(int i = 0; i < length; ++i){
            int index = numbers[i] % length;
            if(numbers[index] >= length){
                 *duplication = index;
                 return true;
            }
            numbers[index] += length;
        }
        
        return false;
    }
};

bool duplicate(int numbers[], int length, int* duplication) {
    map<int, int> mp;
    for(int i = 0; i < length; ++i){
        if(mp.find(numbers[i]) == mp.end())
            mp[numbers[i]]++;
        else{
            *duplication = numbers[i];
            return true;
        }
    }
    return false;
}
