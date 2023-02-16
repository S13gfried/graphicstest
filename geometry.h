#pragma once

#include <vector>
#include <stdexcept>

class vector2f {
 public:
  float x, y;

  vector2f(float newX, float newY);
};
/*
class shape2f
{
    private:
    std::vector<vector2f> vertices;

    public:
    shape2f();
    virtual ~shape2f();
    virtual std::vector<vector2f> getVertices() const;
    virtual bool setVertex(int index, vector2f value);
};
*/
class triangle /*: shape2f*/ {
 private:

  std::vector<vector2f>
      vertices;  // vector2f coordinates of vertices. Always has a length of 3.

 public:

  triangle(std::vector<vector2f> newVertices);

  bool setVertex(int index, vector2f value); //Sets vector2f for individual vertex of a triangle
  std::vector<vector2f> getVertices() const; //Gets the whole vector of vector2f triangle vertex coordinates

  bool nonDegenerate() const;  // Check whether vertices are placed on a straight line (area = 0)
};

class rectangleP /*: shape2f*/ {
 public:

enum rectVertices { TOPLEFT, TOPRIGHT, BOTTOMRIGHT, BOTTOMLEFT }; //Relative positions of vertices.
enum diagonalModes { TLBR, TRBL }; //Two possible diagonals: top left - bottom right, top right - bottom left.

 private:

  std::vector<vector2f>
      vertices;  // vector2f coordinates of vertices, clockwise from top left.

    bool rearrangeRelativePositions(); //Compensate for "flips" happening after altering vertices. return 1 if there were any.
    void swapVertices(int index1, int index2); //Swap the inidices of two vertices.

 public:

    rectangleP(vector2f topleft, vector2f bottomright);
    bool setVertex(int index, vector2f newvertex); //Reposition an individual vertex.
    std::vector<vector2f> getVertices() const; //Return a vector of vertices' vector2f with length 4.
    bool nonDegenerate() const; //Check whether all vertices of a rectangle are placed on a straight line (area = 0)
    std::vector<triangle> subdivideTriangles(int diagonal) const; //divide the rectangle into two triangles.
};