/**
 * Anılcan ÇAKIR
 * 16070006108
 */

#include <iostream>
#include "bst.h"

using namespace std;

/**
 * The array stores our numbers
 */
int arr[100];

/**
 * The ordered array and this length
 */
int orderArr[100];
int orderLength = 0;

/**
 * The binary tree stores our numbers
 */
BST tree;


/**
 * Generate random array with input paramters
 * @param inputArr
 * @param count
 * @param min
 * @param max
 */
void generateRandomArray(int inputArr[], int count, int min, int max){
    for (int i = 0; i < count; ++i) {
        inputArr[i]=(rand() % (max- - min)) + min;// Generated Random Numbers.
    }
}

/**
 * Print input array
 * @param inputArr
 * @param count
 */
void printArray(int inputArr[], int count) {
    for (int i = 0; i < count; ++i) {
        cout << "[" << i << "] => " << inputArr[i] << endl;
    }
}

/**
 * Print input node and next
 * @param currentNode
 * @param indent
 */
void printNode(node *currentNode) {
    if (currentNode) {
        printNode(currentNode->left);
        cout << currentNode->data << endl;
        printNode(currentNode->right);
    }
}

/**
 * Print tree
 * @param bst
 */
void printTree(BST bst) {
    cout << "<tree starting>" << endl;
    printNode(bst.getRoot());
    cout << "</tree end>" << endl;
}

/**
 * Node data to push the order array and next
 * @param currentNode
 */
void nodeToArray(node *currentNode) {
    if (currentNode) {
        nodeToArray(currentNode->left);

        orderArr[orderLength] = currentNode->data;
        orderLength++;

        nodeToArray(currentNode->right);
    }
}

/**
 * Start copy array to tree for oredering
 * @param bst
 */
void orderTreeAndCopyArray(BST bst) {
    nodeToArray(bst.getRoot());
}

/**
 * Instert array to tree
 * @param inputArr
 * @param count
 * @return
 */
int insertTreeByCheckingUnique(int inputArr[], int count) {
    int totalDuplicate = 0;
    int duplicateArr[count - 1]; // It can be only count - 1

    // First insert can't be duplicate
    tree.insert(inputArr[0]);

    for (int i = 1; i < count; ++i) {
        if (tree.search(inputArr[i])) {
            totalDuplicate++;
            duplicateArr[totalDuplicate + 1] = inputArr[i];
        } else {
            tree.insert(inputArr[i]);
        }
    }

    if (totalDuplicate > 0) {
        cout << "We have " << totalDuplicate << " duplicate numbers. Our duplicate numbers are" << endl;
        printArray(duplicateArr, totalDuplicate - 1);
    }

    return totalDuplicate;
}

int main() {
    cout << "Generating numbers..." << endl;
    generateRandomArray(arr, 100, 0, 100);
    printArray(arr, 100);
    cout << "Insert the tree and checking duplicates..." << endl;
    int totalDup = insertTreeByCheckingUnique(arr, 100);
    if (totalDup < 0) {
        cout << "We haven't any duplicate numbers :)" << endl;
    }

    cout << "Our tree is now" << endl;
    printTree(tree);

    cout << "Order numbers with binary search and copy to array" << endl;
    orderTreeAndCopyArray(tree);
    cout << "Ordered array" << endl;
    printArray(orderArr, orderLength);

    return 0;
}