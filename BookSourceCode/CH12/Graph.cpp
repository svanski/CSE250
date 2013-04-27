#include "Graph.h"
#include "Matrix_Graph.h"
#include "List_Graph.h"
#include <string>
#include <istream>
#include <sstream>
#include <stdexcept>
#include <limits>
using std::string;
using std::istream;
using std::istringstream;
using std::numeric_limits;

/** Load the edges of a graph from the data in an input file.
    The file should contain a series of lines, each line
    with two or three data values. The first is the source,
    the second is the destination, and the optional third
    is the weight.
    @param in The istream that is connected
           to the file that contains the data
*/
void Graph::load_edges_from_file(istream& in) {
}

/** Factory function to create a graph and load the data from an input
    file. The first line of the input file should contain the number
    of vertices. The remaining lines should contain the edge data as
    described under load_edges_from_file.
    @param in The istream that is connected to the file that contains
              the data
    @param is_directed true if this is a directed graph, false otherwise
    @param type The string "Matrix" if an adjacency matrix is to be
                created, and the string "List" if an adjacency list
                is to be created
    @throws std::invalid_argument if type is neither "Matrix" nor "List"
*/
Graph* Graph::create_graph(istream& in, bool is_directed,
                           const std::string& type) {
  int n;
  in >> n;
  in.ignore(numeric_limits<int>::max(), '\n'); // Skip rest of this line
  Graph* return_value = NULL;
  if (type == "Matrix")
    return_value = new Matrix_Graph(n, is_directed);
  else if (type == "List")
    return_value = new List_Graph(n, is_directed);
  else
    throw std::invalid_argument("Unrecognized Graph Type");
  return_value->load_edges_from_file(in);
  return return_value;
}
