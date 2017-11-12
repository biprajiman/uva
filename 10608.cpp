#include <vector>
#include <map>
#include <iostream>
#include <tuple>
#include <numeric>

using namespace std;

#define REP(i, a, b)\
    for(int i=int(a); i<=int(b); ++i)
typedef vector<int> vi;
typedef tuple<bool, int, int> tbii;

class UnionFind{
    private:
        int _numDisjointSet;
        int maxSetSize;
        vi p;
        vi setSize;
    public:
        UnionFind(int N){
            _numDisjointSet = N;
            p.resize(N);
            setSize.assign(N, 1);
            maxSetSize = 1;
            REP(i, 0, N-1) p[i] = i;
        }

        tbii isSameSet(int i, int j){
            int x = findSet(i);
            int y = findSet(j);
            return (x==y)? std::make_tuple(true, x, y): std::make_tuple(false, x, y);
        }
        int findSet(int i){ return (p[i]==i)? i: (p[i] = findSet(p[i])); }
        void unionSet(int i, int j){
            tbii r = isSameSet(i, j);
                if(std::get<0>(r)) return;
                
                --_numDisjointSet;
                p[std::get<1>(r)] = std::get<2>(r);
                setSize[std::get<2>(r)] += setSize[std::get<1>(r)];
                maxSetSize = std::max(maxSetSize, setSize[std::get<2>(r)]);
         }

        int getMaxSetSize(){ return maxSetSize; }
        int getSetSize(int i){ return setSize[findSet(i)]; }
        int numOfDisjointSet(){ return _numDisjointSet; }

};

int main(){
    int T, N, M;
    cin >> T;
    int f1, f2;
    REP(i, 0, T - 1){
        cin >> N >> M;
        UnionFind UF(N+1);

        REP(i, 0, M - 1){
            cin >> f1 >> f2;
            UF.unionSet(f1, f2);
        }

        cout << UF.getMaxSetSize() << endl;
    }

    return 0;
}