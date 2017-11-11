#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

void printReverse(string& s){
    stringstream ss(s);
    int counter = 0;
    string t;
    while(getline(ss, t, ' ')){
        if(counter > 0) cout << " ";
        std::reverse(t.begin(), t.end());
        cout << t;
        counter = 1;
    }
    cout << endl;
}

int main(){
    string s;
    while(getline(cin, s)){
        printReverse(s);
    }
    return 0;
}

