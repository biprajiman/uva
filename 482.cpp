#include <vector>
#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <numeric>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;

vi splitInd(string& s){
    vi v;
    stringstream ss(s);
    string t;
    while(getline(ss, t, ' ')){
        v.push_back(stoi(t));
    }

    return v;
}

vs splitNum(const string& s){
    vs v;
    stringstream ss(s);
    string t;
    while(getline(ss, t, ' ')){
        v.push_back(t);
    }
    return v;
}

int main(){
    int N;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> N;
    
    string s;
    getline(cin, s);

    for(int i = 0; i < N; ++i) // number of test cases
    {
        getline(cin, s);
        getline(cin, s);
        vi inds = splitInd(s);

        getline(cin, s);
        vs nums = splitNum(s);
        vs ncopy(nums);

        for(int j = 0; j < inds.size(); ++j){
            ncopy[inds[j]-1] = nums[j];
        }

        for(int j = 0; j < inds.size(); ++j){
            cout <<  ncopy[j] << endl;
        }
        
        if(i < N-1) cout << endl;
    }

    return 0;
}