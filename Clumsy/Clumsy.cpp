//
// Created by yinshuo on 2021/4/1.
//
#include <iostream>
#include <stack>

class Clumsy{
public:
    int clumsy(int N);
};

int Clumsy::clumsy(int N) {
    int result = 0;
    std::stack<int> st;
    st.push(N);

    for(auto i = 1; i < N; ++i) {
        int tmp = N - i;
        int idx = i % 4;
        switch(idx) {
            case 1: st.top() *= tmp; break;
            case 2: st.top() /= tmp; break;
            case 3: st.push(tmp); break;
            default: st.push(-tmp); break;
        }
    }

    while(!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

int main() {
    int NUM = 4;
    Clumsy cl;
    int res = cl.clumsy(NUM);
    std::cout << " res is : " << res << std::endl;
    return 0;
}
