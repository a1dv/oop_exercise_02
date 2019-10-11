#include <iostream>

class TimePoint
{
    public:
        unsigned long long hours;
        unsigned long long min;
        unsigned long long sec;

        TimePoint summaring(TimePoint second);

        TimePoint difference(TimePoint second);

        TimePoint secadding(unsigned long long addsec);

        TimePoint minadding(unsigned long long addmin);

        long long trans_to_sec();

        long long trans_to_min();

};
TimePoint operator + (TimePoint first, TimePoint second);
TimePoint operator - (TimePoint first, TimePoint second);
std::istream& operator>> (std::istream &npt, TimePoint &point);
std::ostream& operator<< (std::ostream &out, TimePoint &point);
bool operator > (TimePoint first, TimePoint second);
bool operator < (TimePoint first, TimePoint second);
bool operator == (TimePoint first, TimePoint second);
unsigned long long operator "" _mult(unsigned long long npt);
