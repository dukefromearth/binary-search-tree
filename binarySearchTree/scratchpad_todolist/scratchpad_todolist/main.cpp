////
////  main.cpp
////  scratchpad_todolist
////
////  Created by Stephen Duke on 4/1/18.
////  Copyright © 2018 Stephen Duke. All rights reserved.
////
//
#include <iostream>
using namespace std;
//
//
//class Generic{
//protected:
//    string _dueDate;
//    string _description;
//public:
//    void setDueDate(string dueDate) { _dueDate = dueDate; }
//    void setDescription(string description) { _description = description; }
//    virtual string getDueDate() { return _dueDate; }
//    virtual string getDescription() { return _description; }
//  //  virtual string getTime() {return "base";}
//    virtual void setTime(string) {}
//};
//
//class Event : public Generic {
//private:
//    string _location;
//    string _time;
//public:
//    void setLocation(string loc) { _location = loc; }
//    void setTime(string time) { _time = time; }
//    string getLocation() { return _location; }
//    string getTime() { return _time; }
//
//};
//
//int main() {
////    Event n;
////    Generic *n1 = &n;
//    Generic *n1 = new Event;
//    n1->setTime("12:30");
//    cout << n1->getTime() << endl;
//}
//
//



class newClass{
private:

public:
    struct date{
        int _month,_day,_year;
        date() {}
        ~date() {}
        void setMonth(int month) {_month = month;}
        int getMonth() {return _month;}
    };
    date newDate;
};

int main(){
    newClass thisClass;
    thisClass.newDate.setMonth(5);
    cout << thisClass.newDate.getMonth() << endl;

}
