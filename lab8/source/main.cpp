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

glm::mat4 Perspective(float fov_y, float aspect, float near, float far);

int main()
{
	float width = 780.0f;
	float height = 750.0f;
	float fov_y = 45.0f;
	float near_z = 0.1f;
	float far_z = 500.0f;
	float aspect = width / height;

	glm::mat4 pro_mat = Perspective(fov_y, aspect, near_z, far_z);
	std::cout << glm::to_string(pro_mat) << std::endl;
	return 0;
}

glm::mat4 Perspective(float fov_y, float aspect, float near, float far)
{
	fov_y = glm::radians(fov_y);
	glm::mat4 pro_mat(0);
	pro_mat[0][0] = 1.0f / (aspect * glm::tan(fov_y / 2.0f));
	pro_mat[1][1] = 1.0f / (glm::tan(fov_y / 2.0f));
	pro_mat[2][2] = -(far + near) / (far - near);
	pro_mat[2][3] = -1.0f;
	pro_mat[3][2] = -(2.0f * far* near) / (far - near);
	pro_mat[3][3] = 0;
	return pro_mat;
}


