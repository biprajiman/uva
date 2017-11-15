#include <string>
#include <stack>
#include <iostream>
using namespace std;

stack<char> op;

int precedence(char c){
    if(c == '*' || c == '/') return 10;
    else if (c == '+' || c == '-') return 1;
    else return 0;
}

int main(){
    int N;
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout);
    cin >> N;
    string s;
    getline(cin, s);
    getline(cin, s);

     for(int i=0; i < N; i++)
     { 
        // number of test cases
        
        // while input for the expression
        while(true)
        {
            getline(cin, s);

            if(s.size() <=0 ) break;

            if(s[0] == '(') op.push(s[0]);
            else if(s[0] == ')')
            {
                while(not op.empty() && op.top() != '('){
                    cout << op.top();
                    op.pop();
                }
                if(not op.empty()) op.pop(); // remove '('
            }
            else if(s[0] == '+' or s[0] == '-' or s[0] == '*' or s[0] == '/')
            {
                while(not op.empty() and (precedence(op.top()) > precedence(s[0]) or 
                        precedence(op.top()) == precedence(s[0]))){ // precedence
                    cout << op.top();
                    op.pop();
                }
                op.push(s[0]);
            }
            else
            {
                cout << s[0];
            }
            //else nothing
        }

        while(not op.empty()) { // rest of the operators
            cout << op.top(); 
            op.pop();
        }

        cout << endl; //blank line after each expression

        if (i < N-1) cout << endl;
    }

    return 0;
}