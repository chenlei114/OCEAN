#include<math.h>

/*定义矩阵结构体*/
typedef struct matrix
{
	int row;//行
	int col;//列
	double*ptr;//数组指针
}MATRIX;

/*定义向量结构体*/
typedef struct vector
{
	int row;//行
	int col;//列
	double*ptr;//数组指针
}VECTOR;

int Matrix_Mul(MATRIX mat1,MATRIX mat2,MATRIX *mat_result);//矩阵相乘
int Matrix_GetValue(MATRIX mat,int row,int col,double* value);//获取二维矩阵的值
int Matrix_PutValue(MATRIX *mat,int row,int col,double value);//改变二维矩阵的值
int Matrix_Print(MATRIX mat);//打印矩阵
int Matrix_equal(MATRIX mat1,MATRIX mat2);//两个矩阵的值相等
