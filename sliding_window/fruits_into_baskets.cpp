#include <bits/stdc++.h>
#include <iostream>
#include <vector>

int totalFruit(vector<int> &nums , int k) {
    int n = nums.size();
    int l = 0 , r = 0;
    int maxLen = 0;
    unordered_map<int , int> mpp;
    while(r < n) {
        mpp[nums[r]]++;

        // when the condition is violated
        if(mpp.size() > k) {
            while(mpp.size() > k) {
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0) mpp.erase([nums[l]]);
                l++;
            }
        }

        // when the condition is satisfied
        if(mpp.size() <= k) {
            int len = r - l + 1;
            maxLen = max(maxLen , len);
        }
        r++;
    }
    return maxLen;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0 ; i < n ; i++) {
        cin >> nums[i];
    }
    int k;
    cin >> k;
    int ans = totalFruit(nums , k);
    cout << ans << endl;
    return 0;
}