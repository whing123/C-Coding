/* *题目：
 *  1231
 *  lca
 * *思路：
 *  
 * *技法：
 *  
 */

#include <iostream>
using namespace std ;
 
struct binarytree
{
    int father ;
    int left, right ;
    binarytree(){father = left = right = 0 ;}
};
 
int main()
{
    int n, x, y, a, b ;
    cin >> n >> x >> y ;
    binarytree tree[n+1] ;
    for (int i = 1; i <= n; ++i){
        cin >> a >> b ;
        tree[i].left = a ;
        tree[i].right = b ;
        if (a != 0 ) tree[a].father = i ;
        if (b != 0)  tree[b].father = i ;
    }
    int yi = y ;
    bool judge = false ;
    while(tree[x].father != 0){
        while(tree[y].father != 0){
            if(tree[x].father == tree[y].father){
                cout << tree[x].father ;
                judge = true ;
                break ;}
            y = tree[y].father ;
        }
        if(judge) break ;
        x = tree[x].father ;
        y = yi ;
    }
    return 0 ;
}