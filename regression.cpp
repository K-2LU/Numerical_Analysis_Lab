#include <bits/stdc++.h>
using namespace std;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL)
#define newline cout << endl;
#define out(n) cout << n << ' ';
#define debug(n) cout << "Debug: " << n << ' ';

const int MAX_N = 1e5+9;
typedef long long ll;

void solve()   {
}

int main()  {
   optimize;
   int n;	cin >> n;
   vector <pair<double, double>> v;
   for (int i = 0; i < n; ++i)	{
   	double a, b;	cin >> a >> b;
   	v.push_back({a, b});
   }

   double xy, xi, yi, x2i;
   xy = xi = yi = x2i = 0.0;
   for (int i = 0; i < n; i++)	{
   		xy += (v[i].first * v[i].second);
   		xi += v[i].first;
   		yi += v[i].second;
   		x2i += v[i].first * v[i].first;
   }

   double a1 = (n*xy - (xi*yi))/ (n*x2i - xi*xi);
   double a2 = (x2i*yi - xi*xy)/(n*x2i - xi*xi);
   cout << a1 << ' ' << a2 << endl;
}