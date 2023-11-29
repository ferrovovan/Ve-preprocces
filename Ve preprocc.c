#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, ""); // Устанавливаем локаль для корректной работы с широкими символами

    FILE *inputFile, *outputFile;
    inputFile = fopen("input.txt", "r, ccs=UTF-8"); // Открываем файл на чтение с указанием кодировки UTF-8
    outputFile = fopen("output.txt", "w, ccs=UTF-8"); // Открываем файл на запись с указанием кодировки UTF-8

    if (inputFile == NULL || outputFile == NULL) {
        perror("Ошибка открытия файла");
        return 1;
    }

    wint_t wc;
    while ((wc = fgetwc(inputFile)) != WEOF) {
        // Преобразование русских букв в английские (пример для буквы 'а' и 'А')
        if (wc == L'а') {
            wc = L's';
        } else if (wc == L'А') {
            wc = L'A';
        }

        fputwc(wc, outputFile); // Записываем символ в выходной файл
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
