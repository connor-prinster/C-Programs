#include "ListUtils.hpp"

#include <iostream>
#include <fstream>

using namespace std;

Employment* build_empl_list(std::string filename) 
{
    Employment * head = NULL;
    Employment * list = NULL;
    
    ifstream fin;
    fin.open(filename);
    string dummyLine;
    getline(fin, dummyLine);
    
    std::string read_area_fips;
    unsigned read_annual_avg_emplvl;
    long unsigned read_total_annual_wages;
    
    while(fin >> read_area_fips >> read_annual_avg_emplvl >> read_total_annual_wages)
    {
        Employment * tail = new Employment(read_area_fips, read_annual_avg_emplvl, read_total_annual_wages);
        if(list == NULL)
        {
            list = tail;
            head = list;
        }
        else
        {
            list->next = tail;
            list = list->next;
        }
    }
    return head;
}


void append_lists(Employment* head, Employment* tail) 
{
    //#warning "TODO: implement append_lists()
    Employment * h = head;
    
    if(head == NULL)
    {
        head = tail;
        return;
    }
    
    for(; h->next != NULL; h = h->next);
    
    h->next = tail;
}


int list_length(Employment *emp) 
{
    Employment * h = emp;
    int counter = 0;
    while(h != NULL)
    {
        h = h->next;
        counter++;
    }
    return counter;
}


void print_every_empl(Employment *emp) 
{
    for(; emp != NULL; emp = emp->next)
        std::cout << *emp << std::endl;
}

void cleanup_list(Employment * emp)
{
    while(emp != NULL)
    {
        Employment * temp = emp->next;  //make sure you use the ->next before you lose the address for it
        delete emp; //free up the memory by deleting emp
        emp = temp; //emp now equals emp->next for the next time we kill it.
    }
}