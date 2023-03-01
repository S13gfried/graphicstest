#pragma once

#include <stdexcept>
#include <vector>

class vector2f {
 public:
  float x, y;

  vector2f(float newX, float newY);
};

vector2f operator+(const vector2f& lhs, const vector2f& rhs);

vector2f operator-(const vector2f& lhs, const vector2f& rhs);

class shape2f {
 protected:

  std::vector<vector2f> vertices;

 public:
  virtual std::vector<vector2f> getVertices() const;
  // virtual getVertex(int index) const;
  bool setVertex(const int& index, const vector2f& value);
};
class triangle : public shape2f {
 public:
  triangle(std::vector<vector2f> newVertices);
  bool nonDegenerate()
      const;  // Check whether vertices are placed on a straight line (area = 0)
};

class rectangleP : public shape2f {
 public:

  enum rectVertices {
    TOPLEFT,
    TOPRIGHT,
    BOTTOMRIGHT,
    BOTTOMLEFT
  };  // Relative positions of vertices.
  enum diagonalModes {
    TLBR,
    TRBL
  };  // Two possible diagonals: top left - bottom right, top right - bottom
      // left.

 private:
  bool rearrangeRelativePositions();  // Compensate for "flips" happening after
                                      // altering vertices. return 1 if there
                                      // were any.
  void swapVertices(int index1,
                    int index2);  // Swap the inidices of two vertices.

 public:
  rectangleP(vector2f topleft, vector2f bottomright);
  bool setVertex(int index,
                 vector2f newvertex);  // Reposition an individual vertex.
  bool nonDegenerate() const;  // Check whether all vertices of a rectangle are
                               // placed on a straight line (area = 0)
  std::vector<triangle> subdivideTriangles(
      int diagonal) const;  // divide the rectangle into two triangles.
};