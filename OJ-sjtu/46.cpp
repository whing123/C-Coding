/* *题目：
 *  1044
 *  二哥打游戏
 * *思路：
 *  
 * *技法：
 *  
 */

#include <iostream>
#include <list>
#include <string>
 
using namespace std;

#define DEBUG 0
 
struct resource {
	string name;
	int foodCost;
	int woodCost;
	int level;
	bool operator<(resource b) {
		return level > b.level;
	}
};
 
int main()
{
	list<resource> unit;
	list<resource>::iterator it;
	list<int> food, wood;
	int sumFood, sumWood;
	int N, K;
	int i;
 
	string re_name;
	int fCost, wCost, re_level;
	resource newResource;
 
	//input resources
	cin >> K;
	for (i = 0; i < K; i++)
	{
		cin >> re_name >> fCost >> wCost >> re_level;
		newResource.name = re_name;
		newResource.foodCost = fCost;
		newResource.woodCost = wCost;
		newResource.level = re_level;
		unit.push_back(newResource);
	}
	unit.sort();
 
#if DEBUG
	for (i = 0; i < K; i++)
	{
		newResource = unit.front();
		cout << newResource.name	 << ' ' <<
			    newResource.foodCost << ' ' <<
				newResource.woodCost << ' ' <<
				newResource.level    << endl;
		unit.pop_front();
	}
#endif
 
	int number, option;
	int numFarmer = 0;
	sumFood = 0;
	sumWood = 0;
 
	int foodtmp, woodtmp;
 
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> re_name >> number;
		option = re_name == "food" ? 0 : 1;
		number += numFarmer;
		switch (option)
		{
			case 0:
				food.push_back(number);
				sumFood += number;
				break;
			case 1:
				wood.push_back(number);
				sumWood += number;
		}
 
		for (it = unit.begin(); it != unit.end(); it++)
		{
			foodtmp = 0;
			woodtmp = 0;
			if (sumFood >= (*it).foodCost && sumWood >= (*it).woodCost)
			{
				while (foodtmp < (*it).foodCost)
				{
					sumFood -= food.front();
					foodtmp += food.front();
					food.pop_front();
				}
				while (woodtmp < (*it).woodCost)
				{
					sumWood -= wood.front();
					woodtmp += wood.front();
					wood.pop_front();
				}
 
				cout << "#" << i + 1 << ": a " << (*it).name << " was created.\n";
				if ((*it).name == "farmer")
				{
					numFarmer++;
				}
			}
		}
		//cout << "food: " << sumFood << ", wood: " << sumWood << endl;
	}
 
	cout << "food: " << sumFood << ", wood: " << sumWood << endl;
 
    return 0;
}