#include "preprocess.h"

int preprocess(string filenamein, string filenameout){
    fstream file(filenamein);
	ofstream output(filenameout);
	string line, newline, auxiliar, rotulo;

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

	while(getline(file, line)){				                        //Loop principal, percorre cada linha do arquivo
		
		int verifica = 0;

		for(int i = 0; i < int(line.size()); i++){                  //Loop secundário, percorre cada caractere da linha
			
			line.erase(std::remove_if(line.begin(), line.end(), [](char caracter){      //Remove linhas vazias
				return std::isspace(caracter) && caracter != ' '; }), line.end());

			if(line[i] == ' ' && line[i+1] == ':'){					//Tira espaço antes de dois pontos
				line.erase(i, 1);
			}
			if(line[i] == ',' && line[i+1] != ' '){                 //Espaço antes e depois da vírgula
				line.insert(i+1, 1, ' ');
			}
			else if(line[i] != ' ' && line[i+1] == ','){
				line.insert(i+1, 1, ' ');
			}

			if(line[i] == ':' && line[i+1] == ' ' && (!isalpha(line[i+2]))){      //Rotulo seguido de dois pontos e enter pt.1
				verifica++;
				auxiliar = line.substr(0, i+1);
				//rotulo = line.substr(0, i);
			}
			if(verifica!=0){
				line.clear();
				line = auxiliar;
				getline(file, newline);
				line = auxiliar + " " + newline;		//Rotulo seguido de dois pontos e enter pt.2
				auxiliar.clear();
				newline.clear();
				verifica=0;
				break;		
			}
		
			if(line[i] == ';'){							//Retira todos os comentários
				int j = i;
				while(j < int(line.size())){
					line[j] = ' ';
					j++;
				}
			}
						
			while(line[0] == ' '){						//Retira espaços no começo da linha
				line.erase(0, 1);
			} 

			for(char &caracter : line){
        		caracter = std::toupper(caracter);      //Transforma tudo em maiúsculo
   			}
		}
		
		std::istringstream ler(line);
        std::ostringstream juntar;	
        std::string proxima;

		int verifica2 = 0;
        int palavra = 1;
        
        while(ler >> proxima){                         //Tira espaços no meio da linha
            if(palavra == 1){
                juntar << proxima;
                palavra = 0;
            }else {
                juntar << ' ' << proxima;
            }
			verifica2 = 1;
        }

		if(verifica2 == 1){
			output << juntar.str() << std::endl;       //Linhas com espaços removidos do meio
		}
		else if(int(line.size())){
			output << line << endl;         
		}

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
da “,”(ex: COPY A1 , A2) (OK)

- SEMPRE tera UM espaço no mínimo entre TOKENS, com exceção do “:” (ex. R1: 
INPUT N1) (OK)
*/
