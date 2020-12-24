#include "Load.h"

void Load::load(Field &field, Player &player, IEnemy **e1, IEnemy **e2, IEnemy **e3) {
    bool flag;
    fileStreamI.read((char*)&flag, sizeof(bool));
    if(flag) {
        player.load(fileStreamI);
    }
    field.load(fileStreamI);
    int cnt = 0;
    fileStreamI.read((char*)&cnt, sizeof(int));
    BType type;
    int x;
    int y;
    if(cnt == 0){
        *(e1) = nullptr;
        *(e2) = nullptr;
        *(e3) = nullptr;
    } else if(cnt ==1){
        fileStreamI.read((char *)&x, sizeof(int));
        fileStreamI.read((char *)&y, sizeof(int));
        fileStreamI.read((char *)&type, sizeof(BType));
        switch (type) {
            case KILL: *(e1) = new Enemy<killAction>(x, y);
                break;
            case THIEF: *(e1) = new Enemy<thiefAction>(x, y);
                break;
            case ATTACK: *(e1) = new Enemy<attackAction>(x, y);
            default: throw ReadException("Wrong action in file!\n");
        }
        *(e2) = nullptr;
        *(e3) = nullptr;
    } else if(cnt == 2){
        fileStreamI.read((char *)&x, sizeof(int));
        fileStreamI.read((char *)&y, sizeof(int));
        fileStreamI.read((char *)&type, sizeof(BType));
        switch (type) {
            case KILL: *(e1) = new Enemy<killAction>(x, y);
                break;
            case THIEF: *(e1) = new Enemy<thiefAction>(x, y);
                break;
            case ATTACK: *(e1) = new Enemy<attackAction>(x, y);
            default: throw ReadException("Wrong action in file!\n");
        }
        fileStreamI.read((char *)&x, sizeof(int));
        fileStreamI.read((char *)&y, sizeof(int));
        fileStreamI.read((char *)&type, sizeof(BType));
        switch (type) {
            case KILL: *(e2) = new Enemy<killAction>(x, y);
                break;
            case THIEF: *(e2) = new Enemy<thiefAction>(x, y);
                break;
            case ATTACK: *(e2) = new Enemy<attackAction>(x, y);
            default: throw ReadException("Wrong action in file!\n");
        }
        *(e3) = nullptr;
    } else if(cnt == 3){
        fileStreamI.read((char *)&x, sizeof(int));
        fileStreamI.read((char *)&y, sizeof(int));
        fileStreamI.read((char *)&type, sizeof(BType));
        switch (type) {
            case KILL: *(e1) = new Enemy<killAction>(x, y);
                break;
            case THIEF: *(e1) = new Enemy<thiefAction>(x, y);
                break;
            case ATTACK: *(e1) = new Enemy<attackAction>(x, y);
            default: throw ReadException("Wrong action in file!\n");
        }
        fileStreamI.read((char *)&x, sizeof(int));
        fileStreamI.read((char *)&y, sizeof(int));
        fileStreamI.read((char *)&type, sizeof(BType));
        switch (type) {
            case KILL: *(e2) = new Enemy<killAction>(x, y);
                break;
            case THIEF: *(e2) = new Enemy<thiefAction>(x, y);
                break;
            case ATTACK: *(e2) = new Enemy<attackAction>(x, y);
            default: throw ReadException("Wrong action in file!\n");
        }
        fileStreamI.read((char *)&x, sizeof(int));
        fileStreamI.read((char *)&y, sizeof(int));
        fileStreamI.read((char *)&type, sizeof(BType));
        switch (type) {
            case KILL: *(e3) = new Enemy<killAction>(x, y);
                break;
            case THIEF: *(e3) = new Enemy<thiefAction>(x, y);
                break;
            case ATTACK: *(e3) = new Enemy<attackAction>(x, y);
            default: throw ReadException("Wrong action in file!\n");
        }
    }

    /*fileStreamI.read((char *)&x, sizeof(int));
    fileStreamI.read((char *)&y, sizeof(int));
    fileStreamI.read((char *)&type, sizeof(BType));
    *(e1) = new Enemy<attackAction>(x, y);
    fileStreamI.read((char *)&x, sizeof(int));
    fileStreamI.read((char *)&y, sizeof(int));
    fileStreamI.read((char *)&type, sizeof(BType));
    *(e2) = new Enemy<thiefAction>(x, y);
    fileStreamI.read((char *)&x, sizeof(int));
    fileStreamI.read((char *)&y, sizeof(int));
    fileStreamI.read((char *)&type, sizeof(BType));
    *(e3) = new Enemy<killAction>(x, y);*/
}

Load::Load(std::string filename) {
    fileStreamI.open(filename);
    if(!fileStreamI.is_open()){
        throw ReadException("Wrong file!\n");
    }
}

Load::~Load() {
    fileStreamI.close();
}