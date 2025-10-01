#ifndef LEVEL_TEXTURES_HPP
#define LEVEL_TEXTURES_HPP

#include "raylib.h"
#include <string>

using namespace std;

/**
 * Represents the set of all textures a level itself needs, which includes all variants
 * of walls, floors and corners.
 */
class LevelTextures{

    public:

        /**
        * The constructor takes in a file path which identifies a png file including
        * all necessary textures in various source rectangles. 
        */
        LevelTextures(string path);

        ~LevelTextures();

        
            
};

#endif