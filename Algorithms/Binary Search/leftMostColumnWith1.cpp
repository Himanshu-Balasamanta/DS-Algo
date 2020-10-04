#include<bits/stdc++.h>
using namepsace std;

class BinaryMatrix {
  public:
    int get(int row, int col);
    vector<int> dimensions();
};

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &bin) {
        
        int n, m, i = 0, j = 0, u, l , mid;
        n = bin.dimensions()[0], m = bin.dimensions()[1];
        for(i = 0; i != n; i++){
            l = 0, u = m - 1;
            while(l <= u){
                mid = (l + u)/2;
                if(bin.get(i,mid))u = mid - 1;
                else l = mid + 1;
            }
            if(l != m)break;
        }
        if(i == n)return -1;
        while(i != n){
            for(; i != n; i++)if(bin.get(i,l))break;
            if(i == n)return l;
            u = l; l = 0;
            while(l <= u){
                mid = (l + u)/2;
                if(bin.get(i,mid))u = mid - 1;
                else l = mid + 1;
            }
        }
        return l;
    }
};

int main()
{}