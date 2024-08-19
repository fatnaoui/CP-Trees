#include <bits/stdc++.h>
using namespace std;
#define ll int
#define F(i,a,b) for(int i=a;i<=b;i++)

// example of a tree to find the minimum element in a specific range
void BuildTree(ll *a,ll s,ll e,ll *tree,ll index){
    // base case
    if(s == e){
        tree[index] = a[s];
        return ;
    }
    ll middle = (s + e)/2;

    // Recursive case
    BuildTree(a,s,middle,tree,2*index);
    BuildTree(a,middle+1,e,tree,2*index+1);
    tree[index] = min(tree[2*index],tree[2*index+1]);
    return ;
}

int main() {
    ll a[] = {1,3,2,-5,6,4};
    ll n = sizeof(a)/sizeof(ll);
    ll *tree = new ll[4*n+1];
    BuildTree(a,0,n-1,tree,1);
    F(i,1,4*n){
        cout<<tree[i]<<' ';
    }
    // you will get garbage values at index 10 and 11
}
