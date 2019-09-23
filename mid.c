#include <stdio.h>
#include <stdbool.h>

//reference
//https://baijiahao.baidu.com/s?id=1637300760685563546&wfr=spider&for=pc
//https://blog.csdn.net/guotianqing/article/details/87527614
int  find_mid(int *a, int m,  int *b, int n);

int main() {
	int a[] = {1, 2, 3, 5, 10};
	int b[] = {3, 7, 12, 13, 15, 18};
	int ret = find_mid(a, 5 , b, 6);
	printf("wztest =====> ret:%d \n", ret);
}

int max(int a, int b) {
	return a >= b ? a : b;
}

int min(int a, int b) {
	return a <= b? a : b;
}

int getLeftMax(int *a, int m, int i, int *b ,int n, int j) {
	if (i == 0) return b[j-1];
	if (i == m) return max(a[m-1], b[j-1]);
	if (j == 0) return a[i-1] ;
	if (j == n) return max(a[i-1], b[n-1]);
	return max(a[i-1], b[j-1]);
}

int getRightMin(int *a, int m, int i, int *b ,int n, int j) {
	if (i == 0) return min(a[0], b[j]);
	if (i == m) return b[j];
	if (j == 0) return min(a[i], b[0]);
	if (j == n) return a[i];
	return min(a[i], b[j]);
}

int find_mid(int *a, int m, int *b, int n) {
	int i = 0, j = 0;
	int imin = 0, imax = m-1;
	int rightMin, leftMax;
	int total = m+n;

	bool odd = total % 2;
	printf("wztest odd:%d \n", odd);

	if (m == 0) {
		int index = 0;
		if (odd) {
			index = (n-1)/2;
			return b[index];
		}
		index = n/2;
		return (b[index-1] + b[index])/2;
	}

	if (n == 0) {
		int index = 0;
		if (odd) {
			index = (m-1)/2;
			return a[index];
		}
		index = m/2;
		return (a[index-1] + a[index])/2;
	}


	while(imin <= imax) {
		i = (imin + imax) / 2 ;
		j = (m+n)/2 - i;
		printf("wztest imin:%d, imax:%d, i:%d, j:%d \n", imin, imax, i, j);

		if (a[i-1] > b[j] && i > 0 && j != n) {
			printf("2222 right > left, a[i-1] is big, so imin++ \n");
			//right > left, so imax --
			imax = i -1;
			continue;
		}

		if (b[j-1] > a[i] && j > 0 && i != m) {
			//right > left, so imin ++ 
			printf("2222 right > left, a[i] is small, so imin++ \n");
			imin = i + 1;
			continue;
		
		}

		leftMax = getLeftMax(a, m, i, b, n, j);	
		rightMin = getRightMin(a, m, i, b, n, j);

		if (odd) {
			return rightMin;
		}

		if (!odd) {
			return (rightMin + leftMax) / 2;
		}
		
	}
	return -1;
}

