# define _CRT_SECURE_NO_WARNINGS
# include<stdio.h>
# include<stdlib.h>
# define MAXSIZE 20
//宏定义MAXSIZE作为线性表的长度
typedef int datatype;
//switch 'int' to 'datatype'
typedef struct list {
	datatype data[MAXSIZE];  //MaxSize 是线性表总长度-数组总元素个数 
	int length;  //  线性表的当前长度//the length of sequenlist 
}sequenlist;
//define the struction
void creatlist1(sequenlist* seqlist, int a[], int n)
//函数参数：结构体定义的结构体变量，定义数组，数组长度
//仅创建顺序表，存储数组，不返回值
{
	int i = 0, k = 0;
	//变量i用于代表索引数组下标
	//变量k用于统计最终顺序表长度
	while (i < n)
	{
		seqlist->data[i] = a[i];
		//结构体变量指向结构体定义的数据数组
		/*
			eg:
			将数组下标索引值为i的元素值赋给顺序表下标索引为i的数据数组
			下标索引值从0开始
		*/
		i++;
		k++;
		//函数体索引赋值每循环一次顺序表最终统计长度+1
	}
	seqlist->length = k;
	//将统计长度赋给结构体变量指向的length,作为顺序表的最终长度
}
//first type of creat squenlist
void displaylist(sequenlist* seqlist)
//输出顺序表
//参数：结构体定义的结构体变量
{
	int i;
	//索引结构体变量指向的数据数组的元素下标
	for (i = 0; i < seqlist->length; i++)
		//i<seqlist->leagth而不是i<=seqlist->length
		/*
			i<seqlist->length的所有循环结果
			i=[0,1,2,3,4,5]
			i<=seqlist->length的所有循环结果
			i=[0,1,2,3,4,5,6]
			多循环一次,但i=6的顺序表数据数组的下标索引为空，no necessary*/
	{
		printf("|%d|", seqlist->data[i]);
		//每循环一次打印结构体变量指向的数据数组元素
	}
	printf("\n");
	//打印转义字符\n换行
}
void creatlist2(sequenlist* seqlist, int n)
//函数参数：结构体定义的结构体变量，输入顺序表的长度
{
	int i = 0, k;

	for (k = 0; k < n; k++)
	{
		scanf("%d", &seqlist->data[i]);
		i++;//？
	}
	seqlist->length = n;
	//将输入的顺序表长度值赋给结构体变量指向的length,作为顺序表的最终长度
}
//second type of creat sequenlist
int insert(sequenlist* seqlist, int index1, int x)
//传入参数：结构体定义的结构体变量，要插入的位置，要插入的元素
{
	int length = seqlist->length;
	//便于函数体引用结构体变量指向的顺序表长度
	//非正常的情况
	if (length > MAXSIZE)return -1;
	//判断顺序表长度是否大于结构体的最大数据数组长度
	if (index1<1 || index1>length + 1)return -1;
	/*
	1.判断插入位置，插入位置如果是0，for循环到最后会将data[-1]的值赋给data[0]
	  ,很明显data[-1]不存在。
	2.插入位置也不能在顺序表末位置的下下一个位置，已创建的顺序表的数据数组最后一个元素的下标索引值为length-1
	  下一个位置的下标索引值为length
	  下下一个位置的下标索引值为length+1
	*/
	//正常情况
	int j;
	for (j = length; j >= index1; j--)
		//将顺序表的长度赋给变量j
	{
		seqlist->data[j] = seqlist->data[j - 1];
	}
	//从最后一个元素开始到与插入位置有相同下标索引值的元素结束依次向后移一位
	seqlist->data[index1 - 1] = x;
	//插入位置的下标索引值为index-1,将插入的元素值赋给顺序表数据数组的插入位置
	seqlist->length++;
	//顺序表长度+1
	return 1;
	//返回正常值
}
//顺序表元素插入
int delete(sequenlist* seqlist, int index2)
//
{
	int length = seqlist->length;
	if (length == 0)return -1;
	if (index2<1 || index2>length + 1);
	int i;
	for (i = index2 - 1; i < length; i++)
		seqlist->data[i] = seqlist->data[i + 1];
	seqlist->length--;
	return 1;
}
//顺序表元素删除
int getdata(sequenlist* seqlist, int index)
{
	int length = seqlist->length;
	if (index<1 || index>length)return -1;
	else return seqlist->data[index - 1];
}
int locate(sequenlist* seqlist, int data)
{
	int i, length = seqlist->length;
	for (i = 0; i < length; i++)
	{
		if (seqlist->data[i] == data)
			return i + 1;
	}
	return -1;
}
/*void insertsort(sequenlist*seqlist)
{
	int i, j,length=seqlist->length;
	for (i = 2; i <= length; i++)
	{
		seqlist->data[0] = seqlist->data[i];
		j = i - 1;
		while (seqlist->data[0] < seqlist->data[j])
		{
			seqlist->data[j+1] = seqlist->data[j];
			j--;
		}
		seqlist->data[j + 1] = seqlist->data[0];
	}
} */
void creatlist3(sequenlist* seqlist, int n)//创建增序顺序表 
{
	int i = 0, k;
	for (k = 0; k < n; k++)
	{
		scanf("%d", &seqlist->data[i]);
		i++;
	}
	seqlist->length = n;
	int p, q, temp;
	for (p = 1; p < n; p++)
	{
		if (seqlist->data[p] < seqlist->data[p - 1])
		{
			temp = seqlist->data[p];
			for (q = p - 1; q >= 0 && seqlist->data[q] > temp; q--)
				seqlist->data[q + 1] = seqlist->data[q];
			seqlist->data[q + 1] = temp;
		}
	}
}
int addinsert(sequenlist* seqlist, int x)//增序顺序表插入 
{
	if (seqlist->length == MAXSIZE)return -1;
	int temp, i, length = seqlist->length;
	temp = x;

	for (i = length - 1; seqlist->data[i] > temp; i--) {}
	int j;
	for (j = length; j > i; j--)
		/*在执行for循环时，首先执行初始化表达式，
		这一步通常是完成某一变量的初始化工作；下一步判断循环条件表达似乎的值，
		若循环条件表达式的值为true，
		则进入循环体；在执行完循环体后紧接着计算循环后操作表达式，
		*/ {
		seqlist->data[j] = seqlist->data[j - 1];
	}
	seqlist->data[j + 1] = temp;
	seqlist->length++;
	return 1;
}
/*void creatlist3(sequenlist* seqlist, int n) {
	int i;
	for (i = 0; i < n; i++) {
		scanf("%d", &seqlist->data[i]);
	}
	seqlist->length = n;

	int p, q, temp;
	for (p = 1; p < n; p++) {
		if (seqlist->data[p] < seqlist->data[p-1]) {
			temp = seqlist->data[p];
			for (q = p - 1; q >= 0 && seqlist->data[q] > temp; q--) {
				seqlist->data[q + 1] = seqlist->data[q];
			}
			seqlist->data[q + 1] = temp;
		}
	}
}*/
int main()
{
	/*	sequenlist lista;
		sequenlist listb;

		int a[6]={2,3,4,5,6,7};
		creatlist1(&lista,a,6);
		displaylist(&lista);
		int n;
		printf("请输入顺序表的元素个数；");
		scanf("%d",&n);
		creatlist2(&listb,n);
		displaylist(&listb);

		int index1,x1;
		printf("请输入插入的位置；\n");
		scanf("%d",&index1);
		printf("请输入插入的元素；\n");
		scanf("%d",&x1);
		insert(&listb,index1,x1);
		displaylist(&listb);
		printf("\n");

		int index2;
		printf("请输入你要删除那个位置上的元素；");
		scanf("%d",&index2);
		delete(&listb,index2);
		displaylist(&listb);
		int index3;
		printf("请输入你要查找那个位置上的元素；");
		scanf("%d",&index3);
		printf("第%d个元素是%d\n",index3,getdata(&listb,index3));
		int data;
		printf("请输入你要查找的元素；");
		scanf("%d",&data);
		printf("你要查找的%d在第%d个位置上\n",data,locate(&listb,data));
		*/
	sequenlist listc;
	int m;
	printf("请输入顺序表的元素个数；");
	scanf("%d", &m);
	creatlist3(&listc, m);
	displaylist(&listc);
	int x2;
	printf("请输入插入的元素；\n");
	scanf("%d", &x2);
	addinsert(&listc, x2);
	displaylist(&listc);
	return 0;
}