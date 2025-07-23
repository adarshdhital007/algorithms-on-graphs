# Graph Decomposition - Week 1

This repository contains implementations for two fundamental graph algorithm problems focused on graph decomposition using Depth-First Search (DFS).

## Table of Contents

- [Overview](#overview)
- [Problems](#problems)
  - [1. Finding Exit from Maze](#1-finding-exit-from-maze)
  - [2. Adding Exits to Maze](#2-adding-exits-to-maze)
- [Implementation Details](#implementation-details)
- [Usage](#usage)
- [Compilation and Execution](#compilation-and-execution)
- [Algorithm Analysis](#algorithm-analysis)
- [Project Structure](#project-structure)

## Overview

This project implements two core graph traversal problems that demonstrate the practical applications of Depth-First Search (DFS) in graph decomposition:

1. **Reachability Problem**: Determining if there's a path between two nodes in an undirected graph
2. **Connected Components**: Counting the number of connected components in an undirected graph

Both problems are implemented in **Java** and **C++** to provide multiple language options.

## Problems

### 1. Finding Exit from Maze

**Problem Description:**
Given an undirected graph and two vertices, determine whether there is a path between them.

**Real-world Application:**
This solves the maze navigation problem where you need to determine if there's a path from your current position to the exit.

**Input Format:**
```
n m
x₁ y₁
x₂ y₂
...
xₘ yₘ
u v
```

Where:
- `n` = number of vertices (1 ≤ n ≤ 1000)
- `m` = number of edges (0 ≤ m ≤ 1000)
- `xᵢ yᵢ` = edges in the graph (1-indexed)
- `u v` = source and destination vertices

**Output:**
- `1` if there is a path between u and v
- `0` if there is no path between u and v

**Example:**
```
Input:
4 4
1 2
3 2
4 3
1 4
1 4

Output:
1
```

### 2. Adding Exits to Maze

**Problem Description:**
Given an undirected graph, find the number of connected components.

**Real-world Application:**
This solves the problem of determining how many separate maze sections exist, which helps in planning multiple exits.

**Input Format:**
```
n m
x₁ y₁
x₂ y₂
...
xₘ yₘ
```

Where:
- `n` = number of vertices (1 ≤ n ≤ 1000)
- `m` = number of edges (0 ≤ m ≤ 1000)
- `xᵢ yᵢ` = edges in the graph (1-indexed)

**Output:**
- Number of connected components in the graph

**Example:**
```
Input:
4 2
1 2
3 4

Output:
2
```

## Implementation Details

### Algorithm: Depth-First Search (DFS)

Both problems use DFS as the core traversal algorithm:

**DFS Characteristics:**
- **Time Complexity**: O(V + E) where V is vertices and E is edges
- **Space Complexity**: O(V) for the recursion stack and visited array
- **Traversal**: Explores as far as possible along each branch before backtracking

### Key Components

1. **Adjacency List Representation**: Efficient graph storage using lists
2. **Visited Array**: Tracks explored vertices to avoid cycles
3. **Recursive DFS**: Implements depth-first traversal recursively

## Usage

### Java Implementation

#### Problem 1: Reachability
```bash
# Compile
javac Reachability.java

# Run
java Reachability < input.txt
```

#### Problem 2: Connected Components
```bash
# Compile
javac ConnectedComponents.java

# Run
java ConnectedComponents < input.txt
```

### C++ Implementation

#### Problem 1: Reachability
```bash
# Compile
g++ -o reachability reachability.cpp

# Run
./reachability < input.txt
```

#### Problem 2: Connected Components
```bash
# Compile
g++ -o connected_components connected_components.cpp

# Run
./connected_components < input.txt
```

## Compilation and Execution

### Prerequisites

**For Java:**
- Java Development Kit (JDK) 8 or higher
- `javac` compiler
- `java` runtime

**For C++:**
- GCC compiler or equivalent
- C++11 standard support

### Sample Input Files

Create test input files to verify the implementations:

**test_reachability.txt:**
```
4 4
1 2
3 2
4 3
1 4
1 4
```

**test_components.txt:**
```
4 2
1 2
3 4
```

## Algorithm Analysis

### Reachability Algorithm

```java
private static int reach(ArrayList<Integer>[] adj, int x, int y) {
    boolean[] visited = new boolean[adj.length];
    dfs(adj, x, visited);
    return visited[y] ? 1 : 0;
}
```

**Steps:**
1. Initialize visited array
2. Perform DFS starting from source vertex x
3. Check if destination vertex y was visited during traversal
4. Return 1 if reachable, 0 otherwise

### Connected Components Algorithm

```java
private static int numberOfComponents(ArrayList<Integer>[] adj) {
    boolean[] visited = new boolean[adj.length];
    int count = 0;
    
    for (int i = 0; i < adj.length; i++) {
        if (!visited[i]) {
            dfs(adj, visited, i);
            count++;
        }
    }
    return count;
}
```

**Steps:**
1. Initialize visited array and component counter
2. Iterate through all vertices
3. For each unvisited vertex, start a new DFS (new component)
4. Increment component counter for each DFS initiation
5. Return total component count

### Complexity Analysis

| Algorithm | Time Complexity | Space Complexity | Notes |
|-----------|----------------|------------------|-------|
| Reachability | O(V + E) | O(V) | Single DFS traversal |
| Connected Components | O(V + E) | O(V) | Multiple DFS calls, but each edge visited once |

## Project Structure

```
.
├── README.md
├── .gitignore
└── week1_graph_decomposition1/
    ├── week1_graph_decomposition1.pdf
    ├── 1_finding_exit_from_maze/
    │   ├── Reachability.java
    │   └── reachability.cpp
    └── 2_adding_exits_to_maze/
        ├── ConnectedComponents.java
        └── connected_components.cpp
```

### File Descriptions

- **`Reachability.java`**: Java implementation of the reachability problem
- **`reachability.cpp`**: C++ implementation of the reachability problem
- **`ConnectedComponents.java`**: Java implementation of connected components counting
- **`connected_components.cpp`**: C++ implementation of connected components counting
- **`week1_graph_decomposition1.pdf`**: Problem statements and detailed specifications

## Key Learning Outcomes

1. **Graph Representation**: Understanding adjacency list representation
2. **DFS Implementation**: Recursive depth-first search traversal
3. **Graph Connectivity**: Concepts of reachability and connected components
4. **Algorithm Analysis**: Time and space complexity evaluation
5. **Multi-language Implementation**: Java and C++ programming practices

## Contributing

When contributing to this project:

1. Maintain consistent coding style across Java and C++ implementations
2. Ensure input validation and error handling
3. Add comprehensive test cases
4. Update documentation for any new features or changes
5. Follow the existing project structure

## License

This project is part of an algorithms and data structures course focusing on graph decomposition techniques.