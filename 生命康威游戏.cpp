#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
int main() { //����������Ϸ���汾 1�����õ��� main ����ʵ��
 const int HT = 23, WD = 39, RATE = 30;
 int map[HT + 2][WD + 2] = {0}; //��Ϸ��ͼ������Ϊ��Ϸ��������Ϊ�գ�
 int bak[HT + 2][WD + 2] = {0}; //����ǰ���ڱ��ݵ�ǰ��ͼ
 int ix, iy, n;
 //��ʼ��
 srand(time(0)); //��ʼ�����������
 for (iy = 1; iy <= HT; iy++) //��ѭ��
  for (ix = 1; ix <= WD; ix++) //��ѭ��
   map[iy][ix] = ((rand() % 100) < RATE) ? 1 : 0; //��ʼ����ͼ
 printf("����������Ϸ\n ��ͼ����: %d, ����: %d\n", HT, WD);
 printf("��ʼ����ʣ�%d%%\n ���س�����ʼ", RATE);
 getchar();                                                                                                                                                                                                                                                                       
 int count = 0; //��������
 while (1) { //����ѭ������;���� break �˳�
  //���Ƶ�ͼ
  for (iy = 1; iy <= HT; iy++) { //��ѭ��
   for (ix = 1; ix <= WD; ix++) //��ѭ��
    printf((map[iy][ix] ? "[]" : " "));
   printf("\n");
  }
  printf("������Ϸ������������%d \n �س������£�x �˳�", ++count);
//  if (getchar() == 'x') //��ȡ�ַ������жϡ�x ���˳�
//   break;
//  sleep(1);
  system("cls");
  //���Ƶ�ǰ��ͼ�������ڸ���
  for (iy = 1; iy <= HT; iy++)
   for (ix = 1; ix <= WD; ix++)
    bak[iy][ix] = map[iy][ix];
  //����ÿ�������Χ��������������ݴ˸���������״̬
  for (iy = 1; iy <= HT; iy++) {
   for (ix = 1; ix <= WD; ix++) {
    n = bak[iy-1][ix-1] + bak[iy-1][ix] + bak[iy-1][ix+1]
    + bak[iy][ix-1] + bak[iy][ix+1]
    + bak[iy+1][ix-1] + bak[iy+1][ix] + bak[iy+1][ix+1];
    if (n <= 1) map[iy][ix] = 0; //ϡ�ٶ�����
    //if (n == 2 || n == 3) map[iy][ix] = map[iy][ix];//����
    if (n == 3 && map[iy][ix] == 0) map[iy][ix] = 1; //��ֳ
    if (n >= 4) map[iy][ix] = 0; //���������
   }
  }
 }
 printf("\n ��Ϸ������ллʹ�á�");
 return 0;
}
//��Ҫ: ��
//��ע: -
