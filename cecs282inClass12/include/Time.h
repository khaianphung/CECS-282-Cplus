#ifndef TIME_H
#define TIME_H


class Time
{
    protected:
        int hour, min, sec;
public:

    //constructor
    Time( int h, int m, int s );
    //print out the time
    void printTime();
};

#endif // TIME_H
