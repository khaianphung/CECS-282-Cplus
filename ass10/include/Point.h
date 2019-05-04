#ifndef Point_h
#define Point_h

class Point
{
    public:
    Point();
    Point(int x, int y);
    //getters
    int getX() const;
    int getY() const;
    //setters
    void setX(int x);
    void setY(int y);
    //print out the result
    void print() const;



    protected:
    int x, y;
};


#endif
