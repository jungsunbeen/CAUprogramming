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
        perror("���� ���� ����");
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
                // ����ó��
                // printf("Invalid line: %s\n", line);
            }
        }
        fclose(pFile);
    }

    char gameword[10][10];
    int count = 1, score = 0, life = 3;
    int random = rand() % MAX_WORD;

    strcpy(gameword[0], word[random]);
    printf("��ǻ�� : %s \n", gameword[0]);
    printf("�����ձ� �ܾ� : ");
    scanf("%s", gameword[count]);
    if (gameword[0][strlen(gameword[0]) - 1] == gameword[count][0]) {//����Ȯ��
        for (int i = 0;i < MAX_WORD;i++) {
            if (strcmp(gameword[count], word[i]) == 0) {
                count = 1;
            }
            else//�ܾ ��������������
                ;
        }
    }
    if (count == 1) {
        score += 1;
        printf("+1\n���� ���� %d�� ��� :������\n", score);
    }
    else if (count == 0) {
        printf("�׷� �ܾ� ����\n���� ���� %d�� ���  ����\n", score);
        count++;
        life = 2;
    }

    int check = 0;
    int check2 = 0;

    while (life > 0) {
        for (count = 2; count < 100; count++) {
            printf("�����ձ� �ܾ� : ");
            scanf("%s", gameword[count]);

            // ������ ��ġ�ϴ��� Ȯ��
            if (gameword[count - 1][strlen(gameword[count - 1]) - 1] == gameword[count][0]) {
                // �ߺ� �ܾ� Ȯ��
                for (int j = 0; j < count; j++) {
                    if (strcmp(gameword[count], gameword[j]) == 0) {
                        printf("�ߺ��� �ܾ �Է��Ͽ����ϴ� \n");
                        life--;
                        check = 1;
                        break;
                    }
                }

                if (check==0) {
                    // �ܾ �����ϴ��� Ȯ��
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
                printf("������ ��ġ���� �ʽ��ϴ�.\n");
                life--;
            }

            if (check2 == 0) {
                printf("�������� �ʴ� �ܾ�\n");
                life--;
            }

            printf("���� ���� %d�� ��� : ", score);
            for (int l = 0; l < life; l++) {
                printf("��");
            }
            printf("\n");

            if (life == 0) {
                printf("�������� ���� : %d", score);
                break;
            }
        }
    }

    return 0;
}