#include <stdio.h>

#define MAX_DATA 50
#define MAX_SPACE 50

int main()
{
    char space[MAX_SPACE];
    int user_choice, count = 0, i = 0;

    while (count < MAX_SPACE && i < MAX_DATA)
    {
        printf("%d 바이트 남음\n", MAX_SPACE -count);
        printf("> ");
        scanf("%d", &user_choice);

        switch (user_choice)
        {
            case 1:
                if (count + sizeof(char) <= MAX_SPACE)
                {
                    space[count] = 'C';
                    printf("Enter char: ");
                    scanf("%hhd", &space[++count]);
                    count += sizeof(char);
                    i++;

                }
                else
                {
                    printf("Not enough space to store char.\n");
                }
                break;

            case 2:
                if (count + sizeof(short) <= MAX_SPACE)
                {
                    space[count] = 'S';
                    printf("Enter short: ");
                    scanf("%hd", &space[++count]);
                    count += sizeof(short);
                    i++;

                }
                else
                {
                    printf("Not enough space to store short.\n");
                }
                break;

            case 3:
                if (count + sizeof(int) <= MAX_SPACE)
                {
                    space[count] = 'I';
                    printf("Enter int: ");
                    scanf("%d", &space[++count]);
                    count += sizeof(int);
                    i++;

                }
                else
                {
                    printf("Not enough space to store int.\n");
                }
                break;

            case 4:
                if (count + sizeof(long long) <= MAX_SPACE)
                {
                    space[count] = 'LL';
                    printf("Enter long long: ");
                    scanf("%lld", &space[++count]);
                    count += sizeof(long long);
                    i++;

                }
                else
                {
                    printf("Not enough space to store long long.\n");
                }
                break;

            default:
                printf("Invalid choice.\n");
        }

        if (count >= MAX_SPACE)
            break;
    }

    printf("저장공간이 꽉 찼습니다.\n");
    printf("총 데이터 : %d\n", i);

    printf("Data and types stored: \n");
    for (int j = 0; j < count;)
    {
        switch (space[j])
        {
            case 'C':
                printf("%hhdC ", space[j+1]);
                j += sizeof(char) + 1;
                break;

            case 'S':
                printf("%hdS ", *((short*)&space[j+1]));
                j += sizeof(short) + 1;
                break;

            case 'I':
                printf("%dI ", *((int*)&space[j+1]));
                j += sizeof(int) + 1;
                break;

            case 'LL':
                printf("%lldLL ", *((long long*)&space[j+1]));
                j += sizeof(long long) + 1;
                break;

            default:
                break;
        }
    }

    return 0;
}

