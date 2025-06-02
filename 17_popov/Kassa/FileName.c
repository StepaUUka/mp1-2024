#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "locale.h"

struct Product
{
    char* name;
    double price;
    double quantity;
};

typedef struct Product Product;

Product create_product(char* name, double price, double quantity)
{
    Product product;
    product.name = name;
    product.price = price;
    product.quantity = quantity;
    return product;
}

Product inventory[] =
{
    {"банан", 200.0, 10.0},
    {"яблоко", 202.0, 2.0},
    {"апельсин", 30.0, 15.0},
    {"картошка", 40.0, 100.0}
};

int string_length(char* s)
{
    int length = 0;
    while (s[length] != '\0')
    {
        length++;
    }
    return length;
}

int number_length(double n)
{
    int length = 3;
    while (n > 1.0)
    {
        n /= 10;
        length++;
    }
    if (n > 0.01)
    {
        return length;
    }
    else
    {
        return length + 1;
    }
}

Product find_product(Product* product)
{
    char* name = product->name;
    double quantity = product->quantity;
    Product result;
    for (int i = 0; i < 4; i++)
    {
        if (strcmp(name, inventory[i].name) == 0)
        {
            if (quantity <= inventory[i].quantity)
            {
                result = create_product(name, inventory[i].price * quantity, quantity);
            }
            else
            {
                result = create_product(name, inventory[i].price * inventory[i].quantity, inventory[i].quantity);
            }
            return result;
        }
    }

    return create_product(name, 0.0, 0.0);
}

// Функция для вывода информации о товаре и общей стоимости
void print_invoice(Product* products, Product* receipt, int count, double total)
{
    printf("\nНазвание товара\tЦена\tКоличество\n");
    for (int i = 0; i < count; i++) {
        if (receipt[i].quantity > 0.0) {
            printf("%s", receipt[i].name);
            for (int j = 0; j < 13 - string_length(receipt[i].name); j++)
            {
                printf(".");
            }
            printf("%.2lf", receipt[i].price);
            for (int j = 0; j < 14 - number_length(receipt[i].price); j++)
            {
                printf(".");
            }
            printf("%.2lf\n", receipt[i].quantity);
        }
        else {
            printf("Товар %s не найден.\n", products[i].name);
        }
    }
    printf("\nОбщая стоимость - %.2lf\n", total);
}
int main()
{
    system("chcp 1251");

    setlocale(LC_ALL, "Russian");

    int n;
    char buffer[256];
    double total = 0.0;

    printf("Введите количество товаров, которые хотите купить:\n");
    scanf_s("%d", &n);
    getchar();

    Product products_list[100];
    Product receipt_list[100];
    int receipt_count = 0;

    for (int i = 0; i < n; i++)
    {
        printf("Введите товар %d:\n", i + 1);
        fgets(buffer, sizeof(buffer), stdin);

        int product_quantity;
        char product_name[100];

        if (sscanf_s(buffer, "%d %99[^\n]", &product_quantity, product_name, (unsigned)_countof(product_name)) == 2)
        {


            for (int v = 0; product_name[v]; v++)
            {
                product_name[v] = tolower(product_name[v]);
            }

            // Проверяем, есть ли товар уже в чеке
            int found = 0;
            for (int j = 0; j < receipt_count; j++)
            {
                if (strcmp(receipt_list[j].name, product_name) == 0)
                {
                    receipt_list[j].quantity += product_quantity;
                    receipt_list[j] = find_product(&receipt_list[j]);
                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                products_list[receipt_count].name = (char*)malloc(strlen(product_name) + 1);
                strcpy_s(products_list[receipt_count].name, strlen(product_name) + 1, product_name);
                products_list[receipt_count].quantity = product_quantity;

                receipt_list[receipt_count] = find_product(&products_list[receipt_count]);
                receipt_count++;

            }
        }
        else
        {
                printf("Ошибка ввода. Попробуйте снова.\n");
                i--;
        }
        
    }

    total = 0.0;
    for (int i = 0; i < receipt_count; i++) 
    {
        total += receipt_list[i].price;
    }


    print_invoice(products_list, receipt_list, receipt_count, total);


    for (int i = 0; i < receipt_count; i++) 
    {
        free(products_list[i].name);
    }

    return 0;
}
