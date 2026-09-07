#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include "../headers/DataStructure/Tree/myPriorityQueue.h"

using namespace std;

enum LeftRight
{
    left, right
};

struct Point {
    int x, y;
    LeftRight dir;
    bool operator<(const Point& other) const 
    { 
        if (x != other.x)
        {
            return x < other.x;
        }
        if (dir != other.dir)
        {
            return dir < other.dir;
        }
        if (dir == LeftRight::left)
        {
            return y > other.y;
        }
        else return y < other.y;
    }
    bool operator==(const Point& other) const
    {
        return x == other.x && y == other.y;
    }
    bool operator>(const Point& other) const
    {
        if (x != other.x)
        {
            return x > other.x;
        }
        if (dir != other.dir)
        {
            return dir > other.dir;
        }
        if (dir == LeftRight::left)
        {
            return y < other.y;
        }
        else return y > other.y;
    }
    void PrintPoint()
    {
        cout << "(" << x << " " << y << ")\n";
    }
};

struct Building {
    Point bottomLeft;
    Point topRight;

    void PrintBuilding()
    {
        cout << "(" << bottomLeft.x << " " << bottomLeft.y << ") (" << topRight.x << " " << topRight.y << ")\n";
    }
};

int main()
{
    vector<Point> outline;

    vector<Building> buildings = {
    {{5, 0}, {9, 12}},
    {{14, 0}, {17, 6}},
    {{1, 0}, {5, 10}},
    {{10, 0}, {12, 8}},
    {{7, 0}, {9, 15}},
    {{2, 0}, {7, 15}},
    {{10, 0}, {12, 12}}
    };
    //vector<Building>buildings = { { { 1, 0 }, { 5, 10 } }, { {1, 0}, {5, 10} } };
    vector<Point> PointQueue;
    for (Building b : buildings)
    {
        Point leftPoint = { b.bottomLeft.x, b.topRight.y, LeftRight::left };
        PointQueue.emplace_back(leftPoint);
        Point rightPoint = { b.topRight.x, b.topRight.y, LeftRight::right };
        PointQueue.emplace_back(rightPoint);
    }
    sort(PointQueue.begin(), PointQueue.end());

    myPTQ<int> height(PointQueue.size(), true);
    unordered_map<int, int> lazyDelete;
    int lastHeight = 0;
    int currentHeight = 0;
    height.Enqueue(0);
    
    for (Point p : PointQueue)
    {
        p.PrintPoint();
        if (p.dir == 0)
        {
            height.Enqueue(p.y);
        }
        else
        {
            if (height.Top() == p.y)
            {
                height.Dequeue(lastHeight);
            }
            else
            {
                if (lazyDelete.find(p.y) != lazyDelete.end())
                {
                    lazyDelete[p.y]++;
                }
                else lazyDelete[p.y] = 1;
            }
        }
        while (!height.IsEmpty())
        {
            currentHeight = height.Top();
            if (lazyDelete[currentHeight] > 0)
            {
                lazyDelete[currentHeight]--;
                int temp;
                height.Dequeue(temp);
            }
            else break;
        }

        if (lastHeight != currentHeight)
        {
            Point P1, P2;
            P1.x = p.x;
            P1.y = lastHeight;
            P2.x = p.x;
            P2.y = currentHeight;
            outline.emplace_back(P1);
            outline.emplace_back(P2);
            lastHeight = currentHeight;
        }
    }
    cout << '\n';
    for (Point p : outline)
    {
        p.PrintPoint();
    }
}