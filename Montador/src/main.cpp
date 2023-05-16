#include "preprocess.h"
#include <string>

using namespace std;



// Para compilar, use: make
// Para rodar, use: ./montador <arquivo de entrada>
// Ex: ./montador ../testes/bin.asm
int main(int argc, char *argv[]){
    
    string filenamein(argv[1]);        //  arquivos para o preprocessador
    string filenameout = "preprocessed.asm";

    if (argc != 2) { // Forma de utilização: ./montador <arquivo de entrada>
         cout << "Numero de argumentos invalido" << endl;
        return 1;
    }

    if(preprocess(filenamein, filenameout)){
        cout << "Arquivo Preprocessado com sucesso" << endl;
    } 
    
    return 0;
}


