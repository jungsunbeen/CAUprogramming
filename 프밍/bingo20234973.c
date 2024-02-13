#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
    // �õ带 �ʱ�ȭ�Ͽ� ������ ���ڸ� ����
    srand(time(NULL));

    int mybingo[5][5], computerbingo[5][5];  // 5x5 ������ �迭
    int number[25];// 1���� 25������ ���� �迭
    int mybingoN = 0, computerbingoN = 0;
    void cheakbingo(int mybingo[5][5], int mybingoN);

    // 1���� 25������ ���ڷ� �迭 �ʱ�ȭ
    for (int i = 0; i < 25; i++){
        number[i] = i + 1;
    }

    // ���� ���� (Fisher-Yates ���� �˰��� ���)
    for (int i = 24; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = number[i];
        number[i] = number[j];
        number[j] = temp;
    }

    // ���ڸ� �����ǿ� ��ġ
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            mybingo[i][j] = number[i * 5 + j];
        }
    }

    //�� ���� ���
    printf("my bingo:\n");
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            printf("+----");
        }
        printf("+\n");

        for (int j = 0; j < 5; j++){
            if (number[mybingo[i][j]] == 0){
                printf("|(%2d)", mybingo[i][j]);
            }
            else
                printf("|%3d ", mybingo[i][j]);
        }
        printf("|\n");
    }

    for (int j = 0; j < 5; j++){
        printf("+----");
    }
    printf("+\n");

    // ���� ���� (Fisher-Yates ���� �˰��� ���)
    for (int i = 24; i > 0; i--){
        int j = rand() % (i + 1);
        int temp = number[i];
        number[i] = number[j];
        number[j] = temp;
    }

    // ���ڸ� �����ǿ� ��ġ
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            computerbingo[i][j] = number[i * 5 + j];
        }
    }

    //��ǻ�� ���� ���
    printf("computer bingo:\n");
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            printf("+----");
        }
        printf("+\n");

        for (int j = 0; j < 5; j++){
            if (number[computerbingo[i][j]] == 0){
                printf("|(%2d)", computerbingo[i][j]);
            }
            else
                printf("|----");
        }
        printf("|\n");
    }

    for (int j = 0; j < 5; j++){
        printf("+----");
    }
    printf("+\n");

    //game start
    int num, i, j, k;
    int count = 1;

    //�� ����
    do {
        while (count % 2 == 1) {
            printf("1���� 25������ ���ڸ� �Է��ϼ��� :");
            scanf("%d", &num);
            if (num >= 1 && num <= 25) {
                if (number[num] != 0) {
                    number[num] = 0;
                    count++;
                    break;
                }
                else if (number[num] == 0)
                    printf("�̹� �Է��� �����Դϴ�. �ٸ� ���ڸ� �Է��ϼ��� : ");
            }
            else
                printf("1~25 ���ڸ� �Է��ϼ��� : ");
        }

        //��ǻ�� ����
        while (count % 2 == 0) {
            if (number[computerbingo[2][2]] != 0) {
                num = computerbingo[2][2];
                number[num] = 0;
                count++;
                break;
            }
            /*
            else if (number[computerbingo[2][2]] == 0)
            {
                for (i = 0; i < 5; i++)
                {
                    for (j = 0; j < 5; j++)
                    {
                        if (computerbingo[i][j] == 0 && computerbingo[i + 1][j + 1] == 0)
                        {
                            if (number[computerbingo[i + 2][j + 2]] != 0) {
                                num = computerbingo[i + 2][j + 2];
                                number[num] = 0;
                                count++;
                                break;
                            }
                        }
                        else if (computerbingo[i][j] == 0 && computerbingo[i - 1][j - 1] == 0){
                            if (number[computerbingo[i - 2][j - 2]] != 0) {
                                num = computerbingo[i - 2][j - 2];
                                number[num] = 0;
                                count++;
                                break;
                            }
                        }
                    }
                }
            }*/
            else {
                do {
                    num = rand() % 25 + 1;
                } while (number[num] == 0);
                number[num] = 0;
                count++;
                break;
            }
        }
        printf("��ǻ�ʹ� %d�� �����Ͽ����ϴ�.\n", num);

        //�� ���� ���
        printf("my bingo:\n");
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                printf("+----");
            }
            printf("+\n");

            for (int j = 0; j < 5; j++) {
                if (number[mybingo[i][j]] == 0) {
                    printf("|(%2d)", mybingo[i][j]);
                }
                else
                    printf("|%3d ", mybingo[i][j]);
            }
            printf("|\n");
        }

        for (int j = 0; j < 5; j++) {
            printf("+----");
        }
        printf("+\n");

        //��ǻ�� ���� ���
        printf("computer bingo:\n");
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                printf("+----");
            }
            printf("+\n");

            for (int j = 0; j < 5; j++) {
                if (number[computerbingo[i][j]] == 0) {
                    printf("|(%2d)", computerbingo[i][j]);
                }
                else
                    printf("|----");
            }
            printf("|\n");
        }

        for (int j = 0; j < 5; j++) {
            printf("+----");
        }
        printf("+\n");

        // ���� �˻�
        mybingoN = 0, computerbingoN = 0;
        int h, v;

        for (h = 0; h < 5; h++) {
            for (v = 0; v < 5; v++) {
                if (number[mybingo[h][v]] != 0) break;
            }
            if (v == 5) mybingoN++;
        }
        for (h = 0; h < 5; h++) {
            for (v = 0; v < 5; v++) {
                if (number[computerbingo[h][v]] != 0) break;
            }
            if (v == 5) computerbingoN++;
        }
        for (h = 0; h < 5; h++) {
            for (v = 0; v < 5; v++) {
                if (number[mybingo[v][h]] != 0) break;
            }
            if (v == 5) mybingoN++;
        }
        for (h = 0; h < 5; h++) {
            for (v = 0; v < 5; v++) {
                if (number[computerbingo[v][h]] != 0) break;
            }
            if (v == 5) computerbingoN++;
        }
        for (h = 0; h < 5; h++)
            if (number[mybingo[h][h]] != 0) break;
        if (h == 5) mybingoN++;
        for (h = 0; h < 5; h++)
            if (number[computerbingo[h][h]] != 0) break;
        if (h == 5) computerbingoN++;
        for (h = 0; h < 5; h++)
            if (number[mybingo[h][4 - h]] != 0) break;
        if (h == 5) mybingoN++;
        for (h = 0; h < 5; h++)
            if (number[computerbingo[h][4 - h]] != 0) break;
        if (h == 5) computerbingoN++;
        printf("mybingo�� ��: %d\ncomputerbingo�� ��: %d\n", mybingoN, computerbingoN);
    } while (mybingoN < 5 && computerbingoN < 5);

    printf("my bingo:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("+----");
        }
        printf("+\n");

        for (int j = 0; j < 5; j++) {
            if (number[mybingo[i][j]] == 0) {
                printf("|(%2d)", mybingo[i][j]);
            }
            else
                printf("|%3d ", mybingo[i][j]);
        }
        printf("|\n");
    }

    for (int j = 0; j < 5; j++) {
        printf("+----");
    }
    printf("+\n");

    //��ǻ�� ���� ���
    printf("computer bingo:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("+----");
        }
        printf("+\n");

        for (int j = 0; j < 5; j++) {
            if (number[computerbingo[i][j]] == 0) {
                printf("|(%2d)", computerbingo[i][j]);
            }
            else
                printf("|----");
        }
        printf("|\n");
    }

    for (int j = 0; j < 5; j++) {
        printf("+----");
    }
    printf("+\n");

    if (mybingoN > computerbingoN)
        printf("�¸��Ͽ����ϴ�!");

    else if (mybingoN < computerbingoN) {
        printf("�й��Ͽ����ϴ� ��.��");
    }
    else
        printf("�����ϴ�");

    return 0;
}