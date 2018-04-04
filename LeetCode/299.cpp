/* *题目：
 *  299
 *  Bulls and Cows
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    string getHint(string secret, string guess) {
        int len = secret.length();
        int a = 0, b = 0;
        int i, j;
        char tmp[5];
        
        for(i = 0;i < len;i++)
        {
            if(secret[i] == guess[i])
            {
                secret[i] = '.';
                guess[i] = '.';
                a++;
            }
        }
        
        for(i = 0;i < len;i++)
        {
            for(j = 0;secret[i] != '.' &&  j < len;j++)
            {
                if(guess[j] != '.' && secret[i] == guess[j])
                {
                    secret[i] = '.';
                    guess[j] = '.';
                    b++;
                }
            }
        }
        
        sprintf(tmp,"%dA%dB",a,b);
        string t(tmp);
        
        return t;
    }
};