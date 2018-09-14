/* *题目：
 *  字符串的排列
 */

class Solution {
public:
    vector<string> Permutation(string str) {
        if(str.size() == 0)
            return array;
		
		vector<string> array;
        Permutation(array, str, 0);
        sort(array.begin(), array.end());

        return array;
    }
     
    void Permutation(vector<string> &array, string str, int begin) // 遍历第begin位的所有可能性
    {
        if(begin == str.size()-1)
            array.push_back(str);

        for(int i = begin; i <= str.size()-1; i++){

            if(i != begin && str[i] == str[begin])//有重复字符时，跳过
                continue;
            swap(str[i], str[begin]); // 当i==begin时，也要遍历其后面的所有字符；
                                      // 当i!=begin时，先交换，使第begin位取到不同的可能字符，再遍历后面的字符
            Permutation(array, str, begin+1); // 遍历其后面的所有字符；
             
            swap(str[i], str[begin]); // 为了下次，还需要将begin处的元素重新换回来
        }
    }
};

// java

public ArrayList Permutation(String str) {
    ArrayList res = new ArrayList();
    if (str != null && str.length() > 0) {
        PermutationHelper(str.toCharArray(), 0, res);
        Collections.sort(res);
    }
    return res;
}
public void PermutationHelper(char[] cs, int i, ArrayList list) {
    if (i == cs.length - 1) {
        String val = String.valueOf(cs);
        if (!list.contains(val)) // no repeat
            list.add(val);
    } else {
        for (int j = i; j < cs.length; ++j) {
            swap(cs, i, j);
            PermutationHelper(cs, i + 1, list);
            swap(cs, i, j);
        }
    }
}