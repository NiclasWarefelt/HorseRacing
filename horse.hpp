#ifndef HORSE_HPP_INCLUDED
#define HORSE_HPP_INCLUDED

class Horse {
public:
    void setId(int id);
    void setTime(int time);
    int getTime();
    int getId();
private:
    int myTime;
    int myId;
};

#endif // HORSE_HPP_INCLUDED
