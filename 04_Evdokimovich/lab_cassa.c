//
// Created by Семён Евдокимович on 17.12.2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct Tovar {
    char *name;
    double price;
    double quantity;
};
int lenstring (char *s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;

}
int lenchis(double n) {
    int len = 3;
    while (n > 1.0) {
        n/=10;
        len++;
    }
    if (n > 0.01) {
        return len;
    }else return len+1;
}
typedef struct Tovar Tovar;
Tovar newtovar(char *name, double price, double quantity){
    Tovar tovar;
    tovar.name = name;
    tovar.price = price;
    tovar.quantity = quantity;
    return tovar;
}
Tovar sklad[] = {
    {"banana", 100.0, 10.0},
    {"apple" ,202.0, 2.0},
    {"orange", 30.0,15.0},
    {"water", 40.0 ,100.0}
};
Tovar search(Tovar *tovar) {
    char *name = tovar->name;
    double count = tovar->quantity;
    double pri;
    double quant;
    int i;Tovar res;
    //printf("")
    for (i = 0; i < 4; i++) {
        if (strcmp(name, sklad[i].name) == 0) {
            if (count <= sklad[i].quantity) {
                res = newtovar(name,sklad[i].price * count,count);
            } else {

                res = newtovar(name,sklad[i].price * (sklad[i].quantity),sklad[i].quantity);
            }
            break;
        } else {
            res = newtovar(name,0.0,0.0);

        }
    }
    return res;
}

int main() {
    int kol[10];
    int i = 0, j = 0;
    int n;
    char buf[256]; int count = 0; char c[10][100];
    double summa=0.0;
    Tovar spisok[10000];
    Tovar chek[10000];
    printf("Enter length of the list\n");
    scanf("%d", &n);
    for(i = 0; i<n+1; i++) {
        fgets(buf, 256, stdin);
        if (sscanf(buf, "%d %s", &kol[i], c[i])!=2) {
            sscanf(buf, "%s %d", c[i],&kol[i]);
        }
        spisok[i].name = strdup(c[i]);
        spisok[i].quantity = kol[i];
        for (j=0; j<sizeof(spisok[i].name); j++) {
            spisok[i].name[j] = tolower(spisok[i].name[j]);
        }
        chek[i] = search(&spisok[i]);
    }
    printf("\nName         Price         Quantity\n");
    for(i = 0; i<n+1; i++) {
        if (chek[i].quantity > 0.0) {
            printf("%s", spisok[i].name);
            for (j=0; j<13-lenstring(chek[i].name); j++) {
                printf(".");
            }
            printf("%.2lf", chek[i].price);
            for (j=0; j< 14 - lenchis(chek[i].price); j++) {
                printf(".");
            }
            printf("%.2lf\n", chek[i].quantity);
            summa += chek[i].price;
        }

    }

    printf("Total price - %.2lf",summa);
}

