#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <set>
#include <vector>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
typedef unodered_map<string, int> umsi;
typedef set<string> ss;

#define REP(i, a, b) \
    for(int i =(int)a; i<=(int)b; i++) // a to b, and variable i is local!
#define TRvi(c, it) \
    for(vi::iterator it = (c).begin(); it != (c).end(); it++)