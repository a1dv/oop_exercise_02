#include <iostream>

struct TimePoint
{
    int hours;
    int min;
    int sec;
};

TimePoint operator + (TimePoint first, TimePoint second) {
  first.sec += second.sec;
  first.min += second.min + (first.sec / 60);
  first.hours += second.hours + (first.min / 60);
  first.min = first.min % 60;
  first.sec = first.sec % 60;
  first.hours = first.hours % 24;
  return first;
}

int main()
{
    TimePoint first;
    first.sec = 45;
    first.min = 14;
    first.hours = 23;
    TimePoint second;
    second.sec = 12;
    second.min = 1;
    second.hours = 1;
    first = first + second;
    std::cout << first.sec << " " << first.min << " " << first.hours;
}
