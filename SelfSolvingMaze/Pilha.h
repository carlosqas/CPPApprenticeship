#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#include <iostream>
#include <string>
#include <array>
#include <vector>

using namespace std;

constexpr int MAXPILHA = 10;
using TipoDado = int;

class Pilha {
    private:
        array<TipoDado, MAXPILHA> dados;
        int topo_;
    public:
        Pilha();
        void push(TipoDado elem);
        bool pop();
        TipoDado topo();
        bool vazia();
        bool cheia();
};

Pilha::Pilha(){
    topo_ = -1;
};

void Pilha::push(TipoDado elem){
    if(cheia())
        cerr << "Pilha cheia!" << endl; //cerr é um erro, mesma coisa do COUT
    else {
        ++topo_;
        dados[topo_] = elem;
    }
};

bool Pilha::pop(){
    if(vazia()){
        cerr << "Pilha vazia!" << endl;
        return false;
    }
    else{
        --topo_;
        return true;
    }
};

TipoDado Pilha::topo(){
    if(!vazia())
        return dados[topo_];
    else {
        cerr << "Pilha vazia!" << endl;
        return -1;
    }
};

bool Pilha::vazia(){
    return (topo_ == -1);
};

bool Pilha::cheia(){
    return (topo_ == MAXPILHA - 1);
};

#endif