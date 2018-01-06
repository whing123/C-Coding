/* *题目：
 *  1052
 *  二哥学集合论
 * *思路：
 *  
 * *技法：
 *  
 */

#include <iostream>
#include <list>
 
using namespace std;
 
typedef list<int> list_int;
 
int main()
{
	int n, m;
	int i;
	int cnt_val, cnt;
	list_int list_cnt, list_tmp;
	list_int::iterator it, it_1;
	list<list_int> list_all;
	list<list_int>::iterator it_a, it_b, it_all;
 
	char op;
	int a, b;
 
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> cnt_val;
		list_cnt.push_back(cnt_val);
	}
 
	for (it = list_cnt.begin(); it != list_cnt.end(); it++)
	{
		cnt = *it;
		for (i = 0; i < cnt; i++)
		{
			cin >> cnt_val;
			list_tmp.push_back(cnt_val);
		}
 
		list_tmp.sort();
		list_tmp.unique();
		list_all.push_back(list_tmp);
 
		list_tmp.clear();
	}
 
	cin >> m;
	for (i = 0; i < m; i++)
	{
		cin >> op;
		cin >> a >> b;
		it_a = list_all.begin();
		advance(it_a, a - 1);
		it_b = list_all.begin();
		advance(it_b, b - 1);
 
		switch (op)
		{
			case '+':
				if (a != b)  //要考虑集合相同的情况，下同
				{
					for (it = it_b->begin(); it != it_b->end(); it++)
					{
						it_a->push_back(*it);
					}
					it_a->sort();
					it_a->unique();
				}
				break;
			case '-':
				if (a != b)
				{
					for (it = it_b->begin(); it != it_b->end(); it++)
					{
						if (it_a->empty())
							break;
						it_a->remove(*it);
					}
				}
				else
					it_a->clear();
				break;
			case '*':
				if (a != b)
				{
					for (it = it_a->begin(); it != it_a->end(); it++)
					{
						for (it_1 = it_b->begin(); it_1 != it_b->end(); it_1++)
						{
							if (*it == *it_1)
							{
								list_tmp.push_back(*it);
								break;
							}
						}
					}
					it_a->clear();
					(*it_a) = list_tmp;
					list_tmp.clear();
				}
				break;
		}
	}
 
	for (it_all = list_all.begin(); it_all != list_all.end(); it_all++)
	{
		if (!it_all->empty())
		{
			it_all->sort();
			it_all->unique();
			for (it = it_all->begin(); it != it_all->end(); it++)
			{
				cout << *it << ' ';
			}
			cout <<endl;
		}
		else
			cout << endl;
	}
 
	//cin >> n;
    return 0;
}