#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int func(int N) {
    int i = sqrt((double)N);
    while(i >= 1) {
        if(N % i == 0)
            return i;
        i--;
    }
    return 1;
}
int cmp(int a, int b) {return a > b;}
int main() {
    int N, m, n, t = 0;
    scanf("%d", &N);
    n = func(N);
    m = N / n;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    sort(a.begin(), a.end(), cmp);
    vector<vector<int> > b(m, vector<int>(n));
    int level = m / 2 + m % 2;
	//由于是从外边向里面进行填充
    for (int i = 0; i < level; i++) {
		//所以第一个填充的是对角线上的元素，一直到最后一个为止；
		//同时维护一个变量，记录的是已经填充进去的元素个数和剩余未填充的元素个数
		//j++操作表示的就是元素的移动情况
        for (int j = i; j <= n - 1 - i && t <= N - 1; j++)
			//表示最上行的填充
                b[i][j] = a[t++];
        for (int j = i + 1; j <= m - 2 - i && t <= N - 1; j++)
			//表示最右行的填充
                b[j][n - 1 - i] = a[t++];
        for (int j = n - i - 1; j >= i && t <= N - 1; j--)
			//表示最下行的填充
                b[m - 1 - i][j] = a[t++];
        for (int j = m - 2 - i; j >= i + 1 && t <= N - 1; j--)
			//表示最左行的填充
                b[j][i] = a[t++];
    }
	
	//打印
    for (int i = 0; i < m; i++) {
        for (int j = 0 ; j < n; j++) {
            printf("%d", b[i][j]);
            if (j != n - 1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}