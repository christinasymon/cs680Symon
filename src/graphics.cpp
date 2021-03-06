#include "graphics.h"
#include <vector>
#include <json.hpp>
#include <fstream>
using namespace nlohmann;
Graphics::Graphics()
{
    index = -1;
}
extern int lookAtIndex;
Graphics::~Graphics()
{

}
std::vector<Object*> list1;

/**
 * Allows you to update the index of the planet you are currently on
 *
 */
void Graphics::UpdateIndex() {
     index++;
     if(index >= (int) list1.size() ) {
         index = -1;
     }
}


bool Graphics::Initialize(int width, int height)
{
    json j;
    std::ifstream i("../objects/planets.json");
    i >> j;
    float awesome = j["Sun"]["SpinSpeed"];
    std::cout << sizeof(j);
  

    glewExperimental = GL_TRUE;
    auto status = glewInit();
    glGetError();

    if (status != GLEW_OK)
    {
      std::cerr << "GLEW Error: " << glewGetErrorString(status) << "\n";
      return false;
    }

   GLuint vao;
   glGenVertexArrays(1, &vao);
   glBindVertexArray(vao);

   m_camera = new Camera();
   if(!m_camera->Initialize(width, height))
   {
     printf("Camera Failed to Initialize\n");
     return false;
   }

/**
* Instructions on how to add objects
* Constructor: (float distance1, float speed1, float speed21, signed int direction1, signed int direction21, unsigned int pause1, float double21,  float scale1)
*  distance1 = distance from parent
*  speed1 = speed of all rotation
*  direction1 = 
*
*
*
*/
   std::string objectName = "smoothSphere.obj";
   float dist = 0;
   float orbit = 0;
   float spin = 0;
   float scale = 0;
   std::string objName = "";
   std::string texName = "";

  float dsScale = .00001;   

  dist = j["Sun"]["distance"];
  orbit = j["Sun"]["OrbitSpeed"];
  spin = j["Sun"]["SpinSpeed"];
  scale = j["Sun"]["Scale"];
  objName = j["Sun"]["object"];
  texName = j["Sun"]["Texture"];

   m_cube = new Object(dist*dsScale,orbit,spin,1,1,1,1,scale*dsScale,objName, texName );
   list1.push_back(m_cube);

dist = j["Mercury"]["distance"];
  orbit = j["Mercury"]["OrbitSpeed"];
  spin = j["Mercury"]["SpinSpeed"];
  scale = j["Mercury"]["Scale"];
  objName = j["Mercury"]["object"];
 texName = j["Mercury"]["Texture"];
 
   m_cube->children.push_back(new Object(dist*dsScale,orbit,spin,1,1,1,1,scale*dsScale,objName, texName) ); 
   m_cube->children.at(0)->parent = m_cube;
   m_cube->children.at(0)->level =1;
   list1.push_back(m_cube->children.at(0));

dist = j["Venus"]["distance"];
  orbit = j["Venus"]["OrbitSpeed"];
  spin = j["Venus"]["SpinSpeed"];
  scale = j["Venus"]["Scale"];
  objName = j["Venus"]["object"];
 texName = j["Venus"]["Texture"];
 
   m_cube->children.push_back(new Object(dist*dsScale,orbit,spin,1,1,1,1,scale*dsScale,objName, texName) ); 
   m_cube->children.at(1)->parent = m_cube;
   m_cube->children.at(1)->level =1;
   list1.push_back(m_cube->children.at(1));


  dist = j["Earth"]["distance"];
  orbit = j["Earth"]["OrbitSpeed"];
  spin = j["Earth"]["SpinSpeed"];
  scale = j["Earth"]["Scale"];
  objName = j["Earth"]["object"];
 texName = j["Earth"]["Texture"];
 
   m_cube->children.push_back(new Object(dist*dsScale,orbit,spin,1,1,1,1,scale*dsScale,objName, texName) ); 
   m_cube->children.at(2)->parent = m_cube;
   m_cube->children.at(2)->level =1;
   list1.push_back(m_cube->children.at(2));


  dist = j["Mars"]["distance"];
  orbit = j["Mars"]["OrbitSpeed"];
  spin = j["Mars"]["SpinSpeed"];
  scale = j["Mars"]["Scale"];
  objName = j["Mars"]["object"];
 texName = j["Mars"]["Texture"];
 
   m_cube->children.push_back(new Object(dist*dsScale,orbit,spin,1,1,1,1,scale*dsScale,objName, texName) ); 
   m_cube->children.at(3)->parent = m_cube;
   m_cube->children.at(3)->level =1;
   list1.push_back(m_cube->children.at(3));


 dist = j["Jupiter"]["distance"];
  orbit = j["Jupiter"]["OrbitSpeed"];
  spin = j["Jupiter"]["SpinSpeed"];
  scale = j["Jupiter"]["Scale"];
  objName = j["Jupiter"]["object"];
 texName = j["Jupiter"]["Texture"];

   m_cube->children.push_back(new Object(dist*dsScale,orbit,spin,1,1,1,1,scale*dsScale,objName, texName) ); 
   m_cube->children.at(4)->parent = m_cube;
   m_cube->children.at(4)->level =1;
   list1.push_back(m_cube->children.at(4));

dist = j["Saturn"]["distance"];
  orbit = j["Saturn"]["OrbitSpeed"]; //https://www.deviantart.com/bob3studios/art/Pluto-Texture-Map-Fixed-Blur-762286905
  spin = j["Saturn"]["SpinSpeed"];
  scale = j["Saturn"]["Scale"];
  objName = j["Saturn"]["object"];
 texName = j["Saturn"]["Texture"];

   m_cube->children.push_back(new Object(dist*dsScale,orbit,spin,1,1,1,1,scale*dsScale,objName, texName) ); 
   m_cube->children.at(5)->parent = m_cube;
   m_cube->children.at(5)->level =1;
   list1.push_back(m_cube->children.at(5));

dist = j["Uranus"]["distance"];
  orbit = j["Uranus"]["OrbitSpeed"];
  spin = j["Uranus"]["SpinSpeed"];
  scale = j["Uranus"]["Scale"];
  objName = j["Uranus"]["object"];
 texName = j["Uranus"]["Texture"];

   m_cube->children.push_back(new Object(dist*dsScale,orbit,spin,1,1,1,1,scale*dsScale,objName, texName) ); 
   m_cube->children.at(6)->parent = m_cube;
   m_cube->children.at(6)->level =1;
   list1.push_back(m_cube->children.at(6));

dist = j["Neptune"]["distance"];
  orbit = j["Neptune"]["OrbitSpeed"];
  spin = j["Neptune"]["SpinSpeed"];
  scale = j["Neptune"]["Scale"];
  objName = j["Neptune"]["object"];
 texName = j["Neptune"]["Texture"];

   m_cube->children.push_back(new Object(dist*dsScale,orbit,spin,1,1,1,1,scale*dsScale,objName, texName) ); 
   m_cube->children.at(7)->parent = m_cube;
   m_cube->children.at(7)->level =1;
   list1.push_back(m_cube->children.at(7));
  
dist = j["Pluto"]["distance"];
  orbit = j["Pluto"]["OrbitSpeed"];
  spin = j["Pluto"]["SpinSpeed"];
  scale = j["Pluto"]["Scale"];
  objName = j["Pluto"]["object"];
 texName = j["Pluto"]["Texture"];

   m_cube->children.push_back(new Object(dist*dsScale,orbit,spin,1,1,1,1,scale*dsScale,objName, texName) ); 
   m_cube->children.at(8)->parent = m_cube;
   m_cube->children.at(8)->level =1;
   list1.push_back(m_cube->children.at(8));

 scale = j["Saturn"]["Scale"];
 texName = "ring.jpg";
 objName = "ring.obj";
   
   
   list1.push_back( new Object(0,0,0,1,1,1,1,scale*.001,objName, texName) );

   //list1.at(9)->parent = list1.at(5);
  //  std::cout << list1.at(9)->objName << '\n';


   i.close();
  m_shader = new Shader();
  if(!m_shader->Initialize())
  {
    printf("Shader Failed to Initialize\n");
    return false;
  }

  if(!m_shader->AddShader(GL_VERTEX_SHADER))
  {
    printf("Vertex Shader failed to Initialize\n");
    return false;
  }

 
  if(!m_shader->AddShader(GL_FRAGMENT_SHADER))
  {
    printf("Fragment Shader failed to Initialize\n");
    return false;
  }


  if(!m_shader->Finalize())
  {
    printf("Program to Finalize\n");
    return false;
  }


  m_projectionMatrix = m_shader->GetUniformLocation("projectionMatrix");
  if (m_projectionMatrix == INVALID_UNIFORM_LOCATION) 
  {
    printf("m_projectionMatrix not found\n");
    return false;
  }

  // Locate the view matrix in the shader
  m_viewMatrix = m_shader->GetUniformLocation("viewMatrix");
  if (m_viewMatrix == INVALID_UNIFORM_LOCATION) 
  {
    printf("m_viewMatrix not found\n");
    return false;
  }

  // Locate the model matrix in the shader
  m_modelMatrix = m_shader->GetUniformLocation("modelMatrix");
  if (m_modelMatrix == INVALID_UNIFORM_LOCATION) 
  {
    printf("m_modelMatrix not found\n");
    return false;
  }

  //enable depth testing
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);

 // glEnable(GL_CULL_FACE);
  //glCullFace(GL_BACK);

  return true;
}

/** 
 * Iteratively calls update within object.cpp
 *
 */
void Graphics::Update(unsigned int dt)
{
 
  for(unsigned int x = 0; x < list1.size(); x++) {
      list1.at(x)->Update(dt);
  }
}
void Graphics::Recenter() {
     m_camera->view = glm::lookAt( glm::vec3(0.0, 8.0, -16.0), //Eye Position
                      glm::vec3(0.0, 0.0, 0.0), //Focus point
                      glm::vec3(0.0, 1.0, 0.0)); //Positive Y is up
    lookAtIndex= -1;
}
/**
* Call this to reverse stuff
* Reverses based on current index
*/
void Graphics::Reverse(int x) {
    if(index == -1) {
        IterativeReverse(x);
    }
    else {
        list1.at(index)->Reverse(x);
    }
}

/**
 * Don't call this, Reverse will call it
 */
void Graphics::IterativeReverse(int mode) {
   
   for(unsigned int x = 0; x < list1.size(); x++) {        
       list1.at(x)->Reverse(mode);         
   }
}

/**
 * Call this to render all objects in the list.
 */
void Graphics::IterativeRender(Object* obj) {
      for(unsigned int x = 0; x < list1.size(); x++) {
          glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(list1.at(x)->GetModel()));
          list1.at(x)->Render();   
      }
}
void Graphics::camerachange(int p){
p1=p;
}
/**
 * Renders stuff
 */
float speed=2.0;
float rotated=0.0;
void Graphics::Render()
{
int indix = 2;

glm::vec4 d;
if(p1==1)
{
speed+=0.009;

//std::cout<<speed<<"\n";
}
else if(p1==2)
{
speed-=0.009;

}
else if (p1==3)
{
rotated+=0.05;
}
else if(p1 == 4)
{
rotated-=0.05;
}

if(lookAtIndex  > -1) {
    indix = lookAtIndex;

glm::mat4 c = list1.at(indix)->model2;
 d = c * glm::vec4(0.0, 0.0, 0.0, 1.0);


 m_camera->view = glm::lookAt( glm::vec3(d.x + 3*list1.at(indix)->sc + speed, d.y , d.z), //Eye Position
                      glm::vec3(d.x, d.y, d.z), //Focus point
                      glm::vec3(0.0, 1, 0));

//focus point should be position of planet
// eye position should be focus point + some direction + zoom

} else {
     Recenter();
}




  glClearColor(0.0, 0.0, 0.2, 1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  m_shader->Enable();

  glUniformMatrix4fv(m_projectionMatrix, 1, GL_FALSE, glm::value_ptr(m_camera->GetProjection())); 
  glUniformMatrix4fv(m_viewMatrix, 1, GL_FALSE, glm::value_ptr(m_camera->GetView())); 

  IterativeRender(m_cube);
  
  auto error = glGetError();
  if ( error != GL_NO_ERROR )
  {
    string val = ErrorString( error );
    std::cout<< "Error initializing OpenGL! " << error << ", " << val << std::endl;
  }
}

std::string Graphics::ErrorString(GLenum error)
{
  if(error == GL_INVALID_ENUM)
  {
    return "GL_INVALID_ENUM: An unacceptable value is specified for an enumerated argument.";
  }

  else if(error == GL_INVALID_VALUE)
  {
    return "GL_INVALID_VALUE: A numeric argument is out of range.";
  }

  else if(error == GL_INVALID_OPERATION)
  {
    return "GL_INVALID_OPERATION: The specified operation is not allowed in the current state.";
  }

  else if(error == GL_INVALID_FRAMEBUFFER_OPERATION)
  {
    return "GL_INVALID_FRAMEBUFFER_OPERATION: The framebuffer object is not complete.";
  }

  else if(error == GL_OUT_OF_MEMORY)
  {
    return "GL_OUT_OF_MEMORY: There is not enough memory left to execute the command.";
  }
  else
  {
    return "None";
  }
}

