#include "all.h"

/*int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int k;
    while(scanf("%d\n", &k)!=EOF){
        map<double, int> frac;
        double target = (double)1/k;
        vii result;
        for(int i=10000; i>0; i--)
        {
            double temp = (double)1/i;
            frac[temp] = i;
        }

        for(int j=1; j<=10000; j++){
            double res = target - (double)1/j;
            if(frac.find(res)!=frac.end()) result.push_back({frac[res], j});
        }

        cout << result.size() << endl;
        for(ii p: result) printf("1/%d = 1/%d + 1/%d\n", k, p.first, p.second); 
    }

    return 0;
}*/

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int k;
    while(scanf("%d\n", &k)==1){
        vii result;
        for(int i=k+1; i<=2*k; i++){
            if((i*k) % (i-k) == 0) // signifies integer result
            {
                result.push_back(std::make_pair((i*k)/(i-k), i));
            }
        }

        cout << result.size() << endl;
        for(ii p: result) printf("1/%d = 1/%d + 1/%d\n", k, p.first, p.second);
    }
    return 0;
}