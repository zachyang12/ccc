#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define beg begin
#define vec vector

const ll inf = LLONG_MAX;
const ll mod9 = 998244353, mod1 = 1000000007;

vec<vec<int>>directions = {{1,0},{-1,0},{0,-1},{0,1}};

string alph = "abcdefghijklmnopqrstuvwxyz";
string ALPH = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";



template <typename T>
T bisect_left(const vec<T>& arr, T target) {
    T left = 0, right = arr.size();
    while (left < right) {
        T mid = left + (right - left) / 2;
        if (arr[mid] < target) left = mid + 1;
        else right = mid;
    }
    return left;
}

template <typename T>
T bisect_right(const vec<T>& arr, T target) {
    T left = 0, right = arr.size();
    while (left < right) {
        T mid = left + (right - left) / 2;
        if (arr[mid] <= target) left = mid + 1;
        else right = mid;
    }
    return left;
}

template <typename T>
T pows(T base, T exp, T mod) {
    static_assert(std::is_integral<T>::value, "Template parameter must be an integral type");
    T ans = 1;
    base = base % mod;
    if (base == 0) return 0;
    while (exp > 0) {
        if (exp % 2 == 1) ans = (ans * base) % mod;
        exp >>= 1;
        base = (base * base) % mod;
    }
    return ans;
}

template <typename T>
bool same(const vec<T>& A, const vec<T>& B) {
    if (A.size() != B.size()) return false;
    for (size_t i = 0; i < A.size(); ++i) {
        if (A[i] != B[i]) return false;
    }
    return true;
}

template <typename T>
bool in(const T&A, const vec<T>& B) {
    for (auto i:B){
        if (i==A){
            return true;
        }
    }
    return false;
}

template <typename T>
void combinations(const vec<T>& arr) {
    int n = arr.size();
    int totalCombinations = pow(2, n);

    for (int i = 0; i < totalCombinations; ++i) {
        vec<T> subset;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {subset.push_back(arr[j]);}
        }
        //output
        for (const T&elem:subset){
            cout<<elem<<" ";
        }
        cout<<endl;
    }
}

template <typename T>
void permutations(vec<T> arr) {
    sort(arr.beg(),arr.end());
    do{
        //output
        for (const T&elem:arr) {
            cout<<elem<<" ";
        }
        cout<<endl;

    } while (next_permutation(arr.beg(),arr.end()));
}


bool check (ll a, ll b, ll c, ll d){
    double logA = std::log(static_cast<double>(a));
    double logC = std::log(static_cast<double>(c));

    double result1 = b * logA;
    double result2 = d * logC;

    if (result1 > result2) {
        return false;
    } else{
        return true;
    }
}


int main() {
ios_base::sync_with_stdio(0);
cin.tie(0); cout.tie(0);





int T; cin>>T;
for (int op = 0; op<T; op++){


int N; cin>>N;
vector<ll>A(N),l,ans(N,inf);
map<int,vector<int>>dic;
ll num = 0;

for (int i = 0; i < N; ++i){
    cin>>A[i];
    num+=A[i];
    l.push_back(num);
    dic[A[i]].push_back(i);
}


for (int i = 0; i < N; ++i){
    int right = bisect_right(l,A[i]+l[i]);
    if (right<N){

        int checkl = bisect_left(dic[A[right]],i+1);
        int checkr = bisect_right(dic[A[right]],right);

        if (checkr-checkl<right-i or A[i+1]>A[i]){
            ans[i] = min(ans[i],right-1);
        }

        // cout<<right<<" r "<<i<<endl;
    }
    if (i>=1){
        int left = bisect_left(l,l[i-1]-A[i]);
        if (left-1>=0){

            int checkl = bisect_left(dic[A[left]],left);
            int checkr = bisect_right(dic[A[left]],i-1);

            if (checkr-checkl<i-left or A[i-1]>A[i]){
                ans[i] = min(ans[i],i-left);
            }
            // cout<<left<<" l "<<i<<endl;
        }else if (l[i-1]>A[i]){

            int checkr = bisect_right(dic[A[0]],i-1);
            if (checkr<i or (A[0]>A[i])){
                ans[i] = min(ans[i],i);
            }
            // cout<<0<<" l "<<i<<endl;
        }
    }

}







}

}

