#include <map>
#include <vector>
#include <unordered_map>

class FourSumSolution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        std::unordered_map<int, int> umap;
        // 给四数相加分组，A+B = -（C+D）即可证明 A+B+C+D = 0
        // 1. 使用hashtable记录A+B
        for (int a : A) {
            for (int b : B) {
                umap[a+b]++;
            }
        }
        int count = 0;
        // 2. 使用hashtable找到 0-C+D = A+B的项
        for (int c : C) {
            for (int d : D) {
                if (umap.find(0-(c+d))) {
                    count += umap[0-(c+d)];
                }
            } 
        }
        return count;
    }
};