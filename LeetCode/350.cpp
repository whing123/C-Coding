/* *题目：
 *  350
 *  Intersection of Two Arrays II
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> num1Map, num2Map;
        vector<int> result;
        int sizeOfN1 = nums1.size(), sizeOfN2 = nums2.size();
        for(int i = 0;i < sizeOfN1;i++){
            if(num1Map.count(nums1[i])){
                num1Map[nums1[i]]++;
                continue;
            }
            num1Map.insert(pair<int,int>(nums1[i],1));
        }
        for(int i = 0;i < sizeOfN2;i++){
            if(num2Map.count(nums2[i])){
                num2Map[nums2[i]]++;
                continue;
            }
            num2Map.insert(pair<int,int>(nums2[i],1));
        }
        
        map<int,int>::iterator it;
        for(map<int,int>::iterator it1 = num1Map.begin();it1 != num1Map.end();it1++){
            if((it = num2Map.find(it1->first)) != num2Map.end()){
                result.insert(result.end(),it1->second > it->second ? it->second : it1->second,it1->first);
            }
        }
        return result;
    }
};