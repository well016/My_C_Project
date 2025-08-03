#include <stdio.h>
#include <string.h>

void replace(char * dst, const char * src)
{
    size_t lenbomb = strlen("bomb");
    size_t lenwater = strlen("watermelon");


    char * s;   // src: указатель на начало подстроки, где ищем bomb
    char * p;   // src: b
    char * d;   // ddfdsfdsfds


    // сначал
    s = (char *)src;            // 
    p = NULL;                   // про бомбу ничего не известно
    d = dst;                    // еще ничего не скопировалиd asdas





    // ищем бомбу начиная с адреса s
    p = strstr(s, "bomb");      // p указыва


    // обезвредим бомбу
     while ((p = strstr(s, "bomb")) != NULL) {            // бомба есть
        size_t n = p - s;       // количество символов перед бомбой
        strncpy(d, s, n);       // скопируем символы перед бомбой в dst
        d = d + n;              // передвинем d в конце строки
        strcpy(d, "watermelon");// допишем в конец строки арбуз
        d = d + lenwater;       // передвинем конец строки за арбуз


        s = p + lenbomb;        // указатель на остаток строки поставим за бомбой
    }


    // оставшаяся строка
    strcpy(d, s);
}

int main()
{
    char d[1000];
    char out[1000];
    while (fgets(d, sizeof(d), stdin) != NULL) {
        // Удаляем символ новой строки в конце, если он есть
        size_t len = strlen(d);
        if (len > 0 && d[len-1] == '\n') {
            d[len-1] = '\0';
        }
        replace(out, d);
        printf("%s\n", out);
    }
    return 0;
}   
