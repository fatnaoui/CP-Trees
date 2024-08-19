#include <iostream>
using namespace std;
#define ll long long int

ll lazy[1000] = {0};

void BuildTree(ll *a,ll s,ll e,ll *tree,ll index){
    if(s == e){
        tree[index] = arr[s];
        return ;
    }
    ll middle = (s + e)/2;
    BuildTree(a,s,middle,tree,2*index);
    BuildTree(a,middle+1,tree,2*index+1);
    tree[index] = min(tree[2*index],tree[2*index+1])
    return ;
}

void UpdateRangeLazy(ll s,ll e,ll l,ll r,ll *tree,ll inc,ll index){
    if(lazy[index] != 0){
        tree[index] += lazy[index];
        if(s != e){
            lazy[2*index] += lazy[index];
            lazy[2*index+1] += lazy[index];
        }
        lazy[index] = 0;
    }
    if((s > r) || (e < l)){
        return ;
    }
    if((l <= s) && (e <= r)){ // optimization
        tree[index] += inc;
        if(s != e){
            lazy[2*index] += inc;
            lazy[2*index] += inc;
        }
        return ;
    }
    ll middle =(s + e)/2;
    UpdateRangeLazy(s,middle,l,r,tree,inc,2*index);
    UpdateRangeLazy(middle+1,e,l,r,tree,inc,2*index+1);
    tree[index] = min(tree[2*index],tree[2*index+1]);
    return ;
}

int main() {
    ll arr[] = {3,2,5,4,1};
    ll n = sizeof(arr)/sizeof(ll);
    ll tree = new ll[4*n+1];
    BuildTree(a,0,n-1,tree,1)
}
