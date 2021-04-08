//
// Created by yinshuo on 2021/4/8.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge(vector<int>& v, int L, int R, int M) {
    int LEFT_SIZE = M - L;
    int RIGHT_SIZE = R - M + 1;
    vector<int> left(LEFT_SIZE, 0);
    vector<int> right(RIGHT_SIZE, 0);

    for(auto i = L; i < M; ++i) {
        left[i-L] = v[i];
    }
    for(auto i = M; i <= R; ++i) {
        right[i-M] = v[i];
    }

    int k(0) , l(0), idx(L);
    while(k < LEFT_SIZE && l < RIGHT_SIZE) {
        if(left[k] < right[l]) {
            v[idx] = left[k];
            ++k;
        }
        else {
            v[idx] = right[l];
            ++l;
        }
        ++idx;
    }
    while(k < LEFT_SIZE) {
        v[idx] = left[k];
        ++k;
        ++idx;
    }
    while(l < RIGHT_SIZE) {
        v[idx] = right[l];
        ++l;
        ++idx;
    }

    return;
}

void mergeSort(vector<int>& v, int L, int R) {
    if(L == R) return;
    else {
        int M = (L + R) / 2;
        mergeSort(v, L, M);
        mergeSort(v, M+1, R);
        merge(v, L, R, M+1);
    }
}


int main() {
    vector<int> test = {5,8,2,7,6,1,9,3,4,0};

    mergeSort(test, 0, test.size()-1);
    auto iter = test.begin();
    while(iter != test.end()) {
        cout << *iter << endl;
        ++iter;
    }

    return 0;

}
