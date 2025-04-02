class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n+1,0);

        for(int i=n-1; i>=0; --i){
            long long points = questions[i][0];
            long long brainpower = questions[i][1];

            if(i + brainpower + 1 < n){
                dp[i] = max(dp[i+1], points + dp[i + brainpower + 1]);
            } else {
                dp[i] = max(dp[i+1], points);
            }
        }

        return dp[0];
    }
};