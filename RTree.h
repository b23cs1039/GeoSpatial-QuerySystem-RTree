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
                insertInPoint(root,p,box1);
            }
            else insertOutPoint(root,p,box1);
        }
    }

    void removeLocation(pair<double,double> p){

    }

    pair<double,double> nearNeighbour(pair<double,double> p){

    }

    vector<pair<double,double>> inRange(pair<double,double> p, double radius){

    }

    private:
    void insertInPoint(RTreeNode* curr,pair<double,double> p, MBR box1){
        if(curr->isLeaf) curr->locations.emplace_back(p);
        bool inside = false;
        for(int i=0;i<curr->children.size();i++){
            if(curr->children[i]->box.contain(box1)){
                insertInPoint(curr->children[i],p,box1);
                inside = true;
                break;
            }
        }
        if(!inside){
            insertOutPoint(chooseChild(curr,p,box1),p,box1);
        }
    }

    void insertOutPoint(RTreeNode* curr, pair<double,double> p, MBR box1){
        curr->box.expand(p);
        if(curr->isLeaf) curr->locations.emplace_back(p);

        insertOutPoint(chooseChild(curr,p,box1),p,box1);
    }

    RTreeNode* chooseChild(RTreeNode* node,pair<double,double> p, MBR box1){
        RTreeNode* Child = node->children[0];
        RTreeNode* waste = Child;
        waste->box.expand(p);
        double minAreaDiff = waste->box.area()-Child->box.area();
        for(int i=0;i<node->children.size();i++){
            RTreeNode* temp = node->children[i];
            double initArea = temp->box.area();
            temp->box.expand(p);
            double finArea = temp->box.area();

            double diffArea = finArea-initArea;

            if(diffArea < minAreaDiff){
                Child = node->children[i];
                minAreaDiff = diffArea;
            }
        }

        return Child;
    }
};