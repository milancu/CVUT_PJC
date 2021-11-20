#include "trie.hpp"

#include <utility>
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

trie_node *findBegin(const trie_node *node, int begin) {
    for (int i = begin; i < num_chars; i++) {
        if (node->children[i] != nullptr) {
            node = node->children[i];
            i = 0;
            if (node->is_terminal) {
                return const_cast<trie_node *>(node);
            }
        }
    }
    return const_cast<trie_node *>(node);
}

bool containAnotherChildren(const trie_node *node, int begin) {
    for (int i = begin; i < num_chars; i++) {
        if (node->children[i] != nullptr) {
            return true;
        }
    }
    return false;
}

trie_node *createNewNode(trie_node *parent, char &str) {
    trie_node *newNode = new trie_node();
    newNode->payload = str;
    newNode->parent = parent;
    parent->children[str] = newNode;
//    cout << "Vytvorilo se: " << newNode->payload << endl;
    return newNode;
}

void deleteNode(trie_node *node) {
    for (int i = 0; i < num_chars; i++) {
        if (node->children[i] != nullptr) {
            deleteNode(node->children[i]);
        }
    }
    delete node;
}

trie::trie() {
    m_root = new trie_node();
    m_size = 0;
}

trie::trie(const trie &rhs) { //copy construktor
    m_root = new trie_node();
    m_size = 0;
    if (!rhs.empty()) {
        for (auto value: rhs) {
            this->insert(value);
        }
    }
}

trie::trie(trie &&rhs) {
    m_root = new trie_node();
    m_size = 0;
    if (!rhs.empty()) {
        for (auto value: rhs) {
            this->insert(value);
        }
    }
}

trie::trie(const vector<string> &strings) {
    m_root = new trie_node();
    m_size = 0;

    for (string s: strings) {
        insert(s);
    }
}

trie &trie::operator=(const trie &rhs) {
    if (rhs.begin() == this->begin()) {
        for (auto value: rhs) {
            this->insert(value);
        }
        return *this;
    }
    this->~trie();
    this->m_root = new trie_node();
    this->m_size = 0;
    for (auto value: rhs) {
        this->insert(value);
    }
    return *this;
}

trie &trie::operator=(trie &&rhs) {
    this->~trie();
    this->m_root = new trie_node();
    this->m_size = 0;
    if (!rhs.empty()) {
        for (auto value: rhs) {
            this->insert(value);
        }
    }
    return *this;
}

bool trie::erase(const std::string &str) {
    trie_node *currNode = m_root;
    for (int i = 0; i < str.size(); i++) {
        char currentChar = str[i];
        if (currNode->children[currentChar] == nullptr) {
            return false;
        } else {
            currNode = currNode->children[currentChar];
        }
    }
    if (currNode->is_terminal) {
        currNode->is_terminal = false;
        m_size--;
        return true;
    } else {
        return false;
    }
}

bool trie::insert(const std::string &str) {
    trie_node *currNode = m_root;
    if (str == "") {
        m_size++;
        m_root->is_terminal = true;
    }
    for (int i = 0; i < str.size(); i++) {
        char currentChar = str[i];
        if (currNode->children[currentChar] == nullptr) {
            currNode = createNewNode(currNode, currentChar);
        } else {
            currNode = currNode->children[currentChar];
        }
    }
    if (currNode->is_terminal) {
        return false;
    }
    currNode->is_terminal = true;
    m_size++;
    return true;
}

bool trie::contains(const std::string &str) const {
    trie_node *currNode = m_root;
    for (int i = 0; i < str.size(); i++) {
        char currentChar = str[i];
        if (currNode->children[currentChar] == nullptr) {
            return false;
        } else {
            currNode = currNode->children[currentChar];
        }
    }
    return currNode->is_terminal;
}

size_t trie::size() const {
    return m_size;
}

bool trie::empty() const {
    return m_size == 0;
}

trie::~trie() {
    deleteNode(m_root);
    m_size = 0;
}

//Druha stage

trie::const_iterator trie::begin() const {
    if (m_root->is_terminal) {
        return trie::const_iterator(m_root);
    }
    return trie::const_iterator(findBegin(m_root, 0));
}

trie::const_iterator trie::end() const {
    return trie::const_iterator();
}

trie::const_iterator::const_iterator(const trie_node *node) {
    this->current_node = node;
}

trie::const_iterator &trie::const_iterator::operator++() {
    if (current_node->is_terminal && containAnotherChildren(current_node, 0)) {
        current_node = findBegin(current_node, 0);
        return (const_iterator &) current_node;
    }
    while (current_node->parent != nullptr) {
        if (containAnotherChildren(current_node->parent, current_node->payload + 1)) {
            current_node = findBegin(current_node->parent, current_node->payload + 1);
            return (const_iterator &) current_node;
        } else {
            current_node = current_node->parent;
        }
    }
    current_node = nullptr;
    return (const_iterator &) current_node;
}

trie::const_iterator trie::const_iterator::operator++(int) {
    while (current_node->parent != nullptr) {
        if (containAnotherChildren(current_node->parent, current_node->payload + 1)) {
            current_node = findBegin(current_node->parent, current_node->payload + 1);
            return trie::const_iterator(current_node);
        } else {
            current_node = current_node->parent;
        }
    }
    current_node = nullptr;
    return trie::const_iterator(current_node);
}

bool trie::const_iterator::operator==(const trie::const_iterator &rhs) const {
    return current_node == rhs.current_node;
}

bool trie::const_iterator::operator!=(const trie::const_iterator &rhs) const {
    return current_node != rhs.current_node;
}

trie::const_iterator::reference trie::const_iterator::operator*() const {
    const trie_node *currNode = current_node;
    string result = "";

    while (currNode->parent != nullptr) {
        result = currNode->payload + result;
        currNode = currNode->parent;
    }

    return result;
}

//Treti Stage

void trie::swap(trie &rhs) {
    trie_node *currNode = m_root;
    m_root = rhs.m_root;
    rhs.m_root = currNode;

    size_t currSize = m_size;
    m_size = rhs.m_size;
    rhs.m_size = currSize;
}

bool trie::operator==(const trie &rhs) const {
    auto rit = rhs.begin();
    auto lit = this->begin();
    while (rit != rhs.end() && lit != this->end()) {
        if (*rit != *lit) return false;
        rit++;
        lit++;
    }
    return rit == rhs.end() && lit == this->end();
}

bool operator!=(const trie &lhs, const trie &rhs){
    auto rit = rhs.begin();
    auto lit = lhs.begin();
    while (rit != rhs.end() && lit != lhs.end()) {
        if (*rit != *lit) return false;
        rit++;
        lit++;
    }
    return rit == rhs.end() && lit == lhs.end();
}

//! Lexicografické uspořádání, viz operator<
bool operator<=(const trie &lhs, const trie &rhs){
    return false;
}

//! Lexicografické uspořádání, viz operator<
bool operator>(const trie &lhs, const trie &rhs){
    return false;
}

//! Lexicografické uspořádání, viz operator<
bool operator>=(const trie &lhs, const trie &rhs){
    return false;
}

bool trie::operator<(const trie &rhs) const {
    return false;
}

trie trie::operator&(const trie &rhs) const {
    return trie();
}

trie trie::operator|(const trie &rhs) const {
    return trie();
}




