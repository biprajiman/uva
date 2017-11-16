#include <iostream>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

typedef vector<int> vi;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int N; // number of test cases
    cin >> N;
    string s;
    getline(cin, s);

    for(int i = 0; i < N; ++i){
        int p; // number of places
        int m = 9999999;
        cin >> p;
        getline(cin, s);// flush cin
        vi darr(p, 0);
        
        for(int j=0; j<p; j++){
            getline(cin, s);
            stringstream ss(s);
            string t;
            while(getline(ss, t, ' ')){
                ++darr[j];
            }

            if(darr[j] < m) m = darr[j];
        }

        getline(cin, s);// flush space
        int count = 0;
        for(int j=0; j<p; ++j){
            if (darr[j] == m) {
                if (count > 0) cout << " ";
                cout << (j+1);
                count = 1;
            }
        }

        cout << endl;

    }
    return 0;
}