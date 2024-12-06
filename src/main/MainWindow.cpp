#include "year.h"


WeekWindow::WeekWindow(Point xy, int h, int w)
    : Window{xy, w, h, "ToDoList"},
    Monday{Point{30,20}, 100, 70, "Monday", cb_day},
    Tuesday{Point{30, 130}, 100, 70, "Tuesday", cb_day},
    Wednesday{Point{30,240}, 100, 70, "Wednesday", cb_day},
    Thursday{Point{140,20}, 100, 70, "Thursday", cb_day},
    Friday{Point{140,130}, 100, 70, "Friday", cb_day},
    Saturday{Point{140,240}, 100, 70, "Saturday", cb_day},
    Sunday{Point{250,20}, 100, 70, "Sunday", cb_day},
    current_week{Point{10,15}, "Week:    Time:   "},
    next{Point{w - 100 , h/2 - 35}, 100, 70, "years", cb_years},
    prev{Point{0 , y_max()-70}, 100, 70, "Back", cb_back},
    year_page_counter{0},
    years{1}
{

    for (int j = 0; j < 3; ++j)
    {
        Button* year = new Button{Point{30, 20 + 110*j}, 100, 70, std::to_string(current_year), current_year_cb};
        years[year_page_counter].push_back(year);
        current_year += 1;
    }
    for (int j = 0; j < 3; ++j)
    {
        Button* year = new Button{Point{140, 20 + 110*j}, 100, 70, std::to_string(current_year), current_year_cb};
        years[year_page_counter].push_back(year);
        current_year += 1;
    }
    for (int j = 0; j < 3; ++j)
    {
        Button* year = new Button{Point{250, 20 + 110*j}, 100, 70, std::to_string(current_year), current_year_cb};
        years[year_page_counter].push_back(year);
        current_year += 1;
    }

    attach(Monday);
    attach(Tuesday);
    attach(Wednesday);
    attach(Thursday);
    attach(Friday);
    attach(Saturday);
    attach(Sunday);
    attach(current_week);
    attach(next);
};

void WeekWindow::cb_years(Address, Address years)
{
    auto& cy = Graph_lib::reference_to<Button>(years);
    dynamic_cast<WeekWindow&>(cy.window()).years_page();
}

void WeekWindow::cb_add_years(Address, Address add)
{
    auto& ca = Graph_lib::reference_to<Button>(add);
    dynamic_cast<WeekWindow&>(ca.window()).add_years();
}

void WeekWindow::cb_week_page(Address, Address week)
{
    auto& we = Graph_lib::reference_to<Button>(week);
    dynamic_cast<WeekWindow&>(we.window()).week_page();
}

void WeekWindow::cb_back(Address, Address back)
{
    auto& ba = Graph_lib::reference_to<Button>(back);
    dynamic_cast<WeekWindow&>(ba.window()).back_page();
}

void WeekWindow::current_year_cb(Address, Address pw)
{
    auto& btn = Graph_lib::reference_to<Button>(pw);
    Year* year_window = new Year(&btn, &reinterpret_cast<WeekWindow&>(btn.window()));
    dynamic_cast<WeekWindow&>(btn.window()).hide();
}

void WeekWindow::cb_day(Address, Address pw)
{
    auto& btn = Graph_lib::reference_to<MyButton>(pw);
    std::string s1 = "01:21";
    std::string s2 = "011";
    Task t1(s1, s2);
    // Task t2("02:21", "Details about the task");
    // Task t3("03:21", "Details about the task");
    Day day;
    day.addTask(&t1);
    // day.addTask(t2);
    // day.addTask(t3);
    DayWindow* day_window = new DayWindow(day, 700, 600);
}

void WeekWindow::week_page()
{
    for (size_t i = 0; i < years[year_page_counter].size(); ++i)
    {
        detach(*years[year_page_counter][i]);
    }
    if (year_page_counter != 0)
    {
        detach(prev);
    }

    year_page_counter = 0;

    attach(Monday);
    attach(Tuesday);
    attach(Wednesday);
    attach(Thursday);
    attach(Friday);
    attach(Saturday);
    attach(Sunday);
    attach(current_week);
    attach(next);

    redraw();
}

void WeekWindow::add_years()
{
    if (year_page_counter == 0)
    {
        attach(prev);
    }
    for (size_t i = 0; i < years[year_page_counter].size(); ++i)
    {
        detach(*years[year_page_counter][i]);                  
    }
    year_page_counter += 1;

    if (year_page_counter < years.size())
    {
        for (size_t i = 0; i < years[year_page_counter].size(); ++i)
        {
            attach(*years[year_page_counter][i]);                  
        }
        redraw();  
    }
    else
    {
        years.resize(year_page_counter + 1);

        for (int j = 0; j < 3; ++j)
        {
            Button* year = new Button{Point{30, 20 + 110*j}, 100, 70, std::to_string(current_year), current_year_cb};
            years[year_page_counter].push_back(year);
            current_year += 1;
        }
        for (int j = 0; j < 3; ++j)
        {
            Button* year = new Button{Point{140, 20 + 110*j}, 100, 70, std::to_string(current_year), current_year_cb};
            years[year_page_counter].push_back(year);
            current_year += 1;
        }
        for (int j = 0; j < 3; ++j)
        {
            Button* year = new Button{Point{250, 20 + 110*j}, 100, 70, std::to_string(current_year), current_year_cb};
            years[year_page_counter].push_back(year);
            current_year += 1;
        }
        for (size_t i = 0; i < years[year_page_counter].size(); ++i)
        {
            attach(*years[year_page_counter][i]);                  
        }
        redraw();
    }
}

void WeekWindow::back_page()
{
    for (size_t i = 0; i < years[year_page_counter].size(); ++i)
    {
        detach(*years[year_page_counter][i]);                  
    }
    if (year_page_counter == 1)
    {
        year_page_counter -= 1;
        for (size_t i = 0; i < years[year_page_counter].size(); ++i)
        {
            attach(*years[year_page_counter][i]); 
        }
        detach(prev);
        redraw();
    }
    else
    {
        year_page_counter -= 1;
        for (size_t i = 0; i < years[year_page_counter].size(); ++i)
        {
            attach(*years[year_page_counter][i]); 
        }
        redraw();
    }
}

void WeekWindow::years_page()
{
    detach(Monday);
    detach(Tuesday);
    detach(Wednesday);
    detach(Thursday);
    detach(Friday);
    detach(Saturday);
    detach(Sunday);
    detach(current_week);
    detach(next);

    static Button more_years = Button{Point{x_max() - 100 , y_max()/2 - 35}, 100, 70, "Next", cb_add_years};
    static Button week_page = Button{Point{x_max() - 100 , y_max()-70}, 100, 70, "Week page", cb_week_page};
    attach(more_years);
    attach(week_page);             

    for (size_t i = 0; i < years[year_page_counter].size(); ++i)                
    {
        attach(*years[year_page_counter][i]);
    }

    redraw();
}
