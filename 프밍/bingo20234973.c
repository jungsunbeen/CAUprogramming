#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
    // 시드를 초기화하여 무작위 숫자를 생성
    srand(time(NULL));

    int mybingo[5][5], computerbingo[5][5];  // 5x5 빙고판 배열
    int number[25];// 1부터 25까지의 숫자 배열
    int mybingoN = 0, computerbingoN = 0;
    void cheakbingo(int mybingo[5][5], int mybingoN);

    // 1부터 25까지의 숫자로 배열 초기화
    for (int i = 0; i < 25; i++){
        number[i] = i + 1;
    }

    // 숫자 섞기 (Fisher-Yates 셔플 알고리즘 사용)
    for (int i = 24; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = number[i];
        number[i] = number[j];
        number[j] = temp;
    }

    // 숫자를 빙고판에 배치
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            mybingo[i][j] = number[i * 5 + j];
        }
    }

    //내 빙고 출력
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

    // 숫자 섞기 (Fisher-Yates 셔플 알고리즘 사용)
    for (int i = 24; i > 0; i--){
        int j = rand() % (i + 1);
        int temp = number[i];
        number[i] = number[j];
        number[j] = temp;
    }

    // 숫자를 빙고판에 배치
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            computerbingo[i][j] = number[i * 5 + j];
        }
    }

    //컴퓨터 빙고 출력
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

    //내 차례
    do {
        while (count % 2 == 1) {
            printf("1부터 25사이의 숫자를 입력하세요 :");
            scanf("%d", &num);
            if (num >= 1 && num <= 25) {
                if (number[num] != 0) {
                    number[num] = 0;
                    count++;
                    break;
                }
                else if (number[num] == 0)
                    printf("이미 입력한 숫자입니다. 다른 숫자를 입력하세요 : ");
            }
            else
                printf("1~25 숫자를 입력하세요 : ");
        }

        //컴퓨터 차례
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
        printf("컴퓨터는 %d를 선택하였습니다.\n", num);

        //내 빙고 출력
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

        //컴퓨터 빙고 출력
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

        // 빙고 검사
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
        printf("mybingo의 수: %d\ncomputerbingo의 수: %d\n", mybingoN, computerbingoN);
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

    //컴퓨터 빙고 출력
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
        printf("승리하였습니다!");

    else if (mybingoN < computerbingoN) {
        printf("패배하였습니다 ㅠ.ㅠ");
    }
    else
        printf("비겼습니다");

    return 0;
}