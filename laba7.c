// Дана строка символов. Слова в строке отделяются одним пробелом. 
//Поменять местами самое длинное и самое короткое слово.
//

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char* str;
	char** words;
	int* l;
	int i, j = 0, n, m = 0, k = 0, d=0;
	int* nw;

	printf("Line length: ");
	scanf_s("%d\n", &n);
	n += 1;

	str = (char*)malloc(n * sizeof(char));	// выделение памяти 

	fgets(str, n - 2, stdin);

	puts(str);

	for (i = 0; i < n; i++) { // Подсчёт количества пробелов.
		if (str[i] == ' ') {
			m++;
		}
	}
	m++;

	printf("Words number: %d\n", m);

	nw = (int*)malloc(m * sizeof(int)); // Нахождение пробелов в строке.
	nw[0] = -1;
	k = 1;
	for (i = 0; i < n; i++) {
		if ((str[i] = ' ') | (str[i] = '\0')) {
			nw[k] = i;
			k++;
		}
	}
	k = 0;
	printf("\n");
	for (i = 0; i < m; i++) {
		printf("%d  ", nw[i]);
	}
	
	l = (int*)malloc(m * sizeof(int));

	for (i = 0; i < m; i++) {  //Подсчёт кол-ва символов в словах.
		while ((str[k] != ' ') & (str[k]!='\0')) {
			l[i]++;
			k++;
		}
		k++;
	}
	l[i]--;

	for (i = 0; i < m; i ++){
		printf("%d\t", l[i]);
	}

	words = (char**)calloc(m, sizeof(char*));

	for (i = 0; i < m; i++) {
		words[i] = (char*)calloc(l[i], sizeof(char));
	}

	k = 0;

	/*for (i = 0; i < m; i++) { //Заполнение массива words словами 
		for (j = 0; j < n; j++) {
			if ((str[k] != ' ') & (str[k] != '\0')) {
			words[i][j] = str[k];
			}
			k++;
		}
		k++;
	}*/

	
	
	return 0;

}
