#include "geometry.h"
#include <iostream>

void printShape(shape2f shape)
{
    std::vector<vector2f> vertices = shape.getVertices();
    for(int i = 0; i < vertices.size(); i++)
        std::cout << "#" << i << ": " << vertices[i].x << ", " << vertices[i].y << "\n";
    std::cout << std::endl;
}


int main()
{
    return 0;
}
int main()
{
    return 0;
}