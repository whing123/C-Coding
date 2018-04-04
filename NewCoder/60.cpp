/* *题目：
 *  字符流中第一个只出现一次的字符
 * *思路：
 *  
 */

class Solution
{
public:
    //Insert one char from stringstream
    void Insert(char ch)
    {
        data.push_back(ch);
        mp[ch]++;
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        vector<char>::iterator it;
        for(it = data.begin(); it != data.end(); it++){
            if(mp[*it] == 1){
                return *it;
            }
        }
         
        return '#';
    }
public:
    vector<char> data;
    map<char, int> mp;
};