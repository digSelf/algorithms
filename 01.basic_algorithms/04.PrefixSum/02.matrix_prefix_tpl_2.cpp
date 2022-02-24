/**
 * @file 02.matrix_prefix_tpl_2.cpp
 * @author iforget
 * @brief 这个模板使用的是vector容器，要学会二维vector的定义和初始化
 * @version 0.1
 * @date 2022-02-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> calc_matrix_prefix_sum(vector<vector<int>>& matrix) {
    // 计算前缀和
    int rows = matrix.size();
    int cols = matrix.back().size();
    
    // 这里的二维的初始化，通过临时变量指定每一列的初始化的值
    vector<vector<int>> s(rows + 1, vector<int>(cols + 1, 0));
    
    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= cols; ++j) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + matrix[i - 1][j - 1];
        }
    }
    
    return s;
}

int main() {
    // 关闭缓存同步
    std::ios::sync_with_stdio(false);
    
    int n, m, q;
    cin >> n >> m >> q;
    
    // 使用临时变量进行二维vector的初始化，这里的初始化没有指定列的初始化的值
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    } // 读取矩阵
    
    auto s = calc_matrix_prefix_sum(matrix);
    
    while (q --) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        cout << s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1] << endl;
    }
    
    return 0;
}