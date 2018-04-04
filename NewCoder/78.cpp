/* *题目：
 *  数字在排序数组中出现的次数
 */

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.size() == 0){
            return 0;
        }
        
        int res = 0;
        int firstK = getfirstK(data,k,0,data.size()-1);
        int lastK = getlastK(data,k,0,data.size()-1);
        if(firstK != -1 && lastK != -1){
            res = lastK - firstK + 1;
        }
        
        return res;
    }
    
    int getfirstK(vector<int> data ,int k, int s, int e){
        if(s > e){
            return -1;
        }
        
        int mid = s + (e-s)/2;
        if(data[mid] < k){
            return getfirstK(data,k,mid+1,e);
        }else if(data[mid] > k){
            return getfirstK(data,k,s,mid-1);
        }else if(mid-1 >= s && data[mid-1] == k){
            return getfirstK(data,k,s,mid-1);
        }
        return mid;
    }
    
    int getlastK(vector<int> data ,int k, int s, int e){
        while(s <= e){
            int mid = s + (e-s)/2;
            if(data[mid] < k){
                s = mid + 1;
            }else if(data[mid] > k){
                e = mid - 1;
            }else if(mid+1 <= e && data[mid+1] == k){
                s = mid + 1;
            }else{
                return mid;
            }
        }
        
        return -1;
    }
};