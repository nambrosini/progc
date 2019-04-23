#ifndef _DATEHANDLING_H_
#define _DATEHANDLING_H_

enum { Jan=1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };

typedef struct {
    int day;
    int month;
    int year;
} Date;

Date const INVALID_DATE = {-1, -1, -1};

Date calculate_next_date(Date date);

#endif // _DATEHANDLING_H_
