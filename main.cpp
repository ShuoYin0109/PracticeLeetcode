#include <iostream>
class logPrint{
public:
    void OutPutM(int a);
};

void logPrint::OutPutM(int a) {
    std::cout << a << std::endl;
}


int main() {
    int units_sold = 0;
    int units_sold1 = {0};
    int units_sold2{0};//列表初始化有数据类型不匹配导致丢失数据信息的风险
    int units_sold3(0);//括号不存在这种风险
    int units_sold4(units_sold3);
    long a(3.14159265758);
    int units_sold5{a};
    int &d = units_sold3;
    int &e(units_sold3);
    int &f{units_sold2};
    int *ptr = nullptr;
    ptr = new int(3);
    int &test = *ptr;
    logPrint l;
    std::cout << "Hello, World!" << std::endl;
    std::cout << "aaa: " << units_sold5 << std::endl;
    std::cout << "bbb: " << d << e << f <<std::endl;

    std::cout << "ccc: " << *ptr << std::endl;
    l.OutPutM(test);

    delete ptr;
    ptr = nullptr;
    return 0;
}
