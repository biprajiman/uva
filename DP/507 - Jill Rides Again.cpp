#include "./all.h"

using namespace std;

int main(){
    vi A = {4, -5, 4, -3, 4, 4, -4, 4, -5};
    vi dp(A.size()+1, 0);

    for(int i=1; i<=A.size();i++){
        dp[i] = max(dp[i], dp[i-1]+A[i-1]);
    }

    return dp[A.size()-1];
}