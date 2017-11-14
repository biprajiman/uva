#include <stack>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
/*
Very hard to understand
So basically we have a stream of numbers from 1 to N
we have a target sequence we want to achieve
We have to figure out if we can read the first stream such that second stream configuration could be achieved
*/
void marshals(int N){
    stack<int> cars;
    
    int c;
    while(true){ // process blocks
        while(!cars.empty()) cars.pop();
        vi train(N, 0);
        for(int i = 0; i < N; i++) // one block
        {
            // if 0 we are done with block
            cin >> c; // read in the first configuration number
            if(!c) return;
            train[i] = c;
        }
        
        int j = 1;
        int i = 0;
        while(j <= N){ // input streams from 1..N
            cars.push(j);
            while(!cars.empty() && i < N && cars.top() == train[i])
            {
                cars.pop();
                ++i;
            }
            ++j;
        }

        if(cars.empty()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

}

int main(){
    int n;
    while(true){
        cin >> n;
        if(!n) return 0;
        marshals(n);
        cout << endl;
        
    }
}
