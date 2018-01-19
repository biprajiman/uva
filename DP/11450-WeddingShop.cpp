/*
Learn the DP recurse and memo
Alternative bottom up
*/
#include "./all.h"

int M, C;
vvi memo(210, vi(25, -1)); // 200 Money (M) limits and 20 garments (C) limits
vi p(25, vi(25, 0)); // max of 20 garments(C) with 20 different models(K) limits

// RECURSIVE BACKTRACK
int shop(int money, int g){ //money left
    if(money<0) return -100000;
    if(g==C)// we have a winner
    {
        return M-money;
    }

    int K = price[g][0]; // different models for this garment
    int ans = -1;
    for(int i=1; i<=K; i++){
        ans = max(ans, shop(money-price[g][i], g+1)); // try this model and other garments
    }

    return ans;
}


// RECURSIVE BACKTRACK WITH MEMO Top Down DP
int shop(int money, int g){ //money left
    if(money<0) return -100000;
    if(g==C)// we have a winner
    {
        return M-money;
    }
    if(memo[money][g]!=-1) return memo[money][g];

    int K = price[g][0]; // different models for this garment
    int ans = -1;
    for(int i=1; i<=K; i++){
        ans = max(ans, shop(money-price[g][i], g+1)); // try this model and other garments
    }

    return memo[money][g]=ans;
}

int main() {
    // easy to code if you are already familiar with it
    int i, j, TC, score;
    scanf("%d", &TC);
    while (TC--)
    {
        scanf("%d %d", &M, &C);
        for (i = 0; i < C; i++)
        {
            scanf("%d", &price[i][0]);
            // store K in price[i][0]
            for (j = 1; j <= price[i][0]; j++)
                scanf("%d", &price[i][j]);
        }
        //memset(memo, -1, sizeof memo);
        // TOP-DOWN: initialize DP memo table
        score = shop(M, 0);
        // start the top-down DP
        if (score < 0)
            printf("no solution\n");
        else
            printf("%d\n", score);
} } // return 0;