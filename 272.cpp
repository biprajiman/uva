#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

bool l = true;

string texQuotes(const string &s){
    string r;
    for(int i=0; i<s.size(); ++i){
       if(s[i]=='"'){
           if(l) r.push_back('`'), r.push_back('`');
           else r.push_back('\''), r.push_back('\'');
           l = !l;
        }else r.push_back(s[i]);
    }
    return r;
}

int main(){
    string s;
    while(getline(cin, s)){
        printf("%s\n", texQuotes(s).c_str());
    }

    return 0;
}
