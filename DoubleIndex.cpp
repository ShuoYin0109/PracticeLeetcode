//
// Created by yinshuo on 2021/3/28.
//
#include "DoubleIndex.h"
#include <algorithm>
#include <iostream>
#define MIN_SIZE 3
#define M_TARGET 0
std::vector<std::vector<int>> DoubleIndex::TreeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    if(nums.size() < MIN_SIZE ) return result;
    sort(nums.begin(), nums.end());
    for(auto i = 0; i < nums.size(); ++i) {
        if(nums[i] > M_TARGET) return result;
        if(i > 0 && nums[i] == nums[i-1]) continue;
        int left = i + 1;
        int right = nums.size() - 1;
        while(left < right) {
            int tmp = nums[i] + nums[left] + nums[right];
            if(tmp > M_TARGET) --right;
            else if(tmp < M_TARGET) ++left;
            else {
                result.push_back(std::vector<int>{nums[i], nums[left], nums[right]});
                while(left < right && nums[right] == nums[right-1]) --right;
                while(left < right && nums[left] == nums[left+1]) ++left;
                --right;
                ++left;
            }
        }
    }
    return result;
}

void main() {
    std::vector<int> numbers = [-1, 0, 1, 2, -1, 4];
    DoubleIndex db;
    std::vector<std::vector<int>> s = db.TreeSum(numbers);
    std::cout << " aaa : " << s << std::endl;
    return;
}
