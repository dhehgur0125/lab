//#define  FREEGLUT_LIB_PRAGMAS  0

#include <iostream>
#include <GL/gl3w.h>
#include <string>
#include "Loader.h"
#include"cow_vbo.h"
#include "Viewer.h"
#include<glm/mat4x4.hpp>

class MyGlWindow {
public:
	std::unique_ptr<cow> m_cow;
	std::unique_ptr<Viewer>m_viewer;
	void initialize();
	MyGlWindow(int w, int h);
	~MyGlWindow();
	void draw();
	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;
	glm::mat4 mvp;
	void setSize(int size_w, int size_h);
	void setAspect(int size_aspect);
private:
	GLuint vaohandle;
	
	std::unique_ptr<ShaderProgram> shaderProgram;

	int m_width;
	int m_height;
	float m_aspect;
	
	void setupBuffer();

};
