//
// Created by yinshuo on 2021/4/3.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class LongestComSubSeq {
public:
    int LongestCommonSubSequence(std::string text1, std::string test2);
};

int LongestComSubSeq::LongestCommonSubSequence(std::string text1, std::string text2) {
    std::vector<std::vector<int>> dp(text1.size()+1, std::vector<int>(text2.size()+1, 0));
    for(auto i = 1; i < text1.size()+1; ++i) {
        for(auto j = 1; j < text2.size()+1; ++j) {
            if(text1[i-1] == text2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[text1.size()][text2.size()];
}

int main() {
    std::string ta("abcd"), tb("efg");
    LongestComSubSeq lcss;
    int res = lcss.LongestCommonSubSequence(ta, tb);
    std::cout << "Result is : " << res << std::endl;
    return 0;
}

