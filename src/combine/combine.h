#ifndef COMBINE_H
#define COMBINE_H

class CombineSolution {
    private:
        vector<vector<int>> result;
        vector<int> path;
        void backtracking(int n, int k, int startIndex) {
            if (path.size() == k) {
                return result.push_back(path);
            }
            for (int i = startIndex; i <= n; i++)
            {
                path.push_back(i);
                backtracking(n, k ,i + 1);
                path.pop_back();
            }
        }
    public:
        vector<vector<int>> combine(int n, int k) {
            backtracking(n, k, 1);
            return result;
        }
    };

#endif