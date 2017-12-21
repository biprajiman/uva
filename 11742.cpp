#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxM =  22;
int n, m, p[10];
int a[maxM], b[maxM], c[maxM];

bool accepted(){
    for(int i=0; i < m; i++){
        if(c[i]>0 && abs(p[a[i]]-p[b[i]]) > c[i]) return false; //atmost
        if(c[i]<0 && abs(p[a[i]]-p[b[i]]) <  -c[i]) return false; //atleast
    }

    return true;
}

int main(){
    freopen("input.txt", "r", stdin);
    while (scanf("%d %d", &n, &m) && (n + m)) {
        for(int i=0; i<m; i++) scanf("%d %d %d", &a[i], &b[i], &c[i]);
        for(int i=0; i<n; i++) p[i] = i;

        int res = 0;
        do{
            if(accepted()) ++res;
        }while(next_permutation(p, p+n));

        printf("%d\n", res);
    }
    return 0;
}