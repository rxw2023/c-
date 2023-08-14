
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define WIDTH 8
#define HEIGHT 8
int map[HEIGHT][WIDTH] = {
	{0, 0, 1, 1, 1, 0, 0, 0},
	{0, 0, 1, 4, 1, 0, 0, 0},
	{0, 0, 1, 0, 1, 1, 1, 1},
	{1, 1, 1, 3, 0, 3, 4, 1},
	{1, 4, 0, 3, 2, 1, 1, 1},
	{1, 1, 1, 1, 3, 1, 0, 0},
	{0, 0, 0, 1, 4, 1, 0, 0},
	{0, 0, 0, 1, 1, 1, 0, 0}
};
int x,y;//�˵�λ�� 
int boxs;//���ӵĸ���
/*
0 ��
1 ǽ
2 ��
3 ����
4 Ŀ�ĵ�(��)
5 ����ɵ�����
*/ 
void initData();
void drawMap();
void moveUp();
void moveLeft();
void moveDown();
void moveRight(); 
int main(int argc, char *argv[] ){
	char direction;//����̵ķ��� 
	initData();   //��ʼ������ 
    while(1){
	system("cls");
	drawMap();
	if(!boxs){
		break;
	}
	direction=getch();
	switch(direction){
		case 'w':
			moveUp();
			break;
		case 'a':
			moveLeft();
			break;
		case 's':
			moveDown();
			break;
		case 'd':
			moveRight();
			break;
	} 
}
printf("��ϲ�������Ϸ��*");
return 0;
}
void initData(){
int i,j;
printf("��Ϸ�����У����Ժ�......");
for(i=0;i<HEIGHT;i++){
	for(j=0;j<WIDTH;j++){
		if(map[i][j]==2){
			x=j;
			y=i;
		}
		if(map[i][j]==3){
			boxs++;
		}
	}
}
}
void drawMap( ){
	int i,j;
	for(i=0;i<WIDTH;i++){
		for(j=0;j<HEIGHT;j++){
			switch(map[i][j]){
				case 0:
				      printf("  ");
				      break;
				case 1:
					  printf("��");
					  break;
				case 2:
					  printf("��");
					  break;
				case 3:
				      printf("��");
					  break;
			    case 4:
				      printf("��");
				      break;
				case 5:
					  printf("��");
					  break;
			}
		}
		printf("\n");
	}
}
void moveUp(){
	//���������������Ϸ�������
	int ux, uy; 
	
	//���Ϸ�û��Ԫ��ʱ��ֱ��return	
	if(y == 0){
		return;
	}
	
	//��¼�Ϸ�����
	ux = x;
	uy = y - 1; 
	
	//�Ϸ�Ϊ����ɷ���
	if(map[uy][ux] == 5){
		return;
	} 
	
	//�����Ϸ�Ϊǽ��ֱ��return 
	if(map[uy][ux] == 1){
		return;
	}
	
	//�����Ϸ�Ϊ����
	if(map[uy][ux] == 3){
		//�ж������Ϸ��Ƿ�Ϊǽ 
		if(map[uy - 1][ux] == 1){
			return;
		}
		
		//�ж������Ϸ��Ƿ�Ϊ��
		if(map[uy - 1][ux] == 4){
			//�������������ݸ�ֵΪ5�� 
			map[uy - 1][ux] = 5;
			map[uy][ux] = 0;
					
			//���ӵ���Ŀ��1	
			boxs--; 
		}else{
			//�ƶ�����
			map[uy - 1][ux] = 3;
		}
	}
	map[y][x] = 0;
	map[uy][ux] = 2;
	y = uy; 
} 
void moveLeft(){
	//����������������ߵ�����
	int lx, ly; 
	
	//�����û��Ԫ��ʱ��ֱ��return	
	if(x == 0){
		return;
	}
	
	//��¼�������
	lx = x - 1;
	ly = y; 
	
	//���Ϊ����ɷ���
	if(map[ly][lx] == 5){
		return;
	} 
	
	//�������Ϊǽ��ֱ��return 
	if(map[ly][lx] == 1){
		return;
	}
	
	//�������Ϊ����
	if(map[ly][lx] == 3){
		//�ж���������Ƿ�Ϊǽ 
		if(map[ly][lx - 1] == 1){
			return;
		}
		
		//�ж���������Ƿ�Ϊ��
		if(map[ly][lx - 1] == 4){
			//������������ݸ�ֵΪ5�� 
			map[ly][lx - 1] = 5;
			map[ly][lx] = 0;
		
			//���ӵ���Ŀ��1 
			boxs--; 
		}else{
			//�ƶ����� 
			map[ly][lx - 1] = 3; 
		}
	}
	map[y][x] = 0;
	map[ly][lx] = 2;
	x = lx; 
}

void moveDown(){
	//���������������·�������
	int dx, dy; 
	
	//���·�û��Ԫ��ʱ��ֱ��return	
	if(y == HEIGHT - 1){
		return;
	}
	
	//��¼�·�����
	dx = x;
	dy = y + 1; 
	
	//�·�Ϊ����ɷ���
	if(map[dy][dx] == 5){
		return;
	} 
	
	//�����·�Ϊǽ��ֱ��return 
	if(map[dy][dx] == 1){
		return;
	}
	
	//�����·�Ϊ����
	if(map[dy][dx] == 3){
		//�ж������·��Ƿ�Ϊǽ 
		if(map[dy + 1][dx] == 1){
			return;
		}
		
		//�ж������·��Ƿ�Ϊ��
		if(map[dy + 1][dx] == 4){
			//�������������ݸ�ֵΪ5�� 
			map[dy + 1][dx] = 5;
			map[dy][dx] = 0;
			
			//���ӵ���Ŀ��1 
			boxs--; 
		}else{
			//�ƶ�����
			map[dy + 1][dx] = 3; 
		}
	}
	map[y][x] = 0;
	map[dy][dx] = 2;
	y = dy; 
}

void moveRight(){
	//���������������ұߵ�����
	int rx, ry; 
	
	//���ұ�û��Ԫ��ʱ��ֱ��return	
	if(x == WIDTH - 1){
		return;
	}
	
	//��¼�ұ�����
	rx = x + 1;
	ry = y; 
	
	//�ұ�Ϊ����ɷ���
	if(map[ry][rx] == 5){
		return;
	} 
	
	//�����ұ�Ϊǽ��ֱ��return 
	if(map[ry][rx] == 1){
		return;
	}
	
	//�����ұ�Ϊ����
	if(map[ry][rx] == 3){
		//�ж������ұ��Ƿ�Ϊǽ 
		if(map[ry][rx + 1] == 1){
			return;
		}
		
		//�ж���������Ƿ�Ϊ��
		if(map[ry][rx + 1] == 4){
			//�������ұ����ݸ�ֵΪ5�� 
			map[ry][rx + 1] = 5;
			map[ry][rx] = 0;
			
			//���ӵ���Ŀ��1 
			boxs--; 
		}else{
			//�ƶ����� 
			map[ry][rx + 1] = 3; 
		}
	}
	map[y][x] = 0;
	map[ry][rx] = 2;
	x = rx; 
}
