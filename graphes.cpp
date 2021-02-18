#include "graphes.hpp"
#include <algorithm>

void Graph::add_node(unsigned int id)
{
    // verifier que le noeud n'existe pas
    if (nodeSet.find(id) == nodeSet.end())
    {
        node mynode(id);
        nodeSet[id] = mynode;
        nbNodes++;
    }
}

void Graph::add_edge(unsigned int a, unsigned int b)
{
    // verifier si la liste a éte créé pour le sommet A
    if (adjacence.find(a) == adjacence.end())
    {
        std::map<unsigned int, edge> m;
        m[b] = edge(a,b);
        adjacence[a] = m;
    }
    else
    {
        if (adjacence[a].find(b) == adjacence[a].end()) {
            // ajouter le sommet source a la liste d'adjacence
            adjacence[a][b] = edge(a,b);
            nbEdges++;
        }
    }
}

void Graph::print()
{
    std::cout << "nodes: " << std::endl;
    for(auto elem : nodeSet) {
        std::cout << elem.first << " : " << elem.second.id << std::endl ;
    }

    std::cout << "edges: " << std::endl;
    for(auto elem : adjacence) {
        std::cout << elem.first << " :\t";
        //std::cout << "size=" << elem.second.size() << "\t";

        for (auto elem2 : elem.second)
            std::cout << elem2.second.dest  << " ";
        std::cout << std::endl;
    }
}

void Graph::read_dimacs(const std::string& filename)
{
    // verifier que le fichier existe
    std::ifstream inputfile(filename);
    if (!inputfile) {
        std::cerr << "read_dimacs_graph(): no file" << std::endl;
        return;
    }

    int nb_nodes=0, nb_edges=0;
    bool read_p = true;		// pour lire la 1ere ligne "p edge"

    std::string line;
    while (std::getline(inputfile, line))
    {
        std::istringstream linestream(line);

        if ( read_p && (line[0] == 'p'))    // p edge
        {
            std::string skip1, skip2;
            linestream >> skip1 >> skip2 >> nb_nodes >> nb_edges;
            std::cout << "nodes: " << nb_nodes << "\tedges: " << nb_edges << std::endl;
            if (nb_nodes < 1)
            {
                std::cerr << "read_dimacs(): wrong number of nodes" << std::endl;
                inputfile.close();
                return;
            }
            else {
                // add nodes
                for (int i=1; i<=nb_nodes; i++)
                    add_node(i);
                read_p = false;
            }
        }
        else if (!read_p && (line[0] == 'e'))
        {
            // lire chaque ligne 'e <src> <dest>'
            std::string tmp;
            int debut, fin;
            linestream >> tmp >> debut >> fin;
            add_edge(debut,fin);
            add_edge(fin,debut);
        }
    }
    inputfile.close();
}

// Vecteur de couleurs (Réduisez le avec le petite flèche à gauche car il prend de la place)

std::vector<std::string> _colors = {"cadetblue3",
                                   "deeppink3",
                                   "cyan3",
                                   "darkgoldenrod1",
                                   "sandybrown",
                                   "grey83",
                                   "aquamarine4",
                                   "lavenderblush4",
                                   "lemonchiffon2",
                                   "lightyellow",
                                   "cyan2",
                                   "whitesmoke",
                                   "darkslateblue",
                                   "gray56",
                                   "mediumpurple2",
                                   "navajowhite2",
                                   "lemonchiffon4",
                                   "purple2",
                                   "lawngreen",
                                   "olivedrab",
                                   "grey10",
                                   "khaki2",
                                   "rosybrown",
                                   "darkgoldenrod",
                                   "grey57",
                                   "gray12",
                                   "gray11",
                                   "grey72",
                                   "tomato4",
                                   "darkseagreen2",
                                   "purple1",
                                   "mediumspringgreen",
                                   "skyblue1",
                                   "thistle1",
                                   "grey97",
                                   "grey48",
                                   "grey65",
                                   "grey90",
                                   "lightseagreen",
                                   "gray81",
                                   "palevioletred4",
                                   "mistyrose",
                                   "gray78",
                                   "grey39",
                                   "grey93",
                                   "lightgoldenrod3",
                                   "darkolivegreen3",
                                   "orange1",
                                   "turquoise",
                                   "grey30",
                                   "darkslategray4",
                                   "grey95",
                                   "gray46",
                                   "cadetblue2",
                                   "gray43",
                                   "palevioletred2",
                                   "dimgrey",
                                   "gray50",
                                   "grey100",
                                   "grey3",
                                   "mediumorchid4",
                                   "oldlace",
                                   "wheat",
                                   "lightcyan",
                                   "darkgreen",
                                   "cornsilk1",
                                   "lightblue3",
                                   "gray47",
                                   "chocolate4",
                                   "thistle3",
                                   "blue4",
                                   "gray64",
                                   "honeydew",
                                   "indianred1",
                                   "gainsboro",
                                   "lightcyan1",
                                   "lavenderblush",
                                   "navajowhite3",
                                   "chocolate2",
                                   "palegreen2",
                                   "olivedrab1",
                                   "olivedrab4",
                                   "deepskyblue1",
                                   "orange",
                                   "darkolivegreen1",
                                   "gray92",
                                   "gray35",
                                   "lavender",
                                   "lightsteelblue",
                                   "chartreuse2",
                                   "grey15",
                                   "grey89",
                                   "skyblue",
                                   "indianred3",
                                   "yellow4",
                                   "lightskyblue4",
                                   "gray4",
                                   "grey22",
                                   "grey81",
                                   "turquoise2",
                                   "gray66",
                                   "lightskyblue3",
                                   "bisque3",
                                   "gray28",
                                   "paleturquoise3",
                                   "slateblue4",
                                   "indianred",
                                   "chocolate",
                                   "lavenderblush2",
                                   "grey46",
                                   "aquamarine3",
                                   "gray25",
                                   "lightsalmon3",
                                   "darkgoldenrod3",
                                   "gray34",
                                   "violetred3",
                                   "rosybrown2",
                                   "gold2",
                                   "chartreuse4",
                                   "cyan4",
                                   "grey50",
                                   "grey75",
                                   "gray30",
                                   "grey33",
                                   "gray73",
                                   "grey91",
                                   "steelblue3",
                                   "goldenrod3",
                                   "lightsteelblue1",
                                   "gray3",
                                   "lightpink4",
                                   "gray68",
                                   "gray89",
                                   "peachpuff4",
                                   "mediumorchid",
                                   "gray70",
                                   "orchid",
                                   "gray67",
                                   "orange2",
                                   "aquamarine1",
                                   "azure1",
                                   "plum2",
                                   "mediumslateblue",
                                   "grey25",
                                   "gray38",
                                   "mediumpurple1",
                                   "yellow1",
                                   "honeydew3",
                                   "grey49",
                                   "lightsteelblue3",
                                   "green",
                                   "khaki4",
                                   "olivedrab2",
                                   "seashell2",
                                   "orchid3",
                                   "lightblue4",
                                   "skyblue4",
                                   "indianred2",
                                   "grey2",
                                   "mediumvioletred",
                                   "darkturquoise",
                                   "palegoldenrod",
                                   "blueviolet",
                                   "antiquewhite1",
                                   "slategrey",
                                   "deeppink",
                                   "gray27",
                                   "grey24",
                                   "gray51",
                                   "gray20",
                                   "maroon3",
                                   "orchid4",
                                   "darkseagreen",
                                   "gray14",
                                   "slategray1",
                                   "rosybrown4",
                                   "snow4",
                                   "mistyrose1",
                                   "powderblue",
                                   "grey58",
                                   "khaki1",
                                   "cornsilk3",
                                   "steelblue4",
                                   "papayawhip",
                                   "cadetblue4",
                                   "slategray3",
                                   "salmon1",
                                   "seagreen2",
                                   "purple3",
                                   "hotpink3",
                                   "cornsilk4",
                                   "mistyrose3",
                                   "mintcream",
                                   "mediumaquamarine",
                                   "grey88",
                                   "seagreen3",
                                   "lightsalmon",
                                   "grey6",
                                   "hotpink4",
                                   "deeppink1",
                                   "darkolivegreen",
                                   "snow2",
                                   "chocolate3",
                                   "grey11",
                                   "gray83",
                                   "darkslategrey",
                                   "magenta3",
                                   "gray59",
                                   "indianred4",
                                   "ivory",
                                   "royalblue2",
                                   "khaki3",
                                   "wheat2",
                                   "honeydew2",
                                   "lightsalmon2",
                                   "gray85",
                                   "paleturquoise",
                                   "yellow3",
                                   "grey66",
                                   "dodgerblue",
                                   "gray0",
                                   "gray41",
                                   "gold4",
                                   "slateblue3",
                                   "green4",
                                   "grey52",
                                   "gray16",
                                   "gray29",
                                   "gray19",
                                   "linen",
                                   "royalblue",
                                   "gold3",
                                   "violetred2",
                                   "lightsteelblue2",
                                   "gray93",
                                   "maroon2",
                                   "gray17",
                                   "gray75",
                                   "greenyellow",
                                   "gray18",
                                   "brown1",
                                   "forestgreen",
                                   "darkorchid3",
                                   "orangered2",
                                   "maroon4",
                                   "wheat4",
                                   "lightgoldenrodyellow",
                                   "lightsalmon1",
                                   "grey55",
                                   "lightcyan4",
                                   "yellowgreen"
                                   "gray71",
                                   "grey29",
                                   "grey61",
                                   "slategray4",
                                   "goldenrod",
                                   "grey76",
                                   "grey68",
                                   "deepskyblue2",
                                   "springgreen1",
                                   "darkslategray",
                                   "moccasin",
                                   "green2",
                                   "darkslategray3",
                                   "brown",
                                   "plum4",
                                   "lightgoldenrod1",
                                   "antiquewhite",
                                   "purple4",
                                   "orchid1",
                                   "darkgoldenrod2",
                                   "sienna1",
                                   "grey19",
                                   "slateblue1",
                                   "gray6",
                                   "darkseagreen1",
                                   "grey96",
                                   "mistyrose2",
                                   "darkorange3",
                                   "grey42",
                                   "gray77",
                                   "pink3",
                                   "gray61",
                                   "grey53",
                                   "yellow2",
                                   "grey34",
                                   "blue3",
                                   "cornsilk",
                                   "orangered1",
                                   "grey21",
                                   "chartreuse",
                                   "lightpink3",
                                   "dodgerblue4",
                                   "coral2",
                                   "grey84",
                                   "white",
                                   "grey4",
                                   "chartreuse1",
                                   "lightgrey",
                                   "antiquewhite2",
                                   "gray33",
                                   "grey87",
                                   "azure3",
                                   "hotpink1",
                                   "burlywood4",
                                   "floralwhite",
                                   "azure",
                                   "palevioletred",
                                   "gray26",
                                   "antiquewhite4",
                                   "gray2",
                                   "gray95",
                                   "grey51",
                                   "gray9",
                                   "grey92",
                                   "cadetblue1",
                                   "ivory1",
                                   "springgreen4",
                                   "limegreen",
                                   "mediumblue",
                                   "gray22",
                                   "grey62",
                                   "darksalmon",
                                   "springgreen2",
                                   "navajowhite",
                                   "palegreen3",
                                   "dodgerblue1",
                                   "grey64",
                                   "lavenderblush1",
                                   "gray84",
                                   "invis",
                                   "grey67",
                                   "grey60",
                                   "gray69",
                                   "gray55",
                                   "sienna4",
                                   "magenta",
                                   "aquamarine",
                                   "firebrick4",
                                   "grey16",
                                   "lightgoldenrod4",
                                   "grey18",
                                   "grey44",
                                   "royalblue1",
                                   "gray49",
                                   "grey13",
                                   "blue2",
                                   "seashell",
                                   "gray97",
                                   "brown3",
                                   "gray36",
                                   "cornsilk2",
                                   "grey14",
                                   "grey17",
                                   "grey86",
                                   "slategray2",
                                   "grey94",
                                   "royalblue4",
                                   "honeydew4",
                                   "palegreen",
                                   "grey31",
                                   "dodgerblue2",
                                   "lightsteelblue4",
                                   "green3",
                                   "saddlebrown",
                                   "orangered3",
                                   "turquoise3",
                                   "chocolate1",
                                   "honeydew1",
                                   "gray86",
                                   "grey9",
                                   "darkorchid4",
                                   "seashell4",
                                   "cadetblue",
                                   "maroon",
                                   "chartreuse3",
                                   "lightskyblue1",
                                   "ivory3",
                                   "lightskyblue",
                                   "gray54",
                                   "springgreen",
                                   "mediumorchid3",
                                   "darkorchid2",
                                   "sienna2",
                                   "grey5",
                                   "darkslategray2",
                                   "violetred",
                                   "firebrick2",
                                   "snow1",
                                   "salmon2",
                                   "darkviolet",
                                   "burlywood",
                                   "lightslategray",
                                   "steelblue1",
                                   "lightyellow1",
                                   "gray91",
                                   "gray99",
                                   "darkslategray1",
                                   "rosybrown1",
                                   "orchid2",
                                   "gray24",
                                   "salmon3",
                                   "skyblue2",
                                   "burlywood2",
                                   "salmon4",
                                   "turquoise1",
                                   "darkorange",
                                   "maroon1",
                                   "tomato1",
                                   "lightyellow4",
                                   "purple",
                                   "plum1",
                                   "lightpink2",
                                   "lightgoldenrod2",
                                   "orange4",
                                   "peachpuff2",
                                   "gray1",
                                   "navyblue",
                                   "bisque4",
                                   "grey99",
                                   "bisque2",
                                   "gray58",
                                   "dimgray",
                                   "antiquewhite3",
                                   "darkorange1",
                                   "slategray",
                                   "gray23",
                                   "lemonchiffon3",
                                   "indigo",
                                   "gray39",
                                   "darkorchid",
                                   "tomato",
                                   "grey78",
                                   "grey71",
                                   "lemonchiffon1",
                                   "gray82",
                                   "cyan1",
                                   "bisque",
                                   "seagreen",
                                   "mediumpurple4",
                                   "darkgoldenrod4",
                                   "sienna",
                                   "grey98",
                                   "green1",
                                   "grey35",
                                   "gray79",
                                   "gray37",
                                   "gray87",
                                   "snow3",
                                   "grey20",
                                   "navajowhite4",
                                   "beige",
                                   "dodgerblue3",
                                   "grey79",
                                   "grey45",
                                   "ghostwhite",
                                   "grey73",
                                   "magenta1",
                                   "grey74",
                                   "grey0",
                                   "grey56",
                                   "thistle",
                                   "thistle2",
                                   "deeppink4",
                                   "grey28",
                                   "lightcoral",
                                   "seagreen1",
                                   "gray76",
                                   "lightpink",
                                   "mediumorchid2",
                                   "lightslateblue",
                                   "pink4",
                                   "grey70",
                                   "goldenrod1",
                                   "darkkhaki",
                                   "coral1",
                                   "lightslategrey",
                                   "tomato3",
                                   "mediumpurple3",
                                   "springgreen3",
                                   "gray15",
                                   "pink1",
                                   "wheat3",
                                   "navajowhite1",
                                   "aquamarine2",
                                   "grey80",
                                   "grey41",
                                   "plum3",
                                   "gray13",
                                   "deepskyblue3",
                                   "coral4",
                                   "gray65",
                                   "lightyellow3",
                                   "grey40",
                                   "orangered",
                                   "cornflowerblue",
                                   "violetred4",
                                   "goldenrod4",
                                   "grey37",
                                   "firebrick1",
                                   "gray100",
                                   "grey59",
                                   "gray88",
                                   "grey36",
                                   "gray60",
                                   "gray42",
                                   "darkolivegreen2",
                                   "gray31",
                                   "grey1",
                                   "turquoise4",
                                   "slateblue",
                                   "rosybrown3",
                                   "seashell1",
                                   "ivory2",
                                   "gray63",
                                   "violetred1",
                                   "gray53",
                                   "gray44",
                                   "black",
                                   "mediumseagreen",
                                   "gray45",
                                   "grey38",
                                   "wheat1",
                                   "sienna3",
                                   "grey69",
                                   "khaki",
                                   "grey47",
                                   "lavenderblush3",
                                   "pink2",
                                   "palegreen4",
                                   "lightskyblue2",
                                   "lightblue1",
                                   "deepskyblue",
                                   "coral",
                                   "gray72",
                                   "burlywood1",
                                   "mediumturquoise",
                                   "azure4",
                                   "darkorchid1",
                                   "darkorange4",
                                   "transparent",
                                   "gray98",
                                   "paleturquoise2",
                                   "peachpuff3",
                                   "seashell3",
                                   "blanchedalmond",
                                   "magenta4",
                                   "grey23",
                                   "salmon",
                                   "grey32",
                                   "grey12",
                                   "grey77",
                                   "peachpuff",
                                   "lightcyan2",
                                   "deepskyblue4",
                                   "orange3",
                                   "lightcyan3",
                                   "violet",
                                   "peachpuff1",
                                   "steelblue",
                                   "lightsalmon4",
                                   "lightblue",
                                   "gray5",
                                   "darkolivegreen4",
                                   "gold1",
                                   "gray7",
                                   "paleturquoise4",
                                   "lightgoldenrod",
                                   "lightgray",
                                   "lightpink1",
                                   "firebrick3",
                                   "gray62",
                                   "coral3",
                                   "palevioletred1",
                                   "darkorange2",
                                   "orangered4",
                                   "blue1",
                                   "gray40",
                                   "azure2",
                                   "gray94",
                                   "grey8",
                                   "lightyellow2",
                                   "gray8",
                                   "brown4",
                                   "aliceblue",
                                   "hotpink2",
                                   "seagreen4",
                                   "grey26",
                                   "palegreen1",
                                   "goldenrod2",
                                   "royalblue3",
                                   "yellow",
                                   "grey27",
                                   "skyblue3",
                                   "thistle4",
                                   "grey7",
                                   "lightblue2",
                                   "deeppink2",
                                   "grey43",
                                   "gray74",
                                   "ivory4",
                                   "gray57",
                                   "firebrick",
                                   "gray10",
                                   "palevioletred3",
                                   "tomato2",
                                   "paleturquoise1",
                                   "lemonchiffon",
                                   "mediumorchid1",
                                   "gray32",
                                   "bisque1",
                                   "grey63",
                                   "mediumpurple",
                                   "mistyrose4",
                                   "crimson",
                                   "grey85",
                                   "midnightblue",
                                   "magenta2",
                                   "grey82",
                                   "gray21",
                                   "olivedrab3",
                                   "steelblue2",
                                   "gray80",
                                   "slateblue2",
                                   "gray52",
                                   "burlywood3",
                                   "brown2",
                                   "gray48",
                                   "hotpink",
                                   "darkseagreen4",
                                   "darkseagreen3",
                                   "gray96",
                                   "grey54",
                                   "gray90"};


void Graph::write_dot()
{
    std::string filename("graph.dot");
    std::ofstream outfile(filename);

    outfile << "digraph {\n";
    outfile << "\tgraph [concentrate=true, label=\"" << filename << "\", "
            << "labelloc=top, labeljust=left, fontsize=14];\n";

    // sommets
    for(auto n : nodeSet) {
        outfile << "\t" << n.second.id << " [";
        outfile << "style=filled, fillcolor="+_colors.at(n.second._numcouleur);
        outfile << ", shape=circle";
        outfile << "]\n";
    }

    // arc
    for(auto parent : adjacence) {
        outfile << "\t" << parent.first << " -> {";

        for(auto neighbor : parent.second) {
            outfile << neighbor.first << " ";
        }
        outfile << "}[arrowhead=none]\n";
    }

    outfile << "}";
    outfile.close();

    // appel à l'outil de conversion DOT
    std::string extcall = "dot -Tpng " + filename + " -o " + filename + ".png";
    std::cout << "Calling : " << extcall << std::endl;
    if (std::system((extcall).c_str()) != 0)
        std::cout << "Call to dot failed." << std::endl;
}


void Graph::k_couleurs(){
    std::vector<unsigned int> coul_adj;
    unsigned int couleur_next_node;
    for(unsigned int j(1);j<=nodeSet.size();++j){
        if(j==1)nodeSet.at(j)._numcouleur = j;
        else {
            for(auto const & i : adjacence.at(j)){
                if(i.second.source==j)coul_adj.push_back(nodeSet.at(i.second.dest)._numcouleur);
                else coul_adj.push_back(nodeSet.at(i.second.source)._numcouleur);
            }
            couleur_next_node=1;
            while ((std::find(coul_adj.begin(), coul_adj.end(), couleur_next_node) != coul_adj.end())) {
                ++couleur_next_node;
            }
            nodeSet.at(j)._numcouleur=couleur_next_node;
            coul_adj.clear();
        }
    }
}

