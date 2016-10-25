//
//  Header.h
//  hahahaha
//
//  Created by Ian J. Fisher on 10/24/16.
//  Copyright © 2016 Ian J. Fisher. All rights reserved.
//

#ifndef Header_h
#define Header_h

#pragma once

#include <string>
using namespace std;

class Course
{
public:
    Course(const string& courseName, int capacity);
    Course(const Course &copy);
    ~Course();
    string getCourseName() const;
    void addStudent(const string& name);
    void dropStudent(const string& name);
    string* getStudents() const;
    int getNumberOfStudents() const;
    void clear();
    
private:
    string courseName;
    string* students;
    int numberOfStudents;
    int capacity;
};

#endif /* Header_h */
