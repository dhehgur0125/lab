#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/dual_quaternion.hpp>
#include<iostream>
#include<glm/glm.hpp>
#include<glm/gtx/string_cast.hpp>
#include <glm/gtc/constants.hpp>
#include<glm/mat4x4.hpp>
#include<glm/mat2x2.hpp>
#include<glm/mat3x2.hpp>
#include<glm/mat3x3.hpp>

int main()
{
	/*
	glm::mat3 m1 { {1,1,-1},{0,2,0},{2,3,1} };
	glm::mat3 m2{ {1,0,0},{0,-1,1},{0,1,2} };
	glm::mat3 m12 = m1 * m2;
	glm::mat3 m21 = m2 * m1;

	std::cout << to_string(m12) << std::endl;
	std::cout << to_string(m21) << std::endl;
	*/
	/*
	glm::mat2 m{{4,1},{8,3}};
	glm::mat2 i = glm::inverse(m);
	std::cout << to_string(i) << std::endl;
	glm::mat2 mi = m * i;
	std::cout << to_string(m*i) << std::endl;*/	
	/*
	glm::mat3 m{ {1,0,0},{2,-1,0},{3,0,1} };
	glm::vec3 a(1, 2, 3);
	//glm::mat3 am = a * m; error
	//glm::vec3 am = a * m; true
	std::cout << to_string(m * a) << std::endl;//true
	std::cout << to_string(a * m) << std::endl;//false
	*/


	return 0;
}