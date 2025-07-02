import heapq

def dijkstra(graph, start_node):
    # dist[node] = shortest distance from start_node to node
    distances = {node: float('inf') for node in graph}
    distances[start_node] = 0

    # Priority queue: (distance, node)
    priority_queue = [(0, start_node)]

    while priority_queue:
        current_distance, current_node = heapq.heappop(priority_queue)

        # If we found a shorter path already, skip
        if current_distance > distances[current_node]:
            continue

        for neighbor, weight in graph[current_node].items():
            distance = current_distance + weight

            # If a shorter path is found
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(priority_queue, (distance, neighbor))
    
    return distances
