#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int B1, B2, B3, G1, G2, G3, C1, C2, C3;
    string config[] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};

    while(scanf("%d %d %d %d %d %d %d %d %d", &B1, &G1, &C1, &B2, &G2, &C2, &B3, &G3, &C3) 
    != EOF){
        int a[6];
        //BCG B1 C2 G3
        a[0] = B2 + B3 + G1 + G2 + C1 + C3;
        //BGC B1 G2 C3
        a[1] = B2 + B3 + G1 + G3 + C1 + C2;
        //CBG C1 B2 G3
        a[2] = B1 + B3 + G1 + G2 + C2 + C3;
        //CGB C1 B3 G2
        a[3] = B1 + B2 + G1 + G3 + C2 + C3;
        //GBC G1 B2 C3
        a[4] = B1 + B3 + G2 + G3 + C1 + C2;
        //GCB G1 B3 C2
        a[5] = B1 + B2 + G2 + G3 + C1 + C3;

        int best_min = INT_MAX;
        
        string s;
        for(int i = 0; i<6; ++i){
            if(a[i]<best_min || (a[i]==best_min && config[i]<s)){
                best_min = a[i];
                s = config[i];
            }
        }

        cout << s << " " << best_min << endl;
    }

    return 0;    
}