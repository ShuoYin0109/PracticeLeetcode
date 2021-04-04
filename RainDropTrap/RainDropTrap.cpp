//
// Created by yinshuo on 2021/4/2.
//
#include <iostream>
#include <vector>
#include <algorithm>

class RainDropTrap{
public:
    int trap(std::vector<int>& height);
    int trap_dp(std::vector<int>& height);
};

int RainDropTrap::trap(std::vector<int> &height) {
    if(height.size() == 0) return 0;
    int sum = 0;
    //第一个和最后一个列不接雨水
    for(auto i = 1; i < height.size()-1; ++i) {
        int rHeight = height[i], lHeight = height[i];
        for(auto l = i-1; l > -1; --l) {
            if(height[l] > lHeight) lHeight = height[l];
        }
        for(auto r = i+1; r < height.size(); ++r) {
            if(height[r] > rHeight) rHeight = height[r];
        }
        int h = std::min(rHeight, lHeight) - height[i];
        if(h > 0) sum += h;
    }
    return sum;
}

int RainDropTrap::trap_dp(std::vector<int> &height) {
    int N = height.size();
    if(N <= 2) return 0;
    int res = 0;
    //每一个i对应一个“左数组”和“右数组”，记录左最高和右最高
    std::vector<int> leftM(N, 0);
    std::vector<int> rightM(N, 0);
    leftM[0] = height[0];
    rightM[N-1] = height[N-1];
    for(auto i = 1; i < N-1; ++i) leftM[i] = std::max(height[i], leftM[i-1]);
    for(auto i = N-2; i > -1; --i) rightM[i] = std::max(height[i], rightM[i+1]);

    for(auto i = 1; i < N-1; ++i) {
        int h = std::min(leftM[i], rightM[i]) - height[i];
        if(h > 0) res += h;
    }
    return res;

}

int main() {
    //std::vector<int> rainStats = {0,1,0,2,1,0,1,3,2,1,2,1};
    std::vector<int> rainStats = {3,1,0,2};
    RainDropTrap rdt;
    int res = rdt.trap(rainStats);
    int res1 = rdt.trap_dp(rainStats);
    std::cout << "1st Result is : " << res << std::endl;
    std::cout << "2nd Result is : " << res1 << std::endl;
    return 0;
}
