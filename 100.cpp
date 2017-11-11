#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int cl(int n){
    int l=1; // count 1
    while(n!=1){
        n = (n%2)? (3*n+1): n/2;
        ++l;
    }
    return l;
}

int mcl(int a, int b){
    int m = 0;
    for(; a<=b; ++a)
        m = std::max(m, cl(a));
    return m;
}

int main(){
    int a, b;
    while(scanf("%d %d\n", &a, &b)==2) // scanf returns number of items in the argument list successfully filled
    {
        printf("%d %d %d\n", a, b, mcl(std::min(a, b), std::max(a, b)));
    }

    return 0;
}
