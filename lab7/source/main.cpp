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
{	//모델행렬구하기
	glm::vec4 local(4.0f, 5.0f, 3.0f, 1.0f);

	glm::mat4 sca = glm::scale(glm::mat4(1.0f), glm::vec3(1.3f, 1.3f, 1.3f));
	glm::mat4 tan = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 5.0f, 0.0f));
	glm::mat4 roty = glm::rotate(glm::mat4(1.0f), glm::radians(56.0f), glm::vec3(0,1,0));
	glm::mat4 rotx = glm::rotate(glm::mat4(1.0f), glm::radians(40.0f), glm::vec3(1, 0, 0));
	glm::mat4 mod = tan * rotx * roty* sca ; //t->r->s 순서
	//std::cout << glm::to_string(mod) << std::endl;

	glm::vec4 wsp = mod * local;
	//std::cout << glm::to_string(wsp) << std::endl; 
	//여기까지

	//뷰행렬구하기
	glm::mat4 view = {	{0.83f, -0.3f, 0.47f, 0},
						{0, 0.84f, 0.54f, 0},
						{-0.56f, -0.45f, 0.7f, 0},
						{0, 0, -44.47f, 1.0f} };
	//위에 view로 부터 카메라 위치랑 카메라가 보고 있는 점을 어떻게 알지?
	//view행렬은 월드에서 카메라로 변경하는 행렬
	//inverse(view)는 카메라 에서 월드 행렬이 됨
	glm::mat4 inView = glm::inverse(view); // 카메라에서 월드
	//inView의 마지막 컬럼이 카메라 위치가 됨

	glm::vec3 camPos = inView[3]; // 카메라 위치
	//view 구성시, 3개의 축을 구했는데 카메라는 -z방향을 바라본다고 가정했음
	//카메라는 -z축을 바라보고 있으므로
	glm::vec3 z_axis = glm::normalize(-inView[2]);

	glm::vec3 look = camPos + z_axis * 10.0f;
	glm::vec3 up(0, 1.0f, 0);
	glm::mat4 myview = lookAt(camPos, look, up);
	std::cout << "view\n" << glm::to_string(view) << std::endl;
	std::cout <<"myview\n" << glm::to_string(myview) << std::endl;

	return 0;
}

glm::mat4 lookAt(glm::vec3 campos, glm::vec3 look, glm::vec3 up)
{
	glm::vec3 z = glm::normalize(campos - look);
	glm::vec3 x = glm::normalize(glm::cross(up, z));
	glm::vec3 y = glm::normalize(glm::cross(z, x));

	glm::mat4 t = glm::translate(glm::mat4(1), -campos);
	glm::mat4 r({ x.x,y.x,z.x,0 }, { x.y,y.y,z.y,0 }, { x.z,y.z,z.z,0 }, { 0,0,0,1 });
	return r * t;
}
