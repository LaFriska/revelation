#include "graphics/LevelGraphics.hpp"
#include <string>
#include "global.hpp"

Rectangle LevelGraphics::tileToSourceRec(LevelGraphics::Tile t){
    switch (t) {
        case LevelGraphics::Tile::WALL_TOP_VARIANT_1:    return getRectangle(0, 1);
        case LevelGraphics::Tile::WALL_TOP_VARIANT_2:    return getRectangle(0, 2);
        case LevelGraphics::Tile::WALL_TOP_VARIANT_3:    return getRectangle(0, 3);
        
        case LevelGraphics::Tile::WALL_LEFT_VARIANT_1:   return getRectangle(1, 0);
        case LevelGraphics::Tile::WALL_LEFT_VARIANT_2:   return getRectangle(2, 0);
        case LevelGraphics::Tile::WALL_LEFT_VARIANT_3:   return getRectangle(3, 0);
        
        case LevelGraphics::Tile::WALL_RIGHT_VARIANT_1:  return getRectangle(1, 4);
        case LevelGraphics::Tile::WALL_RIGHT_VARIANT_2:  return getRectangle(2, 4);
        case LevelGraphics::Tile::WALL_RIGHT_VARIANT_3:  return getRectangle(3, 4);
        
        case LevelGraphics::Tile::WALL_BOTTOM_VARIANT_1: return getRectangle(4, 1);
        case LevelGraphics::Tile::WALL_BOTTOM_VARIANT_2: return getRectangle(4, 2);
        case LevelGraphics::Tile::WALL_BOTTOM_VARIANT_3: return getRectangle(4, 3);
        
        case LevelGraphics::Tile::TOP_LEFT_CORNER:       return getRectangle(0, 0);
        case LevelGraphics::Tile::TOP_RIGHT_CORNER:      return getRectangle(0, 4);
        case LevelGraphics::Tile::BOTTOM_LEFT_CORNER:    return getRectangle(4, 0);
        case LevelGraphics::Tile::BOTTOM_RIGHT_CORNER:   return getRectangle(4, 4);
        
        case LevelGraphics::Tile::FLOOR:                 return getRectangle(2, 2);
        
        case LevelGraphics::Tile::TOP_LEFT_FLOOR:        return getRectangle(1, 1);
        case LevelGraphics::Tile::TOP_RIGHT_FLOOR:       return getRectangle(1, 3);
        case LevelGraphics::Tile::BOTTOM_LEFT_FLOOR:     return getRectangle(3, 1);
        case LevelGraphics::Tile::BOTTOM_RIGHT_FLOOR:    return getRectangle(3, 3);
        
        case LevelGraphics::Tile::TOP_FLOOR:             return getRectangle(1, 2);
        case LevelGraphics::Tile::BOTTOM_FLOOR:          return getRectangle(3, 2);
        case LevelGraphics::Tile::LEFT_FLOOR:            return getRectangle(2, 1);
        case LevelGraphics::Tile::RIGHT_FLOOR:           return getRectangle(2, 3);
    }
    return getRectangle(0,0);
}

LevelGraphics::LevelGraphics(std::string path){
    this->filePath = path;
    texturePack = LoadTexture(path.c_str());
}

void LevelGraphics::draw(int x, int y){
    //Walls
    if(x == 0 && y == 0){
        LevelGraphics::drawSingleTexture(x, y, LevelGraphics::Tile::TOP_LEFT_CORNER);
    }else if(x == 0 && y == LEVEL_HEIGHT - 1){
        LevelGraphics::drawSingleTexture(x, y, LevelGraphics::Tile::BOTTOM_LEFT_CORNER);
    }else if(x == LEVEL_WIDTH - 1 && y == 0){
        LevelGraphics::drawSingleTexture(x, y, LevelGraphics::Tile::TOP_RIGHT_CORNER);
    }else if(x == LEVEL_WIDTH - 1 && y == LEVEL_HEIGHT - 1){
        LevelGraphics::drawSingleTexture(x, y, LevelGraphics::Tile::BOTTOM_RIGHT_CORNER);
    }else if(y == 0){
        LevelGraphics::drawSingleTexture(x, y, LevelGraphics::Tile::WALL_TOP_VARIANT_1);
    }else if(x == 0){
        LevelGraphics::drawSingleTexture(x, y, LevelGraphics::Tile::WALL_LEFT_VARIANT_1);
    }else if(y == LEVEL_HEIGHT - 1){
        LevelGraphics::drawSingleTexture(x, y, LevelGraphics::Tile::WALL_BOTTOM_VARIANT_1);
    }else if(x == LEVEL_WIDTH - 1){
        LevelGraphics::drawSingleTexture(x, y, LevelGraphics::Tile::WALL_RIGHT_VARIANT_1);
    }

    //Floors
    else if(x == 1 && y == 1){
        LevelGraphics::drawSingleTexture(x, y, LevelGraphics::Tile::TOP_LEFT_FLOOR);
    }else if(x == 1 && y == LEVEL_HEIGHT - 2){
        LevelGraphics::drawSingleTexture(x, y, LevelGraphics::Tile::BOTTOM_LEFT_FLOOR);
    }else if(x == LEVEL_WIDTH - 2 && y == 1){
        LevelGraphics::drawSingleTexture(x, y, LevelGraphics::Tile::TOP_RIGHT_FLOOR);
    }else if(x == LEVEL_WIDTH - 2 && y == LEVEL_HEIGHT - 2){
        LevelGraphics::drawSingleTexture(x, y, LevelGraphics::Tile::BOTTOM_RIGHT_FLOOR);
    }else if(y == 1){
        LevelGraphics::drawSingleTexture(x, y, LevelGraphics::Tile::TOP_FLOOR);
    }else if(x == 1){
        LevelGraphics::drawSingleTexture(x, y, LevelGraphics::Tile::LEFT_FLOOR);
    }else if(y == LEVEL_HEIGHT - 2){
        LevelGraphics::drawSingleTexture(x, y, LevelGraphics::Tile::BOTTOM_FLOOR);
    }else if(x == LEVEL_WIDTH - 2){
        LevelGraphics::drawSingleTexture(x, y, LevelGraphics::Tile::RIGHT_FLOOR);
    }else{
        LevelGraphics::drawSingleTexture(x, y, LevelGraphics::Tile::FLOOR);
    }
}

LevelGraphics::~LevelGraphics() {
    UnloadTexture(texturePack);
}

void LevelGraphics::drawSingleTexture(int x, int y, LevelGraphics::Tile tile){
    DrawTexturePro(
        LevelGraphics::texturePack,
        LevelGraphics::tileToSourceRec(tile),
        Rectangle{(float)x * CELL_SIZE, (float)y * CELL_SIZE, (float)CELL_SIZE, (float)CELL_SIZE },
        Vector2{ 0, 0 }, 0.0f, WHITE
    );
}

Rectangle getRectangle(int r, int c){
    return Rectangle {
        (float) (c * PIXEL_SIZE), 
        (float) (r * PIXEL_SIZE),
        (float) PIXEL_SIZE, 
        (float) PIXEL_SIZE
    };
}