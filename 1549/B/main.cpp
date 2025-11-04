#include <iostream>
#include <vector>
#include <string>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/push_relabel_max_flow.hpp>

using namespace std;


typedef boost::adjacency_list_traits<boost::vecS, boost::vecS, boost::directedS> traits;
typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS, boost::no_property,
      boost::property<boost::edge_capacity_t, long,
      boost::property<boost::edge_residual_capacity_t, long,
      boost::property<boost::edge_reverse_t, traits::edge_descriptor>>>> Graph;

typedef traits::vertex_descriptor vertex_desc;
typedef traits::edge_descriptor edge_desc;

class edge_adder {
  Graph &G;

  public:
    explicit edge_adder(Graph &G) : G(G) {}

    void add_edge(int from, int to, long capacity) {
      auto c_map = boost::get(boost::edge_capacity, G);
      auto r_map = boost::get(boost::edge_reverse, G);
      const auto e = boost::add_edge(from, to, G).first;
      const auto rev_e = boost::add_edge(to, from, G).first;
      c_map[e] = capacity;
      c_map[rev_e] = 0; // reverse edge has no capacity!
      r_map[e] = rev_e;
      r_map[rev_e] = e;
    }
};

void testcase(){
  int n; cin >> n;
  string enemy, player;
  cin >> enemy >> player;

  Graph graph(n);
  edge_adder adder(graph);

  int source = boost::add_vertex(graph), target = boost::add_vertex(graph);

  for (int i = 1; i < n-1; i++){
    if (player[i] == '1'){
      int playerNode = boost::add_vertex(graph);

      adder.add_edge(source, playerNode, 1);

      if (enemy[i-1] == '1')
        adder.add_edge(playerNode, i-1, 1);
      
      if (enemy[i] == '0')
        adder.add_edge(playerNode, i, 1);

      if (enemy[i+1] == '1')
        adder.add_edge(playerNode, i+1, 1);
    }
  }

  if (player[0] == '1'){
    int playerNode = boost::add_vertex(graph);

    adder.add_edge(source, playerNode, 1);

    if (enemy[0] == '0')
        adder.add_edge(playerNode, 0, 1);

      if (enemy[1] == '1')
        adder.add_edge(playerNode, 1, 1);
  }

  if (player[n-1] == '1'){
    int playerNode = boost::add_vertex(graph);

    adder.add_edge(source, playerNode, 1);

    if (enemy[n-1] == '0')
        adder.add_edge(playerNode, n-1, 1);

      if (enemy[n-2] == '1')
        adder.add_edge(playerNode, n-2, 1);
  }

  for (int i = 0; i < n; i++)
    adder.add_edge(i, target, 1);

  int flow = boost::push_relabel_max_flow(graph, source, target);

  cout << flow << "\n"; 
}

int main(){
  ios_base::sync_with_stdio(false);
  int t; cin >> t;
  for (int i = 0; i < t; i++)
    testcase();
}