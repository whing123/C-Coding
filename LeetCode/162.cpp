/* *题目：
 *  454
 *  4Sum II
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int sizeA = A.size();
        int sizeB = B.size();
        int sizeC = C.size();
        int sizeD = D.size();
        int i, j, k, l;
        
        //AB之和建立个map, CD之和建立个map
        unordered_map<int,int> AB;
        unordered_map<int,int>::iterator it1;
        unordered_map<int,int> CD;
        unordered_map<int,int>::iterator it2;
        
        for(i = 0;i < sizeA;i++){
            for(j = 0;j < sizeB;j++){
                AB[A[i]+B[j]]++;
            }
        }
        
        for(k = 0;k < sizeC;k++){
            for(l = 0;l < sizeD;l++){
                CD[0-C[k]-D[l]]++;        
            }
        }
        
        //从AB向CD中查找，若找到，出现次数相乘
        int res = 0;
        for(it1 = AB.begin();it1 != AB.end();it1++){
            if((it2 = CD.find(it1->first)) != CD.end()){
                res += it1->second * it2->second;
            }
        }
        
        return res;
    }
};