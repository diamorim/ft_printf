#include "test.h"

char *random_string(int length)
{
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int charset_size = sizeof(charset) - 1;
    

    char *str = malloc(sizeof(char) * (length + 1));

    if (!str)
        return NULL;

    for (int i = 0; i < length; i++)
    {
        str[i] = charset[rand() % charset_size];
    }

    str[length] = '\0';

    return str;
}