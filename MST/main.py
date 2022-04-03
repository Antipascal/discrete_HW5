# %%
import networkx as nx
G = nx.Graph()
f = open('edge_list','rb')
G = nx.read_weighted_edgelist(f)
for e in edges(nx.minimum_spanning_tree(G)):
    print(e)
# %%
