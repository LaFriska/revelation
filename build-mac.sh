g++ -std=c++11 src/*.cpp src/graphics/*.cpp \
    -Iinclude \
    -Llib -lraylib \
    -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL \
    -o revelation
