#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

using namespace std;

#define REP(i, a, b)\
    for(int i = int(a); i<=int(b); ++i)
#define RREP(i, a, b)\
    for(int i = int(b); i>=int(a); --i)
typedef vector<int> vi;
typedef vector< pair<int, int> > vii;

struct addressarray;
void getCoefficients(addressarray& a);

struct addressarray {
    int B;
    int BS;
    int D;
    vi C;
    int C0;
    vii UL;
    friend void operator>>(istream& is, addressarray& a);
};

typedef map<string, addressarray> msi;

void operator>>(istream& is, addressarray& a){
    cin >> a.B >> a.BS >> a.D;
    REP(i, 0, a.D - 1){
        int a1, a2;
        cin >> a1 >> a2;
        a.UL.push_back(std::make_pair(a1, a2));
    }
    getCoefficients(a);
}

// THIS GIVE TLE
/*void parseArrayString(string s, string& name, addressarray& a){
    //NAME B byte_size D D_pairs_of_lower_and_upper_bounds 
    stringstream ss(s);
    int i = 0;
    string t;
    while(getline(ss, t, ' ')){
        if (i == 0) name = t;
        else if(i == 1) a.B = stoi(t);
        else if(i == 2) a.BS = stoi(t);
        else if (i == 3) a.D = stoi(t);
        else {
            int a1 = stoi(t);
            getline(ss, t, ' ');
            int a2 = stoi(t);
            a.UL.push_back(std::make_pair(a1, a2));
        }
        ++i;
    }
}*/

void getCoefficients(addressarray& a){
    a.C = vi(a.D);
    a.C0 = a.B;
    a.C[a.D - 1] = a.BS;
    RREP(i, 0, a.D-2) a.C[i] = a.C[i+1] * (a.UL[i+1].second - a.UL[i+1].first + 1);
    REP(i, 0, a.D-1) a.C0 -= a.C[i]*a.UL[i].first;
}

int main(){
    int N, R;
    cin >> N >> R;

    string name;
    msi M;
    REP(i, 0, N-1)
    {   
        addressarray a;
        cin >> name;
        cin >> a;    
        M[name] = a; // save the array index of map
    }

    int index;
    REP(i, 0, R-1)
    {
        cin >> name;
        cout << name << "[";
        int result = M[name].C0;
        REP(j, 0, M[name].D - 1)
        {
            cin >> index;
            result += M[name].C[j] * index;
            if(j != M[name].D - 1) cout << index << ", ";
            else cout << index << "]";
        }
        cout << " = " << result << endl;
    }
    
    return 0;
}

// GIVES TLE
/*int main(){
    int N, R;
    cin >> N >> R;

    string s, name;
    int B;
    msi M; 

    REP(i, 0, N-1){
        if(getline(cin, s)){
            addressarray a;
            parseArrayString(s, name, a);
            getCoefficients(a);
            M[name] = a; // save the array index of map
        }
    }

    int index;
    REP(i, 0, R-1)
    {
        cin >> name;
        cout << name << "[";
        int result = M[name].C0;
        REP(j, 0, M[name].D - 1)
        {
            cin >> index;
            result += M[name].C[j] * index;
            if(j != M[name].D - 1) cout << index << ", ";
            else cout << index << "]";
        }
        cout << " = " << result << endl;
    }
    
    return 0;
}*/

