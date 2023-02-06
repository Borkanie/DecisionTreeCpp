#ifndef DECISION_H
#define DECISION_H
#include "Node.h"
#include <tuple>
#include <string>
class DecisionTree{
    public:
        DecisionTree() : root(nullptr) {};
        DecisionTree(std::vector<BobosValuePoint> data);
        Node* train(std::vector<BobosValuePoint> data);
        bool predict(BobosValuePoint point);
        std::string ToString();
    private:
        Node* root;
        void train(Node* node);
        //bool predict(Node* node, BobosValuePoint point);
        double getEntropyOfNode(Node* node);
        std::tuple<Node*, Node*, std::string> bestSplit(std::vector<BobosValuePoint> data);
        double getInfoGainOfDecision(std::tuple<Node*,Node*> nodes, std::vector<BobosValuePoint> data);
        
};

#endif
