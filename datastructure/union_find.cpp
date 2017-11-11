/*--Union-Find Disjoint Sets--
References : https://github.com/luisfcofv/competitive-programming-book/blob/master/ch2/ch2_08_unionfind_ds.cpp
*/
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

//--Macros--BEGIN--
typedef vector<int> vi;
#define REP(i, a, b) \
        for (int i = (int)a; i <= (int)b; ++i)
//--Macros--END--
// uncomment rank to use both path compression and rank heuristic
class UnionFind
{
  private:
    vi pset = vi(1000), setSize = vi(1000); // rank = vi(1000, 0); 
    int numberOfSets;
    void initSet(int _size){ pset.resize(_size); setSize.assign(_size, 1); REP(i, 0, _size - 1) pset[i] = i; // rank.assign(N, 0); }
  public:
    UnionFind(int N) { initSet(N); numberOfSets=N; }
    int findSet(int i) { return (pset[i] == i) ? i : (pset[i] = findSet(pset[i])); } //return findSet(pset[i]); // to use without path compression
    void unionSet(int i, int j){ 
        tuple<int, int, bool> r = isSameSet(i, j); 
        if(!std::get<2>(r)) {
            --numberOfSets;
            // rank heuristics
            /* int x = std::get<0>(r), y = std::get<1>(r);
            if(rank[x]>rank(y)){
                pset[y] = x;
            }else{
                pset[x] = y;
                if(rank[x] == rank[y]) ++rank[y];
            }*/
            pset[std::get<0>(r)] = std::get<1>(r); // set parent of parent of i = parent of j
            setSize[std::get<1>(r)] += setSize[std::get<0>(r)]; // increase the set size for parent of j
        }
    }

    tuple<int, int, bool> isSameSet(int i, int j){ 
        tuple<int, int, bool> r;
        int x = findSet(i); int y = findSet(j);
        return (x == y)? std::make_tuple(x, y, true): std::make_tuple(x, y, false);
    }

    int numberOfDisjointSets(){ return numberOfSets; }
    int sizeOfSet(int i){ return setSize[findSet(i)]; }
};

int main() {
    printf("Assume that there are 5 disjoint sets initially\n");
    UnionFind UF(5); // create 5 disjoint sets
    printf("%d\n", UF.numberOfDisjointSets()); // 5
    UF.unionSet(0, 1);
    printf("%d\n", UF.numberOfDisjointSets()); // 4
    UF.unionSet(2, 3);
    printf("%d\n", UF.numberOfDisjointSets()); // 3
    UF.unionSet(4, 3);
    printf("%d\n", UF.numberOfDisjointSets()); // 2
    printf("isSameSet(0, 3) = %d\n", std::get<2>(UF.isSameSet(0, 3))); // will return 0 (false)
    printf("isSameSet(2, 3) = %d\n", std::get<2>(UF.isSameSet(2, 3))); // will return 1 (true)
    for (int i = 0; i < 5; i++) // findSet will return 1 for {0, 1} and 3 for {2, 3, 4}
      printf("findSet(%d) = %d, sizeOfSet(%d) = %d\n", i, UF.findSet(i), i, UF.sizeOfSet(i));
    UF.unionSet(0, 3);
    printf("%d\n", UF.numberOfDisjointSets()); // 1
    for (int i = 0; i < 5; i++) // findSet will return 3 for {0, 1, 2, 3, 4}
      printf("findSet(%d) = %d, sizeOfSet(%d) = %d\n", i, UF.findSet(i), i, UF.sizeOfSet(i));
    return 0;
}