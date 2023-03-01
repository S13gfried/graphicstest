#include "headers/geometry.h"
#include <iostream>

void printShape(const shape2f& shape) //shape2f shape
{
    std::vector<vector2f> vertices = shape.getVertices();
    for(int i = 0; i < (int)vertices.size(); i++)
        std::cout << "#" << i << ": " << vertices[i].x << ", " << vertices[i].y << "\n";
    std::cout << std::endl;
}

vector2f inputVector2f()
{
    vector2f target = vector2f(0.0, 0.0); //todo: make default constructor
    std::cin >> target.x;
    std::cin >> target.y;
    return target;
}

int main()
{
    int vertexNo;
    
    //triangle
    std::cout << "Enter triangle vertices:" << std::endl;
    triangle sample = triangle({inputVector2f(), inputVector2f(), inputVector2f()});

    printShape(sample);

    //resize

    std::cin >> vertexNo;

    std::cout << "setVertex (i, vec2):" << std::endl;
    sample.setVertex(vertexNo, inputVector2f());

    std::cout << "Changed:" << std::endl;

    printShape(sample);
    
    //rectangle
    std::cout << "RECTANGLE:" << std::endl;

    rectangleP Rsample = rectangleP(inputVector2f(), inputVector2f());

    printShape(Rsample);
    // resize (x2)

    std::cout << "setVertex (i, vec2):" << std::endl;
    std::cin >> vertexNo;
    Rsample.setVertex(vertexNo, inputVector2f());

    printShape(Rsample);

    std::cout << "setVertex (i, vec2):" << std::endl;
    std::cin >> vertexNo;
    Rsample.setVertex(vertexNo, inputVector2f());

    printShape(Rsample);

    //subdivide
    std::cout << "Subdivision 1:" << std::endl;

    std::vector<triangle> subdivision = Rsample.subdivideTriangles(rectangleP::TRBL);

    printShape(subdivision[0]);
    printShape(subdivision[1]);

    std::cout << "Subdivision 2:" << std::endl;

    subdivision = Rsample.subdivideTriangles(rectangleP::TLBR);

    printShape(subdivision[0]);
    printShape(subdivision[1]);

    return 0;
}