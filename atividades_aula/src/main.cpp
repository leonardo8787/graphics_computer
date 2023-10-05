// #include <iostream>
// //Biblioteca do OpenGL
// #include <GL/glew.h>
// //Biblioteca que irá desenhar a tela
// #include <GLFW/glfw3.h>
// //Biliotecas de validação
// #include <cassert>
// #include <array>
// #include <glm/glm.hpp>
// #include <iomanip>
// #include <glm/gtx/string_cast.hpp>

// using namespace std;

// //add_executable(Matrizes "Matrizes.cpp")

// //target_include_directories(Matrizes PRIVATE dependencias/glm)

// //PSSO 1: Definir um triângulo em coordenadas normalizadas
// std::array<glm::vec3, 3> Triangle = {
// 	glm::vec3{-1.0f, -1.0f, 0.0f},
// 	glm::vec3{ 1.0f, -1.0f, 0.0f},
// 	glm::vec3{ 0.0f,  1.0f, 0.0f},
// };

// void imprimirFormatado(const glm::mat4& M){
// 	std::cout << std::endl;
// 	for(int i = 0; i< 4; i++){
// 		for(int j = 0; j < 4; j++){
// 			std::cout
// 			<< std::setw(10)
// 			<< std::setprecision(4)
// 			<< std::fixed
// 			<< M[i][j] << " ";
// 		}
// 		std::cout << std::endl;
// 	}
// }

// void Translacao(){
// 	glm::mat4 MIdentidade = glm::identity<glm::mat4>();
// 	std::cout << "Matriz Identidade" << std::endl;
// 	imprimirFormatado(MIdentidade);

// 	glm::vec3 FatorTranslacao{10.0f,10.0f,10.0f};
// 	std::cout << "Fator de translação" << glm::to_string(FatorTranslacao) << std::endl;

// 	glm::mat4 MTranslacao = glm::translate(MIdentidade,FatorTranslacao);
// 	std::cout << "Matriz de translação" << glm::to_string(FatorTranslacao) << std::endl;
// 	imprimirFormatado(MTranslacao);
	
// 	glm::vec4 Posicao1{10,10,10,1};
// 	std::cout << "Posição original" << glm::to_string(Posicao1) << std::endl;
// 	glm::vec4 Direcao1{10,10,10,0};

// 	glm::vec4 Posicao1Linha = MTranslacao * Posicao1;
// 	std::cout << "Posicao1 transladado:: " << glm::to_string(Posicao1Linha) << std::endl;
// }

// void Escala(){
// 	glm::mat4 MIdentidade = glm::identity<glm::mat4>();
// 	std::cout << "Matriz Identidade" << std::endl;
// 	imprimirFormatado(MIdentidade);

// 	glm::vec3 FatorEscala{2,2,2};
// 	std::cout << "Fator de escala: " << glm::to_string(FatorEscala) << std::endl;

// 	glm::mat4 MEscala = glm::scale(MIdentidade, FatorEscala);
// 	std::cout << "Matriz de Escala" << std::endl;
// 	imprimirFormatado(MEscala);

// 	glm::vec4 Posicao1{100,100,0,1};
// 	std::cout << "Posicao1 original" << glm::to_string(Posicao1);
// 	glm::vec4 Direcao1{100,0,0,0};

// 	Posicao1 = MEscala * Posicao1;
// 	std::cout << "Posicao1 Escalado" << glm::to_string(Posicao1) << std::endl;
// }

// void Rotacao(){

// 	glm::mat4 MIdentidade = glm::identity<glm::mat4>();
// 	std::cout << "Matriz identidade" << std::endl;
// 	imprimirFormatado(MIdentidade);

// 	const float AnguloDeRotacao = glm::radians(90.0f);
// 	glm::vec3 EixoDeRotacao{0,0,1};
// 	glm::mat4 MRotacao = glm::rotate(MIdentidade, AnguloDeRotacao, EixoDeRotacao);
// 	imprimirFormatado(MRotacao);

// 	//Aplicando a rotação no ponto

// 	glm::vec4 Posicao1{100, 0 ,0,1};
// 	std::cout << "Posicao1 original" << glm::to_string(Posicao1) << std::endl;
// 	glm::vec4 Direcao1 {100,0,0,0};

// 	Posicao1 = MRotacao * Posicao1;
// 	std:: cout << "Posicao1 Rotacionado" << glm::to_string(Posicao1) << std::endl;
// }

// void Composicao(){

// 	glm::mat4 MIdentidade = glm::identity<glm::mat4>();
// 	std::cout <<"Matriz Identidade" << std::endl;
// 	imprimirFormatado(MIdentidade);

// 	//Construindo uma Matriz Escala
// 	constexpr float AnguloDeRotacao = glm::radians(45.0f);
// 	glm::vec3 EixoDeRotacao{0,0,1};
// 	glm::mat4 MRotacao = glm::rotate(MIdentidade, AnguloDeRotacao, EixoDeRotacao);

// 	//Construindo uma Matriz de Escala
// 	glm::vec3 FatorEscala{2,2,0};
// 	glm::mat4 MEscala = glm::scale(MIdentidade,FatorEscala);

// 	//Construindo uma Matriz de Translação
// 	glm::vec3 FatorTranslacao{0,10,0};
// 	glm::mat4 MTranslacao = glm::translate(MIdentidade,FatorTranslacao);

// 	//Agrupamentos das Transformações
// 	//Atenção na ordem, pois é multiplicação de matrizes

// 	glm::mat4 Mtransformacao = MTranslacao * MRotacao * MEscala;
// 	std::cout << "Matriz de Transformação" << std::endl;
// 	imprimirFormatado(Mtransformacao);
	
// 	glm::vec4 Posicao {1,1,0,1};
// 	glm::vec4 Direcao {1,1,0,0};

// 	Posicao = Mtransformacao * Posicao;
// 	Direcao = Mtransformacao * Direcao;

// 	std::cout << "Posicao" << glm::to_string(Posicao) << std::endl;
// 	std::cout << "Direcao" << glm::to_string(Direcao) << std::endl;

// }

// void MatrizDeVizualizacao() {
// 	//É a matriz formada pelas as rtansformações Transfalação, Rotação e Escala
// 	glm::mat4 MatrizModel = glm::identity<glm::mat4>();

// 	//Matriz de Visualização
// 	glm::vec3 Eye{ 10,10,10 };
// 	glm::vec3 Center{ 0,0,0 };
// 	glm::vec3 Up{ 0,1,0 };

// 	glm::mat4 MatrizView = glm::lookAt(Eye, Center, Up);
// 	cout<<"Matriz de Visualização"<<endl;
// 	imprimirFormatado(MatrizView);

// 	//Matriz de projeção
// 	constexpr float FoV = glm::radians(45.0f);
// 	const float AspectioRate = 1000.0f / 1000.0f;
// 	const float Near = 1.0f;
// 	const float Far = 100000.0f;

// 	glm::mat4 MatrizProjecao = glm::perspective(FoV, AspectioRate, Near, Far);

// 	cout<<"Matriz de Projeção"<<endl;
// 	imprimirFormatado(MatrizProjecao);

// 	//Gerando o modelo completo
// 	glm::mat4 ModelViewProjection = MatrizProjecao * MatrizView * MatrizModel;

// 	cout<<"Matriz MVP"<<endl;
// 	imprimirFormatado(ModelViewProjection);

// 	//Aplicando o MVP em um ponto qualquer
// 	glm::vec4 Ponto{ 0,0,0,1 };
// 	cout<<"Ponto Original: "<<glm::to_string(Ponto)<<endl;

// 	Ponto = ModelViewProjection * Ponto;
// 	cout<<"Ponto Projetado (Coordenada Homogenia): "<<glm::to_string(Ponto) <<endl;

// 	//Aplicando o MVP no triangulo
// 	for(glm::vec3& Vertice : Triangle){
// 		glm::vec4 VerticeProjetado = ModelViewProjection * glm::vec4{Vertice , 1};

// 		//CAlculando a coordenada homogenea
// 		VerticeProjetado /= VerticeProjetado.w;
// 		Vertice = VerticeProjetado;
// 	}
// }

// //Definindo as dimenções da janela
// const int Width = 800;
// const int Heigth = 600;

// int main() {
// 	setlocale(LC_ALL, "pt_BR");
// 	//Inicializando a biblioteca do GLFW 
// 	assert(glfwInit() == GLFW_TRUE);

// 	//Construindo a janela
// 	GLFWwindow* window = glfwCreateWindow(Width, Heigth, "CG com OpenGL", nullptr, nullptr);
// 	//Verificar se a janela é nula
// 	assert(window);

// 	//Definindo a janela de contexto
// 	glfwMakeContextCurrent(window);

// 	//inicializa o GLEW
// 	int statusGlwInit = glewInit();
// 	std::cout << statusGlwInit << std::endl;
// 	assert(glewInit() == GLEW_OK);
	
// 	//Verificar a versão do OpenGL que está sendo usando
// 	GLint GLMajorVersion = 0;
// 	GLint GLMinorVersion = 0;

// 	glGetIntegerv(GL_MAJOR_VERSION, &GLMajorVersion);
// 	glGetIntegerv(GL_MINOR_VERSION, &GLMinorVersion);

// 	std::cout << "Maior versão do OpenGL suportada:" << GLMajorVersion << std::endl;
// 	std::cout << "Menor versão do OpenGL suportada:" << GLMinorVersion << std::endl;

// 	//Obtendo informações do driver utilizado
// 	std::cout << "Fabircante do driver de video:" << glGetString(GL_VENDOR) << std::endl;
// 	std::cout << "Modelo da placa de video:" << glGetString(GL_RENDERER) << std::endl;
// 	std::cout << "Versão do OpenGL:" << glGetString(GL_VERSION) << std::endl;
// 	std::cout << "Versão do GLS:" << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

// 	//PSSO 1: Definir um triângulo em coordenadas normalizadas
// 	std::array<glm::vec3, 3> Triangle = {
// 		glm::vec3{-1.0f, -1.0f, 0.0f},
// 		glm::vec3{1.0f, -1.0f, 0.0f},
// 		glm::vec3{0.0f, 1.0f, 0.0f},
// 	};

// 	//É a matriz formada pelas as rtansformações Transfalação, Rotação e Escala
// 	glm::mat4 MatrizModel = glm::identity<glm::mat4>();

// 	//Matriz de Visualização
// 	glm::vec3 Eye{ 0,0,10 };
// 	glm::vec3 Center{ 0,0,0 };
// 	glm::vec3 Up{ 0,1,0 };

// 	glm::mat4 MatrizView = glm::lookAt(Eye, Center, Up);
// 	cout<<"Matriz de Visualização"<<endl;
// 	imprimirFormatado(MatrizView);

// 	//Matriz de projeção
// 	constexpr float FoV = glm::radians(45.0f);
// 	const float AspectioRate = 1000.0f / 1000.0f;
// 	const float Near = 1.0f;
// 	const float Far = 100000.0f;

// 	glm::mat4 MatrizProjecao = glm::perspective(FoV, AspectioRate, Near, Far);

// 	cout<<"Matriz de Projeção"<<endl;
// 	imprimirFormatado(MatrizProjecao);

// 	//Gerando o modelo completo
// 	glm::mat4 ModelViewProjection = MatrizProjecao * MatrizView * MatrizModel;

// 	cout<<"Matriz MVP"<<endl;
// 	imprimirFormatado(ModelViewProjection);

// 	//Aplicando o MVP em um ponto qualquer
// 	glm::vec4 Ponto{ 0,0,0,1 };
// 	cout<<"Ponto Original: "<<glm::to_string(Ponto)<<endl;

// 	Ponto = ModelViewProjection * Ponto;
// 	cout<<"Ponto Projetado (Coordenada Homogenia): "<<glm::to_string(Ponto) <<endl;

// 	//Aplicando o MVP no triangulo
// 	for(glm::vec3& Vertice : Triangle){
// 		glm::vec4 VerticeProjetado = ModelViewProjection * glm::vec4{Vertice , 1};

// 		//CAlculando a coordenada homogenea
// 		VerticeProjetado /= VerticeProjetado.w;
// 		Vertice = VerticeProjetado;
// 	}
	
// 	//PASSO 2: copiar os vértices do triângulo para a memória da GPU

// 	// Variável que vai conter o identificador do buffer de vértices
// 	GLuint VertexBuffer;

// 	// Gerar um identificador glGenBuffers(NUMERO DE BUFFER, INDETIFICADOR);
// 	glGenBuffers(1, &VertexBuffer);

// 	//Ativar o buffer de vértices, comandos vão afetar o VertexBuffer.
// 	//O buffer para onde vamos copiar os vertices do triangulo.
// 	glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer);

// 	// Passa para o OpenGL o ponteiro para os dados que serão copiados para GPU
// 	// basicamente copia os dados para a memória de vídeo
// 	// glBufferData(ORIGEM DOS DADOS, TAMANHO EM BYTES, PONTEIRO PARA OS DADOS
// 	//				, TIPO DE USO DO BUFFER);
// 	glBufferData(GL_ARRAY_BUFFER, sizeof(Triangle), Triangle.data(), GL_STATIC_DRAW);


// 	//Definir cor de fundo
// 	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);

// 	//Construindo o loop de eventos
// 	while (!glfwWindowShouldClose(window)) {
// 		// Limpar o Buffer de cor
// 		glClear(GL_COLOR_BUFFER_BIT);

// 		// DESENHAR INICIO
// 		// Habilita o atributo na posição 0, normalmente é o atributo de vértices
// 		// Esse vai ser o identificador que vamos usar no shader para ler a posição
// 		// de cada vértice.
// 		glEnableVertexAttribArray(0);

// 		// Diz para o OpenGL que o VertexBuffer vai ficar associado ao atributo 0
// 		// glBindBuffer(TIPO, BUFFER CRIADO);
// 		glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer);

// 		// Informa ao OpenGL onde, dentro do VertexBuffer, os vértices estão.
// 		// Neste exemplo  o array Triangles é tudo
// 		// glVertexAttribPointer(INDICE, QUANTIDADE DE VERTICES, TIPO
// 		//							, SE AS POCIÇÕES ESTÃO NORMALIZADAS, USADOS EM TEXTURAS
// 		//							, PONTEIRO);
// 		glVertexAttribPointer(0, Triangle.size(), GL_FLOAT, GL_FALSE, 0, nullptr);

// 		// Por fim, diz para o OpenGL desenhar o triângulo
// 		// glDrawArrays(QUE OBJETO SERÁ DESENHADO, INDICE DO OBJETO
// 		//				, QUANTIDADE DE VERTICES PRA DESENHAR);
// 		glDrawArrays(GL_TRIANGLES, 0, Triangle.size());

// 		//Como boa pratica devemos Desliga o glBindBuffer e desabilitar o atributo da posição
// 		//Desliga o glBindBuffer
// 		glBindBuffer(GL_ARRAY_BUFFER, 0);
// 		//desabilitar o atributo da posição
// 		glDisableVertexAttribArray(0);
// 		// DESENHAR FIM
		
// 		//Processa todos os eventos na fila do GLFW
// 		glfwPollEvents();
// 		//Envia o conteúdo para desenhar na tela
// 		glfwSwapBuffers(window);
// 	}

// 	//Desalocar o VertexBuffer da memória de video
// 	glDeleteBuffers(1, &VertexBuffer);

// 	//Finaliza a biblioteca GLFW
// 	glfwTerminate();
// 	return 0;
// }
