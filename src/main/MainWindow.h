#ifndef MAINWINDOW
#define MAINWINDOW


#include <iostream>
#include <Graph_lib/Graph.h>
#include <Graph_lib/GUI.h>
#include <Graph_lib/Window.h>
#include <vector>
#include "another_part/MyButton.h"
#include "another_part/DayDraw.h"
#include "another_part/DayLogic.h"
#include "another_part/ChangeTaskInfo.h"
#include "another_part/TaskWindow.h"
#include "another_part/PARAMETERS.h"

using namespace Graph_lib;

class WeekWindow : public Graph_lib::Window
{
    public:
        WeekWindow(Point xy, int h, int w);
        std::vector<Button> week_days;
        void years_page();
        void add_years();
        void week_page();
        void back_page();
    private:
        int current_year = 2024;
        std::vector<std::vector<Button*>> years;
        Button Monday;
        Button Tuesday;
        Button Wednesday;
        Button Thursday;
        Button Friday;
        Button Saturday;
        Button Sunday;
        Text current_week;
        Button next;
        Button prev;
        int year_page_counter;
        static void cb_day(Address, Address);
        static void cb_years(Address, Address);
        static void current_year_cb(Address, Address);
        static void cb_add_years(Address, Address);
        static void cb_week_page(Address, Address);
        static void cb_back(Address, Address);
};

#endif //MAINWINDOW