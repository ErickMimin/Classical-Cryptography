#ifndef CIPHER_H_
#define CIPHER_H_

#include <iostream>
using namespace std;

    class Cipher{

        protected:
            string alphabet = "";
            string menssage = "";
            string cMenssage = "";
        public:
            Cipher(string, string);
            Cipher(string);
            ~Cipher();
            static int mod(int, int);
            string getCipherMenssage();
            void setCipherMenssage(string);
            string getMenssage();
            virtual void encrypt(){}; 
            virtual void decrypt(){};   

    };
    

#endif