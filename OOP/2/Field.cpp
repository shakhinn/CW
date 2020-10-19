#include "Field.h"

Field::Field(int width, int height):width(width),height(height), entrance({0, 0}), exit({0, 0}){
    map = new Cell*[width];
    for (int x = 0; x<width; x++){
        map[x] = new Cell[height];
    }
    Field::generateMap();
}
Field* Field::uniqueInstance = nullptr;

Field* Field::instance() {
    if (!uniqueInstance)
        uniqueInstance = new Field(WIDTH, HEIGHT);
    return uniqueInstance;
}

Field::~Field() {
    for(int x = 0; x < width; x++){
        delete [] map[x];
    }
    delete [] map;
}

Field::Field(const Field &a): map(new Cell*[a.width]), width(a.width), height(a.height),entrance(a.entrance),exit(a.exit){
    for(int x = 0; x < width; x++){
        map[x] = new Cell[height];
        for(int y = 0; y < height; y++){
            map[x][y] = a.map[x][y];
        }
    }
}

Field & Field::operator=(const Field &a){
    if(this != &a){
        for(int x = 0; x < width; x++){
            delete [] map[x];
        }
        delete [] map;
        width = a.width;
        height = a.height;
        entrance = a.entrance;
        exit = a.exit;
        map = new Cell*[width];
        for (int x = 0; x < width; x++){
            map[x] = new Cell[height];
            for(int y = 0; y < height; y++){
                std::swap(map[x][y],a.map[x][y]);
            }
        }
    }
    return *this;
}

Field::Field(Field &&a)noexcept: map(a.map),width(a.width), height(a.height),entrance(a.entrance),exit(a.exit){
    a.map = nullptr;
}

Field & Field::operator=(Field &&a)noexcept{
    if(this == &a){
        return *this;
    }
    std::swap(width, a.width);
    std::swap(height,a.height);
    std::swap(entrance, a.entrance);
    std::swap(exit, a.exit);
    std::swap(map,a.map);
    return *this;
}

void Field::initialiseMap() {
    int chanceToStartOpen = 40;
    srand(time(nullptr));
    for(int x=0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            if(rand()%100 < chanceToStartOpen){
                map[x][y].makeClose();
            }
        }
    }
}

int Field::countOpenNeighbors(int x, int y) {
    int count = 0;
    for(int i=-1; i<2; i++){
        for(int j=-1; j<2; j++){
            int neighbour_x = x+i;
            int neighbour_y = y+j;
            if(i==0 && j==0){
            } else if(neighbour_x < 0 || neighbour_y < 0 || neighbour_x >= width || neighbour_y >= height){
                count = count + 1;
            }
            else if(map[neighbour_x][neighbour_y].show()){
                count = count + 1;
            }
        }
    }
    return count;
}

void Field::doSimulationStep() {
    int deathLimit = 5;
    int birthLimit = 4;
    Cell** newMap = new Cell*[width];
    for(int x = 0; x < width; x++){
        newMap[x] = new Cell[height];
        for(int y = 0; y < height; y++){
            int count = Field::countOpenNeighbors(x,y);
            if(map[x][y].show()){
                if(count < deathLimit){
                    newMap[x][y].makeOpen();
                } else{
                    newMap[x][y].makeClose();
                }
            } else{
                if(count > birthLimit){
                    newMap[x][y].makeClose();
                } else{
                    newMap[x][y].makeOpen();
                }
            }
        }
    }
    for(int x = 0; x < width; x++){
        delete [] map[x];
    }
    delete [] map;
    map = newMap;
}

void Field::generateMap() {
    int numberSteps = 1;
    Field::initialiseMap();
    for(int i = 0; i < numberSteps; i++){
        Field::doSimulationStep();
    }
    for(int i = 0; i < height; i++){
        map[0][i].makeClose();
        map[width-1][i].makeClose();
    }
    for(int i = 0; i < width; i++){
        map[i][0].makeClose();
        map[i][height-1].makeClose();
    }
    if(!makeEntrance() || !makeExit()){
        generateMap();
    }
    makeCoins();
    makeTele();
    makeBombs();
}

int Field::countNeighbors(int x, int y) {
    int count = 0;
    for(int i=-1; i<2; i++){
        for(int j=-1; j<2; j++){
            int neighbour_x = x+i;
            int neighbour_y = y+j;
            if((i==0 && j==0) || (neighbour_x < 0 || neighbour_y < 0 || neighbour_x >= width || neighbour_y >= height)){
            }
            else if(!map[neighbour_x][neighbour_y].show()){
                count = count + 1;
            }
        }
    }
    return count;
}

void Field::checkSpace(int x, int y, int *count, int flag) {
    if(map[x][y].show()|| *count > 100)
        return;
    if(!map[x][y].show()){
        *count+=1;
        if(flag == 1) {
            checkSpace(x + 1, y, count, flag);
            checkSpace(x, y + 1, count, flag);
        } else if(flag == 0) {
            checkSpace(x - 1, y, count, flag);
            checkSpace(x, y - 1, count,flag);
        } else if(flag == 2){
            checkSpace(x + 1, y, count, flag);
            checkSpace(x, y + 1, count, flag);
            checkSpace(x - 1, y, count, flag);
            checkSpace(x, y - 1, count,flag);
        }
    }
}

bool Field::makeEntrance() {
    int count = 0;
    for(int i = 1; i < width-1; i++){
        for(int j = 1; j < height-1; j++){
            if(countNeighbors(i,j)==8){
                checkSpace(i, j, &count, 1);
                if(count > 100) {
                    map[i][j].makeEntrance();
                    entrance.x = i;
                    entrance.y = j;
                    return true;
                }
            }
        }
    }
    return false;
}

bool Field::makeExit() {
    int count = 0;
    for(int i = width - 1; i > 1; i--){
        for(int j = height - 1; j > 1; j--){
            if(countNeighbors(i,j)==8){
                checkSpace(i, j, &count, 0);
                if(count > 100) {
                    map[i][j].makeExit();
                    exit.x = i;
                    exit.y = j;
                    return true;
                }
            }
        }
    }
    return false;
}

void Field::makeCoins() {
    /*int hiddenLimit = 4;
    for(int i = 1; i < width-1; i++){
        for(int j = 1; j < height-1; j++){
            if(!map[i][j].show()){
                int nbs = countOpenNeighbors(i, j);
                if(nbs >= hiddenLimit && nbs <= 6) {
                    int count = 0;
                    checkSpace(i, j, &count, 2);
                    if (count > 100){
                        map[i][j].makeCoin();
                    }
                }
            }
        }
    }*/
    int cntCoins = 0;
    while (cntCoins < 40){
        int x = std::experimental::randint(2, WIDTH-3);
        int y = std::experimental::randint( 2, HEIGHT-3);
        if(!map[x][y].show() && map[x][y].showCELL() == OPEN){
            map[x][y].makeCoin();
            cntCoins++;
        } else{
            continue;
        }
    }
}

void Field::makeBombs(){
    int cntBomb = 0;
    while (cntBomb < 5){
        int x = std::experimental::randint(5, WIDTH-3);
        int y = std::experimental::randint( 5, HEIGHT-3);
        if(!map[x][y].show()&& map[x][y].showCELL() == OPEN){
            map[x][y].makeBomb();
            cntBomb++;
        } else{
            continue;
        }
    }
}

void Field::makeTele() {
    int cntTele = 0;
    while (cntTele < 2){
        int x = std::experimental::randint(5, WIDTH-3);
        int y = std::experimental::randint( 5, HEIGHT-3);
        if(!map[x][y].show()&& map[x][y].showCELL() == OPEN){
            map[x][y].makeTele();
            cntTele++;
        } else{
            continue;
        }
    }
}

void Field::showField() {
    for(int x = 0; x < width; x++){
        for(int y = 0; y < height; y++){
            if(map[x][y].showCELL() == EXIT){
                std::cout<<"\033[1;31m#\033[0m";
            }
            else if(map[x][y].showCELL() == ENTRANCE){
                std::cout<<"\033[1;34m@\033[0m";
            }else if(map[x][y].showCELL() == OPEN){
                std::cout << map[x][y].showCELL();
            }else if(map[x][y].showCELL() == CLOSE){
                std::cout << map[x][y].showCELL();
            } else if(map[x][y].showCELL() == COIN){
                std::cout << "2";
            }
        }
        std::cout<<"\n";
    }
}

Cell** Field::getMap() {
    return map;
}

Point & Field::getEntrance(){
    return entrance;
}
Point & Field::getExit() {
    return exit;
}
