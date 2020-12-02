///////////////////////////////////// Created by Mingxuan Lu ///////////////////////////////////
#include <iostream>
#include <algorithm>
#include <stack>
#include <stdlib.h>
#include <vector>
#include "sort.hpp"
using namespace std;

struct Point{
    int x, y;
};

// A reference point for sorting porints in comparison
Point p0;

// Find next to top in a stack
Point next_to_top(stack<Point> &s1){
    Point p = s1.top();
    s1.pop();
    Point next = s1.top();
    s1.push(p);
    return next;
}

// Swap two points
void swap_Points(Point &p1, Point &p2){
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

// Return distance between two points
int dist(Point p1, Point p2){
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

// Find orientation of ordered triplet (p1,p2,p3)
// return value:
// 0 for colinear
// 1 for clockwise
// 2 for counterclockwise
int ccw(Point p1, Point p2, Point p3){
    int val = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);
    if(val == 0) return 0;
    else if(val > 0) return 1;
    else return 2;
}

// The function used by qsort()
int cmp(const void *vp1, const void *vp2){
    Point *p1 = (Point *)vp1;
    Point *p2 = (Point *)vp2;

    int ori = ccw(p0, *p1, *p2);
    if(ori == 0){
        if(dist(p0, *p2) >= dist(p0, *p1)) return -1;
        else return 1;
    }
    else if(ori == 2) return -1;
    else return 1;
}

// Funtion to get the convex hull
void convexHull(Point points[], int n){
    // Find the point at the bottom
    int ymin = points[0].y, min = 0;

    for(int i = 1; i < n; i++){
        int y = points[i].y;

        // Choose the bottom or most left point in case of a tie
        if((y < ymin) || (ymin == y && points[i].x < points[min].x)) ymin = points[i].y, min = i;
    }

    // Place the bottom-most point at first position
    swap_Points(points[0], points[min]);

    // Sort n-1 points with respect to the first position based on polar angle
    p0 = points[0];
    qsort(&points[1], n-1, sizeof(Point), cmp);

    // If several points have the same angle with p0,
    // only keep the one farthest from p0
    int m = 1;
    for(int i = 1; i < n; i++){
        // Keep removing ith point if angle of i and i+1 is the same
        while(i < n - 1 && ccw(p0, points[i], points[i+1]) == 0) i++;
        points[m] = points[i];
        m++;
    }

    // If modified array of points has less than 3 points, convex hull is impossible
    if(m == 0) return;
    else if(m == 1){
        int xout = points[0].x;
        int yout = points[0].y;
        cout << xout << " " << yout << endl;
        return;
    }
    else if(m == 2){
        int xout = points[0].x;
        int yout = points[0].y;
        cout << xout << " " << yout << endl;
        
        xout = points[1].x;
        yout = points[1].y;
        if(xout == points[0].x && yout == points[0].y) return;
        else cout << xout << " " << yout << endl;
        return;
    }

    // Create an empty stack and push first three points into it
    stack<Point> s;
    s.push(points[0]);
    s.push(points[1]);
    s.push(points[2]);

    // Deal with the rest n-3 points
    for(int i = 3; i < m; i++){
        // Keep removing top point while the angle made by points next to top, top and points[i] is a non-left turn
        while(ccw(next_to_top(s), s.top(), points[i]) != 2) s.pop();
        s.push(points[i]);
    }

    // Done, print the output
    stack<Point> sout;
    while(!s.empty()){
        Point p = s.top();
        sout.push(p);
        s.pop();
    }
    while(!sout.empty()){
        Point pout = sout.top();
        int xout = pout.x;
        int yout = pout.y;
        cout << xout << " " << yout << endl;
        sout.pop();
    }
}

// Deiver program
int main()
{
    int num;
    cin >> num;
    if(num == 0) return 0;
    Point *points = new Point[num];

    for(int i = 0; i < num; i++){
        int xin;
        int yin;
        cin >> xin;
        cin >> yin;
        points[i].x = xin;
        points[i].y = yin;
    }

    convexHull(points, num);
    delete[] points;
    return 0;
}

