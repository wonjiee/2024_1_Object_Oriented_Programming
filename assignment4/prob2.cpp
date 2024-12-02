#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

class Circle;

class Rect{
    friend class Circle;
private:
    int xm, xM;
    int ym, yM;

public:
    Rect() = default;
    Rect(int xm, int xM, int ym, int yM) : xm(xm), xM(xM), ym(ym), yM(yM) {}
    Rect findMaxMin(vector<Rect>&Rects){
        int tmpxM=Rects[0].xM;
        int tmpxm=Rects[0].xm;
        int tmpyM=Rects[0].yM;
        int tmpym=Rects[0].ym;
        Rect tmp;
        for(int i=0;i<Rects.size();i++){
            if (tmpxM<Rects[i].xM)
                tmpxM=Rects[i].xM;
            if(tmpyM<Rects[i].yM)
                tmpyM=Rects[i].yM;
            if (tmpxm>Rects[i].xm)
                tmpxm=Rects[i].xm;
            if (tmpym>Rects[i].ym)
                tmpym=Rects[i].ym;
        }
        return tmp=Rect(tmpxm,tmpxM,tmpym,tmpyM);
    }
    void findsmallCircle(Rect Maxmin){
        double centerX = (Maxmin.xm + Maxmin.xM) / 2.0;
        double centerY = (Maxmin.ym + Maxmin.yM) / 2.0;
        double radius = sqrt(pow(Maxmin.xM-centerX,2)+pow(Maxmin.yM-centerY,2));
        cout<<centerX<<" "<<centerY<<" "<<radius;
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

void makelist(string filename, vector<Rect>& Rects) {
    ifstream theFile(filename);
    Rect tmp;
    string line;
    while (getline(theFile, line)) {
        vector<string> coord = split_line(line, ' ');
        if (coord.size() > 1) {
            tmp = Rect(stoi(coord[0]),stoi(coord[1]), stoi(coord[2]), stoi(coord[3]));
            Rects.push_back(tmp);
        }
    }
}

int main(){
    vector<Rect>Rects;
    Rect tmp;
    makelist("input2.txt",Rects);
    Rect Maxmin;
    Maxmin=Maxmin.findMaxMin(Rects);
    tmp.findsmallCircle(Maxmin);
    return 0;
}