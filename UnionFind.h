//
// Created by yinshuo on 2021/3/27.
//

#ifndef UNTITLED_UNIONFIND_H
#define UNTITLED_UNIONFIND_H

class UnionFind {
private:
    int prev[1000]={0};
public:
    void Init();
    int Find(int x);
    void Join(int x, int y);
};

#endif //UNTITLED_UNIONFIND_H
