#include <limits.h> // provides UINT_MAX, ULONG_MAX

#include "Stats.hpp"
#include "ListUtils.hpp"



unsigned long total_annual_wages(Employment *emp) {
//#warning "TODO: implement total_annual_wages()"
    Employment * h = emp;
    unsigned long keepTrack = 0;
    for(; h != NULL; h = h->next)
    {
        keepTrack += h->total_annual_wages;
    }
    return keepTrack; 
}


unsigned long min_annual_wages(Employment *emp) 
{
//#warning "TODO: implement min_annual_wages()"
    return emp->total_annual_wages;
}


// Assume that the list has been sorted appropriately
unsigned long med_annual_wages(Employment *emp) 
{
Employment * h = emp;
    //#warning "TODO: implement med_annual_emplvl()"
    int last = list_length(emp);
    int med;
    if(last % 2 != 0)
    {
        med = (last / 2) + 1;
        for(int i = 0; i < (med - 1); i++)
        {
            h = h->next;
        }
        return h->total_annual_wages;
    }
    else if(last % 2 == 0)
    {
        long double med1 = last/2;
        for(int i = 0; i < (med1 - 1); i++)
        {
            h = h->next;
        }
        med1 = h->total_annual_wages;
        h = h->next;
        long double med2 = h->total_annual_wages;
        long double totMed = (med1 + med2)/2;
        return totMed;
    }
    return 0;
}


unsigned long max_annual_wages(Employment *emp) 
{
//#warning "TODO: implement max_annual_wages()"
    while(emp->next != NULL)
    {
        emp = emp->next;
    }
    return emp->total_annual_wages;
}


unsigned total_annual_emplvl(Employment *emp) {
//#warning "TODO: implement total_annual_emplvl()"
int keepTrack = 0;
    while(emp != NULL)
    {
        keepTrack += emp->annual_avg_emplvl;
        emp = emp->next;
    }
    return keepTrack; 
}


unsigned min_annual_emplvl(Employment *emp) 
{
    //#warning "TODO: implement min_annual_emplvl()"
    return emp->annual_avg_emplvl;
}


// Assume that the list has been sorted appropriately
unsigned med_annual_emplvl(Employment *emp) 
{
    Employment * h = emp;
    //#warning "TODO: implement med_annual_emplvl()"
    int last = list_length(emp);
    int med;
    if(last % 2 != 0)
    {
        med = (last / 2) + 1;
        for(int i = 0; i < (med - 1); i++)
        {
            h = h->next;
        }
        return h->annual_avg_emplvl;
    }
    else if(last % 2 == 0)
    {
        int med1 = last/2;
        for(int i = 0; i < (med1 - 1); i++)
        {
            h = h->next;
        }
        med1 = h->annual_avg_emplvl;
        h = h->next;
        double med2 = h->annual_avg_emplvl;
        double totMed = (med1 + med2)/2;
        return totMed;
    }
    return 0;
}


unsigned max_annual_emplvl(Employment *emp) 
{
    //#warning "TODO: implement max_annual_emplvl()"
    while(emp->next != NULL)
    {
        emp = emp->next;
    }
    return emp->annual_avg_emplvl;
}
