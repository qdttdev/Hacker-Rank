#include <iostream>

using namespace std;
/*
 * Create classes Rectangle and RectangleArea
 */

class Rectangle
{
    private:
    public:
        double w;
        double h;
        
        void display()
        {
            cout << w << " " << h;
        }
};

class RectangleArea : public Rectangle
{
    public:
        void read_input()
        {
            cin >> w >> h;
        }

        void display()
        {
            cout << endl << w*h;
        }
};



int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;
    
    /*
     * Read the width and height
     */
    r_area.read_input();
    
    /*
     * Print the width and height
     */
    r_area.Rectangle::display();
    
    /*
     * Print the area
     */
    r_area.display();
    
    return 0;
}