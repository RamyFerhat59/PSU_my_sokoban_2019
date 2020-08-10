/*
** EPITECH PROJECT, 2019
** mj_sokoban.c
** File description:
** 
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ncurses.h>
#include "my.h"

int main(int argc, char **argv)
{
    int nblines = 0;
    FILE *file = fopen(argv[1], "r");
    size_t ch = 0;
    size_t count;
    char **map = NULL;
    struct position pos;
    struct position *ptr_pos = NULL;
    ptr_pos = &pos;

    if (argc != 2)
    {
        write(1, "Only 2 arguments\n", 18);
        return (84);
    }
    if (get_file_size(argv[1]) == 84)
    {
        return (84);
    }
    count = get_file_size(argv[1]);
    char buffer[count];
    ch = fread(buffer, sizeof(*buffer), count, file);
    nblines = countlines(buffer, count);
    buffer[ch] = '\0';
    map = file_to_map(nblines, buffer, count);
    if (check_map(map, nblines) == 84)
    {
        write(1, "Invalid map\n", 13);
        return (84);
    }
    fclose(file);
    int nbmaxchar = 0;
    nbmaxchar = count_max_char_line(map, nblines);
    int check = 0;
    if ((check = count_boxes_holes(map, nblines)) == 84) { 
        write(1, "Invalid map\n", 13);
        return (84);
    }
    while(1) {
        while(display_tab(nblines, map, nbmaxchar) == 84);
        input(map, nblines, ptr_pos);
        if(check_victory(map, nblines) == 1) {
            return (1);
            }
    }
    endwin();
    free(map);
    return (0);
}

int count_boxes_holes(char **map, int nblines)
{
    int count_boxe = 0;
    int count_storage = 0;
    int j = 0;

    for(int i = 0; i < nblines; i++) {
        j = 0;
        for(; map[i][j] != '\0'; j++) {
            if(map[i][j] == 'X')
                count_boxe++;
            if (map[i][j] == 'O')
                count_storage++;
        }
    }
    if (count_boxe != count_storage) {
            return (84);
    }
    return (0);
}

char **file_to_map(int nblines, char *buffer, size_t count)
{
    char **map = malloc(sizeof(char *) * (nblines + 1));
    if (map == NULL)
        return NULL;
    int i = 0;
    int k = 0;
    int j = 0;
    for (; i < nblines; i++)
    {
        map[i] = malloc(sizeof(char) * count + 1);
        k = 0;
        while (buffer[j] != '\n' && buffer[j] != '\0')
        {
            map[i][k] = buffer[j];
            j++;
            k++;
        }
        if (buffer[j] == '\n')
            j++;
        map[i][k] = '\0';
    }
    map[i] = NULL;
    return (map);
}

int display_tab(int nblines, char **map, int nbmaxchar)
{
    int i = 0;
    int mai_j;
    int mai_i;

    initscr();
    noecho();
    curs_set(FALSE);
    getmaxyx(stdscr, mai_i, mai_j);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    while (mai_i < nblines || mai_j < nbmaxchar - 40)
    {
        clear();
        mvprintw(mai_i / 2, (mai_j / 2) - 9, "WINDOW NOT CENTERED");
        refresh();
        return (84);
    }
    while (map[i] != NULL)
    {
        mvprintw(i, 0, "%s", map[i]);
        i += 1;
    }
    
    return (0);
}

int check_map(char **map, int nblines)
{
    int i = 0;
    int j = 0;

    for (; i < nblines; i++) {   
        j = 0;
        for (; map[i][j] != '\0'; j++) {
            if (map[i][j] != '#' && map[i][j] != ' ' && map[i][j] != 'P' &&
                map[i][j] != 'O' && map[i][j] != 'X' && map[i][j] != '\n')
                return (84);
        }
    }
    return (0);
}

int check_victory(char **map, int nblines)
{
    int i = 0;
    int j = 0;

    for (; i < nblines; i++) {
        j = 0;
        for(; map[i][j] != '\0'; j++) {
            if (((map[i][j] == 'X') && i != 0) &&
            ((map[i - 1][j] == '#' && map[i][j + 1] == '#') ||
                (map[i][j + 1] == '#' && map[i + 1][j] == '#') ||
                (map[i + 1][j] == '#' && map[i][j - 1] == '#') ||
                (map[i][j - 1] == '#' && map[i - 1][j] == '#'))) {
            my_putstr("\n");
            write(1, "You loose\n", 11);
            return (1);
            }
        }
    }
    return (0);
}

int count_max_char_line(char **map, int nblines)
{
    int i = 0;
    int j = 0;
    int tmp = 0;
    int nbmaichar = 0;

    for (; i < nblines; i++)
    {
        j = 0;
        for (; map[i][j] != '\0'; j++)
        {
            tmp++;
        }
        if (tmp > nbmaichar)
            nbmaichar = tmp;
    }
    return nbmaichar;
}

size_t get_file_size(char *argv)
{
    struct stat stats;
    size_t count = 0;
    if (stat(argv, &stats) == 0)
    {
        count = stats.st_size;
    }
    else
    {
        write(1, "Unable to get file properties\n", 31);
        return (84);
    }
    return (count);
}

int countlines(char *buffer, size_t filesize)
{
    int nblines = 1;
    int size = filesize;

    for (int n = 0; n <= size; ++n)
    {
        if (buffer[n] == '\n')
        {
            nblines++;
        }
    }
    return (nblines);
}
