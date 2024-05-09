#include "spiralMatrix.h"
#include <vector>
#include <map>

using namespace std;

/***
 * 以一圈 四边 四个方向为一组 多次循环直到结束为止
 * 方向：
 *  0 从左到右
 *  1 从上到下
 *  2 从右到左
 *  3 从下到上
 * 
*/
vector<vector<int>> SpiralMatrixSolution::spiralMatrix(int n) {
    int cur_direction = 0; // 当前方向记录
    int cur_level = 0; // 当前循环层数
    int cur_num = 1; // 当前数字
    int cur_num = 1;

    vector<vector<int>> res;

    while (cur_level < n)
    {   
        // 每层循环重置方向记录
        cur_direction = 0;
        while (cur_direction < 3)
        {
            switch (cur_direction)
            {
            case 0:
                // 0-0 0-1 0-2
                for (size_t i = 0; i < n - 1; i++)
                {
                    res[cur_level][cur_level + i] = cur_num;
                    cur_num += 1;
                }
                break;
            case 1:
                // (0-2) 1-2 2-2
                for (size_t i = 1; i < n - 1; i++)
                {
                    res[i][n - 1 - cur_level] = cur_num;
                    cur_num += 1;
                }
                break;
            case 2:
                // (2-2) 2-1 2-0
                for (size_t i = n - 2; i > 0; i--)
                {
                    res[n - 1 - cur_level][i] = cur_num;
                    cur_num += 1;
                }
                break;
            case 3:
                // (2-0) 1-0 (0-0)
                for (size_t i = n - 2; i > 0; i--)
                {
                    res[i][cur_level] = cur_num;
                    cur_num += 1;
                }
                break;
            default:
                break;
            }
            cur_direction += 1;
        }
        cur_level += 1;
    }
    // 奇数矩阵需要手动将最后一个值添加到正中间
    
    return res;
}