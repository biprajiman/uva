#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
#define REP(i, a, b)\
    for(int i=(int)a; i<=(int)b; ++i)

// TLE with this
/*int bubbleSort(vi& v){
    int S = 0;
    vi tmp(v);
    // write merge sort and count swap
    //std::sort(tmp.begin(), tmp.end());
    REP(i, 0, v.size()-1){
        REP(j, 0, v.size()-2){
            if(v[j] > v[j+1]){
                swap(v[j], v[j+1]);
                S++;
            }
        }
    }
    
    return S % 2;
}*/

// needs to be passed onto the function so avoiding the stack copy
// just use the global
vi v(100001), vcopy(100001);


int merge(int start, int end){
    // Left source half is v[start:mid].
    // Right source half is v[mid+1:end].
    // Result is vcopy[start:end]
    int ns = 0; // number of swaps made    
    int i = start, mid = start + (end-start)/2;
    int j = mid + 1; 
    int k = start; // indexing for vcopy
    while(i <= mid && j <= end){
        if (v[i] <= v[j]) vcopy[k++] = v[i++]; // fill from left just copy
        else{ // swap left and right
            ns += (mid + 1) - i; // if v[i] > v[j] all elements to left will be large 
                                //than v[j] and need to swap with all
            ns %= 2;
            vcopy[k++] = v[j++];
        }
    }

    while(i <= mid) vcopy[k++] = v[i++]; // copy rest of left array
    while(j <= end) vcopy[k++] = v[j++]; // copy rest of right array
    REP(l, start, end) v[l] = vcopy[l]; // copy the array back to v
    return ns;
}

int mergeSort(int start, int end){
    if(start>=end) return 0;
    int mid = start + (end-start)/2; // more stable than just using (start+end)/2
    int s1 = mergeSort(start, mid), s2 = mergeSort(mid+1, end);
    int s3 =  merge(start, end);
    return (s1 + s2 + s3) % 2; // total swaps mod 2
}

int main(){
    int N;
    while(true){
        cin >> N;
        if(!N) return 0;
        REP(i, 0, N-1) cin >> v[i];
        cout << ((mergeSort(0, N-1) == 0)? "Carlos": "Marcelo") << "\n";
    }
    return 0;
}