#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef vector<int> vi;
#define REP(i, a, b)\
    for(int i=(int)a; i<=(int)b; ++i)

int bubbleSort(vi& v){
    int S = 0;

    REP(i, 0, v.size()-1){
        REP(j, 0, v.size()-2){
            if(v[j] > v[j+1]) {
                swap(v[j], v[j+1]);
                S++;
            }
        }
    }

    return S;
}

int main(){
    int N;
    cin >> N;
    REP(i, 0, N-1){
        int L;
        cin >> L;
        vi v(L, 0);
        REP(j, 0, L-1) cin >> v[j];
        printf("Optimal train swapping takes %d swaps.\n", bubbleSort(v));
    }

    return 0;
}
