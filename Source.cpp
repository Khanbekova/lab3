#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int M[4][4], m[3][3], OB[4][4], P[3][3], K[4][4];
	int  i, j, o, O, s, r, k = 0, l = 0, size=0;
	srand(8);
	

	printf(" Массив M1:  \n");
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (i == j) {
				M[i][j] = 0;
				printf("%d  ", M[i][j]);
			}
			if (i > j) {
				M[i][j] = M[j][i];
				printf("%d  ", M[i][j]);
			}
			if (i < j) {
				M[i][j] = rand() % 2;
				printf("%d  ", M[i][j]);
			}

		}
		printf("\n");
	}
	printf(" Массив M2:  \n");
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (i == j) {
				m[i][j] = 0;
				printf("%d  ", m[i][j]);
			}
			if (i > j) {
				m[i][j] = m[j][i];
				printf("%d  ", m[i][j]);
			}
			if (i < j) {
				m[i][j] = rand() % 2;
				printf("%d  ", m[i][j]);
			}

		}
		printf("\n");
	}
	printf("а) ОбЪединение графов:  \n");
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			OB[i][j] = M[i][j];
		}
	}
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (m[i][j] == 1) {
				OB[i][j] = 1;
			}
		}
	}
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			printf("%d  ", OB[i][j]);
		}
		printf("\n");
	}
	printf("б) Пересечение графов:  \n");
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			P[i][j] = 0;
		}
	}
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if ((m[i][j] == 1) && (M[i][j] == 1)) {
				P[i][j] = 1;
			}
		}
	}
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf("%d  ", P[i][j]);
		}
		printf("\n");
	}
	printf("в) Кольцевая сумма графов:  \n");
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			K[i][j] = 0;
		}
	}
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if ((M[i][j]!=m[i][j])) {
				K[i][j] = 1;
			}
		}
	}
	for (i = 0; i < 4; i++) {
		K[i][3] = M[i][3];
	}
	for (i = 0; i < 4; i++) {
		K[3][i] = M[3][i];
	}
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			printf("%d  ", K[i][j]);
		}
		printf("\n");
	}
	
	printf("Декартово произведение M1 и M2");
	int dek[12][12];
	int y = 0, x = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int q = 0; q < 3; q++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 3; k++)
				{
					if (((j == i) && (m[q][k] != 0)) || ((k == q) && (M[i][j] != 0))) {
						dek[x][y] = 1;
					}
					else
					{
						dek[x][y] = 0;
					}
					y++;
				}
			}
			y = 0;
			x++;
		}	
	}
	printf("\n\n");
	for (i = 0; i < 12; i++) {
		for (j = 0; j < 12; j++) {
			printf("%d  ", dek[i][j]);
		}
		printf("\n");
	}
	_getch();
}