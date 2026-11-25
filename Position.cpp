#include <iostream>
#include "Constant.cpp"

class Position{
    private:
        int x;
        int y;

    public:
        Position() {}

        Position(int posX, int posY) {
            x = posX;
            y = posY;
        }

        int getX() {
            return x;
        }

        int getY() {
            return y;
        }

        void printPosition(){
            std::cout << "(x : " << x << ", y : " << y << ")";
        }
};
