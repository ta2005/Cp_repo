#include <bits/stdc++.h> 

using namespace std; 

struct rect{
    int x1,y1,x2,y2;
    int area(){
	return (x2-x1)*(y2-y1);
    }
};

int main() {
    rect a,b,c,d;
    cin>>a.x1>>a.y1>>a.x2>>a.y2;
    cin>>b.x1>>b.y1>>b.x2>>b.y2;
    cin>>c.x1>>c.y1>>c.x2>>c.y2;
    int comb=a.area()+b.area();
}
