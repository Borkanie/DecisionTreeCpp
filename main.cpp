#include "Node.h"
#include "DecisionTree.h"
#include <iostream>

/// @brief It will always find the smallest square containg only the true values of any given dataset.
/// Because we only ose x and y asa features all the lines need to be parrallel to the axis.
/// @return 
int main()
{
    std::vector<BobosValuePoint> data = {BobosValuePoint{-1, 0, true},
                               BobosValuePoint{-0.5, 1, true},
                               BobosValuePoint{0, -1, true},
                               BobosValuePoint{0, 0, true},
                               BobosValuePoint{0.1, 0.2, true},
                               BobosValuePoint{-1.4, 4, false},
                               BobosValuePoint{3, -5.3, false},
                               BobosValuePoint{3.3, 1, false},
                               BobosValuePoint{-2, 4, false},
                               BobosValuePoint{3.1, 7, false},
                               BobosValuePoint{5, -4.5, false},
                               BobosValuePoint{0.5, 2, false},
                               BobosValuePoint{-0.3, -4, false},
                               BobosValuePoint{-2.5, -2.5, false},
                               BobosValuePoint{3, 4, false}};

    DecisionTree tree(data);
    std::cout << tree.ToString() << std::endl;
    return 0;
}