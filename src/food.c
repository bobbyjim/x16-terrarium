#include <stdlib.h>
#include <conio.h>

#include "map.h"
#include "food.h"

void food_generate() {
	unsigned char x = 1 + rand() % (MAP_COLS-1),
				  y = 1 + rand() % (MAP_ROWS-1);

	if (map_get_cell(MAP_PLANTS, x, y) == ' ') { // empty cell
		map_set_cell(MAP_PLANTS, x, y, SYM_PLANT);
		textcolor(COLOR_GREEN);
		map_display(x, y, SYM_PLANT);
	}
}
