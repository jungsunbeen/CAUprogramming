#define _CRT_SECURE_NO_WARNINGS
#define MAX_WORD 50000
#include <stdio.h>
#include <string.h>

char line[MAX_WORD];
char word[MAX_WORD][100];
char meaning[MAX_WORD][100];

int main(void)
{
    FILE* pFile;

    char inputword[100];
    int found = 0;
    int k = 0;

    pFile = fopen("dict_test.txt", "r");
    if (pFile == NULL) {
        perror("파일 열기 실패");
    }
    else {
        while (fgets(line, 100, pFile) != NULL)
        {
            
            if (sscanf(line, "%99[^:]:%99[^\n]", word[k], meaning[k]) == 2) {
                word[k][strlen(word[k]) - 1] = '\0';
                k++;
                if (k >= MAX_WORD) {
                    break; 
                }
            }
            else {
                // 예외처리
                // printf("Invalid line: %s\n", line);
            }
        }
        fclose(pFile);
    }

    while (1) {
        found = 0;
        printf("뜻을 찾을 단어를 입력하시오:");
        scanf("%s", inputword);

        for (int i = 0; i < k; i++) {
            if (strcmp(inputword, word[i]) == 0) {
                printf("%s\n", meaning[i]);
                found = 1;
                break;
            }
        }

        if (found == 0) {
            printf("그런 단어 없음 \n");
            break;
        }
    }
    return 0;
}