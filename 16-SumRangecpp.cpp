#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll lazy[1000] = {0};

void BuildTree(ll *arr,ll s,ll e,ll *tree,ll index){
    if(s == e){
        tree[index] = arr[s];
        return ;
    }
    ll middle = (s + e)/2;
    BuildTree(arr,s,middle,tree,2*index);
    BuildTree(arr,middle+1,e,tree,2*index+1);
    tree[index] = tree[2*index]+tree[2*index+1];
    return ;
}

void UpdateRangeLazy(ll s,ll e,ll l,ll r,ll *tree,ll inc,ll index){
    if(lazy[index] !=0){
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
    if((s >= l) && (e <= r)){
        tree[index] += inc*(r-l+1);
        if(s != e){
            lazy[2*index] += inc;
            lazy[2*index] += inc;
        }
        return ;
    }
    ll middle = (s + e)/2;
    UpdateRangeLazy(s,middle,l,r,tree,inc,2*index);
    UpdateRangeLazy(middle+1,e,l,r,tree,inc,2*index+1);
    tree[index] = tree[2*index]+tree[2*index+1];
    return ;
}

ll QueryRangeLazy(ll s,ll e,ll l,ll r,ll *tree,ll index){
    if(lazy[index] !=0){
        tree[index] += lazy[index];
        if(s != e){
            lazy[2*index] += lazy[index];
            lazy[2*index+1] += lazy[index];
        }
        lazy[index] = 0;
    }
    if((s > r) || (e < l)){
        return 0;
    }
    if((s >= l) && (e <= r)){
        return tree[index];
    }
    ll middle = (s+e)/2;
    ll left = QueryRangeLazy(s,middle,l,r,tree,2*index);
    ll right = QueryRangeLazy(middle+1,e,l,r,tree,2*index+1);
    return right+left;
}

int main() {
    ll arr[] = {3,2,5,4,1};
    ll n = sizeof(arr)/sizeof(ll);
    ll *tree = new ll[4*n+1];
    BuildTree(arr,0,n-1,tree,1);
    UpdateRangeLazy(0,n-1,3,4,tree,3,1);
    cout<<QueryRangeLazy(0,n-1,3,4,tree,1);
}
