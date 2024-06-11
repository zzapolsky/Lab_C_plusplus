#include <graphics.h>
#include <cstdlib>
#include <ctime>

// Класс Point
class Point {
protected:
    int X, Y;
    int Color;
public:
    Point(int XN = 0, int YN = 0, int color = WHITE) : X(XN), Y(YN), Color(color) {}
    virtual void Show() {
        setcolor(Color);
        circle(X, Y, 5);
    }
    virtual void Hide() {
        setcolor(getbkcolor());
        circle(X, Y, 5);
    }
    virtual void Move(int offsetX, int offsetY) {
        X += offsetX;
        Y += offsetY;
    }
};


class Krug : public Point {
private:
    int Radius;
public:
    Krug(int XN = 0, int YN = 0, int R = 50, int color = WHITE) : Point(XN, YN, color), Radius(R) {}
    void Show() override {
        setcolor(Color);
        setfillstyle(SOLID_FILL, Color);
        pieslice(X, Y, 0, 360, Radius);
    }
    void Hide() override {
        setcolor(getbkcolor());
        setfillstyle(SOLID_FILL, getbkcolor());
        pieslice(X, Y, 0, 360, Radius);
    }
};


class Ring : public Krug {
private:
    int Width;
public:
    Ring(int XN = 0, int YN = 0, int outerRadius = 50, int innerRadius = 40, int color = WHITE)
        : Krug(XN, YN, outerRadius, color), Width(outerRadius - innerRadius) {}
    void Show() override {
        Krug::Show();
        setfillstyle(SOLID_FILL, getbkcolor());
        pieslice(X, Y, 0, 360, Radius - Width);
    }
};

int main() {
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "");

    srand(static_cast<unsigned>(time(0)));

    Krug krug(150, 150, 50, GREEN);
    Ring ring(450, 150, 50, 40, RED);

    krug.Show();
    ring.Show();

    for (int i = 0; i < 10; ++i) {
        delay(300);
        krug.Hide();
        ring.Hide();
        krug.Move((rand() % 21) - 10, (rand() % 21) - 10);
        ring.Move((rand() % 21) - 10, (rand() % 21) - 10);
        krug.Show();
        ring.Show();
    }

    getch();
    closegraph();
    return 0;
}
