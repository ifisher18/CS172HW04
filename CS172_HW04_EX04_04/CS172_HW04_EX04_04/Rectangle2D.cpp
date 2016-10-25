//////////////////////////
// Ian Fisher
// CS 172 HW04 EX04
// 10/12/16
//////////////////////////

#include <iostream>
using namespace std;

// creates a class called Rectangle2D
class Rectangle2D {
public:
    // data field that declares x, y, width, and height
    double x;
    double y;
    double width;
    double height;
    
    // get function for x
    double get_x () const {
        return x;
    }
    
    // get function for y
    double get_y () const {
        return y;
    }
    
    // set funtion for x
    void set_x (double xset) {
        x = xset;
    }
    
    // set function for y
    void set_y (double yset) {
        y = yset;
    }
    
    // get function for width
    double get_width() const {
        return width;
    }
    
    // get function for height
    double get_height() const {
        return height;
    }
    
    // set function for width
    void set_width (double setWidth) {
        width = setWidth;
    }
    
    // set function for height
    void set_height (double setHeight) {
        height = setHeight;
    }
    
    // no-arg constuctor that sets default values of the rectangle (cordinates are 0,0 and width and height equal 1)
    Rectangle2D () {
        x = 0; // default value of x cordinate is 0
        y = 0; // default value of y cordinate is 0 as well
        width = 1; // default width is 1
        height = 1; // default height is 1
    }
    
    // a constructor that creates a rectangle with specified x, y, width, and height values
    Rectangle2D (double xset, double yset, double setWidth, double setHeight) {
        x = xset; // sets x equal to specified x
        y = yset; // sets y equal to spec. y
        width = setWidth; // sets width equal to setWidth
        height = setHeight; // sets height equal to setHeight
    }
    
    // constant function getArea() that returns the area of the rectangle
    double const getArea () {
        return (width * height); // returns the area based on the calculation that area = width * height
    }
    
    // constant function getPerimeter() that returns the perimeter of the rectangle
    double const getPerimeter () {
        return ((2 * width) + (2 * height)); // returns the perimeter calculation: (width + width) + (height + height)
    }

    // constant function contains(double x, double y)
    // returns true if the specified point (x, y) is inside this rectangle
    bool const contains (double cont_x, double cont_y) {
        if (!((cont_x >= (x - (width / 2))) && (cont_x <= (x + (width / 2))))) { // returns false if the given x value is not inside the rectangle (! = not)
            return false;
        }
        if (!((cont_y >= (y - (height / 2))) && (cont_y <= (y + (height / 2))))) { // if the given y value is not inside the rectangle (! = not)
            return false;
        }
        return true; // if the 'if' statements above are both false, then the function returns true, a.k.a. that the center is within the rectangle
    }
    
    // constant function...contains(const Rectangle2D &r)
    // returns true if the specified rectangle is inside this rectangle
    bool const contains(const Rectangle2D &r) {
        if (!(((r.get_x() - r.get_width()/2) >= (x - (width / 2))) && ((r.get_x() + r.get_width()/2) <= (x + (width / 2))))) { // if the given x value is not inside the rectangle (! = not)
            return false;
        }
        if (!(((r.get_y() - r.get_height()/2) >= (y - (height / 2))) && ((r.get_y() + r.get_height()/2) <= (y + (height / 2))))) { // if the given y value is not inside the rectangle (! = not)
            return false;
        }
        return true;
    }
    
    //constant function overlaps(const Rectangle2D &r)
    // returns true if the specified rectangle overalps with this rectangle
    // returns true if one of the following four statements is true
    bool const overlaps(const Rectangle2D &r) {
        return ((
                    // checks if the top left corner of the rectangle is within the given rectangle
                    contains(r.get_x() - r.get_width()/2, r.get_y() + r.get_height()/2))
                    // checks if the top right corner of the rectangle is within the given rectangle
                || (contains(r.get_x() + r.get_width()/2, r.get_y() + r.get_height()/2))
                    // checks if the bottom left corner of the rectangle is within the given rectangle
                || (contains(r.get_x() - r.get_width()/2, r.get_y() - r.get_height()/2))
                    // checks if the bottom right corner of the rectangle is within the given rectangle
                || (contains(r.get_x() + r.get_width()/2, r.get_y() - r.get_height()/2))
                );
    }
};
int main ()
{
    Rectangle2D r1 = Rectangle2D(2, 2, 5.5, 4.9); // creates a new rectangle r1 with the given parameters
    Rectangle2D r2 = Rectangle2D(4, 5, 10.5, 3.2); // creates a new rectangle r2 with the given parameters
    Rectangle2D r3 = Rectangle2D(3, 5, 2.3, 5.4); // creates a new rectangle r3 with the given parameters
    
    // test program that implements the class
    // cout statements that display to the user what the test program does
    cout << "Test program:" << endl;
    cout << endl;
    cout << "Three Rectangle2D objects:" << endl;
    cout << "1.) r1(2, 2, 5.5, 4.9)" << endl;
    cout << "2.) r2(4, 5, 10.5, 3.2)" << endl;
    cout << "3.) r3(3, 5, 2.3, 5.4)" << endl;
    cout << endl;
    
    // tests the area and parimeter functions
    cout << "The area of r1 is: " << r1.getArea() << endl; // references the getArea function in the class
    cout << "The perimeter of r1 is: " << r1.getPerimeter() << endl; // references the getPerimeter function in the class
    cout << endl;
    
    // tests r1.contain(3, 3)
    cout << r1.contains(3, 3) << endl; // outputs 1 (T) or 0 (F) based on input
    if (r1.contains(3, 3) == true) { // if statement that returns true or false based on whether or not the rectangle contains the point
        cout << "r1 contains the point (3,3)" << endl;
        cout << endl;
    }
    else {
        cout << "r1 does not contain the point (3,3)" << endl;
        cout << endl;
    }
    
    
    // tests r1.contains(r2)
    cout << r1.contains(r2) << endl; // outputs 1 (T) or 0 (F) based on input
    if (r1.contains(r2) == true) { // if statement that returns true or false based on whether or not a rectangle contains another rectangle
        cout << "r1 contains r2." << endl;
        cout << endl;
    }
    else {
        cout << "r1 does not contain r2" << endl;
        cout << endl;
    }
    
    // tests r1.overlaps(r3)
    cout << r1.overlaps(r3) << endl; // outputs 1 (T) or 0 (F) based on input
    if (r1.overlaps(r3) == true) { //
        cout << "r1 overlaps r3" << endl;
        cout << endl;
    }
    else {
        cout << "r1 does not overlap r3" << endl;
        cout << endl;
    }
    return 0;
}
