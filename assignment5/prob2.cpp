#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>
#include <algorithm>

using namespace std;

class Circle;

class Rect {
    friend class Overlap;
private:
    string data;
    int x0, x1, y0, y1;
    double area;
public:
    Rect() = default;
    Rect(string data, int a, int b, int c, int d, double area) : data(data), x0(a), x1(b), y0(c), y1(d), area(area) {}
};

class Circle {
    friend class Overlap;
private:
    string data;
    int x, y;
    int radius;
    double area;
public:
    Circle() = default;
    Circle(string data, int a, int b, int c, double area) : data(data), x(a), y(b), radius(c), area(area) {}
};

class Overlap {
public:
    string data;
    int x, x1;
    int y, y1;
    double area;
    Overlap() = default;
    Overlap(string data, int x, int x1, int y, int y1, double area) : data(data), x(x), x1(x1), y(y), y1(y1), area(area) {}
    Overlap OverlapCircles(vector<Circle*>& Circles, vector<Rect*>& Rects, vector<Overlap>& Overlaps, int i) {
        Overlap tmp;
        int end = Circles.size() - 1;
        if (end < 0)
            return tmp = Overlap("E", -1, -1, -1, -1, -1);
        if (Circles[i]->radius + Circles[end]->radius >= sqrt(pow(Circles[end]->x - Circles[i]->x, 2) + pow(Circles[end]->y - Circles[i]->y, 2))) {
            tmp = Overlap("C", Circles[i]->x, -1, Circles[i]->y, Circles[i]->radius, Circles[i]->area);
            return tmp;
        }
        else return tmp = Overlap("E", -1, -1, -1, -1, -1);
    }

    Overlap OverlapRects(vector<Circle*>& Circles, vector<Rect*>& Rects, vector<Overlap>& Overlaps, int i) {
        Overlap tmp;
        int end = Circles.size() - 1;
        int count = 0;
        if (end < 0)
            return tmp = Overlap("E", -1, -1, -1, -1, -1);
        for (int x = Rects[i]->x0; x <= Rects[i]->x1; x++)
            for (int y = Rects[i]->y0; y <= Rects[i]->y1; y++)
                if (sqrt((Circles[end]->x - x) * (Circles[end]->x - x) + (Circles[end]->y - y) * (Circles[end]->y - y)) <= Circles[end]->radius) {
                    count++;
                    break;
                }
        if (count != 0) {
            tmp = Overlap("R", Rects[i]->x0, Rects[i]->x1, Rects[i]->y0, Rects[i]->y1, Rects[i]->area);
            return tmp;
        }
        else return tmp = Overlap("E", -1, -1, -1, -1, -1);
    }
};

vector<string>split_line(string line, char delimiter) {
    vector<string>coord;
    stringstream sstream(line);
    string str;
    while (getline(sstream, str, delimiter))
        coord.push_back(str);
    return coord;
}

void makelist(string filename, vector<Circle*>& Circles, vector<Rect*>& Rects) {
    ifstream theFile(filename);
    string line;
    while (getline(theFile, line)) {
        vector<string> coord = split_line(line, ' ');
        if (coord[0] == "R") {
            double area = (stoi(coord[2]) - stoi(coord[1])) * (stoi(coord[4]) - stoi(coord[3]));
            Rect* tmp = new Rect(coord[0], stoi(coord[1]), stoi(coord[2]), stoi(coord[3]), stoi(coord[4]), area);
            Rects.push_back(tmp);
        }
        if (coord[0] == "C") {
            double area = stoi(coord[3]) * stoi(coord[3]) * 3.141592;
            Circle* tmp = new Circle(coord[0], stoi(coord[1]), stoi(coord[2]), stoi(coord[3]), area);
            Circles.push_back(tmp);
        }
        if (coord[0] != "R" && coord[0] != "C") {
            if (coord.size() > 2) {
                double area = stoi(coord[2]) * stoi(coord[2]) * 3.141592;
                Circle* tmp = new Circle("C", stoi(coord[0]), stoi(coord[1]), stoi(coord[2]), area);
                Circles.push_back(tmp);
            }
        }
    }
}

int main() {
    vector<Circle*> Circles;
    vector<Rect*> Rects;
    vector<Overlap> Overlaps;
    Overlap tmp;
    makelist("input1.txt", Circles, Rects);
    for (int i = 0; i < Circles.size() - 1; i++)
        if (tmp.data != "E")
            Overlaps.push_back(tmp.OverlapCircles(Circles, Rects, Overlaps, i));
    for (int i = 0; i < Rects.size(); i++)
        if (tmp.data != "E")
            Overlaps.push_back(tmp.OverlapRects(Circles, Rects, Overlaps, i));
    for (int i = 0; i < Overlaps.size(); i++)
        for (int j = i + 1; j < Overlaps.size(); j++) {
            if (Overlaps[i].area > Overlaps[j].area) {
                swap(Overlaps[i], Overlaps[j]);
            }
            if (Overlaps[i].area == Overlaps[j].area)
                if (Overlaps[i].x > Overlaps[j].x)
                    swap(Overlaps[i], Overlaps[j]);
        }
    for (int i = 0; i < Overlaps.size(); i++) {
        if (Overlaps[i].data == "R")
            cout << "R" << " " << Overlaps[i].x << " " << Overlaps[i].x1 << " " << Overlaps[i].y << " " << Overlaps[i].y1 << endl;
        if (Overlaps[i].data == "C")
            cout << "C" << " " << Overlaps[i].x << " " << Overlaps[i].y << " " << Overlaps[i].y1 << endl;
    }

    for (auto circle : Circles)
        delete circle;
    for (auto rect : Rects)
        delete rect;

    return 0;
}