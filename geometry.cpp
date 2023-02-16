#include "geometry.h"

//shape2f::shape2f() {}
//shape2f::~shape2f() {}

//Vector2 generator

vector2f::vector2f(float newX = 0.0, float newY = 0.0) 
  {
     x = newX, y = newY; 
  }

//Generic triangle class

triangle::triangle(std::vector<vector2f> newVertices = {{0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0}}) {
    if (newVertices.size() < 3)
      throw std::invalid_argument("Not enough vertices");
    if (newVertices.size() > 3)
      throw std::invalid_argument("Too many vertices");

    vertices = newVertices;
  }
bool triangle::setVertex(int index, vector2f value) 
  {
    if (index < 0)
      throw std::invalid_argument("Negative index is not supported");
    if (index > 2)
      throw std::invalid_argument("Index out of range");

    vertices[index] = value;
    return 1;
  }
std::vector<vector2f> triangle::getVertices() const 
  { 
    return vertices; 
  }
bool triangle::nonDegenerate() const  // Check whether
  {
    vector2f referencePoint = vertices[0];

    vector2f delta1 = vector2f(
        vertices[1].x - referencePoint.x,
        vertices[1].y - referencePoint.y);  // REFACTOR W/ OVERLOADING!!!

    vector2f delta2 = vector2f(vertices[2].x - referencePoint.x,
                               vertices[2].y - referencePoint.y);

    return !(delta1.x / delta2.x == delta1.y / delta2.y);
  }


//rectangleP - generic rectangle with sides parallel to world axes

rectangleP::rectangleP(vector2f topleft, vector2f bottomright) //possibly make it into a vector
    {
        vertices = std::vector<vector2f>(4);

        vertices[TOPLEFT] = topleft;
        vertices[TOPRIGHT] = vector2f(bottomright.x, topleft.y);
        vertices[BOTTOMRIGHT] = bottomright;
        vertices[BOTTOMLEFT] = vector2f(topleft.x, bottomright.y);
        
        rearrangeRelativePositions();
    }
bool rectangleP::setVertex(int index, vector2f newvertex) //reposition the stated vertex.
    {
        if (index < 0)
            throw std::invalid_argument("Negative index is not supported");
        if (index > 3)
            throw std::invalid_argument("Index out of range");

        switch (index)
        {
        case TOPLEFT:
            vertices[TOPLEFT] = newvertex;
            vertices[TOPRIGHT].y = newvertex.y;
            vertices[BOTTOMLEFT].x = newvertex.x;
            break;
        case TOPRIGHT:
            vertices[TOPRIGHT] = newvertex;
            vertices[TOPLEFT].y = newvertex.y;
            vertices[BOTTOMRIGHT].x = newvertex.x;
            break;
        case BOTTOMRIGHT:
            vertices[BOTTOMRIGHT] = newvertex;
            vertices[BOTTOMLEFT].y = newvertex.y;
            vertices[TOPRIGHT].x = newvertex.x;
            break;
        case BOTTOMLEFT:
            vertices[BOTTOMLEFT] = newvertex;
            vertices[BOTTOMRIGHT].y = newvertex.y;
            vertices[TOPLEFT].x = newvertex.x;
        }
        return rearrangeRelativePositions(); //if the rectangle is flipped, restore the correct order of indices.
    }
std::vector<vector2f> rectangleP::getVertices() const
    {
        return vertices;
    }
void rectangleP::swapVertices(int index1, int index2)
    {
        if (index1 < 0)
            throw std::invalid_argument("Negative index 1 is not supported");
        if (index1 > 3)
            throw std::invalid_argument("Index 1 out of range");

        if (index2 < 0)
            throw std::invalid_argument("Negative index 2 is not supported");
        if (index2 > 3)
            throw std::invalid_argument("Index 2 out of range");
        if (index1 == index2)
            return;

        vector2f buffer = vertices[index1];
        vertices[index1] = vertices[index2];
        vertices[index2] = buffer;
    }
bool rectangleP::rearrangeRelativePositions() //Compensate for "flips" happening after altering vertices. return 1 if there were any.
    {
        bool result = 0;
        for(int iteration = 0; iteration < 2; iteration++)
        {
            if(vertices[TOPLEFT].x > vertices[TOPRIGHT].x)
                swapVertices(TOPLEFT, TOPRIGHT), result = 1;
            if(vertices[BOTTOMLEFT].x > vertices[BOTTOMRIGHT].x)
                swapVertices(BOTTOMLEFT, BOTTOMRIGHT), result = 1;
            if(vertices[TOPLEFT].y < vertices[BOTTOMLEFT].y)
                swapVertices(TOPLEFT, BOTTOMLEFT), result = 1;
            if(vertices[TOPRIGHT].y < vertices[BOTTOMRIGHT].y)
                swapVertices(TOPRIGHT, BOTTOMRIGHT), result = 1;
        }
        return result;
    }
bool rectangleP::nonDegenerate() const 
    {
        //rearrangeRelativePositions();
        return (vertices[TOPRIGHT].x != vertices[TOPLEFT].x) && (vertices[TOPRIGHT].y != vertices[BOTTOMRIGHT].y);
    }
std::vector<triangle> rectangleP::subdivideTriangles(int diagonal = TLBR) const
    {     
        std::vector<triangle> division;

        if(diagonal == TRBL)
        {
            division.push_back(triangle({vertices[TOPLEFT], vertices[TOPRIGHT], vertices[BOTTOMLEFT]}));
            division.push_back(triangle({vertices[TOPRIGHT], vertices[BOTTOMRIGHT], vertices[BOTTOMLEFT]}));
        }
        else
        {
            division.push_back(triangle({vertices[TOPLEFT], vertices[TOPRIGHT], vertices[BOTTOMRIGHT]}));
            division.push_back(triangle({vertices[TOPLEFT], vertices[BOTTOMLEFT], vertices[BOTTOMRIGHT]}));
        }

        return division;
    }