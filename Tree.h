

#include <iostream>
#include <string>
using namespace std;
struct Arbre {
    string value;
    Arbre* gauche; 
    Arbre* droite; 
};
class Tree {
private:
    Arbre* racine; 
    void deleteTree(Arbre* node);
    Arbre* createNewChild(string value);
public:
    Tree();
    ~Tree();
    void inserer(Arbre*& racine, string value, int& isInserer);
    void addValue(string value);
    void parcoursPostfixe(Arbre* racine);
    Arbre* getRoot();
    void bfs(Arbre* racine);
};


