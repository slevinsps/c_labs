#include <stdio.h>
#include <stdio.h>
#include <math.h>
#define PI 3.1415926
int main(void)
{
float a, b;  // ������ � ������ ��஭� ��ࠬ���
float u;  // 㣮� �� ����襬 �᭮�����
float h, s;  // ���� � ���頤� ��ࠬ���
printf("������ �������, ������� ��஭� �࠯�樨 � 㣮� �� ����襩 ��஭�: ");
scanf("%f %f %f", &a, &b, &u);
h = (a-b)*tan((PI/180)*u)/2;
s = h*a/2;
printf("���頤� ࠢ��: %7.3f\n", s);
return 0;
}
