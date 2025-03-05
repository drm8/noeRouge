#ifndef H_OBJECT
#define H_OBJECT
#include <cstdio>
#include <vector>

/*
// TODO list:
//
// 00 - maybe rename this to something that makes more sense?
//
*/

// Prototype player
class player;

class gameObject {
private:
    int id;

public:
    gameObject(int id) {
        this->id = id;
    }
    ~gameObject() {
        // No memory is currently allocated, do nothing
        ;;
    }

    // Getters
    int getId();

    virtual void onTick();
    // TODO 00
    virtual void onRender();
};

class objectHandler {
private:
    int numberOfObjects;
    int nextId;
    std::vector<class gameObject *> allObjects;

public:
    objectHandler() {
        this->numberOfObjects = 0;
        this->nextId = 0;
    }
    ~objectHandler() {
        ;;
    }

    void tickAll();
    class gameObject *getObject(int id);
    class gameObject *createObject();
    class player *createPlayer();
};

#endif
