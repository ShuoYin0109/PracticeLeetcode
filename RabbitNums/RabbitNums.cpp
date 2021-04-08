//
// Created by yinshuo on 2021/4/4.
//
#include <iostream>
#include <vector>
#include <unordered_map>

class RabbitNums {
public:
    int RabbitNumbers(std::vector<int>& answers);
};

int RabbitNums::RabbitNumbers(std::vector<int>& answers) {
    std::unordered_map<int,int> mp;//存储<数字，说该数字的兔子数量>
    int res = 0;
    for(auto &an:answers) {
        mp[an]++;
    }
    auto iter = mp.begin();
    while(iter != mp.end()) {
        std::cout << "first is : " << iter->first << " , second is : " << iter->second <<std::endl;
        int cnt = iter->second, idx = iter->first;
        if(cnt <= idx + 1) res += idx + 1;
        else {
            if(cnt % (idx + 1) == 0) res += cnt;
            else {
                res += ((cnt / (idx + 1)) + 1) * (idx + 1);
            }
        }

        ++iter;
    }

    return res;
}

int main() {
    std::vector<int> v = {};
    RabbitNums rn;
    int rr = rn.RabbitNumbers(v);
    std::cout << "rr is : " << rr << std::endl;
    return 0;
}

