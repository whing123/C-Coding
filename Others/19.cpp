/* *题目：
 *  时针分针夹角
 */

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    string inp;
    cin >> inp;
    int hour = stoi(inp.substr(0, 2));
    if(hour >= 12) hour -= 12;
    int mini = stoi(inp.substr(3, 2));
    
    // 归一化到0-1
    double hh = hour*1.0/12 + 1.0/(12*60)*mini;
    double mm = mini/60.0;
    
    double res = fabs(hh -mm);
    if (res > 0.5) res = 1-res;
    cout<<res*360<<endl;
    
    return 0;
}