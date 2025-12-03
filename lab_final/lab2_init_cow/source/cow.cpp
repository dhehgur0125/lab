#define GLM_ENABLE_EXPERIMENTAL 
#include"cow.h"
#include "cow_vbo.h"
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>

cow::cow()
{
	calculateNormal();
	setup();
}

void cow::calculateNormal()
{
	const uint32_t ntris = 3156; 
	normals.resize(1732); //std::vector 사용 한 경우, 배열 사용 한 경우 필요 x
	for (uint32_t i = 0; i < ntris; ++i) {
		const glm::vec3& v0 = vertices[nvertices[i * 3]]; //v0 
		const glm::vec3& v1 = vertices[nvertices[i * 3 + 1]]; //v1 
		const glm::vec3& v2 = vertices[nvertices[i * 3 + 2]]; //v2
		//세 vertex로 부터 두 벡터를 구한 후 외적을 통해 normal 계산
		glm::vec3 n = glm::normalize(glm::cross(v1 - v0, v2 - v0));
		normals[nvertices[i * 3]] = n;
		normals[nvertices[i * 3 + 1]] = n;
		normals[nvertices[i * 3 + 2]] = n;
	}
}

void cow::setup()
{

	//GLuint vbo_cow_vertices, ibo_cow_elements; GLuint vbo_cow_normals;
	glCreateVertexArrays(1, &vaohandle);
	glCreateBuffers(1, &vbo_position);
	glCreateBuffers(1, &vbo_cow_normals);
	//2.vbo 생성
	//position 처리
	//GPU 메모리 할당
	glNamedBufferData(vbo_position, sizeof(glm::vec3) * 1732, vertices, GL_STATIC_DRAW);
	//GPU에게 해석방법 알려줌
	glVertexArrayVertexBuffer(
		vaohandle, //vao
		0,//binding index 번호 : vao 컨테이너 안 16개의 vbo슬롯 중 0번
		vbo_position,//vbo
		0,//offset
		sizeof(float) * 3 //stride
	);

	glVertexArrayAttribFormat(
		vaohandle,
		0, //속성번호
		3, //vertex당 데이타 수
		GL_FLOAT,
		GL_FALSE,
		0//offset
	);

	glNamedBufferData(vbo_cow_normals, sizeof(glm::vec3) * 1732, normals.data(), GL_STATIC_DRAW);
	//GPU에게 해석방법 알려줌
	glVertexArrayVertexBuffer(
		vaohandle, //vao
		1,//binding index 번호 : vao 컨테이너 안 16개의 vbo슬롯 중 1번
		vbo_cow_normals,//vbo
		0,//offset
		sizeof(float) * 3 //stride
	);

	glVertexArrayAttribFormat(
		vaohandle,
		0, //속성번호
		3, //vertex당 데이타 수
		GL_FLOAT,
		GL_FALSE,
		0//offset
	);
	glVertexArrayAttribBinding(vaohandle,
		0, //속성번호 0
		0 //binding index 0
	);
	glEnableVertexArrayAttrib(vaohandle, 0); //0번 속성 enable

	glVertexArrayAttribBinding(vaohandle,
		1, //속성번호 1
		1 //binding index 1
	);
	glEnableVertexArrayAttrib(vaohandle, 1); //1번 속성 enable

	glCreateBuffers(1, &ibo_cow_elements); //Gluint ibo_cube_elements
	glNamedBufferData(ibo_cow_elements, sizeof(uint32_t) * 9468, nvertices, GL_STATIC_DRAW); //문제
	glVertexArrayElementBuffer(vaohandle, ibo_cow_elements);
}


void cow::draw()
{
	glBindVertexArray(vaohandle);

	int size;
	glGetBufferParameteriv(GL_ELEMENT_ARRAY_BUFFER, GL_BUFFER_SIZE, &size);
	glDrawElements(GL_TRIANGLES, size / sizeof(GLuint), GL_UNSIGNED_INT, 0);
}

