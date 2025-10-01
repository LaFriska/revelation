#ifndef LEVEL_GRAPHICS_HPP
#define LEVEL_GRAPHICS_HPP

#include "raylib.h"
#include <string>

/**
 * Represents the set of all textures a level itself needs, which includes all variants
 * of walls, floors and corners. This class must only be instantiated after a raylib window
 * is successfully initialised.
 */
class LevelGraphics{

    public:

        /**
         * Represents a type of tile in a level.
         */
        enum class Tile {
            WALL_TOP_VARIANT_1,
            WALL_TOP_VARIANT_2,
            WALL_TOP_VARIANT_3,
            WALL_LEFT_VARIANT_1,
            WALL_LEFT_VARIANT_2,
            WALL_LEFT_VARIANT_3,
            WALL_RIGHT_VARIANT_1,
            WALL_RIGHT_VARIANT_2,
            WALL_RIGHT_VARIANT_3,
            WALL_BOTTOM_VARIANT_1,
            WALL_BOTTOM_VARIANT_2,
            WALL_BOTTOM_VARIANT_3,
            TOP_LEFT_CORNER,
            TOP_RIGHT_CORNER,
            BOTTOM_LEFT_CORNER,
            BOTTOM_RIGHT_CORNER,
            FLOOR,
            TOP_LEFT_FLOOR,
            TOP_RIGHT_FLOOR,
            BOTTOM_LEFT_FLOOR,
            BOTTOM_RIGHT_FLOOR,
            TOP_FLOOR,
            BOTTOM_FLOOR,
            LEFT_FLOOR,
            RIGHT_FLOOR
        };

        /**
         * Converts a tile to a source rectangle.
         * */
        static Rectangle tileToSourceRec(Tile t);

        /**
        * The constructor takes in a file path which identifies a png file including
        * all necessary textures in various source rectangles. 
        */
        LevelGraphics(std::string path);

        /**
         * Draws the appropriate tile onto the screen given x and y coordinates.
         */
        void draw(int x, int y);

        ~LevelGraphics();
    
    private:
        std::string filePath;

        // All the textures loaded in.
        Texture2D texturePack;

        void drawSingleTexture(int x, int y, Tile tile);
            
};

extern Rectangle getRectangle(int r, int c);

#endif