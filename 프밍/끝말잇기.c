#define _CRT_SECURE_NO_WARNINGS
#define MAX_WORD 50000
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char line[MAX_WORD];
char word[MAX_WORD][100];
char meaning[MAX_WORD][100];

int main(void)
{
    srand(time(NULL));
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

    char gameword[10][10];
    int count = 1, score = 0, life = 3;
    int random = rand() % MAX_WORD;

    strcpy(gameword[0], word[random]);
    printf("컴퓨터 : %s \n", gameword[0]);
    printf("끝말잇기 단어 : ");
    scanf("%s", gameword[count]);
    if (gameword[0][strlen(gameword[0]) - 1] == gameword[count][0]) {//끝말확인
        for (int i = 0;i < MAX_WORD;i++) {
            if (strcmp(gameword[count], word[i]) == 0) {
                count = 1;
            }
            else//단어가 존재하지않을때
                ;
        }
    }
    if (count == 1) {
        score += 1;
        printf("+1\n현재 점수 %d점 목숨 :♥♥♥\n", score);
    }
    else if (count == 0) {
        printf("그런 단어 없음\n현재 점수 %d점 목숨  ♥♥\n", score);
        count++;
        life = 2;
    }

    int check = 0;
    int check2 = 0;

    while (life > 0) {
        for (count = 2; count < 100; count++) {
            printf("끝말잇기 단어 : ");
            scanf("%s", gameword[count]);

            // 끝말이 일치하는지 확인
            if (gameword[count - 1][strlen(gameword[count - 1]) - 1] == gameword[count][0]) {
                // 중복 단어 확인
                for (int j = 0; j < count; j++) {
                    if (strcmp(gameword[count], gameword[j]) == 0) {
                        printf("중복된 단어를 입력하였습니다 \n");
                        life--;
                        check = 1;
                        break;
                    }
                }

                if (check==0) {
                    // 단어가 존재하는지 확인
                    for (int i = 0; i < MAX_WORD; i++) {
                        if (strcmp(gameword[count], word[i]) == 0) {
                            score += 1;
                            printf("+1\n");
                            check2 = 1;
                            break;
                        }
                    }
                }
            }
            else {
                printf("끝말이 일치하지 않습니다.\n");
                life--;
            }

            if (check2 == 0) {
                printf("존재하지 않는 단어\n");
                life--;
            }

            printf("현재 점수 %d점 목숨 : ", score);
            for (int l = 0; l < life; l++) {
                printf("♥");
            }
            printf("\n");

            if (life == 0) {
                printf("게임종료 총점 : %d", score);
                break;
            }
        }
    }

    return 0;
}