#include <cmath>
#include "tgaimage.h"

constexpr TGAColor white = { 255, 255, 255, 255 }; // attention, BGRA order
constexpr TGAColor green = { 0, 255,   0, 255 };
constexpr TGAColor red = { 0,   0, 255, 255 };
constexpr TGAColor blue = { 255, 128,  64, 255 };
constexpr TGAColor yellow = { 0, 200, 255, 255 };



struct point
{
    int x{ 0 }, y{ 0 };
    point(int xIn, int yIn) : x{ xIn }, y{ yIn } {};
};
void line(const point &pointOne, const point &pointTwo, TGAImage &frameBuffer,const TGAColor Color)
{   
    //create the point for each dot on the line
    for (float t = 0.0; t < 1; t += .01)
    {
        int tx = std::round(pointOne.x + t * (pointTwo.x - pointOne.x));
        int ty = std::round(pointOne.y + t * (pointTwo.y - pointOne.y));
        frameBuffer.set(tx, ty, Color);
    };
}
int main(int argc, char** argv) {
    //set image size
    constexpr int width = 64, height = 64;
    TGAImage framebuffer(width, height, TGAImage::RGB);

    //set the postion values for x and y
    int ax =  7, ay = 3, 
        bx = 12, by = 37,  
        cx = 62, cy = 53;

    //set points
    point PointOne(ax, ay);
    point PointTwo(bx, by);
    point PointThree(cx, cy);

    //create lines from points
    line(PointOne, PointTwo, framebuffer, red);            
    line(PointTwo, PointThree, framebuffer, green);         
    line(PointThree, PointOne, framebuffer, blue);  

    //set point origin to white
    framebuffer.set(ax, ay, white);         
    framebuffer.set(bx, by, white);
    framebuffer.set(cx, cy, white);

    framebuffer.write_tga_file("framebufferLinePercent01.tga");
    return 0;
}