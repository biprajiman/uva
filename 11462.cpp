#include <iostream>
#include <vector>

using namespace std;

typedef vector<long> vi;

#define REP(i, a, b)\
    for(int i= (int)a; i<=(int)b; ++i)

void printV(vi& v){
    int N = 100;
    int counter = 0;
    
    REP(i, 0, N){
        while(v[i]) {
            if(counter > 0) cout << " ";
            cout << i;
            v[i]--;
            counter = 1;
        }
    }
    
    cout << endl;
}

int main(){
    int N;
    while(true){
        cin >> N;
        if (N<=0) return 0;
        int n;
        vi v(101, 0);
        REP(i, 0, N - 1){
            cin >> n;
            v[n]++;            
        }
        printV(v);
    }
    
}