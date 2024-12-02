#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

class GameObject {
protected:
    int distance; // 한 번 이동거리
    int x, y; // 현재 위치
public:
    GameObject() {}
    GameObject(int startX, int startY, int distance) { // 초기 위치와 이동거리 설정
        this->x = startX; this->y = startY;
        this->distance = distance;
    }
    virtual ~GameObject() {}; // 가상 소멸자

    virtual void move(char key) = 0; // 이동한 후 새로운 위치로 x,y 변경
    virtual char getShape() = 0; // 객체의 모양을 나타내는 문자 리턴

    int getX() { return x; }
    int getY() { return y; }
    bool collide(GameObject *p) { // 이 객체가 객체 p와 충돌했으면 true 리턴
        return (this->x == p->getX() && this->y == p->getY());
    }
};

class Human : public GameObject {
private:
    char shape;
public:
    Human() {}
    Human(int startX, int startY, int distance, char tmp) {
        this->x = startX;
        this->y = startY;
        this->distance = distance;
        this->shape = tmp;
    }
    ~Human() override {};

    void move(char key) override {
        if (key == 'a')
            y--; // 왼쪽
        else if (key == 's')
            x++; // 아래
        else if (key == 'd')
            y++; // 오른쪽
        else if (key == 'w')
            x--; // 위
    }
    char getShape() override {
        return shape;
    }
};

class Monster : public GameObject {
private:
    char shape;
    int x2;
    int y2;
public:
    Monster() {}
    Monster(int startX, int startY, int distance, char tmp) {
        this->x = startX;
        this->y = startY;
        this->distance = distance;
        this->shape = tmp;
    }
    ~Monster() override {};

    void move(char key) override {
        while(true) {
            int randNum = rand() % 4;
            if (randNum == 0) {   //east
                if (y == 18) {
                    y++;
                    x2 = x;
                    y2 = y;
                }
                else if (y == 19)
                    continue;
                else {
                    y += distance;
                    x2 = x;
                    y2 = y - 1;
                }
            }
            if (randNum == 1) {  //west
                if (y == 1) {
                    y--;
                    x2 = x;
                    y2 = y;
                } else if (y == 0)
                    continue;
                else {
                    y -= distance;
                    x2 = x;
                    y2 = y + 1;
                }
            }
            if (randNum == 2) {  //north
                if (x == 1) {
                    x--;
                    x2 = x;
                    y2 = y;
                }
                else if (x == 0)
                    continue;
                else {
                    x -= distance;
                    x2 = x + 1;
                    y2 = y;
                }
            }
            if (randNum == 3) {   //south
                if (x == 8) {
                    x++;
                    x2 = x;
                    y2 = y;
                } else if (x == 9)
                    continue;
                else {
                    x += distance;
                    x2 = x+1;
                    y2 = y;
                }
            }
            break;
        }
    }
    bool collide2(GameObject *p) { // 몬스터가 1칸 이동한 부분도 충돌범위로 정함
        return (this->x2 == p->getX() && this->y2 == p->getY());
    }
    char getShape() override {
        return shape;
    }
};

class Food : public GameObject {
private:
    char shape;
public:
    Food() {}
    Food(int startX, int startY, int distance, char tmp) {
        this->x = startX;
        this->y = startY;
        this->distance = distance;
        this->shape = tmp;
    }
    ~Food() override {};

    void move(char key) override {
        while (true) {
            int randNum = rand() % 4;
            if (randNum == 0) {   //east
                if (y == 19)
                    continue;
                else y += distance;
            }
            if (randNum == 1) {  //west
                if (y == 0)
                    continue;
                else y -= distance;
            }
            if (randNum == 2) {  //north
                if (x == 0)
                    continue;
                else x -= distance;
            }
            if (randNum == 3) {
                if (x == 9)
                    continue;
                else x += distance;
            }
            break;
        }
    }
    char getShape() override {
        return shape;
    }
};

void printGameboard(vector<vector<char>>& Gameboard, Human &ObjectHuman, Monster &ObjectMonster, Food &ObjectFood) {
    // 게임 보드를 초기화
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++)
            Gameboard[i][j] = '-';
    }

    int x, y;

    x = ObjectFood.getX();
    y = ObjectFood.getY();
    Gameboard[x][y] = ObjectFood.getShape();

    x = ObjectHuman.getX();
    y = ObjectHuman.getY();
    Gameboard[x][y] = ObjectHuman.getShape();

    x = ObjectMonster.getX();
    y = ObjectMonster.getY();
    Gameboard[x][y] = ObjectMonster.getShape();

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++)
            cout << Gameboard[i][j];
        cout << endl;
    }
}

int main() {
    vector<vector<char>> Gameboard(10, vector<char>(20, '-'));
    Human ObjectHuman(0, 0, 1, 'H');
    Monster ObjectMonster(5, 5, 2, 'M');
    Food ObjectFood(9, 9, 1, 'F');
    srand(time(NULL));
    int allcount = 5;
    int movecount = 0;

    printGameboard(Gameboard, ObjectHuman, ObjectMonster, ObjectFood);

    while (true) {
        char key;
        cout << "Move Human (w/a/s/d): ";
        cin >> key;
        ObjectHuman.move(key);
        ObjectMonster.move(key);
        int randNum = rand() % 5;
        if (allcount + movecount > 3) {
            if (randNum < 3) {
                ObjectFood.move(key);
                movecount++;
                allcount--;
            }
            else allcount--;
        }
        else {
            ObjectFood.move(key);
            movecount++;
            allcount--;
        }
        if (allcount == 0) {
            allcount = 5;
            movecount = 0;
        }

        printGameboard(Gameboard, ObjectHuman, ObjectMonster, ObjectFood);


        if(ObjectMonster.collide(&ObjectFood)|| ObjectMonster.collide2(&ObjectFood)) {
            cout << "Monster has found the food! Game over!.";
            break;
        }
        if(ObjectMonster.collide(&ObjectHuman)|| ObjectMonster.collide2(&ObjectFood)) {
            cout << "Monster has caught the Human! Game over!.";
            break;
        }
        if (ObjectHuman.collide(&ObjectFood)) {
            cout << "Human has found the food! Human win!." << endl;
            break;
        }
    }
    return 0;
}


