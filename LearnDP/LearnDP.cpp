//
// Created by yinshuo on 2021/4/8.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
/*
 * 最长上升子序列

给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。
 */

//dp[i] = max(dp[i], dp[j]+1);

int LengthOfLIS(vector<int>& nums) {
    int N = nums.size();
    if(N == 0) return 0;
    vector<int> dp(N, -1);
    for(auto i = 0; i < N; ++i) {
        dp[i] = 1;
        for(auto j = 0; j < i; ++j) {
            if(nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

/*
 * 最长递增子序列的个数

给定一个未排序的整数数组，找到最长递增子序列的个数。

示例 1:

输入: [1,3,5,4,7]
输出: 2
解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
 */

int findNumberOfLIS(vector<int>& nums) {
    int N = nums.size();
    if(N == 0) return 0;
    vector<int> dp(N, 1);
    vector<int> count(N, 1);
    for(auto i = 0; i < N; ++i) {
        for(auto j = 0; j < i; ++j) {
            if(nums[i] > nums[j]) {
                //第一次找到
                if(dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                }
                //不是第一次
                else if(dp[i] == dp[j] + 1) {
                    count[i] += count[j];
                }
            }
        }
    }
    int max = *max_element(dp.begin(), dp.end());
    int res = 0;
    for(auto i = 0; i < N; ++i) {
        if(max == dp[i]) res += count[i];
    }
    return res;


}

int main() {
    vector<int> test = {10,9,2,5,3,7,101,18};
    int res = LengthOfLIS(test);
    cout << res << endl;
    return 0;
}


