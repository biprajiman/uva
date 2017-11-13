#include <vector>
#include <iostream>
using namespace std;

typedef unsigned long long ll;
#define REP(i, a, b)\
    for(ll i = (ll)a; i <= (ll)b; i++)
typedef vector<int> vi;


vi v(500000), vcopy(500000);
ll merge(ll start, ll end){
    ll mid = start + (end-start)/2;
    ll i = start, j = mid+1;
    ll k = start;
    ll ns = 0;
    while(i<=mid && j<=end){
        if(v[i] <= v[j]) vcopy[k++] = v[i++];
        else{
            ns += (mid+1) - i;
            vcopy[k++] = v[j++];
        }
    }
    
    while( i <= mid) vcopy[k++] = v[i++];
    while( j <= end) vcopy[k++] = v[j++];
    REP(l, start, end) v[l] = vcopy[l];

    return ns;
}

ll mergeSort(ll s, ll e){
    if(s >= e) return 0;
    ll mid = s + (e-s)/2;
    ll s1 = mergeSort(s, mid), s2 = mergeSort(mid+1, e);
    ll s3 = merge(s, e);

    return s1 + s2 + s3;
}

int main(){
    ll N;
    
    while(true){
        cin >> N;

        if(!N) return 0;
        
        REP(i, 0, N-1) cin >> v[i];
        
        cout << mergeSort(0, N-1) << endl;
    }
}