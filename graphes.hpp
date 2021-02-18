#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>


struct node {
    unsigned int id;
    unsigned int _numcouleur;
    node(){}
    node(unsigned int i) : id(i) {}
    ~node(){}
};

struct edge {
    unsigned int source, dest;
    bool active;
    edge() : active(false) {}
    edge(unsigned int a, unsigned int b) : source(a), dest(b), active(true) {}
    edge(unsigned int a, unsigned int b, bool valid) : source(a), dest(b), active(valid) {}
    ~edge(){}
};


class Graph
{
public:
    unsigned int nbNodes;
    unsigned int nbEdges;
    std::map<unsigned int, node> nodeSet;
    std::map<unsigned int, std::map<unsigned int, edge> > adjacence;

    Graph() : nbNodes(0), nbEdges(0) {}
    ~Graph() {}

    void add_node(unsigned int id);
    void add_edge(unsigned int a, unsigned int b);
    void k_couleurs();                                   // Methode de la k_coloration minimal
    void print();
    void read_dimacs(const std::string& filename);
    void write_dot() ;
};


