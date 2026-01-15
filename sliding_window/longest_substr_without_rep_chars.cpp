int lenOfLongestSubstr(string s) {
    int n = s.size();
    int l = 0 , r = 0;
    int maxLen = 0;
    unordered_map<char , int> mpp;
    while(r < n) {
        mpp[s[r]]++;
        // when the condition gets violated
        if(mpp[s[r]] > 1) {
            while(mpp[s[r]] >= 2) {
                mpp[s[l]]--;
                if(mpp[s[l]] == 0) mpp.erase(s[l]);
                l++;
            }
        }

        // when the condition is satisfied
        int len = r - l + 1;
        maxLen = max(maxLen , len);

        // increemneting
        r++;
    }
    return maxLen;
}

int main() {
    string s;
    cin >> s;
    int ans = lenOfLongestSubstr(s);
    cout << ans << endl;
    return 0;
}