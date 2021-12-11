#include "trie.hpp"

#include <utility>
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;


std::vector<std::string> extract(const trie &t) {
    return {t.begin(), t.end()};
}

bool containAnotherChildren(const trie_node *node, int begin) {
    for (int i = begin; i < num_chars; i++) {
        if (node->children[i] != nullptr) {
            return true;
        }
    }
    return false;
}

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
    if (!node->is_terminal) {
        while (node->parent != nullptr) {
            if (containAnotherChildren(node->parent, node->payload + 1)) {
                return findBegin(node->parent, node->payload + 1);
            } else {
                node = node->parent;
            }
        }
    }
    return const_cast<trie_node *>(node);
}

trie_node *createNewNode(trie_node *parent, char &str) {
    trie_node *newNode = new trie_node();
    newNode->payload = str;
    newNode->parent = parent;
    parent->children[str] = newNode;
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

trie::~trie() {
    deleteNode(m_root);
    m_size = 0;
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

bool notContainAnother(trie_node *node) {
    for (int i = 0; i < num_chars; i++) {
        if (node->children[i] != nullptr) {
            return false;
        }
    }
    return true;
}

void deleteParentNodes(trie_node *node) {
    if (node->parent == nullptr) {
        return;
    }
    if (containAnotherChildren(node, 0)) {
        return;
    } else {
        node->parent->children[node->payload] = nullptr;
        deleteParentNodes(node->parent);
        delete node;
        return;
    }
}


bool trie::erase(const std::string &str) {
    trie_node *node = m_root;
    for (int i = 0; i < str.size(); i++) {
        if (node->children[str[i]]->payload == str[i]) {
            node = node->children[str[i]];
        } else {
            return false;
        }
    }
    if (node->is_terminal) {
        node->is_terminal = false;
        m_size--;
        if (notContainAnother(node) && !node->is_terminal) {
            node->parent->children[node->payload] = nullptr;
            deleteParentNodes(node->parent);
            delete node;
        } else {
            return true;
        }
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
    return extract(*this) == extract(rhs);
}

bool operator!=(const trie &lhs, const trie &rhs) {
    return extract(lhs) != extract(rhs);
}

std::ostream &operator<<(ostream &out, const trie &trie) {
    return out;
}


//! Lexicografické uspořádání, viz operator<
bool operator<=(const trie &lhs, const trie &rhs) {
    return extract(lhs) <= extract(rhs);
}

//! Lexicografické uspořádání, viz operator<
bool operator>(const trie &lhs, const trie &rhs) {
    return extract(lhs) > extract(rhs);
}

//! Lexicografické uspořádání, viz operator<
bool operator>=(const trie &lhs, const trie &rhs) {
    return extract(lhs) >= extract(rhs);
}

bool trie::operator<(const trie &rhs) const {
    return extract(*this) < extract(rhs);
}

//Stage 4

std::vector<std::string> trie::search_by_prefix(const string &prefix) const {
    std::vector<std::string> allString = extract(*this);
    std::vector<std::string> result;
    for (auto value: allString) {
        if (value.size() < prefix.size()) {
            continue;
        } else if (value.substr(0, prefix.size()) == prefix) {
            result.push_back(value);
        }
    }
    return result;
}

std::vector<std::string> trie::get_prefixes(const string &str) const {
    std::vector<std::string> allString = extract(*this);
    std::vector<std::string> result;
    for (auto value: allString) {
        if (!str.find(value)) {
            result.push_back(value);
        }
    }
    return result;
}

trie trie::operator&(const trie &rhs) const {
    trie trieResult;
    if (this->empty() || rhs.empty()) {
        return trie();
    }
    if(extract(*this).size() < extract(rhs).size()){
        for(auto elem : extract(*this)){
            if(rhs.contains(elem)){
                trieResult.insert(elem);
            }
        }
    } else {
        for(auto elem : extract(rhs)){
            if(this->contains(elem)){
                trieResult.insert(elem);
            }
        }
    }
    return trieResult;
}



trie trie::operator|(const trie &rhs) const {
    std::vector<std::string> thisString = extract(*this);
    std::vector<std::string> rhsString = extract(rhs);
    std::vector<std::string> allString = extract(rhs);

    allString.insert(allString.end(), thisString.begin(), thisString.end());
    allString.insert(allString.end(), rhsString.begin(), rhsString.end());
    if (thisString.size() == 1 && rhsString.size() == 1) {
        return trie();
    }

    if (thisString.size() == 1) {
        return trie(rhsString);
    }

    if (rhsString.size() == 1) {
        return trie(thisString);
    }


    sort(allString.begin(), allString.end());
    vector<std::string>::iterator it;
    it = std::unique(allString.begin(), allString.end());
    allString.resize(distance(allString.begin(), it));

    return trie(allString);
}