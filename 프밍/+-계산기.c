#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int result = 0, num = 0;
    char opp, check;

    printf("숫자를 입력하세요 (ex 1+2-3=) 단, 결과를 출력하려면 =을 마지막에 넣어야합니다.!! : ");

    scanf("%d%c%d", &result, &opp, &num);
    if (opp == '-')
        result -= num;
    else if (opp == '+')
        result += num;

    while (1) {
        scanf(" %c", &check);
        if (check == '=')
            break;
        else if (check == '+') {
            scanf("%d", &num);
            result += num;
        }
        else if (check == '-') {
            scanf("%d", &num);
            result -= num;
        }
    }

    printf("answer is %d", result);
    return 0;
}
