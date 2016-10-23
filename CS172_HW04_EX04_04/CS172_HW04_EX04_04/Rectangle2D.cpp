//////////////////////////
// Ian Fisher
// CS 172 HW04 EX04
// 10/12/16
//////////////////////////

#include <iostream>
using namespace std;

class Rectangle2D {
public:
    // data field
    double x;
    double y;
    double width;
    double height;
    
    // get functions for x and y
    double get_x () const {
        return x;
    }
    double get_y () const {
        return y;
    }
    
    // set funtions for x and y
    void set_x (double xset) {
        x = xset;
    }
    void set_y (double yset) {
        y = yset;
    }
    
    // get functions for width and height
    double get_width() const {
        return width;
    }
    double get_height() const {
        return height;
    }
    
    // set functions for width and height
    void set_width (double setWidth) {
        width = setWidth;
    }
    void set_height (double setHeight) {
        height = setHeight;
    }
    
    // no-arg constuctor that sets default values of the rectangle (cordinates are 0,0 and width and height equal 1)
    Rectangle2D () {
        x = 0;
        y = 0;
        width = 1;
        height = 1;
    }
    
    // a constructor that creates a rectangle with specified x, y, width, and height values
    Rectangle2D (double xset, double yset, double setWidth, double setHeight) {
        x = xset;
        y = yset;
        width = setWidth;
        height = setHeight;
    }
    
    // constant function getArea() that returns the area of the rectangle
    double const getArea () {
        return (width * height);
    }
    
    // constant function getPerimeter() that returns the perimeter of the rectangle
    double const getPerimeter () {
        return ((2 * width) + (2 * height));
    }
    
    // constant function contains(double x, double y)
    bool const contains (double cont_x, double cont_y) {
        if (!((cont_x >= (x - (width / 2))) && (cont_x <= (x + (width / 2))))) { // if the given x value is not inside the rectangle (! = not)
            return false;
        }
        if (!((cont_y >= (y - (height / 2))) && (cont_y <= (y + (height / 2))))) { // if the given y value is not inside the rectangle (! = not)
            return false;
        }
        return true;
    }
    
    // constant function...contains(const Rectangle2D &r)
    bool const contains (const Rectangle2D &r) {
        if (!(((r.get_x() - r.get_width()/2) >= (x - (width / 2))) && ((r.get_x() + r.get_width()/2) <= (x + (width / 2))))) { // if the given x value is not inside the rectangle (! = not)
            return false;
        }
        if (!(((r.get_y() - r.get_height()/2) >= (y - (height / 2))) && ((r.get_y() + r.get_height()/2) <= (y + (height / 2))))) { // if the given y value is not inside the rectangle (! = not)
            return false;
        }
        return true;
    }
    
    //constant function overlaps(const Rectangle2D &r)
    
    
    
    
    
};
int main ()
{
    
}
