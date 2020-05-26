#include"matrix.h"
#include<stdio.h>

/*****************************************************************

函数名称：Matrix_Mul
函数功能：矩阵相乘mat1*mat2
入   参：mat1，mat2，相乘的两个矩阵
出   参：mat_result-返回结果矩阵
返 回 值：0-成功；非零-失败；

******************************************************************/
int Matrix_Mul(MATRIX mat1,MATRIX mat2,MATRIX *mat_result)
{	
	double tmp1,tmp2,tmp3;
	/*判断两个矩阵是否满足要求*/
	if(mat1.row!=mat2.col||mat1.col!=mat2.row)
	{
		return 1;/*矩阵维数不对应*/
	}
	/*判断结果矩阵是否满足要求*/
	if(mat1.row!=mat_result->row||mat2.col!=mat_result->col)
	{
		return 2;/*结果矩阵维数不对应*/
	}
	for(int k=1;k<=mat1.row;k++)
	
	{
		for(int j=1;j<=mat2.col;j++)
		{
			tmp3=0;
			for(int i=1;i<=mat1.col;i++)
			{
				if(Matrix_GetValue(mat1,k,i,&tmp1)!=0)
				{
					return 1;
				}
				if(Matrix_GetValue(mat2,i,j,&tmp2)!=0)
				{
					return 1;
				}
			
				tmp3=tmp3+tmp1*tmp2;
						
			}
			if(Matrix_PutValue(mat_result,k,j,tmp3)!=0)
				{
				return 1;
				}
		}
	}
}

/*****************************************************************

函数名称：Matrix_GetValue
函数功能：通过下标获取矩阵元素
入   参：mat-矩阵；row-行数；col-列数
出   参：value-返回结果矩阵
返 回 值：0-成功；非零-失败；

******************************************************************/
int Matrix_GetValue(MATRIX mat,int row,int col,double* value)//获取二维矩阵的值
{
	if(mat.row<row||mat.col<col)
	{
		return 1;
	}
	*value=mat.ptr[(row-1)*mat.col+col-1];
	return 0;
}

/*****************************************************************

函数名称：Matrix_PutValue
函数功能：通过下标获设置矩阵元素
入   参：row-行数；col-列数
出   参：mat-设置的矩阵；
返 回 值：0-成功；非零-失败；

******************************************************************/
int Matrix_PutValue(MATRIX *mat,int row,int col,double value)//改变二维矩阵的值
{
	if(mat->row<row||mat->col<col)
	{
		return 1;
	}
	mat->ptr[(row-1)*mat->col+col-1]=value;
	return 0;
}

/*****************************************************************

函数名称：Matrix_Print
函数功能：在控制台打印出矩阵
入   参：mat-待打印矩阵
出   参：mat-设置的矩阵；
返 回 值：0-成功；非零-失败；

******************************************************************/
int Matrix_Print(MATRIX mat)
{
	double tmp;
	for(int i=1;i<=mat.row;i++)
	{
		for(int j=1;j<=mat.col;j++)
		{
			if(Matrix_GetValue(mat,i,j,&tmp)!=0)
			{
					return 1;
			}
			printf("%f,",tmp);
		}
		printf("\n,");
	}
}

/*****************************************************************

函数名称：Matrix_equal
函数功能：两个矩阵的值相等
入   参：mat2-源矩阵
出   参：mat1-目标矩阵；
返 回 值：0-成功；非零-失败；

******************************************************************/
int Matrix_equal(MATRIX mat1,MATRIX mat2)
{	
	double tmp;
	/*判断两个矩阵是否满足要求*/
	if(mat1.row!=mat2.row||mat1.col!=mat2.col)
	{
		return 1;/*矩阵维数不对应*/
	}
	for(int i=1;i<=mat1.row;i++)
	{
		for(int j=1;j<=mat1.row;j++)
		{
			if(Matrix_GetValue(mat2,i,j,&tmp)!=0)
				{
					return 1;
				}
			if(Matrix_PutValue(&mat1,i,j,tmp)!=0)
				{
					return 1;
				}
		}
	}
	return 0;
}



















