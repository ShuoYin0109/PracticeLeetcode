//
// Created by yinshuo on 2021/4/7.
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class KMP {
public:
    KMP() {
        vector<int>*dummy = new vector<int>(1000, 0);
        next = *dummy;
    }
    
    void getNextArry(string pat);
    int getIndexOfPattern(string txt, string pat);

private:
    vector<int> next;
};

void KMP::getNextArry(string pat) {
    int j = -1;

    next[0] = j;

    for(int i = 1; i < pat.length(); ++i) {
        while(j >= 0 && pat[i] != pat[j+1]) {
            j = next[j];
        }
        if(pat[i] == pat[j+1]) {
            j++;
        }
        next[i] = j;

    }
}

int KMP::getIndexOfPattern(string txt, string pat) {
    int j = -1;
    for(int i = 0; i < txt.length(); ++i) {
        while(j >= 0 && txt[i] != pat[j+1]) {
            j = next[j];
        }
        if(txt[i] == pat[j+1]) {
            j++;
        }
        if(j == pat.length()-1) {
            return (i - pat.length() + 1);
        }
    }
    return -1;
}

int main() {
    KMP kp;
    string txt("aabaacaaabaaf");
    string pat("aabaaf");

    kp.getNextArry(pat);

    int res = kp.getIndexOfPattern(txt, pat);
    cout << "Result is : " << res << endl;
    return 0;
}
