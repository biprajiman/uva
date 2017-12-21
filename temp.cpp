#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    
    int B[3], G[3], C[3];
    string config[] = {"BGC", "BCG", "GBC", "GCB", "CBG", "CGB"};
    string s;

    int sumB, sumG, sumC, i;
    ll cur, best_min;

    while(scanf("%d %d %d %d %d %d %d %d %d", &B[0], &G[0], &C[0], &B[1], &G[1], &C[1], &B[2], &G[2], &C[2]) == 9)
    {
        int a[] = {0, 1, 2}; // makes sure values are  kept fixed

        sumB = B[0] + B[1] + B[2];
        sumG = G[0] + G[1] + G[2];
        sumC = C[0] + C[1] + C[2];
        best_min = (1LL << 31);

        i = 0;
        
        do{
            cur = sumB - B[a[0]] + sumG - G[a[1]] + sumC - C[a[2]];

            if(cur < best_min || (best_min == cur && config[i] < s)){
                best_min = cur;
                s = config[i];
            }

            i++;

        }while(next_permutation(a, a+3)); //permute for 6 different possibilities
        
        cout<< s << " " << best_min << endl;
    }

    return 0;    
}