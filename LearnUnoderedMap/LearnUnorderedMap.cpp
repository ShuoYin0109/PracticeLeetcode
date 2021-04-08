//
// Created by yinshuo on 2021/4/4.
//
//unordered_map::insert
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

void display(unordered_map<string,double> myrecipe, string str) {
    cout << str << endl;
    for(auto& x:myrecipe)
        cout << x.first << ": " << x.second << endl;
    cout << endl;
}

int main() {
    unordered_map<string, double> myrecipe, mypantry = {{"milk", 2.0}, {"flour", 1.5}};
    /********************插入************************/
    pair<string, double> myshopping = {"baking powder", 0.3};
    myrecipe.insert(myshopping);
    myrecipe.insert(make_pair<string, double>("eggs", 6.0));
    myrecipe.insert(mypantry.begin(), mypantry.end());
    myrecipe.insert({{"suger", 0.8}, {"salt", 0.1}});
    myrecipe["coffee"] = 10.0;

    display(myrecipe, "myrecipe contains : ");
    /*********************查找************************/

    return 0;
}

