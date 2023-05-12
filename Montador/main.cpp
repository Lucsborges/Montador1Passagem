#include "preprocess.h"
#include "preprocess.cpp"
#include <string>

using namespace std;



//para compilar, use: make
int main(int argc, char *argv[]){
    string filenamein = argv[1];        //  arquivos para o preprocessador
    string filenameout = argv[2];       //

    if (argc != 2) { // Forma de utilização: ./montador <arquivo de entrada>
         cout << "Numero de argumentos invalido" << endl;
        return 1;
    }

    if(preprocess(filenamein, filenameout)){
        cout << "Arquivo Preprocessado com sucesso" << endl;
    } 

    return 0;
}


