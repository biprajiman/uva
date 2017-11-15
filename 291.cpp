#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

vii neighbors(5, vi(5, 0));
vi ans(9, 0);

void dfs(int row, int count){
    ans[count] = row;       
    if(count == 8){ // total of 8 connections so 9 edges
        for(int i=0; i < 9; ++i){
            cout << ans[i] + 1;
        }
        cout << endl;
        return;
    }

    for(int i = 0; i < 5; ++i){
        if(neighbors[row][i]){ // take this path and try
            neighbors[row][i] = neighbors[i][row] = 0;
            dfs(i, count+1);
            neighbors[row][i] = neighbors[i][row] = 1; // reset
        }
    }
}

int main(){
    // possibilities of paths
    neighbors [0] [1] = neighbors [0] [2] = neighbors [0] [4] = 1;
    neighbors [1] [0] = neighbors [1] [2] = neighbors [1] [4] = 1;
    neighbors [2] [0] = neighbors [2] [1] = neighbors [2] [3] = neighbors [2] [4]= 1;
    neighbors [3] [2] = neighbors [3] [4] = 1;
    neighbors [4] [0] = neighbors [4] [1] = neighbors [4] [2] = neighbors [4] [3]= 1;

    dfs(0, 0);

    return 0;
}
