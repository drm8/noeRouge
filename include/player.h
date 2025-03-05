#include <cstdio>

#include "object.h"

class player : public gameObject {
private:
    ;;

public:
    player(int id): gameObject() {
        this->setId(id);
    }
    void onTick() override;
    void onRender() override;
};

// Define the player crate function in the object handler
class player *objectHandler::createPlayer() {
    class player *player = new class player(this->nextId++);
    this->allObjects.push_back(player);
    this->numberOfObjects++;
    return player;
}
