/*
 一个由小写字母组成的字符串，删除其中的重复字符。如：abaaabccd，输出abcd。
*/


int q2(string str)
{
    vector<int> count(26, 0);
    string res = "";
    
    for(char &ch : str)
    {
        if(count[ch - 'a'] == 0) // 首次遇到
        {
            count[ch - 'a']++;
            res.append(1, ch);
        }
    }
    
    cout << res << endl;
    return 0;
}