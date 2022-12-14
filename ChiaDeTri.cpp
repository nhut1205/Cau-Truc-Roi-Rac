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

int sum(int a[], int l, int r)
{
	if (l == r)//nếu vị trí left và right bằng nhau trả về 1 trong 2 giá trị
		return a[l];//trả về giá trị left
	int mid = (l + r) / 2;//chia mảng ra làm 2
	int temp1 = sum(a, l, mid);//tính tổng mảng bên trái
	int temp2 = sum(a, mid + 1, r);//tính tổng mảng bên phải
	return temp1 + temp2;//trả về giá trị
}
int sumChiaHetCho2(int a[], int l, int r)
{
	if (l == r)//nếu vị trí left và right bằng nhau trả về 1 trong 2 giá trị
		return a[l] % 2 == 0 ? a[l] : 0;
	int mid = (l + r) / 2;//chia mảng ra làm 2
	int temp1 = sumChiaHetCho2(a, l, mid);//tính tổng mảng bên trái
	int temp2 = sumChiaHetCho2(a, mid + 1, r);//tính tổng mảng bên phải
	return temp1 + temp2;
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
	int ketqua;
	ketqua = sum(a, 0, n - 1);
	printf("Ket qua : %d ", ketqua);
	printf("\n");
	int ketqua2 = sumChiaHetCho2(a, 0, n - 1);
	printf("Ket qua tong chia het cho 2 : %d", ketqua2);
	_getch();
	return 0;
}