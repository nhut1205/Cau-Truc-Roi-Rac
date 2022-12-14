#include <stdio.h>
#include <conio.h> 
#include <stdlib.h>
#include <time.h>
#define MaxSize 100
void nhapMaTran(int a[][MaxSize], int n)
{
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = rand() % 100;
		}
	}
}

void xuatMaTran(int a[][MaxSize], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
}

void tachArray(int a[][MaxSize] , int n)
{
	int a11[MaxSize][MaxSize], a12[MaxSize][MaxSize], a21[MaxSize][MaxSize], a22[MaxSize][MaxSize];
	for (int i = 0; i < n/2; i++)
	{
		for (int j = 0; j < n/2; j++)
		{
			a11[i][j] = a[i][j];
			a12[i][j] = a[i][(j + n) / 2];
			a21[i][j] = a[(i + n) / 2][j];
			a22[i][j] = a[(i + n) / 2][(j + n) / 2];
		}
	}
	printf("a[1][1] : ",a);
	xuatMaTran(a11, n / 2);
	printf("a[1][2] : ",a);
	xuatMaTran(a12, n / 2);
	printf("a[2][1] : ");
	xuatMaTran(a21, n / 2);
	printf("a[2][2] : ");
	xuatMaTran(a22, n / 2);
}

void congMaTran(int a[][MaxSize], int b[][MaxSize], int c[][MaxSize] ,int n)
{
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++){
		{
			c[i][j] = a[i][j] + b[i][j];
		}
	}
}

void truMaTran(int a[][MaxSize], int b[][MaxSize], int c[][MaxSize], int n)
{
	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < n; j++){
			{
				c[i][j] = a[i][j] - b[i][j];
			}
		}
	}
}

void nhanMaTran(int a[][MaxSize], int b[][MaxSize], int c[][MaxSize], int n)
{

	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++){
		{
			c[i][j] = 0;
			{
				for (int k = 0; k < n; k++)
				{
					c[i][j] += (a[i][k] * b[k][j]);
				}
			}
		}
	}
}

/*thuat toan.  */

void NhapMT(double A[][MaxSize], int N)
{
	int i, j;

	for (i = 0; i<N; i++)
	{
		for (j = 0; j<N; j++)
		{
			scanf("%lf", &A[i][j]);
		}
	}
}


void XuatMT(double A[][MaxSize], int N)
{
	int i, j;

	for (i = 0; i<N; i++)
	{
		for (j = 0; j<N; j++)
		{
			printf("%0.1lf \t", A[i][j]);
		}
		printf("\n");
	}
}

/*cong 2 ma tran*/
void Cong(double A[][MaxSize], double B[][MaxSize], double kq[][MaxSize], int N)
{
	int i, j;

	for (i = 0; i< N; i++)
	{
		for (j = 0; j<N; j++)
		{
			kq[i][j] = A[i][j] + B[i][j];
		}
	}

}

/*tru 2 ma tran*/
void TruMT(double A[][MaxSize], double B[][MaxSize], double kq[][MaxSize], int N)
{
	int i, j;

	for (i = 0; i< N; i++)
	{
		for (j = 0; j<N; j++)
		{
			kq[i][j] = A[i][j] - B[i][j];
		}
	}
}


/*thuat toan.  */
void ThuatToanStrassen(double A[][MaxSize], double B[][MaxSize], double C[][MaxSize], int N)
{
	// toi gian nho nhat
	if (N == 1)
	{
		C[0][0] = A[0][0] * B[0][0];
		return;
	}

	// nhung truong hop con lai
	else
	{
		int sub_N = (int)(N / 2);// giam kich thuot ma tran chia 4 

		double A11[MaxSize][MaxSize], A12[MaxSize][MaxSize], A21[MaxSize][MaxSize], A22[MaxSize][MaxSize];
		double B11[MaxSize][MaxSize], B12[MaxSize][MaxSize], B21[MaxSize][MaxSize], B22[MaxSize][MaxSize];
		double C11[MaxSize][MaxSize], C12[MaxSize][MaxSize], C21[MaxSize][MaxSize], C22[MaxSize][MaxSize];
		double P1[MaxSize][MaxSize], P2[MaxSize][MaxSize], P3[MaxSize][MaxSize], P4[MaxSize][MaxSize], P5[MaxSize][MaxSize], P6[MaxSize][MaxSize], P7[MaxSize][MaxSize];
		double Akq[MaxSize][MaxSize], Bkq[MaxSize][MaxSize];

		int i, j;

		//chia ma trận thành 4 ma trận con:
		for (i = 0; i < sub_N; i++)
		{
			for (j = 0; j < sub_N; j++)
			{
				A11[i][j] = A[i][j];
				A12[i][j] = A[i][j + sub_N];
				A21[i][j] = A[i + sub_N][j];
				A22[i][j] = A[i + sub_N][j + sub_N];

				B11[i][j] = B[i][j];
				B12[i][j] = B[i][j + sub_N];
				B21[i][j] = B[i + sub_N][j];
				B22[i][j] = B[i + sub_N][j + sub_N];
			}
		}
		/*XuatMT(A11, sub_N);
		printf("\n");
		XuatMT(A12, sub_N);
		printf("\n");
		XuatMT(A21, sub_N);
		printf("\n");
		XuatMT(A22, sub_N);
		printf("\n");
		getch();*/
		// tinh p1 to p7:
		/*chi tiet*/

		Cong(A11, A22, Akq, sub_N);   // a11 + a22
		Cong(B11, B22, Bkq, sub_N);   // b11 + b22
		ThuatToanStrassen(Akq, Bkq, P1, sub_N);  // p1 = (a11+a22) * (b11+b22)

		Cong(A21, A22, Akq, sub_N);   // a21 + a22
		ThuatToanStrassen(Akq, B11, P2, sub_N); // p2 = (a21+a22) * (b11)

		TruMT(B12, B22, Bkq, sub_N); // b12 - b22
		ThuatToanStrassen(A11, Bkq, P3, sub_N); // p3 = (a11) * (b12 - b22)

		TruMT(B21, B11, Bkq, sub_N); // b21 - b11
		ThuatToanStrassen(A22, Bkq, P4, sub_N); // p4 = (a22) * (b21 - b11)

		Cong(A11, A12, Akq, sub_N); // a11 + a12
		ThuatToanStrassen(Akq, B22, P5, sub_N); // p5 = (a11+a12) * (b22)

		TruMT(A21, A11, Akq, sub_N); // a21 - a11
		Cong(B11, B12, Bkq, sub_N); // b11 + b12
		ThuatToanStrassen(Akq, Bkq, P6, sub_N); // p6 = (a21-a11) * (b11+b12)

		TruMT(A12, A22, Akq, sub_N); // a12 - a22
		Cong(B21, B22, Bkq, sub_N); // b21 + b22
		ThuatToanStrassen(Akq, Bkq, P7, sub_N); // p7 = (a12-a22) * (b21+b22)

		// calculating c21, c21, c11 e c22:

		Cong(P3, P5, C12, sub_N); // c12 = p3 + p5
		Cong(P2, P4, C21, sub_N); // c21 = p2 + p4

		Cong(P1, P4, Akq, sub_N); // p1 + p4
		Cong(Akq, P7, Bkq, sub_N); // p1 + p4 + p7
		TruMT(Bkq, P5, C11, sub_N); // c11 = p1 + p4 - p5 + p7

		Cong(P1, P3, Akq, sub_N); // p1 + p3
		Cong(Akq, P6, Bkq, sub_N); // p1 + p3 + p6
		TruMT(Bkq, P2, C22, sub_N); // c22 = p1 + p3 - p2 + p6


		// Gop

		for (i = 0; i < sub_N; i++)
		{
			for (j = 0; j < sub_N; j++)
			{
				C[i][j] = C11[i][j];
				C[i][j + sub_N] = C12[i][j];
				C[i + sub_N][j] = C21[i][j];
				C[i + sub_N][j + sub_N] = C22[i][j];
			}
		}

	}

}
void main()
{
	int n ;
	int a[MaxSize][MaxSize], b[MaxSize][MaxSize], c[MaxSize][MaxSize];
	double a1[MaxSize][MaxSize], b1[MaxSize][MaxSize], c1[MaxSize][MaxSize];
	printf("Nhap cap cua ma tran a : ");
	scanf_s("%d", &n);
	nhapMaTran(a, n);
	xuatMaTran(a, n);
	printf("Nhap cap cua ma tran b : ");
	scanf_s("%d", &n);
	nhapMaTran(b, n);
	xuatMaTran(b, n);
	tachArray(a, n);
	printf("\nTach ma tran b\n");
	tachArray(b, n);
	printf("\nCong 2 ma tran\n");
	congMaTran(a, b, c, n);
	xuatMaTran(c, n);
	printf("\nTru 2 ma tran\n");
	truMaTran(a, b, c, n);
	xuatMaTran(c, n);
	//printf("\nNhan 2 ma tran(Khong su dung chia de tri)\n");
	//nhanMaTran(a, b, c, n);
	//xuatMaTran(c, n);
	printf("\nNhan 2 ma tran(Su dung chia de tri)\n");
	ThuatToanStrassen(a1, b1, c1, n);
	xuatMaTran(c, n);
	_getch();
}