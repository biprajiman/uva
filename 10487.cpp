#include "all.h"

int binarySearch(const vi &S, const int &q, int l, int h){
    if(l==h) return S[l];

    
    if(h - l == 1){

        int diff1 = abs(S[l] - q);
        int diff2 = abs(S[h] - q);

        if(diff1 < diff2) return S[l];
        else return S[h];
    }

    int mid = l + (h - l)/2;
    if(q <= S[mid] ) return binarySearch(S, q, l, mid);
    else return binarySearch(S, q, mid, h);
}

int main(){
    READ();
    WRITE();
    int n, m, q;
    int c = 1;
    while(true){
        SI(n);
        if(n==0) break;
        vi A(n), S;
        SVI(A, n);
        
        SI(m);

        for(int i=0; i<A.size(); i++){
            for(int j=i+1; j<A.size(); j++){
                S.push_back(A[i] + A[j]);
            }
        }

        sort(S.begin(), S.end());

        cout << "Case: " << c++ << endl;

        while(m--){
            SI(q);
            printf ("Closest sum to %d is %d.\n", q, binarySearch (S, q, 0, S.size()));
        }

    }

    return 0;
}