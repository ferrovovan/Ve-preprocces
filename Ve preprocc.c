#include <stdio.h>
#include <string.h>
#include "double_char.h"

#define MAX_FILE_NAME 64
#define MAX_STRING_LEN 100
#define MAX_SERVICE_WORD_LEN 50

char calc_rus(char in_char){
	return in_char + 71;
}

char* trans_literation(char in_char){
	if (in_char == 1)
		return "a";
	if (in_char == 2)
		return "b";
}

int procces_string (char *inString, char *outString){
	int in_len = strlen(inString);
	int index = 0;

	int words_len = MAX_STRING_LEN;
	double_char words[word_len];	clear_n_double_char(words, word_len);
	int words_index = 0;

	// считываем в свой формат
	while(index < in_len){
		// считываем символ
		if (inString[index] > 0){	// ASCII СИМВОЛ
			words[words_index].letter[0] = inString[index];
			words[words_index].flag = 1;
			index += 1;
		}
		else{				// пейте воду из байкала
			words[words_index].letter[0] = inString[index];
			words[words_index].letter[1] = inString[index+1];
			words[words_index].flag = 2;
			index += 2;
		}
		words_index++;
	}

	// форматируем строку
	int words_len = words_index;
	words_index = 0;
	if( inString[0] == 35 ){ // если считываем директива препроцессора

		while( word[word_index].letter[0] != 32 ||
			word[word_index].flag != 1){ // ПРОБЕЛ
			words_index++;
		
		}
		if (word[word_index].letter == 32 &&
		word[word_index].flag == 1){ 
			  	
				// анализируем слово
				is_direction = 0;
		}
	}


		char word[MAX_STRING_LEN - 1];
		int i;
		for (i=1; (int*)inString[i] != 32; i++){
			printf("inString[%d]=%d | %c\n", i, (int*)inString[i], inString[i]);
			if( i >= in_len)	return 1;
			word[i - 1] = inString[i];
		}
		// обработка дерективы
		printf("%s\n", word);
		if( strcmp(word, "добавь") )
			strcpy( outString, "#include");
		else if( strcmp(word, "обозначь") )
			strcpy( outString, "#define");
		else
			strcpy( outString, word);
		// Дописываем остаток строки
		strcpy( outString, inString );
	else{
		strcpy( outString, inString );
	}
	return 0;
}

int main(void){
	char file_name[MAX_FILE_NAME];
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	// справка номеров символов
	printf("#=%d\n", (int*)'#');
	printf(" =%d\n", (int*)' ');
	
	scanf("%s\n", file_name);
	FILE *inFile	= fopen(file_name, "r");
	printf("%s\n", file_name);
	
	scanf("%s", file_name);
	FILE *outFile	= fopen(file_name, "w");
	printf("%s\n", file_name);

	char input_string[MAX_STRING_LEN];
	char output_string[MAX_STRING_LEN];

	while( fgets(input_string, MAX_STRING_LEN, inFile)	!= NULL){
		int code = process_string(input_string, output_string);
		printf("%s", output_string);
		return 0;
		fputs(outFile, output_string);
	}
	fclose(inFile);
	fclose(outFile);
	return 0;
}
