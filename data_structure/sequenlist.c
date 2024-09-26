# define _CRT_SECURE_NO_WARNINGS
# include<stdio.h>
# include<stdlib.h>
# define MAXSIZE 20
//�궨��MAXSIZE��Ϊ���Ա�ĳ���
typedef int datatype;
//switch 'int' to 'datatype'
typedef struct list {
	datatype data[MAXSIZE];  //MaxSize �����Ա��ܳ���-������Ԫ�ظ��� 
	int length;  //  ���Ա�ĵ�ǰ����//the length of sequenlist 
}sequenlist;
//define the struction
void creatlist1(sequenlist* seqlist, int a[], int n)
//�����������ṹ�嶨��Ľṹ��������������飬���鳤��
//������˳����洢���飬������ֵ
{
	int i = 0, k = 0;
	//����i���ڴ������������±�
	//����k����ͳ������˳�����
	while (i < n)
	{
		seqlist->data[i] = a[i];
		//�ṹ�����ָ��ṹ�嶨�����������
		/*
			eg:
			�������±�����ֵΪi��Ԫ��ֵ����˳����±�����Ϊi����������
			�±�����ֵ��0��ʼ
		*/
		i++;
		k++;
		//������������ֵÿѭ��һ��˳�������ͳ�Ƴ���+1
	}
	seqlist->length = k;
	//��ͳ�Ƴ��ȸ����ṹ�����ָ���length,��Ϊ˳�������ճ���
}
//first type of creat squenlist
void displaylist(sequenlist* seqlist)
//���˳���
//�������ṹ�嶨��Ľṹ�����
{
	int i;
	//�����ṹ�����ָ������������Ԫ���±�
	for (i = 0; i < seqlist->length; i++)
		//i<seqlist->leagth������i<=seqlist->length
		/*
			i<seqlist->length������ѭ�����
			i=[0,1,2,3,4,5]
			i<=seqlist->length������ѭ�����
			i=[0,1,2,3,4,5,6]
			��ѭ��һ��,��i=6��˳�������������±�����Ϊ�գ�no necessary*/
	{
		printf("|%d|", seqlist->data[i]);
		//ÿѭ��һ�δ�ӡ�ṹ�����ָ�����������Ԫ��
	}
	printf("\n");
	//��ӡת���ַ�\n����
}
void creatlist2(sequenlist* seqlist, int n)
//�����������ṹ�嶨��Ľṹ�����������˳���ĳ���
{
	int i = 0, k;

	for (k = 0; k < n; k++)
	{
		scanf("%d", &seqlist->data[i]);
		i++;//��
	}
	seqlist->length = n;
	//�������˳�����ֵ�����ṹ�����ָ���length,��Ϊ˳�������ճ���
}
//second type of creat sequenlist
int insert(sequenlist* seqlist, int index1, int x)
//����������ṹ�嶨��Ľṹ�������Ҫ�����λ�ã�Ҫ�����Ԫ��
{
	int length = seqlist->length;
	//���ں��������ýṹ�����ָ���˳�����
	//�����������
	if (length > MAXSIZE)return -1;
	//�ж�˳������Ƿ���ڽṹ�������������鳤��
	if (index1<1 || index1>length + 1)return -1;
	/*
	1.�жϲ���λ�ã�����λ�������0��forѭ�������Ὣdata[-1]��ֵ����data[0]
	  ,������data[-1]�����ڡ�
	2.����λ��Ҳ������˳���ĩλ�õ�����һ��λ�ã��Ѵ�����˳���������������һ��Ԫ�ص��±�����ֵΪlength-1
	  ��һ��λ�õ��±�����ֵΪlength
	  ����һ��λ�õ��±�����ֵΪlength+1
	*/
	//�������
	int j;
	for (j = length; j >= index1; j--)
		//��˳���ĳ��ȸ�������j
	{
		seqlist->data[j] = seqlist->data[j - 1];
	}
	//�����һ��Ԫ�ؿ�ʼ�������λ������ͬ�±�����ֵ��Ԫ�ؽ������������һλ
	seqlist->data[index1 - 1] = x;
	//����λ�õ��±�����ֵΪindex-1,�������Ԫ��ֵ����˳�����������Ĳ���λ��
	seqlist->length++;
	//˳�����+1
	return 1;
	//��������ֵ
}
//˳���Ԫ�ز���
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
//˳���Ԫ��ɾ��
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
void creatlist3(sequenlist* seqlist, int n)//��������˳��� 
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
int addinsert(sequenlist* seqlist, int x)//����˳������ 
{
	if (seqlist->length == MAXSIZE)return -1;
	int temp, i, length = seqlist->length;
	temp = x;

	for (i = length - 1; seqlist->data[i] > temp; i--) {}
	int j;
	for (j = length; j > i; j--)
		/*��ִ��forѭ��ʱ������ִ�г�ʼ�����ʽ��
		��һ��ͨ�������ĳһ�����ĳ�ʼ����������һ���ж�ѭ����������ƺ���ֵ��
		��ѭ���������ʽ��ֵΪtrue��
		�����ѭ���壻��ִ����ѭ���������ż���ѭ����������ʽ��
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
		printf("������˳����Ԫ�ظ�����");
		scanf("%d",&n);
		creatlist2(&listb,n);
		displaylist(&listb);

		int index1,x1;
		printf("����������λ�ã�\n");
		scanf("%d",&index1);
		printf("����������Ԫ�أ�\n");
		scanf("%d",&x1);
		insert(&listb,index1,x1);
		displaylist(&listb);
		printf("\n");

		int index2;
		printf("��������Ҫɾ���Ǹ�λ���ϵ�Ԫ�أ�");
		scanf("%d",&index2);
		delete(&listb,index2);
		displaylist(&listb);
		int index3;
		printf("��������Ҫ�����Ǹ�λ���ϵ�Ԫ�أ�");
		scanf("%d",&index3);
		printf("��%d��Ԫ����%d\n",index3,getdata(&listb,index3));
		int data;
		printf("��������Ҫ���ҵ�Ԫ�أ�");
		scanf("%d",&data);
		printf("��Ҫ���ҵ�%d�ڵ�%d��λ����\n",data,locate(&listb,data));
		*/
	sequenlist listc;
	int m;
	printf("������˳����Ԫ�ظ�����");
	scanf("%d", &m);
	creatlist3(&listc, m);
	displaylist(&listc);
	int x2;
	printf("����������Ԫ�أ�\n");
	scanf("%d", &x2);
	addinsert(&listc, x2);
	displaylist(&listc);
	return 0;
}