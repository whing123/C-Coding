/* *题目：
 *  748
 *  Shortest Completing Word
 * *思路：
 *  
 */

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        map<char,int> plate;
        map<char,int>::iterator it;
        
        // make a map
        for(int i = 0; i < licensePlate.size(); ++i){
            if('a' <= licensePlate[i] && licensePlate[i] <= 'z'){
                plate[licensePlate[i]]++;
            }else if('A' <= licensePlate[i] && licensePlate[i] <= 'Z'){
                plate[licensePlate[i]+32]++;
            }
        }
        
        
        vector<string> res; // answers
        int minLength = 16; // min len
        
        for(int i = 0; i < words.size(); ++i){
            map<char,int> tmp;
            map<char,int>::iterator its;
            
            // make a map
            for(int j = 0; j < words[i].size(); ++j){
                tmp[words[i][j]]++;
            }
            
            bool flag = true;
            for(it = plate.begin(); it != plate.end(); ++it){
                if((its = tmp.find(it->first)) != tmp.end()){
                    if(it->second > its->second){ // less num in words[i]
                        flag = false;
                        break;
                    }
                }else{ // not found in words[i]
                    flag = false;
                    break;
                }
            }
            
            if(flag){ // ok
                res.push_back(words[i]);
                if(words[i].length() < minLength){ // find min len
                    minLength = words[i].length();
                }
            }
        }
        
        for(int i = 0; i < res.size(); i++){
            if(res[i].length() == minLength){
                return res[i];
            }
        }
        
        return "";
    }
};