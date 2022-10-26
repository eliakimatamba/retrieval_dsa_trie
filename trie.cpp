
#include <iostream>
using namespace std;
//WE Should BEGIN With Characterizing Each CHARACTER'S Length.
#define CHAR_SIZE 128 //we can assign the character size as 28.
//WE CAN AS WELL IMPORT THE CODE SNIPPET FOR THE HEADER FILE
#include "trie.h"
//We may now move onto current document, where we'll put this script into action.
int main(){
    Trie* head = new Trie();

    head->insert("Hello");
    cout << head->search("Hello") << " ";      // this outputs 1

    head->insert("HelloWorld");
    cout << head->search("HelloWorld") << " "; // this as well outputs 1

    cout << head->search("Helll") << " ";      // this outputs 0 which means its missing or not found.

    head->insert("Hell");
    cout << head->search("Hell") << " ";       // this output 1 as well

    head->insert("H");
    cout << head->search("h");                 // this output 1 also

    cout << endl;

    head->deletion(head, "Hello");
    cout << head->search("Hello") << " ";      // this outputs 0

    cout << head->search("HelloWord") << " "; // this outputs 1
    cout << head->search("Hell");              // this outputs 1

    cout << endl;

    head->deletion(head, "H");
    cout << head->search("h") << " ";          // this outputs 0
    cout << head->search("Hell") << " ";       // this outputs 1
    cout << head->search("helloworld");        // this outputs 1

    cout << endl;

    head->deletion(head, "HelloWorld");
    cout << head->search("HelloWorld") << " "; // this outputs 0
    cout << head->search("Hell") << " ";       // this outputs 1

    head->deletion(head, "Hell");
    cout << head->search("Hell");              // this outputs 0

    cout << endl;

    if (head == nullptr) {
        cout << "THE TRIE IS EMPTY.!!\n";              // Trie is empty now
    }

    cout << head->search("Hell");              // this finally runs and outputs 0
    return 0;
}