#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SENTENCE_COUNT 5
#define MIN_WORD_LENGTH 4
#define MAX_WORD_LENGTH 10
#define MIN_SENTENCE_LENGTH 40
#define MAX_SENTENCE_LENGTH 50

// ������ ���� �빮�� ���� �Լ�
char generateRandomChar() {
    return 'A' + rand() % 26;
}

// ������ �ܾ� ���� �Լ�
void generateRandomWord(char* word, int minLength, int maxLength) {
    int length = minLength + rand() % (maxLength - minLength + 1);
    for (int i = 0; i < length; ++i) {
        word[i] = generateRandomChar();
    }
    word[length] = '\0';
}

// ������ ���� ���� �Լ�
void generateRandomSentence(char* sentence) {
    int wordCount = rand() % (MAX_SENTENCE_LENGTH / MAX_WORD_LENGTH - MIN_SENTENCE_LENGTH / MIN_WORD_LENGTH + 1) + MIN_SENTENCE_LENGTH / MIN_WORD_LENGTH;
    sentence[0] = '\0';

    for (int i = 0; i < wordCount; ++i) {
        char word[MAX_WORD_LENGTH + 1];
        generateRandomWord(word, MIN_WORD_LENGTH, MAX_WORD_LENGTH);

        strcat(sentence, word);
        if (i < wordCount - 1) {
            strcat(sentence, " ");
        }
    }
}

// ����� �Է°� �ӵ� ��� �Լ�
int calculateTypingSpeed(const char* sentence, const char* userInput, double elapsedTime) {
    int correctChars = 0;
    int sentenceLength = strlen(sentence);

    for (int i = 0; i < sentenceLength; ++i) {
        if (sentence[i] == userInput[i]) {
            correctChars++;
        }
    }

    int typingSpeed = (int)((correctChars / elapsedTime) * 60); // �д� �Է� �� ���
    return typingSpeed;
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < SENTENCE_COUNT; ++i) {
        char sentence[MAX_SENTENCE_LENGTH + 1];
        generateRandomSentence(sentence);

        printf("���� %d: %s\n", i + 1, sentence);

        char userInput[MAX_SENTENCE_LENGTH + 1];
        printf("�Է��ϼ���: ");

        clock_t startTime = clock();

        fgets(userInput, sizeof(userInput), stdin);

        clock_t endTime = clock();
        double elapsedTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;

        int typingSpeed = calculateTypingSpeed(sentence, userInput, elapsedTime);

        printf("�Է� �ӵ�: %d Ÿ/��\n", typingSpeed);
    }

    return 0;
}
