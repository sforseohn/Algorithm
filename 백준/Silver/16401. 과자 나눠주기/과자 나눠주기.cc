#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int n, int mid, vector<int>& cookie) {
    int cnt=0;

    for(int c:cookie) {
        cnt+=c/mid;
        if(cnt>=n)
            return true;
    }

    return false;
}



int sol(int n, vector<int>& cookie){
    int start=1;
    int end=*max_element(cookie.begin(), cookie.end());

    int val=0;

    while(start<=end) {
        int mid=(start+end)/2;

        if(check(n,mid,cookie)) {
            start=mid+1;
            val=mid;
        } else {
            end=mid-1;
        }
    }
    return val;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    vector<int> cookie(m);
    for(int i=0;i<m;i++) {
        cin>>cookie[i];
    }

    int res=sol(n, cookie);

    cout<<res;

    return 0;

}