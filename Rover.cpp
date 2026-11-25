#include <iostream>
#include <string>
#include "Grille.cpp"

class Rover {
    private:
        Position position;
        int facing;
        Grille grille;

    public:
        Rover() : position(SIZE/2,SIZE/2), facing(0), grille() {}

        void move(std::string instructions) {
            for (char posInstructions: instructions){
                switch (posInstructions) {
                    case 'f':
                        if (!detectObstacle(forward())) { position = forward(); }
                        break;
                    case 'b':
                        if (!detectObstacle(backward())){ position = backward(); }
                        break;
                    case 'l':
                        left();
                        break;
                    case 'r':
                        right();
                        break;
                }
            }
        }

        Position forward() {
            switch (FACING[facing]) {
                case 'N':
                    return Position(position.getX(), (position.getY() + 1 + SIZE)%SIZE);
                    break;
                case 'E':
                    return Position((position.getX() + 1 + SIZE)%SIZE, position.getY());
                    break;
                case 'S':
                    return Position(position.getX(), (position.getY() - 1 + SIZE)%SIZE);
                    break;
                case 'W':
                    return Position((position.getX() - 1 + SIZE)%SIZE, position.getY());
                    break;
                default:
                    return position;
            }
        }

        Position backward() {
            switch (FACING[facing]) {
                case 'N':
                    return Position(position.getX(), (position.getY() - 1 + SIZE)%SIZE);
                    break;
                case 'E':
                    return Position((position.getX() - 1 + SIZE)%SIZE, position.getY());
                    break;
                case 'S':
                    return Position(position.getX(), (position.getY() + 1 + SIZE)%SIZE);
                    break;
                case 'W':
                    return Position((position.getX() + 1 + SIZE)%SIZE, position.getY());
                    break;
                default:
                    return position;
            }
        }

        void left() {
            facing = (facing+1+NBFACING)%NBFACING;
        }

        void right() {
            facing = (facing+1)%NBFACING;
        }

        bool detectObstacle(Position pos) {
            if (grille.isObstacle(pos)){
                std::cout << "Y a un caillou la ou tu veux aller.\n";
                return true;
            } else {
                return false;
            }
        }

        void printRover() {
            std::cout << "Position : ";
            position.printPosition();
            std::cout << "\nFacing : " << FACING[facing];
        }
};
