#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

struct Date {
    int year, month, day;
};

struct Book {
    int num_book;
    char title[100];
    char author[100];
    char publisher[100];
    char borrower[100];
    int borrowed; // Use int to represent boolean (0 or 1)
    struct Date loanDate;
    struct Date returnDate;
};

struct borrowedhistory {
    char title[100];
    char borrower[100];
    struct Date historyDate;
};

struct Book book_name[100] = {
    {0, "공백", "공백", "공백","", 0, {0, 0, 0}, {0, 0, 0}}, // Initialize with 0 for non-boolean values
    {1, "햄릿", "셰익스피어", "민음사","", 0, {0, 0, 0}, {0, 0, 0}},
    {2, "인간실격", "다자이 오사무", "민음사","", 0, {0, 0, 0}, {0, 0, 0}},
    {3, "삼각유사", "일연", "민음사","", 0, {0, 0, 0}, {0, 0, 0}},
    {4, "노르웨이 숲", "무라카미 하루키","민음사","", 0, {0, 0, 0}, {0, 0, 0}},
    {5, "노인과 바다", "어니스트 헤밍웨이", "민음사","", 0, {0, 0, 0}, {0, 0, 0}}
};

struct borrowedhistory borrowedhistory[100];
int times = 0;

// 함수 프로토타입 선언
struct Date addOneWeek(struct Date inputDate);

int main() {
    int user_choice;
    int num_book = 0;
    struct Date inputDate = { 2023, 4, 11 };

    while (1) {
        printf("도서 관리 프로그램 \n");
        printf("----------------------\n");
        printf("메뉴를 선택하세요 \n");
        printf("1. 책 목록 보기 \n");
        printf("2. 대출반납내역 보기 \n");
        printf("3. 책을 빌리기 \n");
        printf("4. 책을 반납하기 \n");
        printf("5. 프로그램 종료 \n");

        printf("당신의 선택은 : ");
        scanf("%d", &user_choice);
        printf("----------------------\n");

        if (user_choice == 1) {
            printf("현재 책 목록 \n");
            for (int i = 1; i < 6; i++) {
                if (book_name[i].borrowed == 1) {
                    printf("%d. %-20s %-20s %-10s 대출일: %d-%02d-%02d (대출중)\n",
                        book_name[i].num_book, book_name[i].title, book_name[i].author, book_name[i].publisher,
                        book_name[i].loanDate.year, book_name[i].loanDate.month, book_name[i].loanDate.day);
                }
                else {
                    printf("%d. %-20s %-20s %-10s 대출일: %d-%02d-%02d 반납일: %d-%02d-%02d \n",
                        book_name[i].num_book, book_name[i].title, book_name[i].author, book_name[i].publisher,
                        book_name[i].loanDate.year, book_name[i].loanDate.month, book_name[i].loanDate.day,
                        book_name[i].returnDate.year, book_name[i].returnDate.month, book_name[i].returnDate.day);
                }
            }
            printf("----------------------\n");
        }
        else if (user_choice == 2) {
            printf("대출반납 내역 (사람 이름이 뜨면 대출, 안 뜨면 반납 내역입니다!) \n");
            if (times == 0) {
                printf("대출 반납 이력이 없습니다.\n\n");
            }
            
            else if (times != 0) {
                for (int i = 1; i <= times; i++) {
                    printf("%d. %-10s %-10s %d %d %d\n", i, borrowedhistory[i].title, borrowedhistory[i].borrower,
                       borrowedhistory[i].historyDate.year, borrowedhistory[i].historyDate.month, borrowedhistory[i].historyDate.day);
                    
                }
            }
            printf("----------------------\n");
        }
        else if (user_choice == 3) {
            printf("빌릴 책의 번호를 말해주세요 \n");
            printf("책 번호 : ");
            scanf("%d", &num_book);

            if (num_book < 1 || num_book > 5) {
                printf("올바르지 않은 책 번호입니다.\n");
            }
            else if (book_name[num_book].borrowed == 1) {
                printf("이미 대출된 책입니다! \n");
            }
            else {
                times++;
                strcpy(borrowedhistory[times].title, book_name[num_book].title);
                printf("대출할 사람의 이름을 쓰시오 : ");
                scanf("%s", borrowedhistory[times].borrower);
                printf("대출할 날짜를 쓰시오.(예시:2023 12 25)\n");
                scanf("%d %d %d", &inputDate.year, &inputDate.month, &inputDate.day);
                struct Date resultDate = addOneWeek(inputDate);
                printf("\n성공적으로 대출되었습니다.\n대출일 %d-%02d-%02d\n", inputDate.year, inputDate.month, inputDate.day);
                printf("반납일 %d-%02d-%02d\n", resultDate.year, resultDate.month, resultDate.day);
                book_name[num_book].borrowed = 1;
                book_name[num_book].loanDate = inputDate;  // 대출일 저장
                borrowedhistory[times].historyDate = inputDate; // 히스토리에 날짜 저장
            }
            printf("----------------------\n");
        }
        else if (user_choice == 4) {
            printf("반납할 책의 번호를 써주세요 \n");
            printf("책 번호 : ");
            scanf("%d", &num_book);

            if (num_book < 1 || num_book > 5) {
                printf("올바르지 않은 책 번호입니다.\n");
            }
            else if (book_name[num_book].borrowed == 0) {
                printf("이미 반납되어 있는 상태입니다\n");
            }
            else {
                times++;
                strcpy(borrowedhistory[times].title, book_name[num_book].title);
                strcpy(borrowedhistory[times].borrower, "반납완료");
                printf("반납할 날짜를 써주세요 (예시 : 2023 12 25) \n");
                scanf("%d %d %d", &inputDate.year, &inputDate.month, &inputDate.day);
                book_name[num_book].borrowed = 0;
                book_name[num_book].returnDate = inputDate;
                borrowedhistory[times].historyDate = inputDate;
                printf("성공적으로 반납되었습니다\n");
            }
            printf("----------------------\n");
        }
        else {
            break;
        }
    }

    return 0;
}

// 일주일 뒤의 날짜 계산 함수
struct Date addOneWeek(struct Date inputDate) {
    struct tm timeStruct = { 0 };

    // 구조체 필드를 tm 구조체에 설정
    timeStruct.tm_year = inputDate.year - 1900; // 년도에서 1900을 빼야 함
    timeStruct.tm_mon = inputDate.month - 1;   // 월은 0부터 시작
    timeStruct.tm_mday = inputDate.day;

    // 입력된 날짜에 7일을 더함
    time_t timeInSeconds = mktime(&timeStruct);
    timeInSeconds += 7 * 24 * 60 * 60; // 7일의 초 단위

    // 결과를 tm 구조체에서 읽어옴
    struct tm* resultStruct = localtime(&timeInSeconds);

    // 결과 구조체를 반환
    struct Date resultDate;
    resultDate.year = resultStruct->tm_year + 1900; // 1900을 더해야 함
    resultDate.month = resultStruct->tm_mon + 1;     // 월은 0부터 시작하므로 1을 더해야 함
    resultDate.day = resultStruct->tm_mday;

    return resultDate;
}