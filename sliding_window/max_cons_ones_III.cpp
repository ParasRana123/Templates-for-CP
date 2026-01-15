#include <bits/stdc++.h>
#include <vector>
#include <iostream>

int longestOnes(vector<int> &nums , int k) {
    int n = nums.size();
    int l = 0 , r = 0;
    int zeroes = 0 , maxLen = 0;
    while(r < n) {
        if(nums[r] == 0) zeroes++;

        // when the condition is violated
        while(zeroes > k) {
            if(nums[l] == 0) zeroes--;
            l++;
        }

        // when the condition gets satisified
        if(zeroes <= k) {
            int len = (r - l + 1);
            maxLen = max(maxLen , len);
        }

        r++;
    }

    // return the required
    return maxLen;
}

int main() {
    int k;
    cin >> k;
    vector<int> nums(n);
    for(int i = 0 ; i < n ; i++) {
        cin >> nums[i];
    }
    cin >> n;
    int ans = longestOnes(nums , k);
    cout << ans << endl;
    return 0;
}