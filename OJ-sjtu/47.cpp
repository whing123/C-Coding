/* *题目：
 *  1051
 *  静态查找表
 * *思路：
 *  
 * *技法：
 *  
 */

#include <iostream>
#include <list>
 
using namespace std;
 
int main()
{
	list<int> look_list, in_list;
	list<int>::iterator it;
 
	int count, value;
	int n, m, i;
 
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> value;
		look_list.push_back(value);
	}
 
	cin >> m;
	for (i = 0; i < m; i++)
	{
		cin >> value;
		in_list.push_back(value);
	}
 
	count = 0;
	while (!in_list.empty())
	{
		value = in_list.front();
		in_list.pop_front();
 
		for (it = look_list.begin(); it != look_list.end(); it++)
		{
			count++;
			if (*it == value)
			{
				look_list.push_front(*it);
				look_list.erase(it);
				break;
			}
		}
	}
 
	cout << count;
 
    return 0;
}