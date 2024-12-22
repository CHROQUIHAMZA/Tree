#include "Tree.h"
#include<queue>
Tree::Tree()
{
    racine = NULL;
}

Tree::~Tree()
{
    deleteTree(racine);
}

void Tree::deleteTree(Arbre* node)
{
    if (!node) return;
    deleteTree(node->gauche);
    deleteTree(node->droite);
    delete node;
}

Arbre* Tree::createNewChild(string value)
{
    Arbre* ne = new Arbre();
    if (!ne)
    {
        printf("Erreur d'allocation de memoire\n");
        exit(-1);
    }
    ne->value = value;
    ne->droite = ne->gauche = nullptr;
    return ne;
}

void Tree::inserer(Arbre*& racine, string value, int& isInserer)
{
    if (!racine)
    {
        racine = createNewChild(value);
        isInserer = 1;
        return;
    }

    if (!racine->gauche)
    {
        racine->gauche = createNewChild(value);
        isInserer = 1;
        return;
    }

    if (!racine->droite)
    {
        racine->droite = createNewChild(value);
        isInserer = 1;
        return;
    }

    inserer(racine->gauche, value, isInserer);
    if (!isInserer)
        inserer(racine->droite, value, isInserer);
}

void Tree::parcoursPostfixe(Arbre* racine)
{
    if (!racine) return;
    parcoursPostfixe(racine->gauche);
    parcoursPostfixe(racine->droite);
    cout << racine->value << " ";
}

Arbre* Tree::getRoot()
{
    return racine;
}

void Tree::bfs(Arbre* root) {
    if (root == nullptr) return;
    queue<Arbre*> file;
    file.push(root);
    while (!file.empty()) {
        Arbre* current = file.front();
        file.pop();

        cout << current->value << " ";

        if (current->gauche) {
            file.push(current->gauche);
        }
        if (current->droite) {
            file.push(current->droite);
        }
    }
    cout << endl;
}

void Tree::addValue(string value)
{
    int isInserer = 0;
    if (!racine)
    {
        racine = createNewChild(value);
        return;
    }
    inserer(racine, value, isInserer);
}
