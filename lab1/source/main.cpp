#define GLM_ENABLE_EXPERIMENTAL
#define GLM_SWIZZLE
#include<iostream>
#include<glm/glm.hpp>
#include<glm/gtx/string_cast.hpp>
//
int main()
{
	//Q1
	glm::vec3 p (1.0f, 4.0f, -5.0f);
	glm::vec3 v(5.0f, 1.0f, 4.0f);
	std::cout << glm::to_string(p + v) << std::endl;

	//Q2
	glm::vec3 v1(1.0f, 0.0f, 0.0f);
	glm::vec3 v2(0.0f, 1.0f, 0.0f);
	std::cout << glm::to_string(v1 + v2) << std::endl;

	//Q3
	glm::vec3 v11(0.0f, 1.0f, 0.0f);
	v11 *= 2;
	std::cout << glm::to_string(v11) << std::endl;

	//Q4
	glm::vec3 start(8.0f, 2.0f, 5.0f);
	glm::vec3 end(1.0f, -1.0f, 4.0f);
	std::cout << glm::to_string(end - start) << std::endl;

	//Q5
	glm::vec3 v5(1.0f, 3.0f, 4.0f);
	v5 = glm::normalize(v5);
	std::cout << glm::to_string(v5) << std::endl;
	
	//Q6
	glm::vec3 v6(1.0f, -1.0f, 4.0f);
	glm::vec4 v66(v6, 0.0f);
	std::cout << glm::to_string(v66) << std::endl;
}