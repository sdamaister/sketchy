// sketchy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>

static const struct
{
	float x, y;
	float r, g, b;
} vertices[3] =
{
	{ -0.6f, -0.4f, 1.f, 0.f, 0.f },
	{ 0.6f, -0.4f, 0.f, 1.f, 0.f },
	{ 0.f,  0.6f, 0.f, 0.f, 1.f }
};

float positionData[] = {
	-0.8f, -0.8f, 0.0f,
	0.8f, -0.8f, 0.0f,
	0.0f, 0.8f, 0.0f };

float colorData[] = {
	1.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f };

static const char* vertex_shader_text =
"#version 440\n"
"layout(location = 0) in vec3 VertexPosition;\n"
"layout(location = 1) in vec3 VertexColor;\n"
"uniform mat4 RotationMatrix;\n"
"out vec3 Color;\n"
"void main()\n"
"{\n"
"	Color = VertexColor;\n"
"	gl_Position = RotationMatrix * vec4(VertexPosition,1.0);\n"
"}\n";

static const char* fragment_shader_text =
"#version 440\n"
"in vec3 Color;\n"
"out vec4 FragColor;\n"
"void main() {\n"
"	FragColor = vec4(Color, 1.0);\n"
"}\n";

static void error_callback(int error, const char* description)
{
	fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}

static void LogConsoleString(const char* aFormat, ...)
{
	va_list lArgs;
	va_start(lArgs, aFormat);
	char lBuff[1024] = { 0 };
	sprintf(lBuff, aFormat, lArgs);
	std::wostringstream os_;
	os_ << lBuff << "\n";
	OutputDebugString(os_.str().c_str());
}

bool checkShaderCompiled(GLuint aShader)
{
	GLint isCompiled = 0;
	glGetShaderiv(aShader, GL_COMPILE_STATUS, &isCompiled);
	if (GL_FALSE == isCompiled)
	{
		GLint maxLength = 0;
		glGetShaderiv(aShader, GL_INFO_LOG_LENGTH, &maxLength);

		GLchar* lErrorLog = new GLchar[maxLength];
		
		glGetShaderInfoLog(aShader, maxLength, &maxLength, lErrorLog);
		char lBuff[1024];
		sprintf(lBuff, " Compilation shader errors: %d", 1);
		printf(lBuff);
		LogConsoleString(" Compilation shader errors: %d", 1);
		LogConsoleString(lErrorLog);
		
		delete[] lErrorLog;

		return false;
	}

	return true;
}

GLuint vaoHandle;


int main(void)
{
	GLFWwindow* window;
	GLuint vertex_buffer, vertex_shader, fragment_shader, program;
	GLint mvp_location, vpos_location, vcol_location;
	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
		exit(EXIT_FAILURE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwSetKeyCallback(window, key_callback);
	glfwMakeContextCurrent(window);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	glfwSwapInterval(1);
	
	vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, &vertex_shader_text, NULL);
	glCompileShader(vertex_shader);

	if (!checkShaderCompiled(vertex_shader))
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, &fragment_shader_text, NULL);
	glCompileShader(fragment_shader);

	if (!checkShaderCompiled(fragment_shader))
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	program = glCreateProgram();
	glAttachShader(program, vertex_shader);
	glAttachShader(program, fragment_shader);
	glLinkProgram(program);

	GLint status;
	glGetProgramiv(program, GL_LINK_STATUS, &status);
	if (GL_FALSE == status) {
		fprintf(stderr, "Failed to link shader program!\n");
		GLint logLen;

		glGetProgramiv(program, GL_INFO_LOG_LENGTH,
			&logLen);
		if (logLen > 0)
		{
			char * log = new char[logLen];
			GLsizei written;
			glGetProgramInfoLog(program, logLen, &written, log);
			fprintf(stderr, "Program log: \n%s", log);
			delete[] log;
		}
	}
	else
	{
		glUseProgram(program);
	}

	// Create and populate the buffer objects
	GLuint vboHandles[2];
	glGenBuffers(2, vboHandles);
	GLuint positionBufferHandle = vboHandles[0];
	GLuint colorBufferHandle = vboHandles[1];

	// Populate the position buffer
	glBindBuffer(GL_ARRAY_BUFFER, positionBufferHandle);
	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), positionData, GL_STATIC_DRAW);

	// Populate the color buffer
	glBindBuffer(GL_ARRAY_BUFFER, colorBufferHandle);
	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), colorData, GL_STATIC_DRAW);

	// Create and set-up the vertex array object
	glGenVertexArrays(1, &vaoHandle);
	glBindVertexArray(vaoHandle);
	// Enable the vertex attribute arrays
	glEnableVertexAttribArray(0); // Vertex position
	glEnableVertexAttribArray(1); // Vertex color
								  // Map index 0 to the position buffer
	glBindBuffer(GL_ARRAY_BUFFER, positionBufferHandle);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	// Map index 1 to the color buffer
	glBindBuffer(GL_ARRAY_BUFFER, colorBufferHandle);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	glFlush();
	glClearColor(0.3f, 0.3f, 0.3f, 0.3f);

	float lAngle = 0.5f;

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), lAngle * static_cast<float>(glfwGetTime()), glm::vec3(0.0f, 0.0f, 1.0f));
		GLuint location = glGetUniformLocation(program, "RotationMatrix");
		if (location >= 0)
		{
			glUniformMatrix4fv(location, 1, GL_FALSE, &rotationMatrix[0][0]);
		}
		glBindVertexArray(vaoHandle);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		 
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}
