#include <climits>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

void maxSubArraySum(vector<ll>& vec, ll size)
{
    ll max_so_far = INT_MIN, max_ending_here = 0;
    ll start = 0, end = 0, s = 0;

    for (int i = 0; i < size; i++) 
    {
        max_ending_here += vec[i];
        
        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }

        if (max_ending_here < 0) 
        {
            max_ending_here = 0;
            s = i + 1;
        }
    }
    cout << start + 1 << " " << end + 1  << " " << max_so_far;
}


int main()
{

    ll n = 0;
    cin >> n;

    vector<ll> vec(n);
    for (auto& it : vec) {
        cin >> it;
    }

    maxSubArraySum(vec, vec.size());

    return 0;
}