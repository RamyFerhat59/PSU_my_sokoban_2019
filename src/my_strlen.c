/*
** EPITECH PROJECT, 2019
** my_strlen.c
** File description:
** count and returns number of characters 
*/

#include <stdio.h>

int my_strlen(char const *str)
{
    int charcount = 0;
    
    while (str[charcount] != '\n'){
        charcount++;
    }
    return charcount;
}
