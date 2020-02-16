#include "Vigenere.h"
#include "Affine.h"
#include <fstream> 
#include <sstream>
#include <time.h> 

void toFile(string name, string content){
    cout << name << endl;
    ofstream fileO(name);
    fileO << content;
    fileO.close();
}

int main(int argc, char* argv[]){
    string alphabet;
    string menssage;
    srand (time(NULL));
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
            /*
            char sel;
            cout << "¿Random key?(y/n): ";
            scanf("%c", &sel);
            if(sel != 'y'){
                key = "";
                int max = rand() % menssage.length() + 1;
                for(int i = 0; i < max; i++)
                    key.push_back(alphabet[rand() % alphabet.length()]);
                toFile("key.vig", key);
            }else{
                cout << "Introduce la llave(Cadena): ";
                getline(cin, key);
            }*/ 
            Vigenere vigenere(key, alphabet, menssage);
            vigenere.encrypt();
            toFile(fileName.replace(fileName.find_first_of('.'), 4, ".vig"), vigenere.getCipherMenssage());
        }else if(atoi(argv[3]) == 2){
            AffineKey key;
            char sel;
            cout << "¿Random key?(y/n): ";
            scanf("%c", &sel);
            if(sel == 'y'){
                do{
                    key.a = rand() % alphabet.length();
                }while(Affine::modInverse(key.a, alphabet.length()) <= 0);
                key.b = rand() % alphabet.length();            
                toFile("key.aff", to_string(key.a) + " " + to_string(key.b));
            }else{
                cout << "Introduce la llave(Dos enteros): ";
                scanf("%d %d", &key.a, & key.b); 
            }
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
        }else if(atoi(argv[3]) == 4){
            AffineKey key;
            cout << "Introduce la llave(Dos enteros): ";
            scanf("%d %d", &key.a, & key.b);     
            Affine affine(key, alphabet);
            affine.setCipherMenssage(menssage);
            affine.decrypt();
            toFile(fileName.replace(fileName.find_first_of('.'), 4, ".txt"), affine.getMenssage());
        }else{
            cerr << "Tercer argumento invalido" << endl;
            exit(1);
        }
                

        fileAlpha.close();

    }else{
        cerr << "Faltan argumentos" << endl;
        exit(1);
    }
    return 0;
}