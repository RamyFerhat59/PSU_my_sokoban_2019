#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ncurses.h>

struct position {
    int x;
    int y;
};

struct map_infos{
    int count_boxes;
    int count_holes;
};

int countlines(char *buffer, size_t filesize);
size_t get_file_size(char *argv);
char **file_to_map(int nblines, char *buffer, size_t count);
int display_tab(int nblines, char **tab, int nbmaxchar);
void print_map(char **map, int nblines);
int count_max_char_line(char **map, int nblines);
void my_putchar(char c);
int check_map(char **map, int nblines);
struct position *get_pos(char **map, struct position *pos, int nblines);
void movement_right(char **map, struct position *pos);
void movement_left(char **map, struct position *pos);
void movement_down(char **map, struct position *pos);
void movement_up(char **map, struct position *pos);
void input(char **map, int nblines, struct position *pos);
int count_boxes_holes(char **map, int nblines);
int check_victory(char **map, int nblines);

#endif /* !MY_H_ */
