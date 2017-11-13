#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool balanced(string s){
    stack<char> st;
    for(int i=0; i<s.size(); i++){
        if(s[i] != '(' && s[i] != ')' && 
            s[i] != '[' && s[i] != ']') continue;

        if(s[i] == '(' || s[i] == '[') st.push(s[i]);
        else if (s[i] == ')' && !st.empty() && st.top() == '(') st.pop();
        else if (s[i] == ']' && !st.empty() && st.top() != '(') st.pop();
        else return false;
    }

    return st.empty();
}

int main(){
    int N;
    string s;
    cin >> N;
    string null;
    getline(cin, null);
    for(int i = 0; i < N; i++){
        getline(cin, s);
        cout << ((balanced(s)? "Yes": "No")) << endl;
    }
    return 0;
}