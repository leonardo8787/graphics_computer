#include <bits/stdc++.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;

const char* vertexShaderSource = R"(
    #version 330 core
    layout (location = 0) in vec3 aPos;
    uniform mat4 transformation;
    void main()
    {
        gl_Position = transformation * vec4(aPos, 1.0);
    }
)";

const char* fragmentShaderSource = R"(
    #version 330 core
    out vec4 FragColor;
    void main()
    {
        FragColor = vec4(1.0, 0.5, 0.2, 1.0);
    }
)";

int main() {

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Triângulo", NULL, NULL);

	if (window == NULL) {
		std::cout << "Falha ao criar a janela GLFW." << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glewExperimental = true;
	
	if (glewInit() != GLEW_OK) {
		std::cout << "Falha ao inicializar o GLEW." << std::endl;
		return -1;
	}
	
	glViewport(0, 0, 800, 600);
	
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	
	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f,  0.5f, 0.0f
	};
	
	GLuint VAO, VBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	glm::mat4 transformation = glm::mat4(1.0f);
	
	int aux;
	cout<<"Escolha qual transformação deseja fazer: "<<endl;
	cout<<"1 - Translação"<<endl;
	cout<<"2 - Escala"<<endl;
	cout<<"3 - Rotação"<<endl;
	cout<<"4 - Reflexão"<<endl;
	cin>>aux;

	switch (aux)
	{
	case 1:
		transformation = glm::translate(transformation, glm::vec3(0.5f, 0.5f, 0.0f));
		break;
	case 2:
		transformation = glm::scale(transformation, glm::vec3(0.5f, 0.5f, 0.5f));
		break;
	case 3:
		transformation = glm::rotate(transformation, glm::radians(45.0f), glm::vec3(0.0f, 0.0f, 1.0f));
		break;
	case 4:
		transformation = glm::scale(transformation, glm::vec3(-1.0f, 1.0f, 1.0f));
		break;
	default:
		cout<<"Escolha uma opção válida!!!"<<endl;
		break;
	}

	GLint transformLoc = glGetUniformLocation(shaderProgram, "transformation");
	glUseProgram(shaderProgram);
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transformation));
	
	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(shaderProgram);
	
	glfwTerminate();
    

    return 0;
}
