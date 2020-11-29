// Дана строка символов. Слова в строке отделяются одним пробелом. 
//Поменять местами самое длинное и самое короткое слово.
//


#include <stdio.h>
#include <stdlib.h>

int main()
{
	char* str;
	int* l;
	char** words;
	int i, j = 0, n, m = 0, k = 0;
	

	printf("Line length: ");
	scanf_s("%d\n", &n);
	n++;

	str = (char*)malloc(n * sizeof(char));	// Выделение памяти.

	fgets(str, n, stdin);

	puts(str);
	
	k = 0;
	for (i = 0; i < n; i++) { // Подсчёт количества пробелов.
		if (str[i] == ' ') {
			m++;
			
			k++;
		}
	}
	++m;

	printf("Words number: %d\n", m);
	
	l = (int*)calloc(m, sizeof(int));

	k = 0;
	for (i = 0; i < m; i++) {  //Подсчёт кол-ва символов в словах.
		while ((str[k] != ' ') & (str[k]!='\0') & (str[k]!='\n')) {
			l[i]++;
			k++;
		}
		k++;
	}
	
	//l[m - 1]--;
	for (i = 0; i < m; i++) {
		printf("%d\t", l[i]);
	}

	int max = l[0]; //Нахождение длины и номера самого длинного слова.
	int nmax = 0;
	for (i = 0; i < m; i++) {
		if (l[i] > max) {
			max = l[i];
			nmax = i;
		}
	}

	int min = l[0]; //Нахождение длины и номера самого короткого слова.
	int nmin = 0;
	for (i = 0; i < m; i++) {
		if (l[i] < min) {
			min = l[i];
			nmin = i;
		}
	}

	printf("lmax %d   lmin %d ", max, min);
	printf("nmax %d   nmin %d ", nmax, nmin);

	words = (char**)calloc(m, sizeof(char*));

	for (i = 0; i < m; i++) {
		words[i] = (char*)calloc(l[i], sizeof(char));
	}
	k = 0;
	for (i = 0; i < m; i++) { //Заполнение массива words словами 
		for (j = 0; j < l[i]; j++) {
			if ((str[k] != ' ') && (str[k] != '\0')) {
				words[i][j] = str[k];
			}
			k++;
		}
		k++;
	}

	printf("\n");
	for (i = 0; i < m; i++) {
		for (j = 0; j < l[i]; j++) {
			printf("%c", words[i][j]);
		}
		printf("_");
	}

	printf("\nlength:  ");
	for (i = 0; i < m; i++) {
		printf("%d ",l[i]);
	}
	int h = l[nmin];
	l[nmin] = l[nmax];
	l[nmax] = h;
	printf("\nlength after switch:  ");
	for (i = 0; i < m; i++) {
		printf("%d ", l[i]);
	}

	printf("\n");
	i = 0;
	while (i < m) {
		if ((i != nmin) & (i != nmax)) {
			for (j = 0; j < l[i]; j++) {
				printf("%c", words[i][j]);
			}
		}
		else if (i == nmin) {
			for (j = 0; j < max; j++) {
				printf("%c", words[nmax][j]);
			}
		}
		else if (i == nmax) {
			for (j = 0; j < min; j++) {
				printf("%c", words[nmin][j]);
			}
		}
		printf(" ");
		i++;
	}

	free(l);
	free(str);

	for (i = 0; i < m; i++) {
		free(words[i]);
	}
	free(words);
		
		return 0;
}
}
