#include <iostream>
#include <vector>

using namespace std;

class horizontal_line
{
public:
    vector<int> x;
    int y;
};

class vertical_line
{
public:
    vector<int> y;
    int x;
};
void east_walk(vector<horizontal_line> &h_data, vector<vertical_line> &v_data, int &x, int &y, int K)
{
    int count = 0;
    for (int i = 0; i < v_data.size(); i++)
        if (x + K >= v_data[i].x && x < v_data[i].x)
            if (y <= v_data[i].y[1] && y >= v_data[i].y[0])
                count++;
    for (int i = 0; i < h_data.size(); i++)
        if (y == h_data[i].y)
        {
            if (x + K >= h_data[i].x[0] && x <= h_data[i].x[0])
                count++;
        }
    if (count == 0)
    {
        horizontal_line temp;
        temp.x.push_back(x);
        temp.x.push_back(x + K);
        temp.y = y;
        h_data.push_back(temp);
        x = x + K;
        cout << x << " " << y << endl;
    }
    else
        cout << "invalid move" << endl;
}

void north_walk(vector<horizontal_line> &h_data, vector<vertical_line> &v_data, int &x, int &y, int K)
{
    int count = 0;
    for (int i = 0; i < h_data.size(); i++)
        if (y + K >= h_data[i].y && y < h_data[i].y)
            if (x <= h_data[i].x[1] && x >= h_data[i].x[0])
                count++;
    for (int i = 0; i < v_data.size(); i++)
        if (x == v_data[i].x)
        {
            if (y + K >= v_data[i].y[0] && y <= v_data[i].y[0])
                count++;
        }
    if (count == 0)
    {
        vertical_line temp;
        temp.y.push_back(y);
        temp.y.push_back(y + K);
        temp.x = x;
        v_data.push_back(temp);
        y = y + K;
        cout << x << " " << y << endl;
    }
    else
        cout << "invalid move" << endl;
}

void west_walk(vector<horizontal_line> &h_data, vector<vertical_line> &v_data, int &x, int &y, int K)
{
    int count = 0;
    for (int i = 0; i < v_data.size(); i++)
        if (x - K <= v_data[i].x && x > v_data[i].x)
            if (y <= v_data[i].y[1] && y >= v_data[i].y[0])
                count++;
    for (int i = 0; i < h_data.size(); i++)
        if (y == h_data[i].y)
        {
            if (x - K <= h_data[i].x[0] && x >= h_data[i].x[1])
                count++;
        }
    if (count == 0)
    {
        horizontal_line temp;
        temp.x.push_back(x - K);
        temp.x.push_back(x);
        temp.y = y;
        h_data.push_back(temp);
        x = x - K;
        cout << x << " " << y << endl;
    }
    else
        cout << "invalid move" << endl;
}

void south_walk(vector<horizontal_line> &h_data, vector<vertical_line> &v_data, int &x, int &y, int K)
{
    int count = 0;
    for (int i = 0; i < h_data.size(); i++)
        if (y - K <= h_data[i].y && y > h_data[i].y)
            if (x >= h_data[i].x[0] && x <= h_data[i].x[1])
                count++;
    for (int i = 0; i < v_data.size(); i++)
    {
        if (x == v_data[i].x)
        {
            if (y - K <= v_data[i].y[0] && y >= v_data[i].y[1])
                count++;
        }
    }
    if (count == 0)
    {
        vertical_line temp;
        temp.y.push_back(y - K);
        temp.y.push_back(y);
        temp.x = x;
        v_data.push_back(temp);
        y = y - K;
        cout << x << " " << y << endl;
    }
    else
        cout << "invalid move" << endl;
}

int main()
{
    int N, K;
    int x = 0, y = 0;
    vector<horizontal_line> h_data;
    vector<vertical_line> v_data;
    int first = 0;
    while (true)
    {
        cin >> N;
        if (N == 0)
        {
            cin >> K;
            if (first == 0)
            {
                vertical_line temp0;
                temp0.y.push_back(0);
                temp0.y.push_back(K);
                temp0.x = 0;
                v_data.push_back(temp0);
                first++;
                y = K;
                cout << x << " " << y << endl;
            }
            else
                north_walk(h_data, v_data, x, y, K);
            continue;
        }
        if (N == 1)
        {
            cin >> K;
            if (first == 0)
            {
                horizontal_line temp1;
                temp1.x.push_back(0);
                temp1.x.push_back(K);
                temp1.y = 0;
                h_data.push_back(temp1);
                first++;
                x = K;
                cout << x << " " << y << endl;
            }
            else
                east_walk(h_data, v_data, x, y, K);
            continue;
        }

        if (N == 2)
        {
            cin >> K;
            if (first == 0)
            {
                vertical_line temp2;
                temp2.y.push_back(-K);
                temp2.y.push_back(0);
                temp2.x = 0;
                v_data.push_back(temp2);
                first++;
                y = -K;
                cout << x << " " << y << endl;
            }
            else
                south_walk(h_data, v_data, x, y, K);
            continue;
        }
        if (N == 3)
        {
            cin >> K;
            if (first == 3)
            {
                horizontal_line temp3;
                temp3.x.push_back(-K);
                temp3.x.push_back(0);
                temp3.y = 0;
                h_data.push_back(temp3);
                first++;
                x = -K;
                cout << x << " " << y << endl;
            }
            else
                west_walk(h_data, v_data, x, y, K);
            continue;
        }
        if (N == -1)
        {
            cin >> K;
            if (K == -1)
                break;
        }
    }
    return 0;
}
