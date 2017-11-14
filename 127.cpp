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

        bool move = true;
        while(move){
            move = false;
            for(int i=0; i<cards.size(); i++){
                if(i>=3 && isMatch(cards[i].top(), cards[i-3].top())){
                    cards[i-3].push(cards[i].top());
                    cards[i].pop();
                    move = true;
                } 
                else if (i >= 1 && isMatch(cards[i].top(), cards[i-1].top())){
                    cards[i-1].push(cards[i].top());
                    cards[i].pop();
                    move = true;
                }

                if(cards[i].empty()) cards.erase(cards.begin()+i);
            }
        }

        printf("%d piles remaining:", (int)cards.size());
        for(int i=0; i < cards.size(); ++i){
            cout << " " << cards[i].size();
        }

        cout << endl;

    }

    return 0;
}