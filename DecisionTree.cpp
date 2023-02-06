#include "DecisionTree.h"
#ifdef DECISION_H
#include <algorithm>
#include <cmath>
#include <iostream>
DecisionTree::DecisionTree(std::vector<BobosValuePoint> data)
{
    root = train(data);
}

Node *DecisionTree::train(std::vector<BobosValuePoint> data)
{
    Node *node = new Node(data);

    std::tuple<Node *, Node *,std::string> bestSplit = this->bestSplit(data);
    node->left = std::get<0>(bestSplit);
    node->right = std::get<1>(bestSplit);
    node->Condition = std::get<2>(bestSplit);
    if (getEntropyOfNode(node->left) != 0)
    {
        node->left = this->train(node->left->data);
    }
    if (getEntropyOfNode(node->right) != 0)
    {
        node->right = this->train(node->right->data);
    }
    return node;
}

double DecisionTree::getInfoGainOfDecision(std::tuple<Node *, Node *> nodes, std::vector<BobosValuePoint> data)
{
    double info_gain = 0;
    double total_entropy = 0;

    Node *leftNode = std::get<0>(nodes);
    Node *rightNode = std::get<1>(nodes);
    double leftWheight = ((double)leftNode->data.size() / (double)data.size())*getEntropyOfNode(leftNode) ;
    double rightWheight = ((double)rightNode->data.size() / (double)data.size())*getEntropyOfNode(rightNode);
    total_entropy = leftWheight + rightWheight;

    info_gain =  getEntropyOfNode(new Node(data)) - total_entropy;
    return info_gain;
}

double DecisionTree::getEntropyOfNode(Node *node)
{
    double entropy = 0;
    int number_of_true = 0;
    int number_of_false = 0;
    for (int i = 0; i < node->data.size(); i++)
    {
        if (node->data[i].value == true)
        {
            number_of_true++;
        }
    }
    if(number_of_true == node->data.size()|| number_of_true ==0){
        return 0;
    }
    double p_true = (double)number_of_true / (double)node->data.size();
    double p_false = 1 - p_true;
    entropy = p_true * log2(p_true) + p_false * log2(p_false);
    return -entropy;
}

std::tuple<Node *, Node *, std::string> DecisionTree::bestSplit(std::vector<BobosValuePoint> data)
{
    std::string condition = "";
    Node *left = new Node();
    Node *right = new Node();
    double max_info_gain = -100;
    int number_of_feature = 2;
    // we only have to features so instead of for we just use two loops
    std::vector<double> X_feature;
    std::vector<double> Y_feature;
    for (int i = 0; i < data.size(); i++)
    {
        if (std::find(X_feature.begin(), X_feature.end(), data[i].x) == X_feature.end())
        {
            X_feature.push_back(data[i].x);
        }
        if (std::find(Y_feature.begin(), Y_feature.end(), data[i].y) == Y_feature.end())
        {
            Y_feature.push_back(data[i].y);
        }
    }

    for (int i = 0; i < X_feature.size(); i++)
    {
        std::vector<BobosValuePoint> left_data;
        std::vector<BobosValuePoint> right_data;
        for (int k = 0; k < data.size(); k++)
        {
            if (data[k].x <= X_feature[i])
            {
                left_data.push_back(data[k]);
            }
            else
            {
                right_data.push_back(data[k]);
            }
        }
        double info_gain = getInfoGainOfDecision({std::make_tuple(new Node(left_data), new Node(right_data))}, data);
        if (info_gain > max_info_gain)
        {
            condition = "X < " + std::to_string(X_feature[i]);
            max_info_gain = info_gain;
            left = new Node(left_data);
            right = new Node(right_data);
        }
    }

    for (int i = 0; i < Y_feature.size(); i++)
    {
        std::vector<BobosValuePoint> left_data;
        std::vector<BobosValuePoint> right_data;
        for (int k = 0; k < data.size(); k++)
        {
            if (data[k].y <= Y_feature[i])
            {
                left_data.push_back(data[k]);
            }
            else
            {
                right_data.push_back(data[k]);
            }
        }
        double info_gain = getInfoGainOfDecision({std::make_tuple(new Node(left_data), new Node(right_data))}, data);
        if (info_gain > max_info_gain)
        {
            condition = "Y < " + std::to_string(Y_feature[i]);
            max_info_gain = info_gain;
            left = new Node(left_data);
            right = new Node(right_data);
        }
    }

    return std::make_tuple(left, right,condition);
}

std::string DecisionTree::ToString(){
    std::string tree = "";
    tree+= root->ToString();
    return tree;
}

#endif