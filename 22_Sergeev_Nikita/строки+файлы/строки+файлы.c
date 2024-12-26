#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>

#pragma warning(disable : 4996)

// ��������� ��� �������� ���������� � ������
struct Item {
    char name[100];       // �������� ������
    double price;         // ���� �� ��
    double quantity;      // ���������� �� ������ ��� � ����
};

// ������ ������� �� ������
struct Item inventory[] = {
    {"tomato", 820.0, 43.0},
    {"milk", 530.0, 101.0},
    {"cheese", 2250.0, 31.0},
    {"raxat-lukum", 31000.0, 29.0},
    {"bread", 220.0, 52.0},
    {"egg", 1030.0, 2.0}
};

// ������ ��� �������� �������, ��������� �����������
struct Item basket[100];

// ������� ��� �������� ������ � ������ �������
void toLowerCase(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// ������� ��� ������ ������ � ������� �� ������
int findItemByName(const char* itemName) {
    for (int i = 0; i < sizeof(inventory) / sizeof(inventory[0]); i++) {
        int j = 0;
        // ���������� ������ ��� ����� ��������
        while (inventory[i].name[j] != '\0' && itemName[j] != '\0') {
            if (tolower((unsigned char)inventory[i].name[j]) != tolower((unsigned char)itemName[j])) {
                break;
            }
            j++;
        }
        // ���� ������ �������
        if (inventory[i].name[j] == '\0' && itemName[j] == '\0') {
            return i;  // ����� ������
        }
    }
    return -1;  // ����� �� ������
}

int main() {
    int numberOfItems = 0;  // ���������� ��������� �������
    char userInput[100];    // ������ ��� ����� ������������
    char* token;
    char delimiter[] = " ";  // ����������� ��� �����
    char inputLines[100][100];  // ������ ��� �������� ����� � ��������
    char tokens[100][100];  // ������ ��� �������� ������� (����)

    setlocale(LC_ALL, "Russian");

    // ���� ������ �������
    printf("������� ������ �������, ����� ���������, ������� ������ ������:\n");
    while (1) {
        fgets(userInput, sizeof(userInput), stdin);
        userInput[strcspn(userInput, "\n")] = '\0';  // ������� ������ ����� ������
        if (strlen(userInput) == 0) break;  // ��������� ���� ��� ������ ������
        strcpy(inputLines[numberOfItems], userInput);
        numberOfItems++;
    }

    // ��������� ������ �� ��������� ������ (�����)
    int tokenCount = 0;
    for (int i = 0; i < numberOfItems; i++) {
        token = strtok(inputLines[i], delimiter);
        while (token != NULL) {
            strcpy(tokens[tokenCount], token);
            token = strtok(NULL, delimiter);
            tokenCount++;
        }
    }

    // ��������� ������ ������� � ������� (basket) �� ������ ��������� ������
    int basketIndex = 0;
    for (int t = 0; t < tokenCount; t++) {
        double quantity = 1.0;  // ����������� ���������� � 1
        if (sscanf(tokens[t], "%lf", &quantity)) {  // ���� ����� � ��� �����
            basket[basketIndex].quantity = quantity;
            strcpy(basket[basketIndex].name, tokens[t + 1]);
            t++;  // ��������� � ���������� ������
        }
        else {
            basket[basketIndex].quantity = atof(tokens[t + 1]);
            strcpy(basket[basketIndex].name, tokens[t]);
            t++;  // ��������� � ���������� ������
        }
        basketIndex++;
    }

    // ����� ���� � ������� ����� ������� � ��� ����������
    printf("���:\n");
    double totalSum = 0.0;
    for (int i = 0; i < basketIndex; i++) {
        char lowerName[100];
        strcpy(lowerName, basket[i].name);
        toLowerCase(lowerName);

        int inventoryIndex = findItemByName(lowerName);
        if (inventoryIndex != -1) {
            double totalPrice = basket[i].quantity * inventory[inventoryIndex].price;
            totalSum += totalPrice;
            
            printf("%-20s.... %.1lf * %.2lf.... %.2lf\n", basket[i].name, basket[i].quantity, inventory[inventoryIndex].price, totalPrice);
        }
        else {
            printf("%-20s.... �� ������\n", basket[i].name);
        }
    }

    // ����� ����� �����
    printf("�����.................... %.2lf\n", totalSum);

    return 0;
}
