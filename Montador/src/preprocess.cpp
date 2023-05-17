#include "preprocess.h"

int preprocess(string filenamein, string filenameout){
    fstream file(filenamein);
	ofstream output(filenameout);
	string line, newline;
	string rotulo = "";

	//Testa se os arquivos foram abertos com sucesso
	if(!file.is_open()){
		cout << "Arquivo não encontrado\n";
		return 0;
	}
	if(!output.is_open()){
		cout << "Erro ao criar arquivo de saída\n";
		return 0;
	}

	//Pré-processamento
	while(getline(file, line)){			//Loop principal, percorre cada linha do arquivo
		while(line[0] == ' '){						//Retira espaços no começo da linha
			line.erase(0, 1);
		}
		if(rotulo.size()){
			line = rotulo + " " + line;		//Rotulo seguido de dois pontos e enter, pt2		
			rotulo.clear();
		}

		for(int i = 0; i < int(line.size()); i++){ //Loop secundário, percorre cada caractere da linha
			if(line[i] == ';'){						//Retira todos os comentários
				break;
			}

			if((line[i] == ' ') && ((line[i+1] == ' ') || (line[i+1] == '\n') || (line[i+1] == ';'))){//Retira espaços no meio da linha
				continue;
			}
			newline.push_back(toupper(line[i]));		//Transforma tudo em maiúsculo
		}

		while (newline.back() == ' '){		//Retira espaços no final da linha
			newline.pop_back();
		}

		if(newline.back() == ':'){ //rotulo seguido de dois pontos e ENTER, pt1
			rotulo += newline;
			newline.clear();		
		}

		if(newline.size()){ //Remove linhas vazias
			output << newline << endl;
		}
		newline.clear();
		line.clear();
	}

	//Fecha arquivos
	file.close();
	output.close();
    return 1;
}

/*
- Aceitar Maiúsculas e Minúsculas (não ser sensível ao CASO, dica transforme tudo 
para maisculas num arquivo pre-processado e depois use ele) (DONE)

- Aceitar comentário em qualquer parte do código iniciado por ;. (DONE)

- Desconsiderar todos os espaços, tabulações ou enter desnecessários em qualquer 
parte do código (dica tirar no pre-processamento, isto é importante porque vários 
testes possuem esse tipo de coisas, para verificar se o scanner esta funcionando 
corretamente) (DONE)

- Pode dar rotulo seguido de dois pontos e ENTER. O rotulo é considerado como da 
linha seguinte (dica coloca na mesma linha no arquivo pre-processado) (DONE)

- O comando COPY deve separar os argumentos por “,” COM espaços antes e depois 
da “,”(ex: COPY A1 , A2) (PENDING)

- SEMPRE tera UM espaço no mínimo entre TOKENS, com exceção do “:” (ex. R1: 
INPUT N1) (PENDING)
*/