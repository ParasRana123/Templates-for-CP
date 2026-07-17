#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    bool f(int ind , int target , vector<vector<int>> &dp , vector<int> &arr) {
        if(target == 0) return true;
        if(ind == 0) return (arr[0] == target);
        if(dp[ind][target] != -1) return dp[ind][target];
        bool notTake = f(ind - 1 , target , dp , arr);
        bool take = false;
        if(target >= arr[ind]) {
            take = f(ind - 1 , target - arr[ind] , dp , arr);
        }
        return dp[ind][target] = take || notTake;
    }
    
  public:
    bool equalPartition(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for(int i= 0 ; i < n ; i++) {
            sum += arr[i];
        }
        if(sum % 2 == 1) return false;
        int target = sum / 2;
        vector<vector<int>> dp(n , vector<int>(target + 1 , -1));
        return f(n - 1 , target , dp , arr);
    }
};