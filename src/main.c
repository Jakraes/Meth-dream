#include "window.h"
#include "gamemap.h"
#include "gamemap_entity.h"

int main() {
    GameMap* map = gamemap_new(10, 10, GAMEMAP_TEST);
    gamemap_generate(map);
    
    window_open();

    window_draw(map);

    window_refresh();

    while (window_key != TK_CLOSE) {
        window_get_input();

        gamemap_move_all(map);

        window_clear();

        window_draw(map);

        window_refresh();
    }

    window_close();
    
    return 0;
}