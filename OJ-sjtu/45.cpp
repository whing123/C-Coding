/* *题目：
 *  1037
 *  二哥买草
 * *思路：
 *  
 * *技法：
 *  
 */

#include <iostream>
#include <queue>
 
using namespace std;
 
int main()
{
	priority_queue<int> qHigh, qLow, q1;
	int num_high, num_low, input;
	int high_value, low_walue, sum;
	int i;
 
	cin >> num_high >> num_low;
 
	for (i = 0; i < num_high; i++)
	{
		cin >> input;
		qHigh.push(input);
	}
 
	for (i = 0; i < num_low; i++)
	{
		cin >> input;
		qLow.push(input);
	}
 
	sum = 0;
 
	while (!qHigh.empty())
	{
		high_value = qHigh.top();
		while (!qLow.empty())
		{
			low_walue = qLow.top();
			if (high_value > low_walue)
			{
				sum += 2;
				qLow.pop();
				qHigh.pop();
				break;
			}
			else
				qLow.pop();
		}
 
		if (qLow.empty())
		{
			sum += qHigh.size();
			break;
		}
	}
 
	cout << sum;
 
	//getchar();
    return 0;
}