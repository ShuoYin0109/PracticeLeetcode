//
// Created by yinshuo on 2021/4/4.
//
#include <iostream>
#include <vector>

class RabbitNums {
public:
    int RabbitNumbers(std::vector<int>& answers);
};

int RabbitNums::RabbitNumbers(std::vector<int>& answers) {
    
    for(auto &a:answers) {
        std::cout << "members : " << a << std::endl;
    }
    return 0;
}

int main() {
    std::vector<int> v = {1,2,3,4,5,6};
    RabbitNums rn;
    rn.RabbitNumbers(v);
    return 0;
}

