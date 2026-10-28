
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> cloned;

    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        // If already cloned, return the existing clone
        if (cloned.count(node)) {
            return cloned[node];
        }

        // Create a clone of the current node
        Node* copy = new Node(node->val);

        // Store it before exploring neighbors to handle cycles
        cloned[node] = copy;

        // Clone all neighbors
        for (Node* neighbor : node->neighbors) {
            copy->neighbors.push_back(cloneGraph(neighbor));
        }

        return copy;
    }
};
