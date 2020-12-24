#include "Save.h"

Save::Save(std::string filename) {
    fileStreamO.open(filename);
    if(!fileStreamO.is_open()){
        throw ReadException("Wrong File!\n");
    }
}
void Save::save(Field &field, Player *player, IEnemy *e1, IEnemy *e2, IEnemy *e3) {
    if(player) {
        bool flag = true;
        fileStreamO.write((char*)&flag, sizeof(bool));
        player->save(fileStreamO);
    }else {
        bool flag = false;
        fileStreamO.write((char*)&flag, sizeof(bool));
    }
    field.save(fileStreamO);
    BType type;
    int cnt = 0;
    if(e1) cnt++;
    if(e2) cnt++;
    if(e3) cnt++;
    fileStreamO.write((char*)&cnt, sizeof(int));
    int x;
    int y;
    if(e1) {
        x = e1->getX();
        fileStreamO.write((char *) &x, sizeof(int));
        y = e1->getY();
        fileStreamO.write((char *) &y, sizeof(int));
        type = e1->getBehaviorType();
        fileStreamO.write((char *) &type, sizeof(BType));
    }if(e2) {
        x = e2->getX();
        fileStreamO.write((char *) &x, sizeof(int));
        y = e2->getY();
        fileStreamO.write((char *) &y, sizeof(int));
        type = e2->getBehaviorType();
        fileStreamO.write((char *) &type, sizeof(BType));
    }if(e3) {
        x = e3->getX();
        fileStreamO.write((char *) &x, sizeof(int));
        y = e3->getY();
        fileStreamO.write((char *) &y, sizeof(int));
        type = e3->getBehaviorType();
        fileStreamO.write((char *) &type, sizeof(BType));
    }
}

Save::~Save() {
    fileStreamO.close();
}
