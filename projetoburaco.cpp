#include <iostream>
#include <iomanip>
#include <sstream>
#include <locale.h>
#include <cstdlib>
#include <time.h> 
#include <algorithm>
using namespace std;

// Varíáveis globais
const int n = 2; // repetições
const int c = 52; // número total de cartas para cada baralho
string baralho[n][c]; // baralho

const int nJ = 4; // número de jogadores
const int cJ = 11; // cartas na mão de cada jogador  
string mao[nJ][cJ]; // mao do jogador

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	
	// CRIAR BARALHO
	stringstream ss; // ajuda a converter int em string, já que o baralho e a mão são strings e as outras varíaveis int

	for (int i = 0; i < n; ++i) { // loop para criar o baralho
		int nI = 1; // para garantir que esses fiquem com os valores certo
		int nC = 1;	
		for (int j = 0; j < c; ++j) {
			ss.str(""); // esvazia o stringstream para não ficar concatenando os números
			ss << nI << setw(2) << setfill('0') << nC; // faz o espaçamento e garante que todos os números são dois digitos
			if (i == 1) { // esse if e else definem se o baralho é o primeiro ou o segundo
			    ss << 2;
			} else {
			    ss << 1;
			}
			baralho[i][j] = ss.str(); // coloca no baralho
			//cout << baralho[i][j] << " ";
			
			nC++; // n da carta
			if (nC == 14) { // garante que todas os número de carta são gerados 
				nC = 1;
				nI++; // naipe
			}
			if (nI == 5) { // passa por todos os naipes
				nI = 1;
			}
		}

	}
	
	// DEFINIR VALORES ALEATÓRIOS
	srand(time(0)); // randomiza bem
	
    int cartaIntervalo = 104; // intervalo de cartas, é 104 pois são dois baralhos de 52 cartas
    stringstream carta; // mesma coisa de cima
    
	for (int i = 0; i < nJ; ++i) { // cria a matriz da mao
		for (int j = 0; j < cJ; ++j) {
			int cartaRandom; // é a variavel do número aleatório a ser gerado
	        do { // executa isso pelo menos uma vez
	            cartaRandom = rand() % cartaIntervalo + 1; // randomiza no intervalo especifico
	            carta.str(""); // esvazia para não sobrepor
	            carta << baralho[0][cartaRandom]; // define o valor da carta atual
	        } while (find(&mao[0][0], &mao[nJ - 1][cJ], carta.str()) != &mao[nJ - 1][cJ]);
	        // verifica linha por linha da mao para ver se o numero sorteado é igual a algum valor 
	        mao[i][j] = carta.str(); // coloca a carta escolhida na mao
	        cout << "Carta do jogador " << i + 1 << ": " << mao[i][j] << " " << endl; // imprime
	    }
	}
	
	return 0;
}