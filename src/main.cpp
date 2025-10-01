#include "raylib.h"
#include <vector>
#include "global.hpp"
#include "graphics/LevelGraphics.hpp"

int main() {
    
    InitWindow(LEVEL_WIDTH * CELL_SIZE, LEVEL_HEIGHT * CELL_SIZE, "Revelation");
    SetTargetFPS(60);

    LevelGraphics graphics("assets/textures/level-lab.png");

    while(!WindowShouldClose()){

        BeginDrawing();
        ClearBackground(RAYWHITE);

        for(int y = 0; y < LEVEL_HEIGHT; y++){
            for(int x = 0; x < LEVEL_WIDTH; x++){
                graphics.draw(x, y);
            }
        }

        EndDrawing();

    }

    CloseWindow();

    return 0;

}