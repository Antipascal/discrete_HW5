#include <fstream>
#include <vector>
#include <algorithm>

struct Node {
    std::vector<int> connections;
    Node() {
        connections.reserve(20);
    }
};
  
class GraphTable {
public:
    Node* matrix;
    int size;
  
    GraphTable (int n) {
        size = n;
        matrix = new Node[size];
    }
  
    void read(std::ifstream& in, int m) {
        int first, second;
        for (int i = 0; i < m; ++i) {
            in >> first >> second;
            matrix[first - 1].connections.push_back(second - 1);
            matrix[second - 1].connections.push_back(first - 1);
        }
    }

    void incendTable(std::ofstream& out) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j)
                if (std::find(matrix[i].connections.begin(), matrix[i].connections.end(), j) != matrix[i].connections.end())
                    out << "1,";
                else 
                    out << "0,";
            out << '\n';
        }
    }
};
  
  
int main() {
    int n, m, start;
    std::ifstream in("input.txt");
    in >> n >> m;
    GraphTable gt(n);
    gt.read(in, m);
    std::ofstream out("output.txt");
    gt.incendTable(out);
    return 0;
}