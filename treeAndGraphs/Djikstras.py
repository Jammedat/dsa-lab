def dijkstra(graph, source):
    n = len(graph)
    
    # Initialize distances
    distances = {node: float('inf') for node in graph}
    distances[source] = 0  
    
    visited = set() 

    while len(visited) < n:
       
        min_node = None
        min_distance = float('inf')
        
        for node in graph:
            if node not in visited and distances[node] < min_distance:
                min_distance = distances[node]
                min_node = node

        if min_node is None: 
            break


        visited.add(min_node)

      
        for neighbor, weight in graph[min_node].items():
            if neighbor not in visited:
                new_distance = distances[min_node] + weight
                if new_distance < distances[neighbor]:
                    distances[neighbor] = new_distance

    return distances


graph = {
    'A': {'B': 1, 'C': 4},
    'B': {'A': 1, 'C': 2, 'D': 5},
    'C': {'A': 4, 'B': 2, 'D': 1},
    'D': {'B': 5, 'C': 1}
}

source = 'A'
shortest_distances = dijkstra(graph, source)

for vertex, distance in shortest_distances.items():
    print(f"Shortest distance from {source} to {vertex} is {distance}")