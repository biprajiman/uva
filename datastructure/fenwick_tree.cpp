#include <vector>
#include <iostream>

using namespace std;
typedef vector<int> vi;

// implemented for Range Sum Query (stores sum upto ith)
class FenwickTree{
    private:
        vi B, A;
        int LSOne(int i){return (i & (-i)); }
    public:
        FenwickTree(const vi& _A){
            int N = _A.size();
            B.assign(N+1, 0);
            A = A;
        }

        void update(int i, int val){
            //propagate the val 
            for(; i<=B.size(); i += LSOne(i)) B[i] += val;
        }

        int query(int i)
        {
            int sum = 0;
            for(; i>0; i -= LSOne(i)) sum += B[i];
            return sum;
        }

        void build(){
            for(int i=0; i<A.size(); i++){
                update(i+1, A[i]);
            }
        }
}