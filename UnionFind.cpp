//
// Created by yinshuo on 2021/3/27.
//
#include "UnionFind.h"

void UnionFind::Init() {
    for(auto i = 0; i < 1000; ++i) {
        this->prev[i] = 0;
    }
}
int UnionFind::Find(int x) {
    int tmp = x;
    while (tmp != prev[tmp]) {
        tmp = prev[tmp];
    }
    //路径压缩一下
    int i = x, j;
    while (i != prev[i]) {
        j = prev[i];
        prev[i] = tmp;
        i = j;
    }
    return tmp;//返回根节点
}
void UnionFind::Join(int x, int y) {
    int px = Find(x), py = Find(y);
    if(px != py) {
        prev[x] = py;
    }
    return;
}

