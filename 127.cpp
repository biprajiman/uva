#include <vector>
#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

typedef pair<char, char> card;
vector< stack<card> > cards;

bool isMatch(card c1, card c2){
    return c1.first ==  c2.first || c1.second == c2.second;
}

int main(){
    string s;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    while(cin>>s && s != "#"){
        cards.clear();

        // reading and creating the card stacks
        stack<card> st;
        st.push(card(s[0], s[1]));
        cards.push_back(st);
        for(int i=0; i<51; i++){
            cin >> s;
            stack<card> st;
            st.push(card(s[0], s[1]));
            cards.push_back(st);
        }

        int mback;
        for(int i=0; i<cards.size(); i++){
            mback = 0;
            if(i>=3 && isMatch(cards[i].top(), cards[i-3].top())){
                cards[i-3].push(cards[i].top());
                cards[i].pop();
                mback = 4; //start from i-3// -4 here because i will be added 1 in for loop
            } 
            else if (i >= 1 && isMatch(cards[i].top(), cards[i-1].top())){
                cards[i-1].push(cards[i].top());
                cards[i].pop();
                mback = 2;
            }

            if(cards[i].empty()) cards.erase(cards.begin()+i);

            if(mback > 0) i -= mback;
        }
        
        printf("%d pile%s remaining:", (int)cards.size(), ((cards.size()==1)? "": "s"));
        for(int i=0; i < cards.size(); ++i){
            cout << " " << cards[i].size();
        }

        cout << endl;
    }

    return 0;
}