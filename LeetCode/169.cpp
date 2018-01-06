/* *题目：
 *  498
 *  Diagonal Traverse
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int> > & matrix) {
	    
	    vector<int> res;
		if(matrix.size() == 0){
		    return res;
		}
		
		int H = matrix.size();
		int W = matrix[0].size();

		int row, col;
		row = col = 0;

		res.push_back(matrix[0][0]);

		bool down;
		while (!(row == H - 1 && col == W - 1)) {

			// 决定方向 和 下一起点
			// 根据所在边界进行判定
			if (row == 0 && col < W - 1) {  //在第一行
				down = true;
				col++;
			}
			else if (row < H - 1 && col == W - 1) {  //在最后一列
				down = true;
				row++;
			}
			else if (row < H - 1 && col == 0) {  //在第一列
				down = false;
				row++;
			}
			else if (row == H - 1 && col < W - 1) {  //在最后一行
				down = false;
				col++;
			}
			res.push_back(matrix[row][col]);  //加入新起始点

			if (down) {  //左下移动
				while (col > 0 && row < H - 1) {
					col--;
					row++;
					res.push_back(matrix[row][col]);
				}
			}
			else {  //右上移动
				while (col < W - 1 && row > 0) {
					col++;
					row--;
					res.push_back(matrix[row][col]);
				}
			}
		}
		
		return res;
	}
};
