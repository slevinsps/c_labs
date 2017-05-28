#include <stdio.h>
#include "sum_proizved.h"

void test_sum_proizved(void)
{
	int expected;
	int actual;
	const int *pb;
	const int *pe;
	
	// ���� 1
    {
        int a[] = {1,-2,3,-1,5};
		expected = -13;
        pb = a;
		pe = pb + sizeof(a) / sizeof(a[0]);
		actual = sum_proizved(pb,pe-1);
        if (expected == actual)
            printf("Test 1 passed\n");
		else
		{
			printf("Test 1 failed\n");
			printf("  Expected %d\n  Actual %d\n",expected,actual);
		}
    }
	// ���� 2 - ����������� ������������� �����
    {
        int a[] = {1, 5, 8, 4, 5};
		expected = 0;
        pb = a;
		pe = pb + sizeof(a) / sizeof(a[0]);
		actual = sum_proizved(pb,pe-1);
        if (expected == actual)
            printf("Test 2 passed\n");
		else
		{
			printf("Test 2 failed\n");
			printf("  Expected %d\n  Actual %d\n",expected,actual);
		}
    }
	// ���� 3 - ����������� ������������� �����
    {
        int a[] = {-1, -5, -8, -4, -5};
		expected = 0;
        pb = a;
		pe = pb + sizeof(a) / sizeof(a[0]);
		actual = sum_proizved(pb,pe-1);
        if (expected == actual)
            printf("Test 3 passed\n");
		else
		{
			printf("Test 3 failed\n");
			printf("  Expected %d\n  Actual %d\n",expected,actual);
		}
    }
	// ���� 4 - ������� ������ ����
    {
        int a[] = {0};
		expected = 0;
        pb = a;
		pe = pb + sizeof(a) / sizeof(a[0]);
		actual = sum_proizved(pb,pe-1);
        if (expected == actual)
            printf("Test 4 passed\n");
		else
		{
			printf("Test 4 failed\n");
			printf("  Expected %d\n  Actual %d\n",expected,actual);
		}
    }
	// ���� 5 - ��� �����
    {
        int a[] = {1, -2};
		expected = -2;
        pb = a;
		pe = pb + sizeof(a) / sizeof(a[0]);
		actual = sum_proizved(pb,pe-1);
        if (expected == actual)
            printf("Test 5 passed\n");
		else
		{
			printf("Test 5 failed\n");
			printf("  Expected %d\n  Actual %d\n",expected,actual);
		}
    }
	// ���� 6 - ������������ ������� �����
    {
        int a[] = {1, -2, 3, 2.5, 5};
		expected = -10;
        pb = a;
		pe = pb + sizeof(a) / sizeof(a[0]);
		actual = sum_proizved(pb,pe-1);
        if (expected == actual)
            printf("Test 6 passed\n");
		else
		{
			printf("Test 6 failed\n");
			printf("  Expected %d\n  Actual %d\n",expected,actual);
		}
    }
}

int main(void)
{
    test_sum_proizved();
    return 0;
}