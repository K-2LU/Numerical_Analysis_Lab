#include <bits/stdc++.h>
using namespace std;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL)
#define newline cout << endl;
#define out(n) cout << n << ' ';
#define debug(n) cout << "Debug: " << n << ' ';

const int MAX_N = 1e5+9;
typedef long long ll;
double mat[10][10], res[10];
int indxAt;

void gauss(int n)	{

	int ind = 0;
	double maxRow;
	
	for (int i = 1; i < n; i++)	{
		ind = i;
		maxRow = mat[i][i];
		for (int j = i+1; j <= n; j++)	{
			if(abs(maxRow)<abs(mat[j][i]))	{
				maxRow = mat[j][i];
				ind = j;
			}
		}
		swap(mat[ind], mat[i]);

		double ratio;

		for (int j = i+1; j <= n; j++)	{
			ratio = mat[j][i]/mat[i][i];
			
			for (int k = 1; k <= n+1; k++)	{
				mat[j][k] = mat[j][k] - ratio*mat[i][k];
			}
		}
	}

	res[n] = mat[n][n+1]/mat[n][n];
	for (int i = n-1; i >= 1; i--)	{
		res[i] = mat[i][n+1];
		for (int j = i+1; j <= n; j++)
			res[i] = res[i] - mat[i][j]*res[j];
		res[i] = res[i]/mat[i][i];
	}
}

double direct(vector<pair<double, pair<double, double>>> dataPoints, double point)	{
	double ans = 0.0;

	for (int i = 1; i <= 2; i++)	{
		mat[i][1] = 1;
		mat[i][2] = dataPoints[i-1].second.first;
		mat[i][3] = dataPoints[i-1].second.second;
	}
	gauss(2);

	for (int i = 1; i <= 2; i++)	{
		double temp = res[i];
		for (int j = 1; j < i; j++)	{
			temp *= point;
		}
		ans += temp;
	}
	return ans;
}

double quadratic(vector<pair<double, pair<double, double>>> dataPoints, double point)   {
	double ans = 0.0;

	for (int i = 1; i <= 3; i++)	{
		mat[i][1] = 1;
		mat[i][2] = dataPoints[i-1].second.first;
		mat[i][3] = dataPoints[i-1].second.first * dataPoints[i-1].second.first;
		mat[i][4] = dataPoints[i-1].second.second;
	}	gauss(3);
	
	for (int i = 1; i <= 3; i++)	{
		double temp = res[i];
		for (int j = 1; j < i; j++)	{
			temp *= point;
		}
		ans += temp;
	}

	return ans;
}

double cubic(vector<pair<double, pair<double, double>>> dataPoints, double point)   {
	double ans = 0.0;

	for (int i = 1; i <= 4; i++)	{
		mat[i][1] = 1.;
		mat[i][2] = dataPoints[i-1].second.first;
		mat[i][3] = dataPoints[i-1].second.first * dataPoints[i-1].second.first;
		mat[i][4] = dataPoints[i-1].second.first * dataPoints[i-1].second.first * dataPoints[i-1].second.first;
		mat[i][5] = dataPoints[i-1].second.second;
	}	gauss(4);

	for (int i = 1; i <= 4; i++)	{
		double temp = res[i];
		for (int j = 1; j < i; j++)	{
			temp *= point;
		}
		ans += temp;
	}

	return ans;
}

double lagrangian(int ind, double x, vector<pair<double, pair<double, double>>> v, int n)	{
	double sum = 1.0;

	for (int i = 0; i < n; i++)	{
		if(i == ind)	continue;
		sum *= (x - v[i].second.first);
		sum /= (v[ind].second.first - v[i].second.first);
	}

	return sum;
}

double lag_dir(vector<pair<double, pair<double, double>>> v, double x)	{
	double l = 0.0;
	int n = 1;
	for (int i = 0; i < n+1; i++)	{
		double li = lagrangian(i, x, v, n+1);
		li = li * v[i].second.second;
		l += li;
	}

	return l;
}

double lag_quad(vector<pair<double, pair<double, double>>> v, double x)	{
	double l = 0.0;
	int n = 2;
	for (int i = 0; i < n+1; i++)	{
		double li = lagrangian(i, x, v, n+1);
		li = li * v[i].second.second;
		l += li;
	}

	return l;
}

double lag_cub(vector<pair<double, pair<double, double>>> v, double x)	{
	double l = 0.0;
	int n = 3;
	for (int i = 0; i < n+1; i++)	{
		double li = lagrangian(i, x, v, n+1);
		li = li * v[i].second.second;
		l += li;
	}

	return l;
}

int main()  {
   // optimize;
   int n;	cin >> n;

   vector<pair<double, pair<double, double>>> v;
   double a, b;
   for (int i = 0; i < n; i++)	{
   		cin >> a >> b;
   		v.push_back({0., {a, b}});
   }
   double x;	cin >> x;

   for (int i = 0; i < n; i++)
   		v[i].first = abs(x - v[i].second.first);
   	sort(v.begin(), v.end());

	// cout << direct(v, x) << endl;
   	// cout << quadratic(v, x) << endl;
   	// cout << cubic(v, x) << endl;
   	cout << lag_cub(v, x) << endl;
}