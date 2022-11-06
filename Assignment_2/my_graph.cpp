#include <iostream>
#include <map>
#include <ostream>
#include <set>
#include <stdexcept>
#include <vector>

using namespace std;

/**
  Prints `vector<int> v` to stdout
  @format:
    { }
    { 0 -12 7 48}
*/
void printVector(vector<int> v) {
  cout << "{ ";
  for (int element : v) {
    cout << element << " ";
  }
  cout << "}" << endl;
}

class Graph {
private:
  set<int> nodes;
  map<int, vector<int>> adjacency;

public:
  /**
    @returns a constant `set<int>` containing the nodes of the graph
  */
  const set<int> get_nodes() const { return nodes; }

  /**
    Main constructor
    @input:
      `const vector<int> &starts` containing the source vetices
      `const vector<int> &ends` containing the corresponding destination nodes
    @requires:
      `starts` and `ends` have the same size
    @tested:
      Different sizes for `starts` and `ends`
      Same sizes for `starts` and `ends`
      Empty vectors
      Same node has multiple sources / destinations
      Same edge is repeated twice
  */
  Graph(const vector<int> &starts, const vector<int> &ends) {
    if (starts.size() != ends.size()) {
      throw invalid_argument("starts and ends should have the same length");
    }
    int edges_number = starts.size();
    this->adjacency = map<int, vector<int>>();
    this->nodes = set<int>();

    for (int i = 0; i < edges_number; i++) {
      for (int node : {starts[i], ends[i]}) {
        if (nodes.insert(node).second)
          adjacency[node] = *new vector<int>();
      }
      adjacency[starts[i]].push_back(ends[i]);
    }
  }

  /**
    @requires:
      the graph contains at least one node having `int nodeID` as its ID
    @returns the outgoing degree of the `nodeID` vector if it exists in the map,
      otherwise throws an `invalid_argument` error
    @tested:
      Different sizes for starts and ends
      Same sizes for starts and ends
      Empty vectors
      Same node has multiple sources / destinations
      Same edge is repeated twice
  */
  const int numOutgoing(const int nodeID) const {
    if (nodes.find(nodeID) != nodes.end()) {
      return adjacency.find(nodeID)->second.size();
    }
    throw invalid_argument("nodeID " + to_string(nodeID) +
                           " does not exist in graph");
  }

  /**
    @returns
      a `vector<int>` of the outgoing neighbours of the `nodeID` vector if it
    exists in the map
    @requires:
      the graph contains a node `int nodeID`
    @throws an `invalid_argument` error if nodeID` vector is not in the map
    @tested:
      `nodeID` has multiple outgoing neighbors
      `nodeID` has a single outgoing neighbor
      `nodeID` has no outgoing neighbors
      `nodeID` does not exist in the graph
  */
  const vector<int> &adjacent(const int nodeID) const {
    if (nodes.find(nodeID) != nodes.end()) {
      if (adjacency.count(nodeID) != 0) {
        return adjacency.find(nodeID)->second;
      }
      return *new vector<int>();
    }
    throw invalid_argument("nodeID " + to_string(nodeID) +
                           " does not exist in graph");
  }

  /**
    @requires:
      the graph contains at least one node
      the graph is connected
    @returns
      a boolean representing whether the graph contains a non-trivial cycle
    @throws an `logic_error` if the graph is empty
    @tested:
      Different sizes for starts and ends
      Same sizes for starts and ends
      Empty vectors
      Same node has multiple sources / destinations
      Same edge is repeated twice
  */
  const bool hasCycle() const {
    if (this->nodes.empty()) {
      throw logic_error("map does not contain any node");
    }

    set<int> visiting = {};
    set<int> visited = {};
    int current;

    for (int root : get_nodes()) {
      visited.clear();
      visiting.clear();
      visiting.insert(root);

      while (!visiting.empty()) {
        current = *visiting.begin();
        for (int neighbour : adjacent(current)) {
          if (neighbour == current) {
            continue;
          }
          if (neighbour == root)
            return true;
          bool visitedB = visited.find(neighbour) == visited.end();
          bool visitingB = visiting.find(neighbour) == visiting.end();
          if (visited.find(neighbour) == visited.end() &&
              visiting.find(neighbour) == visiting.end()) {
            visiting.insert(neighbour);
          }
        }
        visiting.erase(current);
        visited.insert(current);
      }
    }

    return false;
  }
};

int main() {
  cout << "-------------------- Graphs and Cycles --------------------" << endl;
  // Testing for multiple graphs
  vector<vector<int>> starts_array = {
      {0, 0, 3, 4, 4, 3, 2},
      {0, 0, 0, 4, 4, 3},
      {0, 1, 2, 3, 4, 5, 6, 7, 8},
  };
  vector<vector<int>> ends_array = {
      {1, 2, 0, 3, 1, 1, 4},
      {1, 2, 3, 3, 1, 1},
      {1, 2, 3, 4, 5, 6, 7, 8, 0},
  };

  for (int graphID = 0; graphID < starts_array.size(); graphID++) {
    // Printing the graph info
    cout << "Graph " << graphID + 1 << ": " << endl;
    cout << "starts: ";
    printVector(starts_array[graphID]);
    cout << "ends:   ";
    printVector(ends_array[graphID]);
    cout << endl;

    // Initializing the graph
    Graph g = *new Graph(starts_array[graphID], ends_array[graphID]);
    for (int node : g.get_nodes()) {
      cout << node << " goes to " << g.numOutgoing(node) << " nodes: ";
      printVector(g.adjacent(node));
    };
    cout << endl;

    // Checking for non-trivial cycles
    if (g.hasCycle()) {
      cout << "GRAPH " << graphID + 1 << " HAS A NON_TRIVIAL CYCLE" << endl;
    } else {
      cout << "GRAPH " << graphID + 1 << " HAS NO NON_TRIVIAL CYCLE" << endl;
    }
    cout << endl << endl;
  }
  return 0;
}