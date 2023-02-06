#ifndef NODE_H
#define NODE_H
#include <vector>
#include <string>
struct BobosValuePoint
{
    double x;
    double y;
    bool value;
};
struct Node
{
    Node() : data(std::vector<BobosValuePoint>()), left(nullptr), right(nullptr){};
    Node(std::vector<BobosValuePoint> points) : data(points), left(nullptr), right(nullptr){};
    Node(std::vector<BobosValuePoint> points, Node *leftNode, Node *rightNode) : data(points), left(leftNode), right(rightNode){};
    std::vector<BobosValuePoint> data;
    Node *left;
    Node *right;
    std::string Condition;

public:
    std::string ToString()
    {
        std::string tree = "";
        if(this->left == nullptr && this->right == nullptr){
            return "Leaf";
        }
        tree = "Condition: " + this->Condition;
        if (this->left != nullptr)
        {
            tree += "Left: " + this->left->ToString();
        }
        if (this->right != nullptr)
        {
            tree += "Right: " + this->right->ToString();
        }
        return tree; 
    }
};
#endif