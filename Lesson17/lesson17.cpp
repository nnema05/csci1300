
#include <iostream>
#include "picture.h" // this contains function prototypes for image manipulation

using namespace std;

int main() {
    Picture pic("queen-mary.png"); // creating a variable of type Picture called pic
    // every pixel has (red, green, blue) values that have the range 0-255
    // we can loop over every pixel in the image and change it
    // width is the width of the image 
    // height is the height of the image 
    // (x, y) as the width and height position of the pixel
    // each (x, y) pixel has three properties, red, green, and blue
    // value of red, green and blue is between 0- 255 
    for (int x = 0; x < pic.width(); x++) {
        for (int y = 0; y < pic.height(); y++) {
            // remove red from the picture
            int green = pic.green(x, y); // returns the green vslue for the (x, y) pixel
            int blue = pic.blue(x,y); // return the blue value for (x, y) pixel
            pic.set(x, y, 0, green, blue);
        }
    }

    pic.save("no-red.png");
    // TO RUN!
    // g++ lesson17.cpp picture.cpp lodepng.cpp -o lesson17

    // can you draw a horitontal black line acorss the image that is 10 pixels wide
    Picture pic2("queen-mary.png");
    for (int x = 0; x < pic.width(); x++) { // every horizontal pixel
        for (int y = 50; y < 60; y++) { // height between 50 and 60 
            pic2.set(x, y, 0, 0, 0); // remove color
        }
    }
    pic2.save("black-stripe.png");

    

}