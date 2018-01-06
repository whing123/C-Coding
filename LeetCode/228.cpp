/* *题目：
 *  648
 *  Replace Words
 * *思路：
 *  
 */

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        sort(dict.begin(),dict.end()); // prepare for removing
        vector<string> new_dict;
        new_dict.push_back(dict[0]);
        for(int i = 1, j = 0; i < dict.size(); ++i){
            if(dict[i].find(dict[j]) != 0){ // remove the one with another as its prefix
                new_dict.push_back(dict[i]);
                j = i;
            }
        }
        
        
        for(int i = 0; i < new_dict.size(); ++i){
            int pos = 0;
            while((pos = sentence.find(new_dict[i], pos)) != string::npos){
                if(pos == 0 || (pos > 0 && sentence[pos-1] == ' ')){ // check the beginning
                    int j = 0;
                    // find the end of this word
                    while(pos+new_dict[i].length()+j < sentence.length() && sentence[pos+new_dict[i].length()+j] != ' '){
                        ++j;
                    }
                    if(j > 0){
                        sentence.replace(pos, new_dict[i].length()+j, new_dict[i]); // replace
                    }
                }
                
                ++pos; // not to replace itself
                if(pos >= sentence.length()){
                    break;
                }
            }
        }
        
        return sentence;
    }
};