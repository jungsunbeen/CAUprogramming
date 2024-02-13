#define _CRT_SECURE_NO_WARNINGS
#define MAX_WORD 50000
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

char line[MAX_WORD];
char word[MAX_WORD][100];
char meaning[MAX_WORD][100];

// �� �Լ�: �ܾ��� ���̸� ��
int compareByLength(const void* a, const void* b) {
    return strlen((const char*)b) - strlen((const char*)a);
}

// �� �Լ�: ������ ������ ��
int countVowels(const char* str) {
    int count = 0;
    const char *vowels = "aeiouAEIOU";

    for (int i = 0; str[i] != '\0'; ++i) {
        if (strchr(vowels, str[i]) != NULL) {
            count++;
        }
    }

    return count;
}

int compareByVowels(const void* a, const void* b) {
    return countVowels((const char*)b) - countVowels((const char*)a);
}

int main(void) {
    FILE* pFile;

    char inputword[100];
    int found = 0;
    int k = 0;

    pFile = fopen("dict_test.txt", "r");
    if (pFile == NULL) {
        perror("���� ���� ����");
    }
    else {
        while (fgets(line, 100, pFile) != NULL) {
            if (sscanf(line, "%99[^:]:%99[^\n]", word[k], meaning[k]) == 2) {
                word[k][strlen(word[k]) - 1] = '\0';
                k++;
                if (k >= MAX_WORD) {
                    break;
                }
            }
            else {
                // ����ó��
                // printf("Invalid line: %s\n", line);
            }
        }
        fclose(pFile);

        // �ܾ��� ���̰� �� ������ ���� 10�� �ܾ� ǥ��
        qsort(word, k, sizeof(word[0]), compareByLength);
        printf("�ܾ��� ���̰� �� ������ �ܾ� 10��:\n");
        for (int i = 0; i < 10 && i < k; ++i) {
            printf("%s\n", word[i]);
        }

        // ������ ���� ���� ���Ե� �ܾ� 10�� ǥ��
        qsort(word, k, sizeof(word[0]), compareByVowels);
        printf("\n������ ���� ���� ���Ե� �ܾ� 10�� :\n");
        for (int i = 0; i < 10 && i < k; ++i) {
            printf("%s\n", word[i]);
        }
    }
    return 0;
}