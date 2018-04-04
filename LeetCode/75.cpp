/* *题目：
 *  75
 *  Sort Colors
 */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int i = 0;
        int j = nums.size()-1;
        while(i < j){ // sort 0
            while(i < j && nums[i] == 0){
                i++;
            }
            while(i < j && nums[j] != 0){
                j--;
            }
            if(i < j){
                nums[j] = nums[i];
                nums[i] = 0;
                i++;
                j--;
            }
        }
        
        j = nums.size()-1;
        while(i < j){ // sort 2
            while(i < j && nums[j] == 2){
                j--;
            }
            while(i < j && nums[i] != 2){
                i++;
            }
            if(i < j){
                nums[i] = nums[j];
                nums[j] = 2;
                i++;
                j--;
            }
        }  
    }
};

class Solution {
public:
    void sortColors(int A[], int n) {
        int second=n-1, zero=0;
        for (int i=0; i<=second; i++) {
            while (A[i]==2 && i<second) swap(A[i], A[second--]);
            while (A[i]==0 && i>zero) swap(A[i], A[zero++]);
         }
    }
};