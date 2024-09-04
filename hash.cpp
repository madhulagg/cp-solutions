#include<bits/stdc++.h>
using namespace std;

struct myHash{
    int *arr;
    int cap, size;
    myHash(int c){
        cap = c;
        size = 0;
        for(int i = 0 ; i < size ; i++){
            arr[i] = -1;
        }
    }
    int hash (int key){
        return key % cap;
    }
};

int main(){
    return 0;
}