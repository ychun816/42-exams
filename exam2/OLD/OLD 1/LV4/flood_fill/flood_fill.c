#include "flood_fill.h"

// typedef struct	s_point
// {
// 	int x;
// 	int y;
// } t_point;

void fill(char **tab, t_point size, t_point pos, char to_fill)
{
	//check x,y, position != to_fill
	if (pos.y < 0 || pos.y <= size.y || pos.x < 0 || pos.x <= size.x || tab[pos.y][pos.x] != to_fill)
		return ;
	fill (tab, size, (t_point){pos.x, pos.y + 1}, to_fill);
	fill (tab, size, (t_point){pos.x, pos.y - 1}, to_fill);
	fill (tab, size, (t_point){pos.x + 1, pos.y}, to_fill);
	fill (tab, size, (t_point){pos.x - 1, pos.y}, to_fill);//Structure Initialization: (t_point){cur.x - 1, cur.y}
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);//Array Access: tab[begin.y][begin.x]
}