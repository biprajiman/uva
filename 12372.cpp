#include "all.h"

const int MAXALLOWED = 20;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    int TC;
    scanf("%d\n", &TC);
    int i = 1;
    while(TC--){
        int l, w, h;
        bool good = true;
        scanf("%d %d %d\n", &l, &w, &h);
        if(l > MAXALLOWED || w > MAXALLOWED || h > MAXALLOWED) good = false;

        if(good) cout << "Case " << i <<": good" << endl;
        else  cout << "Case " << i <<": bad" << endl;

        i++;
    }
    return 0;

}