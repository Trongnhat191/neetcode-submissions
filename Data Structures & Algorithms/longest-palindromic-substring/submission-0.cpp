class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();

        vector<vector<bool>> dp(n, vector<bool> (n, false));

        int start=0;
        int max_len = 1;

        for (int i = 0; i< n; i++){
            dp[i][i] = true;
        }

        for (int i = 0; i< n-1; i++){
            if (s[i] == s[i+1]){
                dp[i][i+1] = true;
                start = i;
                max_len =2;
            }
        }

        // duyệt theo độ dài chuõi con từ 3 đến n
        for (int len = 3; len<=n; len++){
            for (int i = 0; i<= n-len; i++){
                int j = i+len -1;

                if (s[i] == s[j] && dp[i+1][j-1] == true){
                    dp[i][j] = true;

                    if (len>max_len){
                        start = i;
                        max_len = len;
                    }
                }
            }
        }
        return s.substr(start, max_len);
    }
};
