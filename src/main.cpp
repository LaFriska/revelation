#include "raylib.h"
#include <vector>
#include "global.hpp"
#include "graphics/LevelTextures.hpp"

int main() {
    
    InitWindow(LEVEL_WIDTH * CELL_SIZE, LEVEL_HEIGHT * CELL_SIZE, "Revelation");
    SetTargetFPS(60);

    Texture2D wallLeft = LoadTexture(TEXTURE_BOUNDARY_WALL);
    Texture2D floor = LoadTexture(TEXTURE_FLOOR);

    while(!WindowShouldClose()){

        BeginDrawing();
        ClearBackground(RAYWHITE);

        for(int y = 0; y < LEVEL_HEIGHT; y++){
            for(int x = 0; x < LEVEL_WIDTH; x++){
                DrawTexturePro(
                    wallLeft,
                    TILE_SOURCE_RECT,
                    Rectangle{ (float)x * CELL_SIZE, (float)y * CELL_SIZE, (float)CELL_SIZE, (float)CELL_SIZE }, // destination rectangle
                    Vector2{ 0, 0 }, 0.0f, WHITE
                );
            }
        }

        EndDrawing();

    }

    UnloadTexture(wallLeft);
    UnloadTexture(floor);

    CloseWindow();

    return 0;

}