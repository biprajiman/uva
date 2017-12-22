#include "all.h"

int findn(int d, int k){
    int i=1; 
    int prev = 0;
    int n = 0;
    for(;;i++){
        n += d*i;
        if(prev<k && k<=n) return i;// ith term is the one
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
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int TC;
    scanf("%d\n", &TC);

    while(TC--){
        vi C;
        int i;
        scanf("%d", &i);

        int c;
        for(int j=0; j<=i; j++) {
            scanf("%d", &c);
            C.push_back(c);
        }
        int d, k;

        scanf("%d %d\n", &d, &k);
        
        int n = findn(d, k);

        cout<<getVal(n, C)<<endl; 
        
    }
    return 0;
}

