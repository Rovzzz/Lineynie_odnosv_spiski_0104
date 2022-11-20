#include <stdio.h>
#include <locale.h>

struct MyStruct
{
	//1 ����
	int a;
	// 2 ���� ��������� �� ������ ��������� ���������
	struct MyStruct* next;
};
typedef struct MyStruct s;
//��������� ��� ������ � �������
s* create(int);
void show(s*);
void delete(s*);
s* insert(s*, s, int);
s* delete_element(s* list, int k);
s* Swap_element(s* list, int a, int m);

int main() {
    int exit = 1;
    while (exit == 1)
    {
		system("chcp 1251>null");
		setlocale(LC_ALL, "Rus");
		printf("������� �� �������� ����������� ������\n");
		printf(" 1 - �������� ������\n 2 - ������� �������� ������ ������\n 3 -�������� �������� �� ������\n 4 - ������ ���� ��������� �������\n");
		printf("\n\n������� ����� ������: ");
		int length;
		scanf_s("%d", &length);
		printf("\n\n�������� ������: ");
		s* list1 = create(length);
		show(list1);
		printf("\n\n�������� ��������: ");
		int enter;
		scanf_s("%d", &enter);
		switch (enter)
		{
		case 1:
			printf("������ �� ������\n");
			system("pause");
			show(list1);
			printf("������ ������\n");
			system("pause");
			delete(list1);
			printf("������ ������\n");
			system("pause");
			break;
		case 2:
			printf("�������  ���������� ����� �����, ������� ������ ��������: ");
			int change_number;
			scanf_s("%d", &change_number);
			printf("������� �����, �� ������� ������ ��������: ");
			int new_number;
			scanf_s("%d", &new_number);
			s item = { new_number,NULL };
			list1 = insert(list1, item, change_number);
			show(list1);
			break;
		case 3:
			printf("�������  ���������� ����� �����, ������� ������ �������: ");
			int delete_number;
			scanf_s("%d", &delete_number);
			list1 = delete_element(list1, delete_number);
			show(list1);
			break;
		case 4:
			printf("�������  ���������� ����� 1 ����� �  ���������� ����� 2 �����, ������� ������ ��������\n");
			printf("�������  ���������� ����� 1 �����: ");
			int first_number;
			scanf_s("%d", &first_number);
			printf("\n�������  ���������� ����� 2 �����: ");
			int second_number;
			scanf_s("%d", &second_number);
			list1 = Swap_element(list1, first_number, second_number);
			show(list1);
			break;
		default:
			printf("�������� ��������!\n");
			break;
		}
		printf("\n\n�� ������ ����������?\n1-��\n0-���\n");
		scanf_s("%d", &exit);
	}
		return 0;
}

//�������� ������
s* create(int n)
{
	//�������� 1 �������� � �������������� ��������� ������
	s* start = malloc(sizeof(s));
	start->a = 1;
	start->next = NULL;

	s* p, * q;
	p = start;
	for (size_t i = 0; i < n - 1; i++)
	{
		q = malloc(sizeof(s));
		q->a = p->a + 1;
		p->next = q;
		p = q;
	}
	p->next = NULL;
	return start;
}

//����� ������
void show(s* list)
{
	//�������� �� ��� ��� ���� ���� �� ������ NULL
	while (list)
	{
		printf("%d ", list->a);
		list = list->next;
	}
	printf("\n");
}

//�������� ������
void delete(s* list)
{
	s* p = list;
	while (p)
	{
		p = list->next;
		free(list);
		list = p;
	}
};

//������� ��������� � ������
s* insert(s* list, s item, int k)
{
	s* el = malloc(sizeof(s));
	el->a = item.a;
	if (k == 1)
	{
		el->next = list;
		list = el;
	}
	else
	{
		void* start = list;
		for (size_t i = 1; i < k - 1; i++)
		{
			list = list->next;
			if (!(list->next))
			{
				printf("�� ����� ������, ����������� ������� ������. ������� ����� ������� � ����� ������\n");
				break;
			}
		}
		void* temp = list->next;
		list->next = el;
		el->next = temp;
		list = start;
	}
	return list;
};

//�������� �������� � �������
s* delete_element(s* list, int k)
{
	if (k == 1)
	{
		list = list->next;
	}
	else
	{
		for (size_t i = 1; i < k - 1; i++)
		{
			list = list->next;
			if (!(list->next))
			{
				printf("�� ����� ������, ����������� ������� ������. ������� ����� ������� � ����� ������\n");
				break;
			}
		}
		s* p1 = list;
		list->next = list->next->next;
	}
};

//������ ���� ��������� �������
s* Swap_element(s* list, int a, int m)
{
	s* min = list;
	s* max = list;
	s* _max = list;
	if (a != 1) {
		for (size_t n = -1; n < a; n++)
		{
			min = min->next;
		}
		for (size_t n = 0; n < m - 2; n++)
		{
			_max = _max->next;
		}
		s* l2 = _max->next;
		max = l2->next;
		s* l1 = min->next;
		min->next = l2;
		_max->next = l1;
		l2->next = l1->next;
		l1->next = max;
		return list;
	}
	else {
		for (size_t n = 0; n < m - 2; n++)
		{
			_max = _max->next;
		}
		s* l2 = _max->next;
		max = l2->next;
		s* l1 = min->next;
		min->next = list;
		_max->next = l1;
		l2->next = l1->next;
		l1->next = max;
		return list;
	}
}
