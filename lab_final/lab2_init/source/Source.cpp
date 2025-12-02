
//#define GLFW_INCLUDE_GLU

#include <iostream>

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

#include "MyGlWindow.h"

//#include <memory>

std::unique_ptr<MyGlWindow> win; //Morden cpp : shared_ptr <-많이 씀
//MyGlWindow win; //cpp 98


int main(void)
{	
	/* Initialize the library */ 
	if (!glfwInit())
	{
		// Initialization failed'
		std::cout << "Error" << std::endl;
		return 0;
	}

	//오픈지엘 버전 지정 : 별 상관은 없음 : 4.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	//'오픈지엘 예전 기능은 다 빼고, 신 기능만 쓸래요'라는 뜻 (예전 기능 사용하려면 : COMPATIBLE_PROFILE
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	int width = 800;
	int height = 800; 
	/* Create a windowed mode window and its OpenGL context */ 
	GLFWwindow* window = glfwCreateWindow(width, height, "OpenGL FrameWork", NULL, NULL);
														  //창 이름
	if (!window) 
	{
		glfwTerminate(); 
		return -1;
	}
	//window 제대로 생성 ->
	
	//opengl : 컨텍스트 생성 -> 컨텍스트? 구조체(struct) 생성

	//opengl 구조체 생성
	glfwMakeContextCurrent(window); //구조체 생성 명령어라고 생각
	
	//헬퍼 초기화 : opengl의 함수를 이용하기 위해 helper(loader)를 초기화
	if (gl3wInit()) // 우리가 쓰는건 gl3w 다른거 쓸거면 저 이름만 바꿔주면 됨
	{
		fprintf(stderr, "failed to initialize OpenGL\n"); 
		return -1;
	}

	//3.2version 서포트 하냐? 라는 뜻
	if (!gl3wIsSupported(3, 2)) 
	{
		fprintf(stderr, "OpenGL 3.2 not supported\n"); 
		return -1;
	}

	printf("OpenGL %s, GLSL %s\n", glGetString(GL_VERSION), 
		glGetString(GL_SHADING_LANGUAGE_VERSION));

	//모니터의 refresh rate sync //모니터 헤르츠
	glfwSwapInterval(1); //enable vsync //1넣으면 맞추고 0넣으면 안맞춤

	//printf("OpenGL %s, GLSL %s\n", glGetString(GL_VERSION), glGetString(GL_SHADING_LANGUAGE_VERSION));

	//MyGlwindow class 객체 생성..
	//win = new MyGlWindow(width, height); //cpp 98방식
	//Morden Cpp 이용 : 스마트 포인터(필수로 익혀둘 것) // 자동으로 delete[]도 해줌
	win = std::make_unique<MyGlWindow>(width, height);


	while (!glfwWindowShouldClose(window)) 
	{ 
		//////////////////////////////
		//Do something, 여기에 뭔가를 그려야함
		//매 프레임 draw() 함수 호출
		win->draw();


		




		//사용자의 입력 감지
		//감지하면 callback함수 호출
		/* Swap front and back buffers */ 
		glfwSwapBuffers(window);
		/* Poll for and process events */ 
		glfwPollEvents();

	}

	glfwDestroyWindow(window); 

	glfwTerminate();

	return 0;
}


