//
// Created by user on 12/13/2021.
//

#ifndef UNTITLED_TRIE_H
#define UNTITLED_TRIE_H

#endif //UNTITLED_TRIE_H


// A class to store a Trie node
class Trie
{
public:
    bool isLeaf;
    Trie* character[CHAR_SIZE];

    // Constructor
    Trie()
    {
        this->isLeaf = false;

        for (int i = 0; i < CHAR_SIZE; i++) {
            this->character[i] = nullptr;
        }
    }

    void insert(string);
    bool deletion(Trie*&, string);
    bool search(string);
    bool havechildren(Trie const*);
};

//we can now develop an iteration which will be used to insert the key.
void Trie::insert(string key)
{
    // we can now jump to the root node where we can start our execution.
    Trie* curr = this;
    for (int i = 0; i < key.length(); i++)
    {
        //  this code helps in creating a new node incase this path doesnt exist.
        if (curr->character[key[i]] == nullptr) {
            curr->character[key[i]] = new Trie();
        }

        // from there now we can navigate to the next code.
        curr = curr->character[key[i]];
    }

    // we can now mark the current node as leaf.
    curr->isLeaf = true;
}

//we can now develop and iterative function which helps in searching the key in the Trie
//this statement however returns true.
//if the key is not found in the true iterative, then it will be returned as false.
bool Trie::search(string key)
{
    // this will return false when the trie is found to be empty.
    if (this == nullptr) {
        return false;
    }

    Trie* curr = this;
    for (int i = 0; i < key.length(); i++)
    {
        // this now will help us to navigate to the next node.
        curr = curr->character[key[i]];

        //if somehow the string isn't correct (Throughout the Trie, I came to the end of a trail.)
        if (curr == nullptr) {
            return false;
        }
    }

    // If somehow the sequence number is just a parent, coherent and logical manner.
    //This same string's termination has been obtained.
    return curr->isLeaf;
}

// Whenever a network device has had any descendants, this function will return true.
bool Trie::havechildren(Trie const* curr)
{
    for (int i = 0; i < CHAR_SIZE; i++)
    {
        if (curr->character[i]) {
            return true;    //the child is now discovered
        }
    }

    return false;
}

// To eliminate a column inside the Trie, just use recursion procedure.
bool Trie::deletion(Trie*& curr, string key)
{
    // while Trie seems to be null, returns if
    if (curr == nullptr) {
        return false;
    }

    // if indeed the key's ending also isn't achieved
    if (key.length())
    {
        // search again for node that corresponds towards the key's subsequent syllable
        // Terminate the cluster centres if it solutions . these solutions; if it isn't a leaf

        if (curr != nullptr &&
            curr->character[key[0]] != nullptr &&
            deletion(curr->character[key[0]], key.substr(1)) &&
            curr->isLeaf == false)
        {
            if (!havechildren(curr))
            {
                delete curr;
                curr = nullptr;
                return true;
            }
            else {
                return false;
            }
        }
    }

    // if indeed the key's conclusion has been attained
    if (key.length() == 0 && curr->isLeaf)
    {
        // if indeed the currently selected node is indeed a leaf node with no successors
        if (!havechildren(curr))
        {
            // this same present node is removed
            delete curr;
            curr = nullptr;

            // delete the non-leaf parent nodes
            return true;
        }

            // Remove any non-leaf parental nodes from of the tree.
        else {
            // mark the current node as a non-leaf node (DON'T DELETE IT)
            curr->isLeaf = false;

            // Shouldn't Remove This Present NODE So As NON-LEAF Base station or nodes.
            return false;
        }
    }

    return false;
}