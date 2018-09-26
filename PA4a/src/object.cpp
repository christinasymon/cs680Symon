#include "object.h"
#include <fstream>

Object::Object(char** argv)
{  
 
 std::ifstream file;
 std::ifstream mfile;
  Vertex ver({0,0,0},{0,0,0});
  char* dummy;
  long index;
  std::string temp;

  if(std::string(argv[2])=="dragon")
	{
	file.open("../Object_files/dragon.obj");
	}
   else if(std::string(argv[2])=="box")
{
  	file.open("../Object_files/box.obj");
} 
 if(!file)
  {
  std::cerr<< "Unable to open file";
  exit(1);
  }
 std::string word,mword;
  while(file>>word)
  {
  if(word=="v")
  {
	 if(std::string(argv[1])=="random")
      {
  	file>> ver.vertex.x;
  	file>> ver.vertex.y;
  	file>> ver.vertex.z;
  	std::cout<< ver.vertex.x<<" "<<ver.vertex.y<<" "<<ver.vertex.z<<std::endl;
	ver.color.r=(rand()%100)/100.0;
	ver.color.g=(rand()%100)/100.0;
	ver.color.b=(rand()%100)/100.0;
      }
else if(std::string(argv[1])=="material")
{
  	file>> ver.vertex.x;
  	file>> ver.vertex.y;
  	file>> ver.vertex.z;
  	std::cout<< ver.vertex.x<<" "<<ver.vertex.y<<" "<<ver.vertex.z<<std::endl;

}
	Vertices.push_back(ver);
  }
  else if(word == "f")
  { 
	for(int i=1;i<=3;i++)
	{
  		file>>temp;
		index=strtol(temp.c_str(),&dummy,10);
		Indices.push_back(index);
      		std::cout<<index<<" ";
	}
    std::cout<<std::endl;
   }
else if(word== "mtllib")
{
	file>>word;
	mfile.open(word);
	while(mfile>>mword)
	{
		if(mword=="Kd")
		{
			mfile>>ver.color.r;
			mfile>>ver.color.g;
			mfile>>ver.color.b;
			break;
		}
 		else
		{
			mfile.ignore(100,'\n');
		}
	}
	mfile.close();
}

 else
{ 
file.ignore(100,'\n');
}

  } 
file.close();

  // The index works at a 0th index
  for(unsigned int i = 0; i < Indices.size(); i++)
  {
    Indices[i] = Indices[i] - 1;
  }

  angle = 0.0f;

  glGenBuffers(1, &VB);
  glBindBuffer(GL_ARRAY_BUFFER, VB);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * Vertices.size(), &Vertices[0], GL_STATIC_DRAW);

  glGenBuffers(1, &IB);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IB);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * Indices.size(), &Indices[0], GL_STATIC_DRAW);
}

Object::~Object()
{
  Vertices.clear();
  Indices.clear();
}

void Object::Update(unsigned int dt)
{
  angle += dt * M_PI/1000;
  model = glm::rotate(glm::mat4(1.0f), (angle), glm::vec3(0.0, 1.0, 0.0));
}

glm::mat4 Object::GetModel()
{
  return model;
}

void Object::Render()
{
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);

  glBindBuffer(GL_ARRAY_BUFFER, VB);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex,color));

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IB);

  glDrawElements(GL_TRIANGLES, Indices.size(), GL_UNSIGNED_INT, 0);

  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);
}

