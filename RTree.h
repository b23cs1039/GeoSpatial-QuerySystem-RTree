#include <bits/stdc++.h>
#include "box.h"
using namespace std;

class RTreeNode{
    public:
    bool isLeaf;
    vector<RTreeNode*> children;
    MBR box;
    int maxlocations;
    vector<pair<double,double>> locations;

    RTreeNode(bool leaf = true, MBR box1, int Max): isLeaf(leaf),box(box1), maxlocations(Max) {};
};

class RTree{
    public:
    RTreeNode* root;
    int Max;

    //constructor
    RTree(int m): Max(m),root(nullptr) {}

    void insertLocation(pair<double,double> p){
        double x = p.first;
        double y = p.second;
        MBR box1(x,y,x,y);

        RTreeNode* temp = new RTreeNode(true,box1,Max);

        if(root == nullptr) root = temp;
        else{
            if(root->box.contain(box1)){
                insertInPoint(root,p);
            }
            else insertOutPoint(root,p);
        }
    }

    void removeLocation(pair<double,double> p){

    }

    pair<double,double> nearNeighbour(pair<double,double> p){

    }

    vector<pair<double,double>> inRange(pair<double,double> p, double radius){

    }

    private:
    void insertInPoint(RTreeNode* curr,pair<double,double> p){

    }

    void insertOutPoint(RTreeNode* curr, pair<double,double> p){
        
    }

    RTreeNode* chooseLeaf(RTreeNode* node, const MBR& box){
        // if(node->isLeaf) return node;

        // RTreeNode* bestChild = nullptr;
        // RTreeNode* container = nullptr;

        // double minIncrease = 0;
        // double minArea = node->boxes[0].area();

        // for(int i=0; i<node->boxes.size();i++){
        //     MBR curr = node->boxes[i];
        //     double currArea = curr.area();

        //     if(curr.contain(box)){
        //         if(currArea < minArea){
        //             minArea = currArea;
        //             container = node->children[i];
        //         }
        //     }

        //     curr.expand(box);
        //     double expandedArea = curr.area();
        //     double AreaDiff = expandedArea;

        //     if(AreaDiff < minIncrease){
        //         minIncrease = AreaDiff;
        //         bestChild = node->children[i];
        //     }
        // }

        // chooseLeaf(bestChild,box);
    }
};