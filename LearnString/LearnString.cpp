//
// Created by yinshuo on 2021/4/4.
//
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cstdio>
#include <algorithm>

using namespace std;

class LearnString {
public:
    void helper(string str, unordered_map<string,int>& mm);
    vector<string> subdomainVisits(vector<string>& cpdomains);
};

void LearnString::helper(string str, unordered_map<string, int> &mm) {
    string str_num, str_dom;
    int pos = str.find(" ");
    str_num = str.substr(0, pos);
    str_dom = str.substr(pos+1);
    cout << "sub str : " << str_num << " , sub dom : " << str_dom << endl;
    int num = atoi(str_num.c_str());
    //mm[str_dom] = num;
    while(pos > 0) {
        mm[str_dom] += num;
        pos = str_dom.find(".");
        str_dom = str_dom.substr(pos+1);
        //cout << "yinshuo" << str_dom << endl;
    }
    return;

}

vector<string> LearnString::subdomainVisits(vector<string> &cpdomains) {
    unordered_map<string,int> mp;
    vector<string> res;
    if(cpdomains.size() == 0) return res;
    for(auto &cp:cpdomains) {
        helper(cp, mp);
    }
    auto iter = mp.begin();
    while(iter != mp.end()) {
        cout << iter->first << " " << iter->second << endl;
        res.push_back({to_string(iter->second) + " " + iter->first});
        ++iter;
    }
    return res;
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> tmp(m+n, 0);
    auto iter1 = nums1.begin(), iter2 = nums2.begin();
    auto iter3 = tmp.begin();
    while(iter1 != nums1.begin()+m && iter2 != nums2.begin()+n) {
        if(*iter1 <= *iter2) {
            *iter3 = *iter1;
            ++iter1;
        }
        else {
            *iter3 = *iter2;
            ++iter2;
        }
        ++iter3;
    }
    while(iter1 != nums1.begin()+m) {
        *iter3 = *iter1;
        ++iter3;
        ++iter1;
    }
    while(iter2 != nums2.begin()+n) {
        *iter3 = *iter2;
        ++iter3;
        ++iter2;
    }
    nums1 = tmp;
    return;
}

bool isValidSudoku(vector<vector<char>>& board) {
    unordered_map<char, int> row[9];
    unordered_map<char, int> col[9];
    unordered_map<char, int> box[9];
    for(auto i = 0; i < 9; ++i) {
        for(auto j = 0; j < 9; ++j) {
            if(board[i][j] == '.') continue;
            else {
                row[i][board[i][j]]++;
                col[j][board[i][j]]++;
                box[i/3*3+j/3][board[i][j]]++;
            }
        }
    }

    for(auto i = 0; i < 9; ++i) {
        unordered_map<char, int> r = row[i];
        unordered_map<char, int> c = col[i];
        unordered_map<char, int> b = box[i];

        auto iter_r = r.begin();
        auto iter_c = c.begin();
        auto iter_b = b.begin();

        while(iter_r != r.end()) {
            if(iter_r->second > 1) return false;
            ++iter_r;
        }

        while(iter_b != b.end()) {
            if(iter_b->second > 1) return false;
            ++iter_b;
        }

        while(iter_c != c.end()) {
            if(iter_c->second > 1) return false;
            ++iter_c;
        }

        return true;
    }
    for(auto i = 0; i < 9; ++i) {
        auto iter = row[i].begin();
        cout << "line is : " << i << endl;
        while(iter != row[i].end()) {
            cout << "1st is : " << iter->first << " , 2nd is : " << iter->second <<endl;
            ++iter;
        }
    }

    for(auto i = 0; i < 9; ++i) {
        auto iter = col[i].begin();
        cout << "col is : " << i << endl;
        while(iter != col[i].end()) {
            cout << "1st is : " << iter->first << " , 2nd is : " << iter->second <<endl;
            ++iter;
        }
    }

    for(auto i = 0; i < 9; ++i) {
        auto iter = box[i].begin();
        cout << "box is : " << i << endl;
        while(iter != box[i].end()) {
            cout << "1st is : " << iter->first << " , 2nd is : " << iter->second <<endl;
            ++iter;
        }
    }
    return true;
}

bool isPalindrome(string s) {
    if(s.empty()) return true;
    string s_good;
    for(auto ch:s) {
        if(isalnum(ch)) s_good += tolower(ch);
    }
    int l(0), r(s_good.size()-1);
    while(l <= r) {
        if(s_good[l] != s_good[r]) return false;
        ++l;
        --r;
    }
    return true;
}


int main() {
    LearnString ls;
    vector<string> test({"900 google.mail.com", "10 tju.mail.com"});

    vector<string> rr = ls.subdomainVisits(test);
    for(auto& r:rr) {
        cout << " res : " << r << endl;
    }

    vector<int> test1 = {1,2,3,0,0,0};
    vector<int> test2({2,5,6});
    merge(test1, 3, test2, 3);
    auto i = test1.begin();
    while(i != test1.end()) {
        cout << *i << endl;
        ++i;
    }

    vector<vector<char>> tt = {
            {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}

    };
    bool rrr = isValidSudoku(tt);
    cout << " result is : " << rrr << endl;

    string s_test("race a car");
    bool r3 = isPalindrome(s_test);
    cout << "is Pal : " << r3 << endl;
    return 0;
}
