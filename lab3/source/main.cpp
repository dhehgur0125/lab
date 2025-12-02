
#define GLM_ENABLE_EXPERIMENTAL
#define GLM_SWIZZLE
#include<iostream>
#include<glm/glm.hpp>
#include<glm/gtx/string_cast.hpp>
#include <glm/gtc/constants.hpp>


int main()
{
	/*glm::vec3 u(1, 0, 0);
	glm::vec3 v(-1, 1, 0);
	glm::vec3 c = glm::cross(u, v);
	float i = glm::length(c);
	float ang = glm::acos(glm::dot(u, v) / (glm::length(u) * glm::length(v)));
	float i2 = glm::length(u) * glm::length(v) * sin(ang);

	glm::vec3 u2(1, 0, 0);
	glm::vec3 v2(0, 1, 0);
	float area = glm::length(glm::cross(u2, v2));

	glm::vec3 u3(1, 0, 0);
	glm::vec3 v3(1, 0, 0);
	float area = glm::length(glm::cross(u3, v3));

	glm::vec3 p1(1, 0, 0);
	glm::vec3 p2(1, 1, 0);
	glm::vec3 p3(-1, 0, 0);
	glm::vec3 v1 = p2 - p1;
	glm::vec3 v2 = p3 - p1;
	float area2 = 0.5f * glm::length(glm::cross(v1, v2));*/

	glm::vec3 p1(3.0f, 0.0f, 0.0f);
	glm::vec3 p2(1.5f, 0.86f, 0.0f);
	glm::vec3 p3(3.0f, 0.0f, -1.0f);
	glm::vec3 u = glm::normalize(glm::cross(p2 - p1, p3 - p1));
	std::cout << glm::to_string(u) << std::endl;

	return 0;
}