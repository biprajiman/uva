#include <iostream>
#include <vector>
#include <cstdio>
#include <tuple>
#include <map>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef map<string, int> msi;
typedef tuple<bool, int, int> tbii;

#define REP(i, a, b) \
    for (int i = (int)a; i <= (int)b; i++)
#define RREP(i, a, b) \
    for (int i = (int)b; i >= (int)a; i--)

class UnionFind
{
  private:
    vi pset;
    vi setSize;
    int _numDisjointSet;
  public:
    UnionFind(int N)
    {
        _numDisjointSet = N;
        pset.resize(N);
        setSize.assign(N, 1);
        REP(i, 0, N-1) pset[i] = i;
    }

    tbii isSameSet(int i, int j){
        int x = findSet(i);
        int y = findSet(j);
        return (x == y)? std::make_tuple(true, x, y): std::make_tuple(false, x, y);
    }

    int findSet(int i){
        return (pset[i] == i)? i: (pset[i] = findSet(pset[i]));
    }

    void unionSet(int i, int j){
        tbii r = isSameSet(i, j);
        if(!std::get<0>(r)){
            --_numDisjointSet;
            pset[std::get<1>(r)] = std::get<2>(r);
            setSize[std::get<2>(r)] += setSize[std::get<1>(r)];
        }
    }

    int numDisjointSet(){ return _numDisjointSet; }
    int getSetSize(int i){ return setSize[findSet(i)]; }
};

int main()
{
    int N, F;
    int count = 0;

    cin >> N;
    string p1, p2;
    REP(i, 0, N - 1)
    {
        cin >> F;
        msi M;
        UnionFind UF(200000);// number of friendship formed is no more than 100000
        REP(j, 0, F - 1){
            cin >> p1 >> p2;
            
            if (M.find(p1) == M.end()){
                M[p1] = count; 
                count++;
            }
            
            if (M.find(p2) == M.end()){
                M[p2] = count;
                count++;
            }

            UF.unionSet(M[p1], M[p2]);

            cout << UF.getSetSize(M[p1]) << endl;
        }
    }
}