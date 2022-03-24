#include "/opt/homebrew/Cellar/igraph/0.9.7/include/igraph/igraph.h" // your path to the folder with igraph
#include <iostream>


void print_vector(igraph_vector_t *v) {
  long int i;
  for (i=0; i<igraph_vector_size(v); i++) {
    printf(" %li", (long int) VECTOR(*v)[i]);
  }
  printf("\n");
}

void print_vectorList(igraph_vector_ptr_t * vl) {
      long int i,n;
      n = igraph_vector_ptr_size(vl);
      for (i=0; i<n; i++) {
        igraph_vector_t * vt;
        vt=(igraph_vector_t*)igraph_vector_ptr_e(vl,i);
        print_vector((igraph_vector_t*)vt);
      }
}


int main() {
    igraph_t graph;
    igraph_vector_t v;
    std::cout << "started\n";
    igraph_real_t edges[] = {7, 16, 39, 29, 39, 12, 12, 33, 12, 29, 29, 33, 33, 30, 33, 22, 33, 11, 33, 20, 33, 4, 33, 42, 33, 15, 11, 20, 20, 4, 20, 22, 30, 22, 22, 4, 4, 42, 30, 4, 15, 0, 15, 41, 41, 0, 41, 16, 41, 7, 16, 1, 16, 28, 7, 28, 28, 1, 28, 35, 19, 35, 19, 28, 19, 1, 19, 26, 26, 1, 26, 35, 26, 6, 35, 6, 35, 8, 35, 17, 35, 32, 35, 7, 7, 32, 6, 8, 17, 8, 17, 32, 17, 37, 17, 42, 17, 36, 17, 3, 32, 24, 32, 42, 42, 36, 42, 24, 42, 30, 30, 36, 30, 9, 30, 14, 9, 36, 9, 3, 9, 14, 14, 10, 14, 3, 14, 23, 14, 5, 14, 27, 14, 13, 14, 40, 3, 36, 3, 21, 3, 40, 3, 18, 3, 37, 37, 8, 37, 18, 18, 34, 18, 43, 18, 40, 18, 13, 40, 21, 40, 13, 13, 25, 13, 2, 13, 38, 38, 2, 38, 31, 5, 23, 5, 13, 5, 27, 1, 5, 8, 26, 23, 13};
    igraph_vector_view(&v, edges, sizeof(edges) / sizeof(double));
    igraph_create(&graph, &v, 0, IGRAPH_UNDIRECTED);
    std::cout << "created\n";
    igraph_vector_ptr_t result;
    igraph_vector_ptr_init(&result, 1);
    igraph_largest_independent_vertex_sets(&graph, &result);
    std::cout << "counted\n";
    int size = igraph_vector_ptr_size(&result);
    print_vectorList(&result);
    igraph_destroy(&graph);
    return 0;
}