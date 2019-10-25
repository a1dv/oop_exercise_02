#include <iostream>

class TimePoint
{
    public:
        long long hours;
        long long min;
        long long sec;

    bool compare(TimePoint moment, double* answ);

    void secadding(long long addsec);

    void secdiff(long long diffsec);

    void minadding(long long addmin);

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
