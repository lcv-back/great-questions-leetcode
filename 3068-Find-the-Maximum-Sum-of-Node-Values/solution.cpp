#include<iostream>
#include<string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long res = 0;
        int n = 0;
        long long d = 1 << 30;
        for(auto &x : nums){
            long long y = x ^ k;
            res += max((long long)x, y);
            if(x < y){
                n = 1 - n;
            }
            d = min(d, abs(x-y));
        }
        return res - n * d;
    }
};

int main(){
	Solution sol;
    vector<int> nums = {1,2,1};
    int k = 3;
    vector<vector<int>> edges = {{0,1}, {0,2}};
    cout << sol.maximumValueSum(nums, k, edges);
	return 0;
}