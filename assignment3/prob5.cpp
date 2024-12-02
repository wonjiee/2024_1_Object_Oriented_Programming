#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class horizontal{
public:
    vector<int>x;
    int y;
};

class vertical{
public:
    int x;
    vector<int>y;
};

void intersect(vector<horizontal>h_data,vector<vertical>v_data,vector<int>&x,vector<int>&y){
    for(int i=0;i<h_data.size();i++){
        for(int j=0;j<v_data.size();j++)
            if (h_data[i].x[0]<=v_data[j].x&&h_data[i].x[1]>=v_data[j].x)
                if (h_data[i].y<=v_data[j].y[1]&&h_data[i].y>=v_data[j].y[0]){
                    x.push_back(v_data[j].x);
                    y.push_back(h_data[i].y);
                }
    }
}

void sortCoordinate(vector<int>&x,vector<int>&y){
    for(int i=0;i<x.size();i++)
        for(int j=i+1;j<x.size();j++){
            if(x[i]>x[j]){
                swap(x[i],x[j]);
                swap(y[i],y[j]);
                continue;
            }
            if (x[i]==x[j]){
                if(y[i]>y[j]){
                    swap(x[i],x[j]);
                    swap(y[i],y[j]);
                }
            }
        }
}

int main() {
    int N,k;
    vector<horizontal>h_data;
    vector<vertical>v_data;
    vector<int>data;
    vector<int>x;
    vector<int>y;
    cin>>N;
    for(int i=0;i<N;i++){
        horizontal temp0;
        vertical temp1;
        data.clear();
        for(int j=0;j<4;j++){
            cin>>k;
            data.push_back(k);
        }
        if(data[0]==data[2]){
            temp1.x=data[0];
            temp1.y.push_back(data[1]);
            temp1.y.push_back(data[3]);
            v_data.push_back(temp1);
        }
        if(data[1]==data[3]){
            temp0.y=data[1];
            temp0.x.push_back(data[0]);
            temp0.x.push_back(data[2]);
            h_data.push_back(temp0);
        }
    }
    intersect(h_data,v_data,x,y);
    sortCoordinate(x, y);
    for(int i=0;i<x.size();i++)
        cout<<"["<<x[i]<<", "<<y[i]<<"]"<<endl;
    
    return 0;
}
