#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include "graphics_headers.h"

class Object
{
  public:
    Object();
    ~Object();
    void Update(unsigned int dt);
    void Render();
    void Reverse(bool);
    glm::mat4 GetModel();
    glm::mat4 GetTranslate();
    void MoonOrPlanet(unsigned int);
    void SetOriginMatrix(glm::mat4);

  private:
    glm::mat4 model, origin, translate;
    std::vector<Vertex> Vertices;
    std::vector<unsigned int> Indices;
    GLuint VB;
    GLuint IB;

    float angle, angle1;
    bool reverse;
    unsigned int if_moon;
};

#endif /* OBJECT_H */
