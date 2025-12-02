#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/dual_quaternion.hpp>
#include<iostream>
#include<glm/glm.hpp>
#include <glm/gtx/matrix_transform_2d.hpp>
#include<glm/gtx/string_cast.hpp>
#include <glm/gtc/constants.hpp>
#include<glm/mat4x4.hpp>
#include<glm/mat2x2.hpp>
#include<glm/mat3x2.hpp>
#include<glm/mat3x3.hpp>


int main()
{
	/*glm::vec3 v(5, 6, 1); glm::mat3 t(1.0); //identity matrix 
	t = glm::translate(t,glm::vec2(2, 3));
	v = t * v;
	std::cout << to_string(t) << std::endl; std::cout << to_string(v) << std::endl;*/

	/*
	glm::vec3 v(5, 6, 1); glm::mat3 t(1.0);
	t = glm::scale(t, glm::vec2(3, 4)); //scale 3x in x axis and 4x in y axis
	v = t * v;
	std::cout << to_string(t) << std::endl; 
	std::cout << to_string(v) << std::endl;*/

	glm::vec3 v(5, 6, 1); glm::mat3 t(1.0);
	t = glm::rotate(t, glm::radians(45.0f)); //45 or 45.0 causes an error
	v = t * v;
	std::cout << to_string(t) << std::endl; 
	std::cout << to_string(v) << std::endl;

	return 0;
}