#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

struct Location {
    const char* name;
    int owner;
    int purchasePrice;
    int tollFee;
};

struct Player {
    int money;
    int dice;
    int position;
} Player1, Player2;

void DisplayBoard(struct Location locations[10]) {
    printf("---------------------------------------\n");
    printf("ΓΑΑΑΑΑΑΑΑΑΑΑΔ\tΓΑΑΑΑΑΑΑΑΑΑΑΔ\tΓΑΑΑΑΑΑΑΑΑΑΑΑΔ\tΓΑΑΑΑΑΑΑΑΑΑΑΔ\tΓΑΑΑΑΑΑΑΑΑΑΑΔ\n");
    printf("Β   %s   Β\tΒ   %s  Β\tΒ  %s  Β\tΒ   %s   Β\tΒ   %s   Β\n",
        locations[5].name, locations[6].name, locations[7].name, locations[8].name, locations[9].name);
    printf("Β    (%d)    Β\tΒ    (%d)    Β\tΒ    (%d)     Β\tΒ    (%d)    Β\tΒ    (%d)    Β\n",
        locations[5].owner, locations[6].owner, locations[7].owner, locations[8].owner, locations[9].owner);
    printf("ΖΑΑΑΑΑΑΑΑΑΑΑΕ\tΖΑΑΑΑΑΑΑΑΑΑΑΕ\tΖΑΑΑΑΑΑΑΑΑΑΑΑΕ\tΖΑΑΑΑΑΑΑΑΑΑΑΕ\tΖΑΑΑΑΑΑΑΑΑΑΑΕ\n");
    printf("     /\\  \t\t\t\t\t\t\t     び    \n");
    printf("     び   \t\t\t\t\t\t\t     び    \n");
    printf("     び   \t\t\t\t\t\t\t     \\/    \n");
    printf("ΓΑΑΑΑΑΑΑΑΑΑΑΔ\tΓΑΑΑΑΑΑΑΑΑΑΑΔ\tΓΑΑΑΑΑΑΑΑΑΑΑΑΔ\tΓΑΑΑΑΑΑΑΑΑΑΑΔ\tΓΑΑΑΑΑΑΑΑΑΑΑΔ\n");
    printf("Β     %s    Β\tΒ   %s  Β\tΒ    %s   Β\tΒ   %s   Β\tΒ   %s   Β\n",
        locations[4].name, locations[3].name, locations[2].name, locations[1].name, locations[0].name);
    printf("Β    (%d)    Β\tΒ    (%d)    Β\tΒ    (%d)     Β\tΒ    (%d)    Β\tΒ    (%d)    Β\n",
        locations[4].owner, locations[3].owner, locations[2].owner, locations[1].owner, locations[0].owner);
    printf("ΖΑΑΑΑΑΑΑΑΑΑΑΕ\tΖΑΑΑΑΑΑΑΑΑΑΑΕ\tΖΑΑΑΑΑΑΑΑΑΑΑΑΕ\tΖΑΑΑΑΑΑΑΑΑΑΑΕ\tΖΑΑΑΑΑΑΑΑΑΑΑΕ\n\n");
}

int main() {
    srand(time(NULL));
    struct Location locations[10] = {
        {"START", 0, 0, 0},
        {"SEOUL", 0, 300, 600},
        {"TOKYO", 0, 300, 600},
        {"SYDNEY", 0, 300, 600},
        {"LA", 0, 300, 600},
        {"CAIRO", 0, 300, 600},
        {"PHUKET", 0, 300, 600},
        {"NEWDELHI", 0, 300, 600},
        {"HANOI", 0, 300, 600},
        {"PARIS", 0, 300, 600},
    };

    int turn = 0;
    int gameOver = 0;
    Player1.money = 5000;
    Player1.position = 0;
    Player2.money = 5000;
    Player2.position = 0;

    while (!gameOver) {
        printf("けけけけけけけ Turn: %d けけけけけけけ\n", turn + 1);
        printf("---------------------------------------\n");
        printf("Player 1税 爽紫是 : %d\n", Player1.dice);
        Player1.dice = rand() % 6 + 1;
        Player1.position = (Player1.position + Player1.dice) % 10;

        if (Player1.position == 0) {
            printf("%s (0)\n", locations[Player1.position].name);
            printf("窒降走 亀鐸\n");
        }
        else {
            if (locations[Player1.position].owner == 0) {
                printf("%s (爽昔蒸製)\n", locations[Player1.position].name);
                if (Player1.money > 300) {
                    printf("Player 1戚 %s 姥古\n", locations[Player1.position].name);
                    locations[Player1.position].owner = 1;
                    Player1.money -= locations[Player1.position].purchasePrice;
                }
                else {
                    printf("接壱 採膳生稽 姥古災亜管 %s\n", locations[Player1.position].name);
                }
            }
            else if (locations[Player1.position].owner == 1) {
                printf("%s (1)\n", locations[Player1.position].name);
                printf("Player 1税 競, 覗軒鳶什~\n");
            }
            else if (locations[Player1.position].owner == 2) {
                printf("%s (2)\n", locations[Player1.position].name);
                printf("Player 2税 競, 搭楳戟 600 走災\n");
                Player1.money -= locations[Player1.position].tollFee;
                if (Player1.money < 0) {
                    gameOver = 1;
                    break;
                }
                Player2.money += locations[Player1.position].tollFee;
            }
            if (gameOver == 1) {
                break;
            }
        }
        printf("Player 1税 接壱 : %d\n", Player1.money);
        printf("---------------------------------------\n");

        Player2.dice = rand() % 6 + 1;
        Player2.position = (Player2.position + Player2.dice) % 10;
        printf("Player 2税 爽紫是 : %d\n", Player2.dice);
        if (Player2.position == 0) {
            printf("%s \n", locations[Player2.position].name);
            printf("窒降走 亀鐸\n");
        }
        else {
            if (locations[Player2.position].owner == 0) {
                printf("%s (爽昔蒸製)\n", locations[Player2.position].name);
                if (Player2.money > 300) {
                    printf("Player 2 %s 姥古\n", locations[Player2.position].name);
                    locations[Player2.position].owner = 2;
                    Player2.money -= locations[Player2.position].purchasePrice;
                }
                else {
                    printf("接壱採膳生稽 姥古災亜管 %s\n", locations[Player2.position].name);
                }
            }
            else if (locations[Player2.position].owner == 1) {
                printf("%s (1)\n", locations[Player2.position].name);
                printf("Player 1税 競, 搭楳戟 600走災\n");
                Player2.money -= locations[Player2.position].tollFee;
                if (Player2.money < 0) {
                    gameOver = 1;
                    break;
                }
                Player1.money += locations[Player2.position].tollFee;
            }
            else if (locations[Player2.position].owner == 2) {
                printf("%s (2)\n", locations[Player2.position].name);
                printf("Player 2税 競, 覗軒鳶什~ \n");
            }
            if (gameOver == 1) {
                break;
            }
        }
        printf("Player 2税 接壱 : %d\n", Player1.money);
        DisplayBoard(locations);
        Sleep(2500);
        printf("\n---------------------------------------\n");

        turn++;

        if (turn == 30) {
            gameOver = 1;
        }
    }

    if (Player1.money > Player2.money) {
        printf("------------------------------\n");
        printf("Player 1 接壱 : %d\n", Player1.money);
        printf("Player 2 接壱 : %d\n", Player2.money);
        printf("Player 1 渋軒! \n");
        printf("------------------------------\n");
    }
    else if (Player2.money > Player1.money) {
        printf("------------------------------\n");
        printf("Player 1 接壱 : %d\n", Player1.money);
        printf("Player 2 接壱 : %d\n", Player2.money);
        printf("Player 2 渋軒!\n");
        printf("------------------------------\n");
    }
    else {
        printf("------------------------------\n");
        printf("Player 1 接壱 : %d\n", Player1.money);
        printf("Player 2 接壱 : %d\n", Player2.money);
        printf("巷渋採! \n");
        printf("------------------------------\n");
    }

    return 0;
}
