import matplotlib.pyplot as plt
import networkx as nx

graph = [
    [0, 1, 1, 1],
    [1, 0, 1, 0],
    [1, 1, 0, 1],
    [1, 0, 1, 0],
]

G = nx.Graph()

for i in range(len(graph)):
    for j in range(i+1, len(graph)):
        if graph[i][j] == 1:
            G.add_edge(i, j)

nx.draw(G, with_labels=True)

# Save the graph visualization to a file
plt.savefig('/home/insomniac/Desktop/#CP/#EXTRA/graph_visualization.png')
