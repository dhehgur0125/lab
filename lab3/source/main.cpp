
#define GLM_ENABLE_EXPERIMENTAL
#define GLM_SWIZZLE
#include<iostream>
#include<glm/glm.hpp>
#include<glm/gtx/string_cast.hpp>
#include <glm/gtc/constants.hpp>

//const double DEGREES_TO_RADIANS = glm::pi<float>() / 180.0;
//const double RADIANS_TO_DEGREES = 180.0 / glm::pi<float>();

int main()
{
	/*glm::vec3 v(2, -1, 1);
	glm::vec3 u(1, 1, 2);
	float d = glm::dot(v, u);
	float c = d / (glm::length(u) * glm::length(v));
	float deg = glm::acos(c);
	float deg2 = glm::degrees(deg);
	std::cout << deg2 << std::endl;*/

	/*glm::vec3 v(1, 2, -1);
	glm::vec3 u(0, 1, 0);
	glm::vec3 b = glm::dot(v, u) * u;
	glm::vec3 a = v - b;
	std::cout << "a: " << glm::to_string(a) << std::endl;
	std::cout << "b: " << glm::to_string(b) << std::endl;*/

	glm::vec3 n(0, 1, 0);
	glm::vec3 p(1, 0, 1);
	glm::vec3 x(-3, 3, 2);
	glm::vec3 xp = x - p;
	float di = glm::dot(xp, n);
	std::cout << "°Å¸® : " << di << std::endl;
	return 0;
}