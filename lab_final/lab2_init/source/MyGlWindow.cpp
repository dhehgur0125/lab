
#define GLM_ENABLE_EXPERIMENTAL 
#include "MyGlWindow.h"
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>

MyGlWindow::MyGlWindow(int w, int h)

//==========================================================================
{
	m_width = w;
	m_height = h;

	setupBuffer();
	
}




void MyGlWindow::setupBuffer()
{
	
	//쉐이더 객체 생성 : Morden cpp
	shaderProgram = std::make_unique<ShaderProgram>();
	
	//load shaders : vertex shader랑 fragment shader 지정
	shaderProgram->initFromFiles("shaders/simple.vert", "shaders/simple.frag");

	//NON DSA(Direct State Access) 방법
	//삼격형의 정보 배열에 저장
	
	//삼각형 위치 저장 : 0
	const float vertexPositon[] = {
		-0.2f, 0.0f, 0.0f, 1.0f,
		0.0f, 0.4f, 0.0f, 1.0f,
		0.2f, 0.0f, 0.0f, 1.0f,
	};

	//삼각형 색상 저장 : 1
	const float vertexColor[] = {
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f,
	};

	const float vertices[] = {//interleave 방식
		-0.2f, 0.0f, 0.0f, 1.0f,   1.0f,0.0f,0.0f,	//position, color for v0
		0.0f, 0.4f, 0.0f, 1.0f,   0.0f,1.0f,0.0f,	//position, color for v1
		0.2f, 0.0f, 0.0f, 1.0f,   0.0f,0.0f,1.0f	//position, color for v2
	};
	/*
	//이제 삼각형에 대한 정보를 CPU가 아닌  GUP에 보냄
	//삼각형의 가진 속성정보 : 위치, 색상
	//
	//1. VAO 생성(Vertex Arrat Object의 약자) : 컨테이너, 실제 속성 정보는 x //VAO의 컨테이너 안 VBO (Vertex Buffer Object의 약자)
	
	glGenVertexArrays(1, &vaohandle); //컨테이너 생성
	glBindVertexArray(vaohandle); //Bind ? 여러개의 vao중에(만일 여러개 있다면) 어떤거 사용할래?
		//Bind : activate의미, 난 앞으로 여기에 뭔가 작업을 할래라고 지정, 선언
		// 
		//2. VBO 생성(Vertex Buffer Object의 약자) : vertex의 속성 정보 저장
		GLuint vbo_positon;
		glGenBuffers(1, &vbo_positon); //vertex 위치 정보를 저장하기 위한 vbo
		glBindBuffer(GL_ARRAY_BUFFER, vbo_positon); //vbo 바인딩 : activate

		//데이터를 메인 메모리 -> GPU메모리로 보낸 후 할당 : 마지막 : usage //변경할려면 다이나믹으로 변경
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositon), vertexPositon, GL_STATIC_DRAW);
		glVertexAttribPointer( //GPU 한테, 메모리에 올라온 데이터 해석 방법을 알려줌
			0, //속성 번호
			4, //데이터 수
			GL_FLOAT, //데이터 타입
			GL_FALSE, //normalize 여부
			0, //stride
			0 //offset
		);
		//속성 enable
		glEnableVertexAttribArray(0); //속성 번호 0번 enable

		GLuint vbo_color;
		glGenBuffers(1, &vbo_color); //vertex 색상 정보를 저장하기 위한 vbo
		glBindBuffer(GL_ARRAY_BUFFER, vbo_color); //vbo 바인딩 : activate

		//데이터를 메인 메모리 -> GPU메모리로 보낸 후 할당 : 마지막 : usage //변경할려면 다이나믹으로 변경
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertexColor), vertexColor, GL_STATIC_DRAW);
		glVertexAttribPointer( //GPU 한테, 메모리에 올라온 데이터 해석 방법을 알려줌
			1, //속성 번호
			3, //데이터 수
			GL_FLOAT, //데이터 타입
			GL_FALSE, //normalize 여부
			0, //stride
			0 //offset
		);
		glEnableVertexAttribArray(1); //속성 번호 1번 enable

	//vao unbound
	glBindVertexArray(0); //현재 사용중인 vao unbound(0을 넣으면 됨)
	//binding 과 unbinding은 한쌍
	*/

	/*
	glGenVertexArrays(1, &vaohandle); //컨테이너 생성
	glBindVertexArray(vaohandle); //binding
		GLuint vbo_vertex;
		glGenBuffers(1, &vbo_vertex);
		glBindBuffer(GL_ARRAY_BUFFER, vbo_vertex); //vbo binding -> activate
		//copy data from CPU to GPU
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		//GPU에게 해석방법 알려줘야 함
		//위치(position)처리
		glVertexAttribPointer(
			0,//속성(attribute) 번호 : 0
			4,//vertex 당 데이터 수
			GL_FLOAT,
			GL_FALSE,
			sizeof(float)*7,//위치가 시작 한 후에 얼마 데이타 후에 다시 위치가 시작하나 : stride(보폭)
			(void*)0 //offset : 얼마 후에 데이타가 시작하나? , void 써줘야함
		);
		glEnableVertexAttribArray(0);

		//색상(color) 처리
		glVertexAttribPointer(
			1,//속성(attribute) 번호 : 1
			3,//vertex 당 데이터 수
			GL_FLOAT,
			GL_FALSE,
			sizeof(float) * 7,//컬러가 시작 한 후에 얼마 데이타 후에 다시 컬러가 시작하나 : stride(보폭)
			(void*)(sizeof(float)*4) //offset : 얼마 후에 데이타가 시작하나? 컬러데이터는 4칸 뒤에서 시작하기 때문에 *4 , void 써줘야함
		);
		glEnableVertexAttribArray(1);
	glBindVertexArray(0);//unbinding
	*/
	
	/*
	//DSA 방법 : 함수 명이 다름(glbinding**이 없음)
	//1. vao생성
	GLuint vbo_position;
	GLuint vbo_color;
	//glCreate*** -> DSA
	glCreateVertexArrays(1, &vaohandle);
	glCreateBuffers(1, &vbo_position);
	glCreateBuffers(1, &vbo_color);
	
	//2.vbo 생성
	//position 처리
	//GPU 메모리 할당
	glNamedBufferData(vbo_position, sizeof(vertexPositon),vertexPositon, GL_STATIC_DRAW);
	//GPU에게 해석방법 알려줌
	glVertexArrayVertexBuffer(
		vaohandle, //vao
		0,//binding index 번호 : vao 컨테이너 안 16개의 vbo슬롯 중 0번
		vbo_position,//vbo
		0,//offset
		sizeof(float)*4 //stride 간격
	);

	//color 처리
	//GPU 메모리 할당
	glNamedBufferData(vbo_color, sizeof(vertexColor), vertexColor, GL_STATIC_DRAW);
	//GPU에게 해석방법 알려줌
	glVertexArrayVertexBuffer(
		vaohandle, //vao
		1,//binding index 번호 : vao 컨테이너 안 16개의 vbo슬롯 중 1번
		vbo_color,//vbo
		0,//offset
		sizeof(float) * 3 //stride
	);

	glVertexArrayAttribFormat(
		vaohandle,
		0, //속성번호
		4, //vertex당 데이타 수
		GL_FLOAT,
		GL_FALSE,
		0//offset
	);
	glVertexArrayAttribBinding(vaohandle, 
		0, //속성번호 0
		0 //binding index 0
	);
	glEnableVertexArrayAttrib(vaohandle, 0); //0번 속성 enable

	glVertexArrayAttribFormat(
		vaohandle,
		1, //속성번호
		3, //vertex당 데이타 수
		GL_FLOAT,
		GL_FALSE,
		0//offset
	);
	glVertexArrayAttribBinding(vaohandle,
		1, //속성번호 1
		1 //binding index 1
	);
	glEnableVertexArrayAttrib(vaohandle, 1); //1번 속성 enable
	*/
	
	//DSA - Interleave 방법
	/*
	GLuint vbo_vertex;
	glCreateVertexArrays(1, &vaohandle);
	glCreateBuffers(1, &vbo_vertex);

	glNamedBufferData(vbo_vertex, sizeof(vertices),vertices, GL_STATIC_DRAW);
	glVertexArrayVertexBuffer(vaohandle, 0, vbo_vertex, 0, sizeof(float) * 7);

	glVertexArrayAttribFormat(vaohandle, 0, 4, GL_FLOAT, GL_FALSE, 0); //마지막 0 offset
	glVertexArrayAttribBinding(vaohandle, 0, 0); //0 : 속성번호 0 : binding index
	glEnableVertexArrayAttrib(vaohandle, 0); //속성번호 0 enable

	glVertexArrayAttribFormat(vaohandle, 1, 3, GL_FLOAT, GL_FALSE, sizeof(float)*4); //마지막 sizeof(float)*4 offset
	glVertexArrayAttribBinding(vaohandle, 1, 0); //1 : 속성번호 0 : binding index
	glEnableVertexArrayAttrib(vaohandle, 1); //속성번호 1 enable
	//번호의 의미 시험에 나옴.. 꼭 기억!
	*/

	GLfloat cube_vertices[] = { 
	// front
	-1.0, -1.0, 1.0, 
	1.0, -1.0, 1.0, 
	1.0, 1.0, 1.0, 
	-1.0, 1.0, 1.0, 
	// back
	-1.0, -1.0, -1.0, 
	1.0, -1.0, -1.0, 
	1.0, 1.0, -1.0, 
	-1.0, 1.0, -1.0,
	};
	GLfloat cube_colors[] = { 
	// front colors
	1.0, 0.0, 0.0,
	0.0, 1.0, 0.0,
	0.0, 0.0, 1.0,
	1.0, 1.0, 1.0, 
	// back colors 
	1.0, 0.0, 0.0,
	0.0, 1.0, 0.0,
	0.0, 0.0, 1.0,
	1.0, 1.0, 1.0,
	};
	GLushort cube_elements[] = {
		0, 1, 2,	2, 3, 0,	1, 5, 6,
		6, 2, 1,	7, 6, 5,	5, 4, 7,
		4, 0, 3,	3, 7, 4,	4, 5, 1,
		1, 0, 4,	3, 2, 6,	6, 7, 3,
	};
	/*
	//NON - DSA 방법으로 큐브
	glGenVertexArrays(1, &vaohandle); //컨테이너 생성
	glBindVertexArray(vaohandle); //Bind ? 여러개의 vao중에(만일 여러개 있다면) 어떤거 사용할래?
	//Bind : activate의미, 난 앞으로 여기에 뭔가 작업을 할래라고 지정, 선언
	// 
	//2. VBO 생성(Vertex Buffer Object의 약자) : vertex의 속성 정보 저장
	
	GLuint vbo_positon;
	glGenBuffers(1, &vbo_positon); //vertex 위치 정보를 저장하기 위한 vbo
	glBindBuffer(GL_ARRAY_BUFFER, vbo_positon); //vbo 바인딩 : activate
	glBufferData(GL_ARRAY_BUFFER, sizeof(cube_vertices), cube_vertices, GL_STATIC_DRAW);
	
	//데이터를 메인 메모리 -> GPU메모리로 보낸 후 할당 : 마지막 : usage //변경할려면 다이나믹으로 변경
	glVertexAttribPointer( //GPU 한테, 메모리에 올라온 데이터 해석 방법을 알려줌
		0, //속성 번호
		3, //데이터 수
		GL_FLOAT, //데이터 타입
		GL_FALSE, //normalize 여부
		0, //stride
		0 //offset
	);
	//속성 enable
	glEnableVertexAttribArray(0); //속성 번호 0번 enable

	GLuint vbo_color;
	glGenBuffers(1, &vbo_color); //vertex 색상 정보를 저장하기 위한 vbo
	glBindBuffer(GL_ARRAY_BUFFER, vbo_color); //vbo 바인딩 : activate

	//데이터를 메인 메모리 -> GPU메모리로 보낸 후 할당 : 마지막 : usage //변경할려면 다이나믹으로 변경
	glBufferData(GL_ARRAY_BUFFER, sizeof(cube_colors), cube_colors, GL_STATIC_DRAW);
	glVertexAttribPointer( //GPU 한테, 메모리에 올라온 데이터 해석 방법을 알려줌
		1, //속성 번호
		3, //데이터 수
		GL_FLOAT, //데이터 타입
		GL_FALSE, //normalize 여부
		0, //stride
		0 //offset
	);
	glEnableVertexAttribArray(1); //속성 번호 1번 enable

	GLuint ibo_cube_elements;
	glGenBuffers(1, &ibo_cube_elements);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo_cube_elements);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cube_elements), cube_elements, GL_STATIC_DRAW);

	

	//vao unbound
	glBindVertexArray(0); //현재 사용중인 vao unbound(0을 넣으면 됨)
	*/

	//DSA 방법으로 큐브
	GLuint vbo_position;
	GLuint vbo_color;
	//glCreate*** -> DSA
	glCreateVertexArrays(1, &vaohandle);
	glCreateBuffers(1, &vbo_position);
	glCreateBuffers(1, &vbo_color);

	//2.vbo 생성
	//position 처리
	//GPU 메모리 할당
	glNamedBufferData(vbo_position, sizeof(cube_vertices), cube_vertices, GL_STATIC_DRAW);
	//GPU에게 해석방법 알려줌
	glVertexArrayVertexBuffer(
		vaohandle, //vao
		0,//binding index 번호 : vao 컨테이너 안 16개의 vbo슬롯 중 0번
		vbo_position,//vbo
		0,//offset
		sizeof(float) * 3 //stride
	);

	//color 처리
	//GPU 메모리 할당
	glNamedBufferData(vbo_color, sizeof(cube_colors), cube_colors, GL_STATIC_DRAW);
	//GPU에게 해석방법 알려줌
	glVertexArrayVertexBuffer(
		vaohandle, //vao
		1,//binding index 번호 : vao 컨테이너 안 16개의 vbo슬롯 중 1번
		vbo_color,//vbo
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

	glVertexArrayAttribFormat(
		vaohandle,
		1, //속성번호
		3, //vertex당 데이타 수
		GL_FLOAT,
		GL_FALSE,
		0//offset
	);
	glVertexArrayAttribBinding(vaohandle,
		1, //속성번호 1
		1 //binding index 1
	);
	glEnableVertexArrayAttrib(vaohandle, 1); //1번 속성 enable

	GLuint ibo_cube_elements;
	glCreateBuffers(1, &ibo_cube_elements); //Gluint ibo_cube_elements
	glNamedBufferData(ibo_cube_elements, sizeof(cube_elements), cube_elements, GL_STATIC_DRAW);
	glVertexArrayElementBuffer(vaohandle, ibo_cube_elements);



}

void MyGlWindow::draw(void)
{
	glClearColor(0.2, 0.2, 0.2, 1); //백그라운드 색상 지정 (R, G, B ,A)
	//어떤 버퍼를 지울지 지정 : 라스터라이제이션 할때 두 개의 버퍼 : color, depth
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // | : bit or
	//0. 뷰포트 설정 : 캔버스 크기 및 위치 설정 : 현재는 800x800인데, 이걸 다 쓸건지 일부만 쓸건지 결정
	glViewport(0, 0, m_width, m_height); //앞 두개는 값: 시작점, 뒤 두개: 크기
	//1. 쉐이더 use
	shaderProgram->use();
	//2. vao binding
	glBindVertexArray(vaohandle);
	//3. cal draw function
	//인덱스가 없을 때 그리기
	//glDrawArrays(GL_TRIANGLE_STRIP, 0, 3); //어떻게 그릴래? 삼각형으로, 시작 인덱스, 끝 인덱스
				//primitive ; 총 3가지 Point, line, Triangle
				// GL_TRIANGLES는 내가 꼭짓점을 만들어줘야함
				//GL_TRIANGLE_STRIP은 v0,v1,v2,v3만 있어도 자동으로 반복 [v0,v1,v2],[v1,v2,v3]
	//인덱스가 있을 때 그리기 
	int size;
	glGetBufferParameteriv(GL_ELEMENT_ARRAY_BUFFER, GL_BUFFER_SIZE, &size);
	glDrawElements(GL_TRIANGLES, size / sizeof(GLushort), GL_UNSIGNED_SHORT, 0);
	//4. 쉐이더 disable
	
	shaderProgram->disable();
}
