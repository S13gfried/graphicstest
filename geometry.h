#pragma once

#include <vector>
#include <stdexcept>

class vector2f {
 public:
  float x, y;

  vector2f(float newX = 0.0, float newY = 0.0);
};

class triangle {
 private:

  std::vector<vector2f>
      vertices;  // vector2f coordinates of vertices. Always has a length of 3.

 public:

  triangle(std::vector<vector2f> newVertices = {{0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0}});

  void setVertex(int index, vector2f value); //Sets vector2f for individual vertex of a triangle
  std::vector<vector2f> getVertices() const; //Gets the whole vector of vector2f triangle vertex coordinates

  bool nonDegenerate() const;  // Check whether vertices are placed on a straight line (area = 0)
};

enum rectVertices { TOPLEFT, TOPRIGHT, BOTTOMRIGHT, BOTTOMLEFT };

class rectangleP {

 private:

  std::vector<vector2f>
      vertices;  // vector2f coordinates of vertices, clockwise from top left.

    bool rearrangeRelativePositions(); //Compensate for "flips" happening after altering vertices. return 1 if there were any.
    void swapVertices(int index1, int index2);

 public:

    rectangleP(vector2f topleft, vector2f bottomright);
    bool setVertex(int index, vector2f newvertex); //reposition the stated vertex.
    std::vector<vector2f> getVertex() const;
};