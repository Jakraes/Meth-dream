#include "BearLibTerminal.h"
#include "Point.h"
#include "Tile.h"
#include "GameObject.h"

const char *config = "window: title='Meth Wizards', size=60x30; font: ./res/font_10x10.png, size=20x20";

int main() {
    terminal_open();
    terminal_set(config);

    // Printing text
    terminal_print(1, 1, "Hello, world!");
    terminal_refresh();

    // Wait until user close the window
    while (terminal_read() != TK_CLOSE);

    terminal_close();
}