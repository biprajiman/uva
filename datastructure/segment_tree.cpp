#include <vector>
#include <iostream>
#include <math.h>
#include <cstdio>
//https://www.hackerearth.com/practice/notes/segment-tree-and-lazy-propagation/
using namespace std;
typedef vector<int> vi;
#define REP(i, a, b) \
    for (int i = (int)a; i <= (int)b; ++i)

#define RANGE_SUM 0
#define RANGE_MAX 1
#define RANGE_MIN 2

class SegmentTree
{
  private:
    vi segment_tree;

  public:
    SegmentTree(int N)
    {
        // total size of array to store the tree 2*2^h + 1, 2 for left and right; 2^h, h = floor(log(N)) height of tree, +1 for root
        int h = (int)ceil(log(N) / log(2));
        int length = 2 * (int)pow(2.0, h);
        segment_tree.assign(length, 0); // resize and assign all the values 0
    }

    void build_segment_tree(int code, int index, int A[], int b, int e)
    {
        if (b == e)
        {
            if (code == RANGE_SUM)
                segment_tree[index] = A[b];
            else
                segment_tree[index] = b;
            return;
        }

        int leftIndex = 2 * index, rightIndex = 2 * index + 1;
        build_segment_tree(code, leftIndex, A, b, (b + e) / 2);
        build_segment_tree(code, rightIndex, A, ((b + e) / 2) + 1, e);
        int lcontent = segment_tree[leftIndex], rcontent = segment_tree[rightIndex];

        if (code == RANGE_SUM)
            segment_tree[index] = lcontent + rcontent;
        else
        {
            int lValue = A[lcontent], rValue = A[rcontent];
            if (code == RANGE_MIN)
                segment_tree[index] = (lValue <= rValue) ? lcontent : rcontent;
            else
                segment_tree[index] = (lValue >= rValue) ? lcontent : rcontent;
        }
    }

    int query(int code, int A[], int index, int b, int e, int i, int j){
        if(i > e || j < b) return -1; // we did not find the query range here

        if(b >= i && e <= j) return segment_tree[index]; //found the overlapping interval

        int p1 = query(code, A, 2*index, b, (b+e)/2, i, j);
        int p2 = query(code, A, 2*index+1, (b+e)/2+1, e, i, j);

        if(p1 == -1) return p2;
        if(p2 == -1) return p1;

        if (code == RANGE_SUM) return p1+p2;
        else if (code == RANGE_MAX) return (A[p1] >= A[p2])? p1: p2;
        else return (A[p1] <= A[p2])? p1: p2;
        
    }

    // add the code to update
    // explore lazy update as well
};

int main()
{
    int A[] = {8,7,3,9,5,1,10};
    SegmentTree ST(7);
    ST.build_segment_tree(RANGE_MIN, 1, A, 0, 6);
    printf("%d\n", ST.query(RANGE_MIN, A, 1, 0, 6, 1, 3)); // answer is index 2
    return 0;
}