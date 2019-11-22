#include <iostream>
#include <cmath>
#include "timepoint.h"
        void TimePoint::secadding(long long addsec)
        {
            this->sec += addsec % 60;
            this->min += (addsec / 60) % 60;
            this->hours += addsec / 3600;
            if (this->sec >= 60) {
                this->sec = this->sec % 60;
                this->min += 1;
            }
            if (this->min >= 60) {
                this->min = this->min % 60;
                this->hours += 1;
            }
            this->hours = this->hours % 24;
        }
        void TimePoint::secdiff(long long diffsec)
        {
            this->sec -= diffsec;
            if (this->sec < 0) {
                this->min -= 1;
                this->min -= diffsec / 60;
                this->sec = this->sec % 60 + 60;
            }
            if (this->min < 0) {
                this->hours -= diffsec / 3600;
                this->min = this->min % 60 + 60;
            }
            this->sec = this->sec % 60;
            this->min = this->min % 60;
            this->hours = abs(this->hours % 24);
        }
        void TimePoint::minadding(long long addmin)
        {
            this->min += addmin % 60;
            this->hours += addmin / 60;
            if (this->min >= 60) {
                this->min = this->min % 60;
                this->hours += 1;
            }
            this->hours = this->hours % 24;
        }
        bool TimePoint::compare(TimePoint moment, double &answ) {
            long long a = this->trans_to_sec();
            long long b = moment.trans_to_sec();
            answ = double(a) / double(b);
            return a > b;
        }
        long long TimePoint::trans_to_sec() {
            this->min = (this->hours * 60) + this->min;
            this->sec = (this->min * 60) + this->sec;
            return this->sec;
        }
        long long TimePoint::trans_to_min() {
            this->min = (this->hours * 60) + this->min;
            if (this->sec >= 30) {
                this->min += 1;
            }
            return this -> min;
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
          first.hours -= second.hours;
          if (first.hours < 0) {
              first.hours += 24;
          }
          first.min -= second.min;
          if (first.min < 0) {
              first.hours -=1;
              first.min += 60;
          }
          first.sec -= second.sec;
          if (first.sec < 0) {
              first.min -= 1;
              first.sec += 60;
          }
          return first;
        }

        bool operator > (TimePoint first, TimePoint second)
        {
            return first.sec + first.min * 60 + first.hours * 3600 > second.sec + second.min * 60 + second.hours * 3600;
        }

        bool operator < (TimePoint first, TimePoint second)
        {
            return first.sec + first.min * 60 + first.hours * 3600 < second.sec + second.min * 60 + second.hours * 3600;;
        }

        bool operator == (TimePoint first, TimePoint second)
        {
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

        out << point.hours << " часов " << point.min << " минут " << point.sec << " секунд\n";

        return out;
    }
