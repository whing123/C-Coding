/* *题目：
 *  电话号码分身
 * *思路：
 *  
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
 
int main(){
    int number [10] = {2,3,4,5,6,7,8,9,0,1};
 
    int T;
    cin >> T;
    int i = 0;
    while(i++ < T){
        vector<int> res;
        string s;
        cin >> s;
         
        map<char,int> tmp;
        for(int j = 0; j < s.size(); ++j){
            tmp[s[j]]++;
        }
         
        map<char,int>::iterator it;
        while((it = tmp.find('Z')) != tmp.end() && it->second > 0){
            tmp['Z']--;
            tmp['E']--;
            tmp['R']--;
            tmp['O']--;
             
            res.push_back(number[0]);
        }
 
        while((it = tmp.find('W')) != tmp.end() && it->second > 0){
            tmp['T']--;
            tmp['W']--;
            tmp['O']--;
             
            res.push_back(number[2]);
        }
         
        while((it = tmp.find('U')) != tmp.end() && it->second > 0){
            tmp['F']--;
            tmp['O']--;
            tmp['U']--;
            tmp['R']--;
             
            res.push_back(number[4]);
        }
         
        while((it = tmp.find('O')) != tmp.end() && it->second > 0){
            tmp['O']--;
            tmp['N']--;
            tmp['E']--;
             
            res.push_back(number[1]);
        }
         
        while((it = tmp.find('R')) != tmp.end() && it->second > 0){
            tmp['T']--;
            tmp['H']--;
            tmp['R']--;
            tmp['E']--;
            tmp['E']--;
             
            res.push_back(number[3]);
        }
         
        while((it = tmp.find('F')) != tmp.end() && it->second > 0){
            tmp['F']--;
            tmp['I']--;
            tmp['V']--;
            tmp['E']--;
             
            res.push_back(number[5]);
        }
         
        while((it = tmp.find('X')) != tmp.end() && it->second > 0){
            tmp['S']--;
            tmp['I']--;
            tmp['X']--;
             
            res.push_back(number[6]);
        }
         
        while((it = tmp.find('S')) != tmp.end() && it->second > 0){
            tmp['S']--;
            tmp['E']--;
            tmp['V']--;
            tmp['E']--;
            tmp['N']--;
             
            res.push_back(number[7]);
        }
         
        while((it = tmp.find('G')) != tmp.end() && it->second > 0){
            tmp['E']--;
            tmp['I']--;
            tmp['G']--;
            tmp['H']--;
            tmp['T']--;
             
            res.push_back(number[8]);
        }
         
        while((it = tmp.find('I')) != tmp.end() && it->second > 0){
            tmp['N']--;
            tmp['I']--;
            tmp['N']--;
            tmp['E']--;
             
            res.push_back(number[9]);
        }
         
        sort(res.begin(), res.end());
        for(int j = 0; j < res.size(); ++j){
            cout << res[j];
        }
        cout << endl;
    }
     
    return 0;
}