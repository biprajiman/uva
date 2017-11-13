#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
#define REP(i, a, b)\
    for(int i=(int)a; i<=(int)b; ++i)

int bubbleSort(vi& v){
    int S = 0;
    vi tmp(v);
    // write merge sort and count swap
    //std::sort(tmp.begin(), tmp.end());
    /*REP(i, 0, v.size()-1){
        REP(j, 0, v.size()-2){
            if(v[j] > v[j+1]){
                swap(v[j], v[j+1]);
                S++;
            }
        }
    }*/
    
    return S % 2;
}

int main(){
    int N;
    while(true){
        cin >> N;
        if(!N) return 0;
        vi v(N, 0);
        REP(i, 0, N-1) cin >> v[i];
        cout << ((bubbleSort(v) == 0)? "Carlos": "Marcelo") << "\n";
    }
    return 0;
}