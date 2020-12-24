#include "Field.h"

Field::Field(int width, int height):width(width),height(height), entrance({0, 0}), exit({0, 0}){
    map = new Cell*[width];
    for (int x = 0; x<width; x++){
        map[x] = new Cell[height];
    }
    Field::generateMap();
}
Field *Field::uniqueInstance = nullptr;

SingletonDestroyer Field::destroyer;

SingletonDestroyer::~SingletonDestroyer() {
    delete uniqueInstance;
}

void SingletonDestroyer::initialize(Field* p ) {
    uniqueInstance = p;
}


Field& Field::instance() {
    if(!uniqueInstance)     {
        uniqueInstance = new Field(WIDTH, HEIGHT);
        destroyer.initialize(uniqueInstance);
    }
    return *uniqueInstance;
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

void Field::initialiseMap() const {
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

int Field::countOpenNeighbors(int x, int y) const {
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
    makeCords();
    if(!makeEntrance() || !makeExit()){
        generateMap();
    }
    makeEnemySpawn();
    makeCoins();
    makeTele();
    makeBombs();
    makeArmor();
}

int Field::countNeighbors(int x, int y) const {
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

void Field::makeCoins() const {
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

void Field::makeBombs() const{
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

void Field::makeTele() const {
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

void Field::returnSpawn(Point &e1, Point &e2, Point &e3) const {
    e1 = en1;
    e2 = en2;
    e3 = en3;
}

void Field::makeArmor() const {
    int cntArmor = 0;
    while (cntArmor < 3){
        int x = std::experimental::randint(8, WIDTH-10);
        int y = std::experimental::randint( 8, HEIGHT-10);
        if(!map[x][y].show() && map[x][y].showCELL() != COIN && map[x][y].showCELL() != TELE && map[x][y].showCELL() != BOMB && map[x][y].showCELL() == OPEN){
            map[x][y].makeArmor();
            cntArmor++;
        } else{
            continue;
        }
    }
}
void Field::makeEnemySpawn() {
    int x, y;
    bool f = false;
    while (!f) {
        x = std::experimental::randint(12, 17);
        y = std::experimental::randint(10, 20);
        if (!map[x][y].show()) {
            en1.x = x;
            en1.y = y;
            f = true;
        }
    }
    f = false;
    while (!f) {
        x = std::experimental::randint(28, 28);
        y = std::experimental::randint(30, 38);
        if (!map[x][y].show()) {
            en2.x = x;
            en2.y = y;
            f = true;
        }
    }
    f = false;
    while (!f) {
        x = std::experimental::randint(8, 12);
        y = std::experimental::randint(42, 48);
        if (!map[x][y].show()) {
            en3.x = x;
            en3.y = y;
            f = true;
        }
    }
}

void Field::makeCords() const {
    for(int x = 0; x < width; x++){
        for(int y = 0; y < height; y++){
            map[x][y].makeCoord(x, y);
        }

    }
}

Point & Field::getEntrance(){
    return entrance;
}

void Field::save(std::ofstream &filestream) {
    filestream.write((char*)&width, sizeof(int));
    filestream<<'\n';
    filestream.write((char*)&height, sizeof(int));
    for(int i = 0; i < this->width; i++){
        for(int j = 0; j < this->height; j++){
            filestream.write((char*)&this->map[i][j], sizeof(Cell));
        }
    }
}
void Field::load(std::ifstream &filestream) {
    width = -1; height = -1;
    filestream.read((char*)&width, sizeof(int));
    filestream.get();
    filestream.read((char*)&height, sizeof(int));
    if(width < 0 || height < 0){
        throw ReadException("Wrong field size!\n");
    }
    setSize(width, height);
    Cell buf;
    for(int i = 0; i < this->width; i++){
        for(int j = 0; j < this->height; j++){
            filestream.read((char*)&buf, sizeof(Cell));
            switch (buf.showCELL()) {
                case OPEN:
                    map[i][j].makeOpen();
                    break;
                case CLOSE:
                    map[i][j].makeClose();
                    break;
                case COIN:
                    map[i][j].makeCoin();
                    break;
                case BOMB:
                    map[i][j].makeBomb();
                    break;
                case TELE:
                    map[i][j].makeTele();
                    break;
                case EXIT:
                    map[i][j].makeExit();
                    break;
                case ENTRANCE:
                    map[i][j].makeEntrance();
                    break;
                case ARMOR:
                    map[i][j].makeArmor();
                    break;
                default:
                    throw ReadException("Wrong cell type!\n");
            }
            }
        }
}

void Field::setSize(int w, int h) {
    width = w;
    height = h;
    map = new Cell*[width];
    for (int x = 0; x<width; x++){
        map[x] = new Cell[height];
    }
}