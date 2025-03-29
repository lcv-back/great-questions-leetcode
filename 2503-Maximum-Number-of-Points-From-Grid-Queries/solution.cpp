#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        int k = queries.size();

        // sort queries and save root index
        vector<pair<int, int>> sortedQueries(k);
        for (int i = 0; i < k; i++) {
            sortedQueries[i] = {queries[i], i};
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        // heap {value cell, row, col}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        int score = 0; // the number of cells was visited

        vector<int> ans(k);
        for (int i = 0; i < k; i++) {
            int query = sortedQueries[i].first;
            int idx = sortedQueries[i].second;

            // traversal when dont have cell less than query
            while (!pq.empty() && get<0>(pq.top()) < query) {
                auto [val, row, col] = pq.top();
                pq.pop();
                score++; // update score valid

                // add neighbor cells 
                for (auto& dir : directions) {
                    int newRow = row + dir[0];
                    int newCol = col + dir[1];
                    if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && !visited[newRow][newCol]) {
                        visited[newRow][newCol] = true;
                        pq.push({grid[newRow][newCol], newRow, newCol});
                    }
                }
            }

            ans[idx] = score; // assign current value
        }

        return ans;
    }
};


/*
time: O(k log k + mn log(mn)))
space: O(m*n)
*/

int main() {
    Solution sol;
    vector<vector<int>> grid = {{1, 2, 3}, {2, 5, 7}, {3, 5, 1}};
    vector<int> queries = {5, 6, 2};
    vector<int> res = sol.maxPoints(grid, queries);
    for (int i : res) cout << i << " ";
    cout << endl; // Kết quả: 2 3 1
    return 0;
}