#include <iostream>
#include <cmath>
#include "timepoint.h"

        TimePoint TimePoint::secadding(unsigned long long addsec)
        {
            this->hours = 0, this->min = 0, this->sec = 0;
            this->sec = addsec % 60;
            this->min = (addsec / 60) % 60;
            this->hours = addsec / 3600;
        }
        TimePoint TimePoint::minadding(unsigned long long addmin)
        {
            this->hours = 0, this->min = 0, this->sec = 0;
            if ((addmin / 60) > 1) {
                this->min = addmin % 60;
                this->hours = addmin / 60;
            }
            else {
                this->sec = addmin;
            }
        }
        long long TimePoint::trans_to_sec() {
            this->min = this->hours + this->min;
            this->sec = this->min * 60 + this->sec;
        }
        long long TimePoint::trans_to_min() {
            this->min = this->hours * 60 + this->min;
            if (this->sec >= 30) {
                this->min += 1;
            }
        }
        TimePoint operator + (TimePoint first, TimePoint second) {
          first.sec += second.sec;
          first.min += second.min + (first.sec / 60);
          first.hours += second.hours + (first.min / 60);
          first.min = first.min % 60;
          first.sec = first.sec % 60;
          first.hours = first.hours % 24;
          return first;
        }

        TimePoint operator - (TimePoint first, TimePoint second)
        {
            first.sec -= second.sec;
            if (first.sec < 0) {
                first.min -= 1;
                first.sec += 60;
            }
            first.min -= second.min;
            if (first.min < 0) {
                first.hours -= 1;
                first.min += 60;
            }
            first.hours -= second.hours;
            first.hours = abs(first.hours);
            return first;
        }

        bool operator > (TimePoint first, TimePoint second)
        {
            unsigned long long a, b;
            return first.sec + first.min * 60 + first.hours * 3600 > second.sec + second.min * 60 + second.hours * 3600;
        }

        bool operator < (TimePoint first, TimePoint second)
        {
            unsigned long long a, b;
            return first.sec + first.min * 60 + first.hours * 3600 < second.sec + second.min * 60 + second.hours * 3600;;
        }

        bool operator == (TimePoint first, TimePoint second)
        {
            unsigned long long a, b;
            return first.sec + first.min * 60 + first.hours * 3600 == second.sec + second.min * 60 + second.hours * 3600;
        }
        unsigned long long operator "" _mult(unsigned long long npt)
        {
            return npt*60;
        }

    std::istream& operator>> (std::istream &npt, TimePoint &point)
    {
        char tmp;
        npt >> point.hours;
        npt >> tmp;
        npt >> point.min;
        npt >> tmp;
        npt >> point.sec;
        return npt;
    }

    std::ostream& operator<< (std::ostream &out, TimePoint &point)
    {

        out << point.hours << " часов " << point.min << " минут " << point.sec << " секунд ";

        return out;
    }
