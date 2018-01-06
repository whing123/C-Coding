/* *题目：
 *  278
 *  First Bad Version
 * *思路：
 *  
 * *技法：
 *  
 */

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        int mid;
        while(1){
            mid = ((long)left + right) / 2;
            if(isBadVersion(mid) && !isBadVersion(mid-1)){
                break;
            }else if(!isBadVersion(mid)){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return mid;
    }
};