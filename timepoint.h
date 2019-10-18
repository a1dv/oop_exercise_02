#include <iostream>

class TimePoint
{
    public:
        unsigned long long hours;
        unsigned long long min;
        unsigned long long sec;

    bool compare(TimePoint moment, double* answ);

    TimePoint secadding(long long addsec);

    TimePoint secdiff(long long diffsec);

    TimePoint minadding(long long addmin);

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
