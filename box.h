#include <bits/stdc++.h>
using namespace std;

class MBR{
    public:
    double X_low;
    double X_high;
    double Y_low;
    double Y_high;

    MBR(double x1,double y1,double x2,double y2): X_low(x1),Y_low(y1),X_high(x2),Y_high(y2) {}

    void expand(const pair<double,double> p){
        X_low = min(X_low ,p.first);
        X_high = max(X_high ,p.first);
        Y_low = min(Y_low ,p.second);
        Y_high = max(Y_high ,p.second);
    }

    bool overlap(const MBR& other) const{
        return !(X_low > other.X_low || X_high < other.X_high || Y_low > other.Y_low || Y_high < other.Y_high);
    }

    bool contain(const MBR& other) const{
        return (X_low < other.X_low && X_high > other.X_high && Y_low < other.Y_low && Y_high > other.Y_high);
    }

    double area() const{
        return ((X_high - X_low) * (Y_high - Y_low));
    }
};