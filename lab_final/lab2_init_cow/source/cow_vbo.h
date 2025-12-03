#include<iostream>
#ifndef __COW 
#define __COW
#include "GL/gl3w.h" 
#include <glm/mat4x4.hpp> 
#include <vector>
#include <string>
#include "Loader.h"

class cow {
public:
	cow();
	void setup();
	void draw();
	void calculateNormal(); //normal계산 함수
	GLuint vaohandle;
	GLuint vbo_cow_vertices;
	GLuint ibo_cow_elements;
	GLuint vbo_cow_normals;
	std::vector<glm::vec3> normals; //normal저장하기 위한 곳
private:
	GLuint vbo_position;
	GLuint vbo_color;
};
#endif