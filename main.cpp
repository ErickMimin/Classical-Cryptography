#include "Vigenere.h"
#include "Affine.h"
#include <fstream> 
#include <sstream>

void toFile(string name, string content){
    ofstream fileO(name);
    fileO << content;
    fileO.close();
}

int main(int argc, char* argv[]){
    string alphabet;
    string menssage;
    if(argc == 4){
        /* Obtenemos el alfabeto de un archivo*/        
        ifstream fileAlpha(argv[1]);
        getline(fileAlpha, alphabet);

        /* Obtenemos el mensaje de un archivo*/        
        ifstream fileMen(argv[2]);
        getline(fileMen, menssage);

        string fileName(argv[2]);

        if(atoi(argv[3]) == 1){
            string key;
            cout << "Introduce la llave(Cadena): ";
            getline(cin, key);     
            Vigenere vigenere(key, alphabet, menssage);
            vigenere.encrypt();
            toFile(fileName.replace(fileName.find_first_of('.'), 4, ".vig"), vigenere.getCipherMenssage());
        }else if(atoi(argv[3]) == 2){
            AffineKey key;
            cout << "Introduce la llave(Dos enteros): ";
            scanf("%d %d", &key.a, & key.b);     
            Affine affine(key, alphabet, menssage);
            affine.encrypt();
            toFile(fileName.replace(fileName.find_first_of('.'), 4, ".aff"), affine.getCipherMenssage());
        }else if(atoi(argv[3]) == 3){
            string key;
            cout << "Introduce la llave(Cadena): ";
            getline(cin, key);     
            Vigenere vigenere(key, alphabet);
            vigenere.setCipherMenssage(menssage);
            vigenere.decrypt();
            toFile(fileName.replace(fileName.find_first_of('.'), 4, ".txt"), vigenere.getMenssage());
        }else{
            cerr << "Argumento 3 invalido" << endl;
            exit(1);
        }
                

        fileAlpha.close();

    }else{
        cerr << "Faltan argumentos" << endl;
        exit(1);
    }
    return 0;
}