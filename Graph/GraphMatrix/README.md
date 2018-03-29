## GraphMatrix

A graph matrix is a way of representing a graph data structure.
This can be done in two common ways, either using an __adjacency matrix__ or a __distance matrix__. Depending on what you want/need to do you would use one over the other.

For example, if I wanted to graph out flights in the United States, I could simply use an adjacency matrix:

|     | MCO | SFO | LAX | JFK |
|-----|-----|-----|-----|-----|
| MCO | 0   | 1   | 1   | 1   |
| SFO | 1   | 0   | 0   | 0   |
| LAX | 1   | 0   | 0   | 0   |
| JFK | 1   | 0   | 0   | 0   |

Here we graph out whether or not we can go from one airport to another. A 1 means theres a connection and a 0 means theres no connection. We assume there are no self loops, as this wouldn't make much sense for an airport to depart and land at the same place in one trip. Our graph above is also _undirected_ thus we can go from either LAX to JFK or from JFK to LAX, which makes sense in the real world context.

A distance matrix, works similarly except we can measure or weigh out our edges. This type of matrix is helpful when we want to find, for example, the shortest path between two cities, or how much it costs for a trip from LAX to JFK:

|     | MCO | SFO | LAX | JFK |
|-----|-----|-----|-----|-----|
| MCO | -1  | 330 | 200 | 420 |
| SFO | 450 | -1  | -1  | -1  |
| LAX | 600 | -1  | -1  | -1  |
| JFK | 911 | -1  | -1  | -1  |

In the above, we are again, _undirected_. We also represent no connections with -1 for example since this makes some-what sense since hopefully our airport isn't returning money instead of making it.

In programming we can represent the above data-structures using a 2-D array. We can check if there is a connection from _MCO_ to _LAX_ by checking if `array[0][2] == 1` since if there is a 1 in that location there is a connection between LAX and MCO. For an undirected graph we can even save some space, if we assume there are no self loops. We could, instead of storing the full 2-D array store only the top or bottom half. This is because as you can see in the adjacency matrix above, there are a lot of duplicate/wasted space across the diagonal and for undirected locations.

A simple implementation of this data structure is implemented in JavaScript here:

```js
class GraphMatrix {
    // Constructs an GraphMatrix with a given nodes array
    // Each element in nodes must be hashable
    // You can also specify the type of graph, either directed or
    // undirected. By default the graph is directed.
    constructor(nodes = [], type = "directed") {
        this.type = type

        // Init nodes map
        this.nodes = new Map()
        for (let i = 0; i < nodes.length; ++i)
            this.nodes.set(nodes[i], i)

        // Init adjacency matrix
        this.data = new Array(nodes.length)
        for (let i = 0; i < nodes.length; ++i) {
           this.data[i] = new Array(nodes.length)
          for (let j = 0; j < nodes.length; ++j)
              this.data[i][j] = 0
        }
    }

    // Returns whether node a is connected to node b
    isConnected(nodeA, nodeB) {
        if (this.nodes.length == 0) return false
        let indexA = this.nodes.get(nodeA), indexB = this.nodes.get(nodeB)
        return this.data[indexA][indexB] == 1
    }

    // Inserts a node into the graph
    insert(node) {
        this.nodes.set(node, this.nodes.size)
        this.data.push(new Array(this.nodes.size).fill(0))
        // Fix other rows
        for (let i = 0; i < this.nodes.size - 1; ++i)
            this.data[i].push(0)
    }

    // Conncets nodeA with nodeB
    // Nodes must exist in the graph already.
    connect(nodeA, nodeB) {
        let indexA = this.nodes.get(nodeA), indexB = this.nodes.get(nodeB)
        this.data[indexA][indexB] = 1
        if (this.type == "undirected")
          this.data[indexB][indexA] = 1
    }
}
```

A live demo can be found [here](https://repl.it/@heyluis/GraphMatrix)