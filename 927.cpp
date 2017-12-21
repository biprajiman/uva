#include "all.h"


int findn(int d, int k){
    int i=1; 
    int prev = 0;
    int n = 0;
    for(;;i++){
        n += d*i;
        if(prev<k && k<=n) return n;
        prev = n;
    }
}

ll getVal(const int n, const vi& c){
    ll an = 0;
    ll curn = 1;
    for(int i=0; i<c.size(); i++){
        an += c[i] * curn;
        curn *= n;
    }

    return an;
}

int main(){
    
    return 0;
}

