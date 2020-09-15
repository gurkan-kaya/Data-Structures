#include <iostream>
#include "Kisi.hpp"
#include"AVL.hpp"

        
int main()
{
    system("CLS");
	
    AVLTree* avltree = new AVLTree();

    avltree->Postorder(avltree->root);
	
	avltree->Temizle();
	
	
    return 0;
}

