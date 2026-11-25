#include <list>
#include "Position.cpp"

class Grille {
    private:
        std::list<Position> obstaclePosition;
    public:

        Grille(){
            caillouGen();
        }

        bool isObstacle(Position target){
            for (Position position : obstaclePosition) {
                if (position.getX() == target.getX() && position.getY() == target.getY()){
                    return true;
                }
            }
            return false;
        }

        void caillouGen(){
            obstaclePosition.push_front(Position(51,51));
            obstaclePosition.push_front(Position(75,75));
        }
};
