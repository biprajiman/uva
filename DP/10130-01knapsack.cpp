#include "../all.h"

#define MAX_N 1010
#define MAX_W 40

int memo[MAX_N][MAX_W];
vi V(MAX_N), W(MAX_N);
int N;
// top down (recursion + memo)

int value(int id, int remW)// item being considered and remainder of the weights
{ 
    if(remW==0 || id==N) return 0; // no weight left so just return 0
    if(memo[id][remW]!=-1) return memo[id][remW];
    if(W[id] > remW) return value(id+1, remW); //ignore this weight cannot use it
    return max(value(id+1, remW), value(id+1, remW- W[id]));
}


int main(){
    int T, G, ans, MW;
    scanf("%d", &T);
    while (T--){
        memset(memo, -1, sizeof memo);

        scanf("%d", &N);

        for(int i = 0; i < N; i++) scanf("%d %d", &V[i], &W[i]);

        ans = 0;
        scanf("%d", &G);
        while (G--){
            scanf("%d", &MW);
            ans += value(0, MW);
        }
        
        printf("%d\n", ans);
    }
    return 0;
}

// bottom up
/*int main(){
    int T, G, ans, MW;
    scanf("%d", &T);
    while (T--){
        memset(memo, 0, sizeof memo);

        scanf("%d", &N);

        for(int i = 1; i <= N; i++) scanf("%d %d", &V[i], &W[i]);

        ans = 0;
        scanf("%d", &G);
        while (G--){
            scanf("%d", &MW);
            for(int i=0; i<=N; i++) memo[i][0] = 0; // 0 max weight
            for(int w=0; w<=MW; w++) memo[0][w] = 0; // 0 item with all the weights

            for(int i=1; i<=N; i++){
                for(int w=1; w<=MW; w++){ // total weight
                    if(W[i] <= w){
                        memo[i][w] = max(memo[i-1][w], V[i]+memo[i-1][w-W[i]]); // whatever is left after using this w-W[i]
                    }else{
                        memo[i][w] = memo[i-1][w];
                    }
                }
            }

            ans += memo[N][MW];
        }
        
        printf("%d\n", ans);
    }
    return 0;
}*/