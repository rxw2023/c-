//Beep()������ͷ�ļ�windows.h
//��������(���ȣ�����ʱ��)
#include<stdio.h>
#include<windows.h>
typedef struct 
{
	int freq; //����
	int duration;//����ʱ��
	char text[32];//�ı�����
}STU;
STU 
t[]={ {1318, 250, "Su"}, {1318, 250, "per"},{1404, 250," ld"},{1318,250,"ol"}, {1175, 250, "��"},{1318,250,"Ц"},{880,500, "��"},
 {1175, 250, "��"},{1046, 250, "��"}, {880,500, "��"},{1046, 500, "��"},  {1175, 500, "��\n"},
{1175, 250, "��"}, {1175, 250, "��"}, {1318, 250, "��"}, {1175, 250, "��"},{1046, 250, "��"}, {1175, 250, "��"}, {1318, 500, "��"}, 
{1046, 250, "��"},{880,250, "û"},{1046, 500, "��"},{1046, 500, "ҫ"},{880,500, "��\n"},
{1318, 250, "��"}, {1318, 250, "��"},{1404, 250," 105"},{1318,250,""}, {1175, 250, ""},{1046, 250, ""}, {1318,250,"��"}, {1175, 125, ""},
 {1175, 250, "��"},{1318,250,""},{880,500, "��\n"},
 {880,250, "��"},{1046, 250, "��"},{988, 500, "��"},{988, 500, "����"},
{1318, 500, "��"}, {1318, 500, "��"}, {1046, 2500, "ˮ\n"},
{1318, 250, "��"}, {1318, 250, "��"},{1404, 250," ��"},{1318,250,"һ"}, {1175, 250, "��"},{1046,250,"��"},{880,500, "��"},
 {1175, 250, "��"},{1046, 250, "��"}, {880,500, "��"},{1046, 500, "ʱ"},  {1175, 500, "��\n"},
{1175, 250, "Ī"}, {1175, 250, "��"}, {1318, 250, "��"}, {1175, 250, "��"},{1046, 250, "��"}, {1175, 250, "��"}, {1318, 500, "��"}, 
{1046, 250, "ʹ"},{880,250, "��"},{1046, 500, "ȥ"},{1046, 500, "��"},{880,500, "��\n"},
{1318, 250, "��"}, {1318, 250, "��"},{1404, 250," 105"},{1318,250,""}, {1175, 250, ""},{1046, 250, ""}, {1318,250,"��"}, {1175, 125, ""},
 {1175, 250, "��"},{1318,250,""},{880,500, "��\n"},
 {880,250, "��"},{1046, 250, "��"},{988, 500, "��"},{988, 500, "����"},
{1318, 500, "��"}, {1318, 500, "��"}, {1046, 2500, "ˮ"},};

main()
{
	int i;
	//�ṹ������ĳ���sizeof(t)/sizeof(STU)�õ����ܽṹ�������С / �����ṹ���С
	for (i=0; i<sizeof(t)/sizeof(STU); i++)
	{
		printf("%s",t[i].text);
		Beep(t[i].freq,t[i].duration);
	}
}
