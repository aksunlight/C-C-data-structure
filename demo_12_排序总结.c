#include<stdio.h>
#include<stdlib.h> 
#include<stdbool.h> 
#define n 10 

int a[n] = {0};
int b[n + 1] = {0}; 

//Ϊ���鸳ֵ 
void assignment(void)
{
	for(int i = 0; i < n; i++)
	{
		a[i] = rand() % 100;
	} 
}

void assignmentb(void)
{
	for(int i = 1; i < n + 1; i++)
	{
		b[i] = rand() % 100;
	} 
}

//��ӡ���� 
void print(void)
{
	for(int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void printb(void)
{
	for(int i = 1; i < n + 1; i++)
	{
		printf("%d ", b[i]);
	}
	printf("\n");
}

//ֱ�Ӳ�������
//�ȶ����㷨ʱ�临�Ӷ�ΪO(n^2) 
void InsertSort(void)
{
	int i, j;
	for(i = 1; i < n; i++)
	{
		if(a[i] < a[i - 1])
		{
			int tmp = a[i];
			for(j = i - 1; tmp < a[j]; j--)  //�Ƚ� 
			{
				a[j + 1] = a[j];  //�ƶ� 
			}
			a[j + 1] = tmp;
		}
	}
}

//�۰��������
//�ȶ����㷨ʱ�临�Ӷ�ΪO(n^2) 
void BinarySort(void)
{
	int i, j, low, high, mid;
	for(i = 1; i < n; i++)
	{
		int tmp = a[i];
		low = 0;
		high = i - 1;
		while(low <= high)  //Ĭ��ԭ���е������򣬵���������Ҫ���������ûʲô�� 
		{
			mid = (low + high) / 2;
			if(a[mid] > tmp)
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
		for(j = i - 1; j >= high + 1; j++)
		{
			a[j + 1] = a[j];
		}
		a[high + 1] = tmp;
	}
} 

//ϣ������
//ȡһ��С��n�Ĳ���d1���ѱ���ȫ����¼�ֳ�d1���� 
//Ȼ���ڸ�����ֱ�Ӳ�������Ȼ��ȡ�ڶ�������d2<d1
//�ظ���������ֱ��d=1�������м�¼��ͬһ����
//����ٽ���һ��ֱ�Ӳ������򼴵õ������¼�� 
//���ȶ����㷨ʱ�临�Ӷ�ΪO(n^1.3)
void ShellSort(void)
{
	int i, j, dk;
	for(dk = n / 2; dk >= 1; dk /= 2)
	{
		for(i = dk; i < n; i++)
		{
			if(a[i] < a[i - dk])
			{
				int tmp = a[i];
			    for(j = i - dk; tmp < a[j]; j -= dk)
			    {
			    	a[j + dk] = a[j];
				}
				a[j + dk] = tmp;
			}
		}
	} 
}

//ð������
//�ȶ����㷨ʱ�临�Ӷ�ΪO(n^2) 
void BubbleSort(void)
{
	for(int i = 0; i < n - 1; i++)
	{
		bool flag = false;  //��ʾ����ð���Ƿ��������ı�־ 
//		for(int j = n - 1; j > i; j--)  //��С����ǰð 
//		{
//			if(a[j - 1] > a[j])
//			{
//				int tmp = a[j];
//				a[j] = a[j - 1];
//				a[j - 1] = tmp;
//				flag = true;  //�����������˽��� 
//			}
//    	}
        for(int j = 0; j < n - i - 1; j++)  //�Ѵ������ð 
    	{
    		if(a[j] > a[j + 1])
    		{
    			int tmp = a[j];
    			a[j] = a[j + 1];
    			a[j + 1] = tmp;
    			flag = true;  //�����������˽���
			}
		}
		if(flag = false)
    	{
    		return;
		}
	}
}

//��������Ļ���˼���ǻ��ڷ��η��ģ��ڴ������L[1...n] 
//����ȡһ��Ԫ��pivot��Ϊ��׼��ͨ��һ�����򽫴������
//���ֳɶ�����������L[1...k-1]1��L[k+1...n]2��ʹ��1������
//Ԫ��С��pivot��2������Ԫ�ش��ڻ����pivot����pivot������
//����λ��L[k]�ϣ�������̾���һ�˿��ţ����ֱ�ݹ�ض�����
//�ӱ��ظ��������̣�ֱ��ÿ������ֻ��һ��Ԫ�ػ��Ϊֹ��������Ԫ��
//������������λ�� 
//���ȶ���ʱ�临�Ӷ�Ϊnlog2n 
void QuickSort(int low, int high)
{
	if(low >= high)
	{
		return;
	}
	int i = low, j = high, x = a[low];
	while(i < j)
	{
		while(i < j && a[j] >= x)
		{
			j--;
		}
		if(i < j)
		{
			a[i++] = a[j];
		}
		while(i < j && a[i] < x)
		{
			i++;
		}
		if(i < j)
		{
			a[j--] = a[i];
		}
	}
	a[i] = x;
	QuickSort(low, i - 1);
	QuickSort(i + 1, high);
} 

//��ѡ������
//���ȶ����㷨ʱ�临�Ӷ�ΪO(n^2)
void SelectSort(void)
{
	for(int i = 0; i < n - 1; i++)
	{
//      �߱Ƚϱ߽��� 
//		for(int j = i + 1; j < n; j++)
//		{ 
//			if(a[j] < a[i])
//			{
//				int tmp = a[i];
//				a[i] = a[j];
//				a[j] = tmp;
//			}
//		} 
//      �����±��ٽ���Ԫ�� 
        int min = i;
        for(int j = i + 1; j < n; j++)
        {
        	if(a[j] < a[min])
        	{
        		min = j;
			}
		}
		if(min != i)
		{
			int tmp = a[i];
			a[i] = a[min];
			a[min] = tmp;
		}
	}
} 

void AdjustDown(int k, int len)
{
	int tmp = b[k];  //����a[0] = a[k] 
	for(int i = 2 * k; i <= len; i *= 2)
	{
		if(i < len && b[i] < b[i + 1])
		{
			i++;  //ȡkey�ϴ���ӽڵ���±� 
		}
		if(tmp >= b[i])
		{
			break;
		} 
		else
		{
			b[k] = b[i];
			k = i;  //k�Ǳ�ɸѡ�ڵ�����λ���±� 
		}
	}
	b[k] = tmp;
}

void BulidMaxHeap(int len)
{
	for(int i = len / 2; i > 0; i--)  //��i=[n/2]��i=1���������� 
	{
		AdjustDown(i, len);  //����i�ڵ�Ϊ������������ɸѡ 
	}
} 

void HeapSort(int len)
{
	BulidMaxHeap(len);
	for(int i = len; i > 1; i--)  //n-1�˽����ͽ��ѹ��� 
	{
		int tmp = b[1];
		b[1] = b[i];
		b[i] = tmp;
		AdjustDown(1, i - 1);  //��ʣ���i-1��Ԫ������ɶ� 
	}
}

int main(void)
{
	/*********��������*********/
	assignment(); 
	printf("δ����\n"); 
	print();
	InsertSort();  
	printf("ֱ�Ӳ�������\n"); 
	print();
	
//	assignment(); 
//	printf("δ����\n"); 
//	print();
//	BinarySort();  
//	printf("�۰��������\n"); 
//	print();
	
	assignment(); 
	printf("δ����\n"); 
	print();
	ShellSort();  
	printf("ϣ������\n"); 
	print();
    
	/*********��������*********/
	assignment(); 
	printf("δ����\n"); 
	print();
	BubbleSort();  
	printf("ð������\n"); 
	print();
	
	assignment(); 
	printf("δ����\n"); 
	print();
	QuickSort(0, n - 1);  
	printf("��������\n"); 
	print();
	
	/*********ѡ������*********/
	assignment(); 
	printf("δ����\n"); 
	print();
	SelectSort();  
	printf("��ѡ������\n"); 
	print();
	
	assignmentb(); 
	printf("δ����\n"); 
	printb();
	HeapSort(n);  
	printf("�����򣨴���ѣ�\n"); 
	printb();
	
//��������һ������ѡ�����򷽷��������ص��ǣ�����������У���L[1...n]�ؿ�����һ����ȫ������
//��˳��洢�ṹ��������ȫ��������˫�׽��ͺ��ӽ��֮������ڹ�ϵ���ڵ�ǰ��������ѡ��ؼ������
//������С����Ԫ�ء�
//�ѵĶ������£�n���ؼ�������L[1...n]��Ϊ�ѣ����ҽ������������㣺
//L(i)<L(2i)��L(i)<L(2i+1)��L(i)>L(2i+1)��L(i)>L(2i)
//����Ĺؼ��ǹ����ʼ�ѣ��Գ�ʼ���н��ѣ�����һ������ɸѡ�Ĺ��̡�n��������ȫ����
//�������һ������ǵ���[n/2]�����ĺ��ӡ��Ե�[n/2]�����Ϊ��������ɸѡ�����ڴ���ѣ�
//�������Ĺؼ���С��������Ů�йؼ��ֽϴ��ߣ��򽻻�����ʹ��������Ϊ�ѡ�֮����ǰ���ζ�
//�����([n/2]-1��1��Ϊ������������ɸѡ�����ý��ֵ�Ƿ�����������ӽ���ֵ�������ǣ���
//�����ӽ���нϴ�ֵ��֮��������������ܻ��ƻ���һ���Ķѣ����Ǽ���������������������һ
//���Ķѣ�ֱ���Ըý��Ϊ�����������ɶ�Ϊֹ�������������������ѵķ������ѣ�ֱ������㡣
//Ӧ���������ݽṹ���������˼·�ܼ򵥣����Ƚ������L[1...n]�е�n��Ԫ�ؽ��ɳ�ʼ��
//���ڶѱ�����ص㣨�Դ󶥶�Ϊ�����Ѷ�Ԫ�ؾ������ֵ������Ѷ�Ԫ�غ�ͨ�����ѵ�
//Ԫ������Ѷ�����ʱ����㼺�������˶��ѵ����ʣ��ѱ��ƻ������Ѷ�Ԫ�����µ���ʹ��
//�������ִ󶥶ѵ����ʣ�������Ѷ�Ԫ�ء�����ظ���ֱ�����н�ʣ��һ��Ԫ��Ϊֹ��

    return 0;
}
