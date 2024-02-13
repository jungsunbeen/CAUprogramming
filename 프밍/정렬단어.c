#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �� �Լ� ����
int compareStrings(const void* a, const void* b) {
    return (*(const char*)a- *(const char*)b);
}

int main() {
    // �Է¹��� ���ڿ��� �ִ� ���̸� ����
#define MAX_LENGTH 100

    // �Է¹��� ���ڿ��� �ܾ ������ �迭 ����
    char input[MAX_LENGTH];
    char words[MAX_LENGTH][MAX_LENGTH];
    char* final_words[MAX_LENGTH]; // �ߺ��� ������ �ܾ ������ ������ �迭

    int word_count = 0, sent_count = 0;

    do {
        // ����ڿ��� �Է��� ����
        printf("������ �Է��ϼ��� (�����Ϸ��� 'end' �Է�): ");
        scanf(" %[^\n]s", input);

        // "end" �Է� �� ����
        if (strcmp(input, "end") == 0) {
            break;
        }

        // ���ڿ��� �ܾ�� ������
        char* token = strtok(input, " "); // ������ �������� ���ڿ��� �ڸ�

        while (token != NULL) {
            // �ܾ �迭�� ����
            strcpy(words[word_count], token);

            // ���� �ܾ ��������
            token = strtok(NULL, " ");

            // �ܾ� ���� ����
            word_count++;
        }

        // ���� ���� ����
        sent_count++;

    } while (1); // ���� ����

    // �ߺ��� ������ �ܾ� ã��
    int final_word_count = 0;
    for (int i = 0; i < word_count; i++) {
        int is_duplicate = 0;
        for (int j = 0; j < final_word_count; j++) {
            if (strcmp(words[i], final_words[j]) == 0) {
                is_duplicate = 1;
                break;
            }
        }

        if (!is_duplicate) {
            final_words[final_word_count++] = words[i];
        }
    }

    // �ܾ� ����
    qsort(final_words, final_word_count, sizeof(char*), compareStrings);

    /*
    printf("\n�ܾ��:\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s\n", words[i]);
    }
    */

    printf("�ܾ��� ����: %d\n", word_count);
    printf("������ ����: %d\n", sent_count);
    printf("�ߺ��� ������ �ܾ��� ����: %d\n", final_word_count);

    // ���ĵ� �ܾ� ���
    printf("\n���ĵ� �ܾ��:\n");
    for (int i = 0; i < final_word_count; i++) {
        printf("%s\n", final_words[i]);
    }

    return 0;
}
