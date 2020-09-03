#include"demo_43_seqlist���Ա�(˳��洢)ͷ�ļ�.h"  //�Ȳ鱾�ļ�����Ŀ¼�� 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _tag_SeqList
{
	int capacity;
	int length;
	int **node;  //Ҳ��int *node; 
}TSeqList;

//�������Ա�������ģ�� 
SeqList* SeqList_Creater(int capacity)
{
	int ret;
	TSeqList* tmp = NULL;
	tmp = (TSeqList *)malloc(sizeof(TSeqList) * capacity);
	if(tmp == NULL)
	{
		ret = 1;
		printf("func SeqList_Create() err:%d\n", ret);
		return NULL;
	} 
	memset(tmp, 0, sizeof(TSeqList));
	tmp->capacity = capacity; 
	tmp->length = 0;
	tmp->node = (int**)malloc(sizeof(void*) * capacity);
	//������Щint *node���������дtmp->node = (int*)malloc(sizeof(void*) * capacity);
	
	return tmp;
}

//�������Ա�2��������ģ�� 
int SeqList_Creater2(int capacity, SeqList**handle)
{
	int ret = 0;
	TSeqList* tmp = NULL;
	tmp = (TSeqList *)malloc(sizeof(TSeqList) * capacity);
	if(ret == NULL)
	{
		ret = 1;
		printf("func SeqList_Create() err:%d\n", ret);
		return ret;
	} 
	memset(tmp, 0, sizeof(TSeqList));
	tmp->capacity = capacity; 
	tmp->length = 0;
	tmp->node = (int**)malloc(sizeof(void*) * capacity);
	//������Щint *node���������дtmp->node = (int*)malloc(sizeof(void*) * capacity);
	 
	if(tmp == NULL)
	{
		ret = 2;
		printf("func SeqList_Create() err:%d\n", ret);
		return ret;
	} 
	
	*handle = tmp;
	
	return ret;
}

//�������Ա�
void SeqList_Destroy(SeqList* list)
{
	if(list == NULL)
	{
		return;
	}
	TSeqList* tmp = (TSeqList*)list;
	if(tmp->node != NULL)
	{
		free(tmp->node);
	}
	free(tmp);
	
	return;
}

//������Ա� 
void SeqList_Clear(SeqList* list)
{
	if(list == NULL)
	{
		return;
	}
	TSeqList* tmp = (TSeqList*)list;

	tmp->length = 0;
	memset(tmp->node, 0, tmp->capacity * sizeof(void*));
	
	return;
}

//���Ա��� 
int SeqList_Length(SeqList* list)
{
	if(list == NULL)
	{
		return -1;
	}
	TSeqList* tmp = (TSeqList*)list;

	return tmp->length;
}

//���Ա����� 
int SeqList_Capacity(SeqList* list)
{
	if(list == NULL)
	{
		return -1;
	}
	TSeqList* tmp = (TSeqList*)list;

	return tmp->capacity;
}

//����Ԫ�� 
int SeqList_Insert(SeqList* list, SeqListNode* node, int pos)
{
	if(list == NULL || node == NULL)
	{
		return -1;
	}
	int i;
	TSeqList* tmp = (TSeqList*)list;
	if(tmp->length >= tmp->capacity)
	{
		return -2;
	}
	if(pos > tmp->length)
	{
		pos = tmp->length;
	}
	if(pos < 0)
	{
		pos = 0;
	}
	
	for(i = tmp->length; i > pos; i--)
	{
		tmp->node[i] = tmp->node[i-1];
	}
	tmp->node[i] = (int*)node;
	tmp->length++;
	
	return 0;
}

//��ȡԪ�� 
SeqListNode* SeqList_Get(SeqList* list, int pos)
{
    TSeqList* tmp = (TSeqList*)list;
	SeqListNode* ret = tmp->node[pos];
	
	if(list == NULL || pos < 0 || pos >= tmp->length)
	{
		return NULL;
	}

	return ret;
}

//ɾ��Ԫ�� 
SeqListNode* SeqList_Delete(SeqList* list, int pos)
{
	int i;
	TSeqList* tmp = (TSeqList*)list;
	SeqListNode* ret = tmp->node[pos];

	if(list == NULL || pos < 0 || pos >= tmp->length)
	{
		return NULL;
	}
	
	for(i = pos + 1; i < tmp->length; i++)
	{
		tmp->node[i - 1] = tmp->node[i];
	}
	tmp->length--;
	
	return ret;
}

