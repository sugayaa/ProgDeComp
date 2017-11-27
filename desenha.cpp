/*********************************************************\
^Trabalho da Disciplina de Programação de Computadores	  ^
^Professor: Renato Bueno                                  ^
^Tópico: Polimorfismo                                     ^
^Autor: Vitor Sugaya 		RA:							  ^
^Realização: 11/2017									  ^
\*********************************************************/

#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<time.h>
#include<unistd.h>
#include <cstdlib>
using namespace std;

/*
Dividi o código em seções para facilitar o entendimento:

	0.1 - variáveis globais de posicionamento - linha 57

	1 - Classes:
		1.1 - Classe abstrata - linha 67 
		1.2 - Classes filhas - linha 145
			1.2.1 - Exemplo Classe filha - linha 149
	2 - Funções:
		2.1 - Sobrecarga de operadores - linha 249
		2.2 - Funções:
			2.2.1 - Funcao De Ordenacao - linha 282
			2.2.2 - Funcao de randomizar Posicao de Objeto - linha 296
			2.2.3 - Funcao de resetar variaveis globais de posicionamento - linha 301
	3 - MAIN:
		3.1 - Preparação do programa:
			3.1.1 - Declaração de variáveis e leitura - linha 314
			3.1.2 - Declaração de vetor de ponteiros do tipo Figura(classe abstrata) - linha 328
			3.1.3 - Declaração de objetos das classes derivadas - linha 330
			3.1.4 - Posicionando cada objeto dentro do vetor do ponteiros - linha 365
		3.2 - Menu:
			3.2.1 - Funcionamento do Menu - linha 394
			3.2.2 - Casos:
				3.2.0 - Caso 0 - linha 547
				3.2.1 - Caso 1 - linha 401
				3.2.2 - Caso 2 - linha 414
				3.2.3 - Caso 3 - linha 439
				3.2.4 - Caso 4 - linha 489
				3.2.5 - Caso 5 - linha 512
				3.2.6 - Caso 6 - linha 536
				3.2.7 - Caso d - linha 553
		3.3 - Debugger - linha 563



*/



//Variáveis Globais que as funções de posicionamento da figura utilizam-se
int x=1;
int y=1;

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1.1
SEÇÃO
Classes
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

//1.2
//CLASSE ABSTRATA FIGURA, POSSUI MÉTODOS VIRTUAIS E Ñ POSSUI OBJETO INSTANCIADO
class figura{
	private:
		//Utilização de pair para armazenamento de coordenadas
		pair <int, int> posicao;
	public:
		//Método construtor de figura, caso não receba parâmetros, construirá objeto c coordenadas (0,0).
		//OBS: O construtor apenas será usado por suas classes filhas, uma vez que a classe figura não consegue instaciar objetos.
		//	   Devido a seus métodos virtuais puros
		figura(int posicaox = 0, int posicaoy = 0){
			if(posicaox >= 0)
				posicao.first = posicaox;
			if(posicaoy >= 0)
				posicao.second = posicaoy;
		}
		//Método para alterar posição
		void setPosicao(int posx, int posy){
			if(posx >= 0)
				posicao.first = posx;
			if(posy >= 0)
				posicao.second = posy;	
		}
		//Método que implementa posicionamento da figura
		void posiciona()const{
			pair <int,int> pos = getPosicao();
			//Percorre as linhas para posicionar o cursor
			for(int i = 1; i < pos.second - y; ++i){
				cout << endl;
				y++;
				x = 1;
			}
			//Percorre as colunas uma vez na linha correta
			for(int i = 1; i <= pos.first - x; ++i){
				cout << "	";
				x++;
			}
		}
		//Método que implementa posicionamento da figura, mas dessa vez mostrando o par de coordenadas de cada objeto
		void posicionaAvancado()const{
			pair <int,int> pos = getPosicao();
			for(int i = 1; i < pos.second - y; ++i){
				cout << endl;
				y++;
				x = 1;
			}
			for(int i = 1; i <= pos.first - x; ++i){
				cout << "             ";
				x++;
			}
		}
		void SetPosicao() const{ //Implementacao do metodo solicitado
			posiciona();
			desenha();
		}
		void SetPosicaoAvancado() const{ //Implementacao do metodo solicitado agora mostrando o par de coordenadas
			posicionaAvancado();
			desenhaAvancado();
		}
		pair<int, int> getPosicao() const{ //Getters
			return posicao;
		}
		virtual void desenha() const = 0; //Método virtual puro

		virtual void desenhaAvancado() const = 0;//Método virtual puro

		virtual ~figura(){ }//Destrutor virtual

		//Friends da classe para facilitar execução de sobrecarga
		friend bool operator<(const figura&, const figura&);
		friend bool operator==(const figura&, const figura&);
};

/*
		FIM DA SEÇÃO DA CLASSE MÃE
*/

/*
	1.2
	INÍCIO DE SESSÃO DAS CLASSES FILHAS
*/
//Declaracao de classe circulo herdando publicamente classe figura
class circulo: public figura{
	public:
		//Construtor da classe circulo, antes construindo a base, classe figura
		circulo(int posx, int posy):figura(posx, posy){

		}
		//Destrutor da classe círculo, importante caso hajam endereços armazenados
		~circulo(){

		}
		//Implementação do método desenha, específico da classe filha, uma vez que o método desenha da classe figura era do tipo virtual puro
		void desenha()const{
			cout << "ᴑ";
		}
		//Implementação do método desenhaAvancado, "" "" , agora com coordenadas
		void desenhaAvancado()const{
			cout << "ᴑ" << " pos: (" << getPosicao().first << ", " << getPosicao().second << ")";
		}

};
//FIM DE EXEMPLO DE CLASSES FILHAS
class quadrado: public figura{
	public:
		quadrado(int posx, int posy): figura(posx, posy){

		}

		~quadrado(){

		}

		void desenha()const{
			cout << "ߛ";
		}

		void desenhaAvancado()const{
			cout << "ߛ"<< " pos: (" << getPosicao().first << ", " << getPosicao().second << ")";
		}
};
class triangulo: public figura{
	public:
		triangulo(int posx, int posy): figura(posx, posy){

		}

		~triangulo(){

		}

		void desenha()const{
			cout << "ߡ";
		}

		void desenhaAvancado()const{
			cout << "ߡ" << " pos: (" << getPosicao().first << ", " << getPosicao().second << ")";
		}
};
class ponto: public figura{
	public:
		ponto(int posx, int posy): figura(posx, posy){

		}

		~ponto(){

		}

		void desenha()const{
			cout << "܁";
		}

		void desenhaAvancado()const{
			cout << "܁" << " pos: (" << getPosicao().first << ", " << getPosicao().second << ")";
		}
};
class sigma: public figura{
	public:
		sigma(int posx, int posy): figura(posx, posy){

		}

		~sigma(){

		}

		void desenha()const{
			cout << "ⵉ";
		}

		void desenhaAvancado()const{
			cout << "ⵉ" << " pos: (" << getPosicao().first << ", " << getPosicao().second << ")";
		}
};

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
FIM
SEÇÃO
Classes
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

//2.1
//SOBRECARGA DE OPERADORES
//

bool operator<(const figura& a,const figura& b){
	if(a.posicao.second == b.posicao.second){
		if(a.posicao.first < b.posicao.first)
			return true;
		else
			return false;
	}	
	if(a.posicao.second < b.posicao.second)
		return true;
	else
		return false;
}

bool operator==(const figura& a, const figura& b){
	if(a.posicao.second == b.posicao.second)
		return true;
	else
		return false;
}

//
//
//FIM DA SOBRECARGA

//2.2
//FUNÇÕES
//

//Ordena o vetor de ponteiros a partir da sobrecarga, ordenada primeiramente pela coordenada Y, e em segundo lugar, a coordenada X
void ordenaClasseAbstrata(figura** figGen){
	//Bubble sort
	for(int i = 0; i < 26; ++i){
		for(int j = 0; j < 26 - 1 - i; ++j){
			if(*figGen[j+1]<*figGen[j]){
	   			figura *tmpPtr = figGen[j];
	   			figGen[j] = figGen[j+1];
	   			figGen[j+1] = tmpPtr;
	   		}
		}
	}
}

//Randomiza coordenadas (X,Y), para todo o vetor de ponteiros do tipo Figura, utiliza-se de valores inteiros para limitar a randomização
void randomiza(figura** figGen, int vx, int vy){
	for(int i= 0; i < 26; ++i)
		figGen[i]->setPosicao(rand()%vx+1,rand()%vy+1);
}

void resetXY(){
	x=1;
	y=1;
}
//
//
//FIM ESCOPO FUNÇÕES


//3
//MAIN
int main(){	

	//3.1
	srand (time(NULL));
	int nf, md = 0, mr = 0, mdisco = 0, mj;	
	cout << "Quantas figuras você deseja? 0 < n < 27 ";
	cin >> nf;
	
	while(nf < 1 || nf > 26){
		cout << "Digite um valor válido."<< endl;
		cin >> nf;
	}

	cout << "Insira o modo de jogo: " << endl << "(1)Padrão (2)Randômico (3)Disco (4)Modo Desenvolvedor (5)Como inserir nova Figura (6)Inserir nº de figuras novamente" << endl;
	
	cin >> mj;
	figura * figGen[26] = {NULL};

	//Declarando figuras
	// e seus tipos
	//

	circulo a(rand()%15+1,rand()%25+1);
	quadrado b(rand()%15+1,rand()%25+1);
	sigma c(rand()%15+1,rand()%25+1);
	ponto d(rand()%15+1,rand()%25+1);
	triangulo e(rand()%15+1, rand()%25+1);
	sigma f(rand()%15+1,rand()%25+1);
	ponto g(rand()%15+1,rand()%25+1);
	triangulo h(rand()%15+1, rand()%25+1);
	quadrado ii(rand()%15+1,rand()%25+1);
	sigma j(rand()%15+1,rand()%25+1);
	ponto k(rand()%15+1,rand()%25+1);
	triangulo l(rand()%15+1, rand()%25+1);
	circulo m(rand()%15+1,rand()%25+1);
	circulo n(rand()%15+1,rand()%25+1);
	ponto o(rand()%15+1,rand()%25+1);
	triangulo p(rand()%15+1, rand()%25+1);
	quadrado q(rand()%15+1,rand()%25+1);
	ponto r(rand()%15+1,rand()%25+1);
	triangulo s(rand()%15+1, rand()%25+1);
	quadrado t(rand()%15+1,rand()%25+1);
	sigma u(rand()%15+1,rand()%25+1);
	ponto v(rand()%15+1,rand()%25+1);
	ponto w(rand()%15+1,rand()%25+1);
	triangulo x(rand()%15+1, rand()%25+1);
	quadrado y(rand()%15+1,rand()%25+1);
	ponto z(rand()%15+1,rand()%25+1);

	//
	//FIM SEÇÃO DECLARAÇÃO
	//

	figGen[0] = &a;
	figGen[1] = &b;
	figGen[2] = &c;
	figGen[3] = &d;
	figGen[4] = &e;
	figGen[5] = &f;
	figGen[6] = &g;
	figGen[7] = &h;
	figGen[8] = &ii;
	figGen[9] = &j;
	figGen[10] = &k;
	figGen[11] = &l;
	figGen[12] = &m;
	figGen[13] = &n;
	figGen[14] = &o;
	figGen[15] = &p;
	figGen[16] = &q;
	figGen[17] = &r;
	figGen[18] = &s;
	figGen[19] = &t;
	figGen[20] = &u;
	figGen[21] = &v;
	figGen[22] = &w;
	figGen[23] = &x;
	figGen[24] = &y;
	figGen[25] = &z;

/*
	MENU
	Funcionamento:
		O menu rodará enquanto o usuário não digitar 0 em sua instância, após selecionar um caso e executá-lo o menu tornará a aparecer
		permitindo assim uma execução contínua do programa.
*/
while(mj != 0){
	switch(mj){
		//Caso 1: apenas mostra as figuras na tela durante o tempo de 3 segundos
		case 1:
			{
				ordenaClasseAbstrata(figGen);	//Ordenação do vetor de ponteiros através da sobrecarga
				for(int i = 0; i < nf; ++i)	figGen[i]->SetPosicao();	//imprimindo figuras em suas respectivas posições
				resetXY();	//Resetando variáveis globais, para caso haja futuros 'prints', a posição ficar adequada, caso contrário, printaria tudo na msm linha
				sleep(3);	//Programa aguarda 3 segundos
				system("clear");	//Limpa tela
				break;
			}
		/*
		Caso 2: Printa diversas figuras na tela, durante o tempo de 10 segundos, mas a cada 1 segundo,
				randomizando posicoes, e ordenando novamente
		*/
		case 2:
			{
				time_t t_agora, t_futuro; //Declaração de variáveis de tempo
				t_agora = time(NULL);	//Função time(NULL)  retorna um inteiro referente a quantidades de segundos passados, desde 1970
										//até o momento em que ela é chamada, o controle do tempo é feito por isso
				t_futuro = time(NULL);
	
					while(t_futuro - t_agora < 10){	//Enquanto o tempo de execução for menor do que 10
						
						randomiza(figGen,25,25);
						ordenaClasseAbstrata(figGen);
	
					for(int i = 0; i < nf; ++i)	figGen[i]->SetPosicao();
					resetXY();
					
					cout.flush();
					sleep(1);
					t_futuro = time(NULL);
					system("clear");
					}
				break;
			}
		/*
		Caso 3: Função disco, funcionamente parecido com o caso 2, mas dessa vez, imprime as figuras com cores aleatórias
		*/
		case 3:
			{
				time_t agora, futuro;
				agora = time(NULL);
				futuro = time(NULL);
	
				while(futuro - agora < 10){
					
					randomiza(figGen,35,35);
					ordenaClasseAbstrata(figGen);

					for(int i = 0; i < nf; ++i){
						int cor = rand()%8;
	
						switch(cor){
							case 0:
								cout << "\033[30m"; break;
							case 1:
								cout << "\033[31m"; break;
							case 2:
								cout << "\033[32m"; break;
							case 3:
								cout << "\033[33m"; break;
							case 4:
								cout << "\033[34m"; break;
							case 5:
								cout << "\033[35m"; break;
							case 6:
								cout << "\033[36m"; break;
							case 7:
								cout << "\033[37m"; break;
						}
						figGen[i]->SetPosicao();
						cout << "\033[0m\n";
					}
					resetXY();
	
					cout.flush();
					sleep(2);
					system("clear");
					//clear();
					futuro = time(NULL);
				}
				break;
			}
		/*
		Caso 4: Modo desenvolvedor, parecido com o caso 1, mas dessa vez imprime ao lado da figura, sua posição
				obs: algumas colunas podem aparecer desalinhadas devido a quantidade de texto de uma figura anterior
				$figura "pos(x,y)"
		*/
		case 4:
		{
			char ctrl = 'c';

			randomiza(figGen,25,25);
			ordenaClasseAbstrata(figGen);

			for(int i = 0; i < nf; ++i)	figGen[i]->SetPosicaoAvancado();
			resetXY();

			cout << endl;

			cout << "Pressione 'q' para sair." << endl;

			do{
				cin >> ctrl;
			}while(ctrl != 'q');

			break;
		}
		/*
		Caso 5: Breve Tutorial de como inserir uma figura, usando a função sleep para mostrar pausadamente passo-a-passo
		*/
		case 5:
		{
			cout << "Como inserir uma nova figura: " << endl;
			cout.flush();
			sleep(3);
			cout << "Abra o arquivo desenha.cpp em uma IDE ou editor de texto de sua preferência." << endl;
			cout.flush();
			sleep(3);
			cout << "Antes do fim da seção classes cole esse trecho de código: "<< endl;
			cout << "Fazendo as seguintes alterações, troque o termo 'DES' pelo nome da sua figura, e o termo 'SIM_DES' pelo desenho da sua figura." << endl << endl;
			cout << "class DES: public figura{" << endl << "	public:" << endl << "		DES(int posx, int posy): figura(posx, posy){ }" << endl; 
			cout << "		~DES(){ }" << endl <<  "		void desenha()const{ cout << \"SIM_DES\"; }" << endl;
			cout << "		void desenhaAvancado()const{ cout << \"SIM_DES\" << \" pos: (\" << getPosicao().first << \", \" << getPosicao().second << \")\"; } };" << endl;
			cout.flush();
			sleep(10);
			cout << "Vá até seção declaração de figuras e seus tipos, troque alguns dos tipos das figuras, pela nova inserida, variável inserida no termo 'DES'." << endl;
			cout.flush();
			sleep(5);
			cout << "Pronto, nova figura inserida :)" << endl;
			cout.flush();
			sleep(2);
			break;
		}
		//Caso 6: Permite a alteração do número de figuras mostradas
		case 6:
		{
			cout << "Insira o número de figuras: " << endl;
			cin >> nf;
			while(nf < 1 || nf > 26){
				cout << "Insira um número válido >:("<< endl << "0 < n < 27"<< endl;
				cin >> nf;
			}
			break;
		}
		//Caso 0: Fecha o programa
		case 0:
		{
			exit(0);
		}
		//caso default caso uma opção inválida seja inserida
		default:
		{
			cout << "Insira uma opção de menu válida." << endl;
		}
	}//---> fim do switch
	//Repetição de escolha para adentrar no switch ou sair d programa
	cout << endl << "Insira o modo de jogo: " << endl << "(1)Padrão (2)Randômico (3)Disco (4)Modo Desenvolvedor (5)Como inserir nova Figura (6)Inserir nº de figuras novamente (0)Exit" << endl;
	cin >> mj;
}

	/* Parte do código para testar ordenação do vetor de ponteiros para figuras

		D
			E
				B
					U
						G
							G
								E
									R
										//
	for(int i = 0; i < nf; ++i){
		pair <int, int> p = figGen[i]->getPosicao();
		cout << i <<": ("<<p.first<<","<<p.second<<")"<<endl;
	}
	*/
	
	for(int i = 0 ; i < 26; ++i){
		free(figGen[i]);
		figGen[i] = NULL;
	}
	

	return 0;
}
