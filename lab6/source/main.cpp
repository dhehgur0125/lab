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


glm::mat4 lookAt(glm::vec3 campos, glm::vec3 look, glm::vec3 up);

int main()
{
	std::cout << to_string(lookAt({ 5,5,5 }, { 0,0,0 }, { 0,1,0 })) << std::endl;

	return 0;
}

glm::mat4 lookAt(glm::vec3 campos, glm::vec3 look, glm::vec3 up)
{
	glm::vec3 z = glm::normalize(campos - look);
	glm::vec3 x = glm::normalize(glm::cross(up, z));
	glm::vec3 y = glm::normalize(glm::cross(z, x));
	
	glm::mat4 t = glm::translate(glm::mat4(1), -campos);
	glm::mat4 r({ x.x,y.x,z.x,0 }, { x.y,y.y,z.y,0 }, { x.z,y.z,z.z,0 }, { 0,0,0,1 });
	return r*t;
}