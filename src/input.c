/*
** EPITECH PROJECT, 2019
** m(*pos).y_sokoban.c
** File description:
** m(*pos).y_sokoban.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ncurses.h>
#include "my.h"

void input(char **map, int nblines, struct position *ptr_pos)
{
    int c = 0;
    c = getch();
    ptr_pos = get_pos(map, ptr_pos, nblines);
    switch (c){ 
        case (KEY_UP):
            movement_up(map, ptr_pos);
            break;
        case (KEY_DOWN):
            movement_down(map, ptr_pos);
            break;
        case (KEY_RIGHT):
            movement_right(map, ptr_pos);
            break;
        case (KEY_LEFT):
            movement_left(map, ptr_pos);
            break;
        default:
            refresh();
    }
    refresh();
}

void movement_up(char **map, struct position *pos)
{
    if (map[(*pos).x - 1][(*pos).y] == 'X' && (map[(*pos).x - 2][(*pos).y] != '#' &&
        map[(*pos).x - 2][(*pos).y] != 'O' && map[(*pos).x - 2][(*pos).y] != 'X')){
        map[(*pos).x][(*pos).y] = ' ';
        map[(*pos).x - 1][(*pos).y] = 'P';
        map[(*pos).x - 2][(*pos).y] = 'X';
    }
    else if (map[(*pos).x - 1][(*pos).y] != '#' && map[(*pos).x - 1][(*pos).y] != 'O'
        && map[(*pos).x - 1][(*pos).y] != 'X'){
        map[(*pos).x][(*pos).y] = ' ';
        map[(*pos).x - 1][(*pos).y] = 'P';
    }
    refresh();

}

void movement_down(char **map, struct position *pos)
{
    if (map[(*pos).x + 1][(*pos).y] == 'X' && (map[(*pos).x + 2][(*pos).y] != '#' &&
        map[(*pos).x + 2][(*pos).y] != 'O' && map[(*pos).x + 2][(*pos).y] != 'X')){
        map[(*pos).x][(*pos).y] = ' ';
        map[(*pos).x + 1][(*pos).y] = 'P';
        map[(*pos).x + 2][(*pos).y] = 'X';
    }
    else if (map[(*pos).x + 1][(*pos).y] != '#' && map[(*pos).x + 1][(*pos).y] != 'O'
        && map[(*pos).x + 1][(*pos).y] != 'X'){
        map[(*pos).x][(*pos).y] = ' ';
        map[(*pos).x + 1][(*pos).y] = 'P';
    }
    refresh();
}

void movement_left(char **map, struct position *pos)
{
    if (map[(*pos).x][(*pos).y - 1] == 'X' && (map[(*pos).x][(*pos).y - 2] != '#' &&
        map[(*pos).x][(*pos).y - 2] != 'O' && map[(*pos).x][(*pos).y - 2] != 'X')){
        map[(*pos).x][(*pos).y] = ' ';
        map[(*pos).x][(*pos).y - 1] = 'P';
        map[(*pos).x][(*pos).y - 2] = 'X';
    }
    else if (map[(*pos).x][(*pos).y - 1] != '#' && map[(*pos).x][(*pos).y - 1] != 'O'
        && map[(*pos).x][(*pos).y - 1] != 'X'){
        map[(*pos).x][(*pos).y] = ' ';
        map[(*pos).x][(*pos).y - 1] = 'P';
    }
    refresh();
}

void movement_right(char **map, struct position *pos)
{
    if (map[(*pos).x][(*pos).y + 1] == 'X' && (map[(*pos).x][(*pos).y + 2] != '#' &&
        map[(*pos).x][(*pos).y + 2] != 'O' && map[(*pos).x][(*pos).y + 2] != 'X')){
        map[(*pos).x][(*pos).y] = ' ';
        map[(*pos).x][(*pos).y + 1] = 'P';
        map[(*pos).x][(*pos).y + 2] = 'X';
    }
    else if (map[(*pos).x][(*pos).y + 1] != '#' && map[(*pos).x][(*pos).y + 1] != 'O'
        && map[(*pos).x][(*pos).y + 1] != 'X'){
        map[(*pos).x][(*pos).y] = ' ';
        map[(*pos).x][(*pos).y + 1] = 'P';
    }
    refresh();
}

struct position *get_pos(char **map, struct position *pos, int nblines)
{
    int i = 0;
    int j = 0;

    for (; i < nblines; i++) {   
        j = 0;
        for (; map[i][j] != '\0'; j++) {
            if (map[i][j] == 'P') {
                (*pos).x = i;
                (*pos).y = j;
            }
        }
    }
    return pos;
}
