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
    vi segment_tree, A;
    int left(int p){ return (p << 1); }
    int right(int p){ return (p << 1) + 1; }

  public:
    SegmentTree(const vi _A)
    {
        // total size of array to store the tree 2*2^h + 1, 2 for left and right; 2^h, h = floor(log(N)) height of tree, +1 for root
        //int h = (int)ceil(log(N) / log(2));
        //int length = 2 * (int)pow(2.0, h);
        int N = _A.size();
        A = _A;
        int length = 4*N; // approximate
        segment_tree.assign(length, 0); // resize and assign all the values 0
    }

    void _merge(int code, int &a, int &b, int &c){ //merge information from b and c to a node
        /*
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
        */
        if (code == RANGE_SUM)
            a = b + c;
        else
        {
            int lValue = A[b], rValue = A[c];
            if (code == RANGE_MIN)
                a = (lValue <= rValue) ? b : c;
            else
                a = (lValue >= rValue) ? b : c;
        }
    }

    void build(int code, int index, int b, int e)
    {
        if (b == e)
        {
            if (code == RANGE_SUM)
                segment_tree[index] = A[b];
            else
                segment_tree[index] = b;
            return;
        }

        int leftIndex = left(index), rightIndex = right(index);

        build(code, leftIndex, b, (b + e) / 2);
        build(code, rightIndex, ((b + e) / 2) + 1, e);
        _merge(code, segment_tree[index], segment_tree[leftIndex], segment_tree[rightIndex]);
    }

    void update(int code, int index, int b, int e, int pos){//pos defines update pos in the array A
        if(b == e){
            if(code == RANGE_SUM)
                segment_tree[index] = A[pos];
            else 
                segment_tree[index] = pos;
            return;
        }

        int mid = ((b+e) >> 1);
        if(pos <= mid)
            update(code, left(index), b, mid, pos);
        else
            update(code, right(index), mid+1, e, pos);
        
        _merge(code, segment_tree[index], segment_tree[left(index)], segment_tree[right(index)]);
    }

    int query(int code, int index, int b, int e, int i, int j){
        if(i > e || j < b) return -1; // we did not find the query range here

        if(b >= i && e <= j) return segment_tree[index]; //found the overlapping interval

        int p1 = query(code, 2*index, b, (b+e)/2, i, j);
        int p2 = query(code, 2*index+1, (b+e)/2+1, e, i, j);

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
    vi A = {8,7,3,9,5,1,10};
    SegmentTree ST(A);
    ST.build(RANGE_MIN, 1, 0, 6);
    printf("%d\n", ST.query(RANGE_MIN, 1, 0, 6, 1, 3)); // answer is index 2
    return 0;
}