#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 비교 함수 정의
int compareStrings(const void* a, const void* b) {
    return (*(const char*)a- *(const char*)b);
}

int main() {
    // 입력받을 문자열의 최대 길이를 정의
#define MAX_LENGTH 100

    // 입력받을 문자열과 단어를 저장할 배열 선언
    char input[MAX_LENGTH];
    char words[MAX_LENGTH][MAX_LENGTH];
    char* final_words[MAX_LENGTH]; // 중복을 제거한 단어를 저장할 포인터 배열

    int word_count = 0, sent_count = 0;

    do {
        // 사용자에게 입력을 받음
        printf("문장을 입력하세요 (종료하려면 'end' 입력): ");
        scanf(" %[^\n]s", input);

        // "end" 입력 시 종료
        if (strcmp(input, "end") == 0) {
            break;
        }

        // 문자열을 단어로 나누기
        char* token = strtok(input, " "); // 공백을 기준으로 문자열을 자름

        while (token != NULL) {
            // 단어를 배열에 저장
            strcpy(words[word_count], token);

            // 다음 단어를 가져오기
            token = strtok(NULL, " ");

            // 단어 개수 증가
            word_count++;
        }

        // 문장 개수 증가
        sent_count++;

    } while (1); // 무한 루프

    // 중복을 제거한 단어 찾기
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

    // 단어 정렬
    qsort(final_words, final_word_count, sizeof(char*), compareStrings);

    /*
    printf("\n단어들:\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s\n", words[i]);
    }
    */

    printf("단어의 갯수: %d\n", word_count);
    printf("문장의 갯수: %d\n", sent_count);
    printf("중복을 제거한 단어의 갯수: %d\n", final_word_count);

    // 정렬된 단어 출력
    printf("\n정렬된 단어들:\n");
    for (int i = 0; i < final_word_count; i++) {
        printf("%s\n", final_words[i]);
    }

    return 0;
}
