#ifndef __CONSTRUTORES_HPP
#define __CONSTRUTORES_HPP

#define GLM_FORCE_SWIZZLE
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cassert>
#include <iostream>
#include <array>

using namespace std;

void Construtor() {
    cout << "Vector 2" << endl;
    glm::vec2 Point0{ 10.0f, 10.0f};
    cout << "Point0: " << glm::to_string(Point0) << endl;

    cout << "Vector 3" << endl;
    glm::vec3 Point1{ 10.0f, 0.0f, 0.0f};
    cout << "Point1: " << glm::to_string(Point1) << endl;

    cout << "Vector 4" << endl;
    glm::vec4 Point2{ 10.0f, 10.0f, 0.0f, 0.0f};
    cout << "Point0: " << glm::to_string(Point2) << endl;

    cout << "Vector 2 de Inteiros" << endl;
    glm::vec2 Point3{ 3, 4};
    cout << "Point0: " << glm::to_string(Point3) << endl;

    cout << "Vector 3 de Booleanos" << endl;
    glm::vec3 Point4{ true, false, true};
    cout << "Point0: " << glm::to_string(Point4) << endl;

    cout << "Vector 3 de Doubles" << endl;
    glm::vec3 Point5{ 10.0, 20.0, 10.0};
    cout << "Point0: " << glm::to_string(Point5) << endl;

    cout << "Vector 3" << endl;
    glm::vec3 Point6{ Point0, 10.0};
    cout << "Point0: " << glm::to_string(Point6) << endl;
}

void MetodoSwizzle() {
    cout<<"Vector 3"<<endl;
    glm::vec3 Ponto{ 1, 2, 3};
    cout<<"Ponto: "<< glm::to_string(Ponto) <<endl;

    //Podemos usar atalhos
    //Pra funcionar tem que colocar #define GLM_SWIZZLE
    //antes do #include <glm/glm.hpp>
    glm::vec3 Ponto2 = Ponto.xxx();
    //glm::vec3 Ponto3 = Ponto.xyx();
    //glm::vec3 Ponto4 = Ponto.xyxw

    cout << "Ponto Eixo X: " << Ponto2.x << endl;
    cout << "Ponto Eixo Y: " << Ponto2.y << endl;
    cout << "Ponto Eixo Z: " << Ponto2.z << endl;
}

void normaliza(){
    glm::vec3 P0{ 10.0f, 10.0f, 0.0f };
    glm::vec3 P1{ 10.0f, 10.0f, 10.0f };

    cout<< "PO: " << glm::to_string(P0) << endl;
    cout<< "PO: " << glm::to_string(P0) << endl;

    glm::vec3 NormaP0 = glm::normalize(P0);
    cout<<"Normalização do vetor P0 = " << glm::to_string(NormaP0) <<endl;
}

array<glm::vec3, 3> Triangle = {
    glm::vec3{-1.0f, -1.0f, 0.0f},
    glm::vec3{ 1.0f, -1.0f, 0.0f},
    glm::vec3{ 0.0f, -1.0f, 0.0f},
}

GLuint VertexBuffer;



#endif