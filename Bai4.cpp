#include <stdio.h>
#include <conio.h>
#define Max 100

void xuatMang(int a[Max], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

int ptMax(int a[Max], int l, int r)
{
	if (l == r)
		return a[l];
	int mid = (l + r) / 2;
	int left = ptMax(a, l , mid);
	int right = ptMax(a, mid + 1, r);
	if (a[left] > a[right])
		return a[left];
	return a[right];
}

int ptVTMax(int a[Max], int l, int r)
{
	if (l == r)
		return l;
	int mid = (l + r) / 2;
	int left = ptVTMax(a, l, mid);
	int right = ptVTMax(a, mid + 1, r);
	if (a[left] > a[right])
		return left;
	return right;
}

void saoChep(int a[], int b[], int n, int bd)
{
	for (int i = 0 , j = bd; i < n; i++,j++)
		b[i] = a[j];
}

int timMax(int a[], int n, int &vt)
{
	if (n == 0)
		return -1;
	if (n == 1)
	{
		vt = 0;
		return a[0];
	}
	else
	{
		if (a[n - 1] > timMax(a, n - 1, vt))
		{
			vt = n - 1;
			return a[n - 1];
		}
		else
			return timMax(a, n - 1, vt);
	}
}

int VT(int a[], int n)
{
	int b[50], c[50];
	if (n == 1) return a[0];
	saoChep(a, b, n / 2, 0);                                          
	saoChep(a, b, n - 1, n / 2);

	int vtb = 0;
	timMax(b, n / 2, vtb);

	int vtc = 0;
	timMax(c, n - n / 2, vtc);
	if (b[vtb] > c[vtc])
		return vtb;
	else
		return vtc + (n - n / 2) - 1;
}


int main()
{
	int a[Max];
	int n;
	printf("Nhap so phan tu cua mng : ");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &a[i]);
	}
	int vtc = 0;
	xuatMang(a, n);
	printf("Phan tu max trong mang %d o vi tri %d", timMax(a,n,vtc), VT(a, n));
	_getch();
	return 0;
}