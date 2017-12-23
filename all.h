#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>
#include <cmath>
#include <set>
//#include <bits/stdc++.h>

using namespace std;
//------macros----------------
#define SI(n) scanf("%d\n", &n)
#define SII (n1, n2) scanf("%d %d\n", &n1, &n2)
#define SVI(a, n) \
    for(int i=0; i<n; i++){\
        scanf("%d\n", &a[i]);\
    }
#define READ() freopen("input.txt","r",stdin);
#define WRITE() freopen("output.txt","w",stdout);

//------most used typedef-----
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;