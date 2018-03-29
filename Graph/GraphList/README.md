## GraphList

A graph list data structure is another way of representing a graph. Similar to a [GraphMatrix](../GraphMatrix), we have a set of nodes that are connected to or unconnected to other nodes via an edge.

Unlike an adjacency matrix, in a graph list we use, linked-lists or arrays per node. For example we may have a graph of airports where each node is an airport and each edge in the graph determines whether one airport has flights to the other airport. In this case, we have an undirected graph since it would make sense if you can leave from airport X and get to airport Y, that you could do the reverse as well.

Let's say we have a LAX airport and this is connected to JFK via a non-stop flight, as well as connected to MCO, etc. 

However, JFK only connects to LAX and MCO

Our datastructure would look something like this:

```
LAX --> JFK --> MCO --> DTW

JFK --> LAX --> MCO
```

Here is some code for implementing the above in JavaScript:

```js
class GraphList {
    // Initializes the graph list with given nodes and type
    // Default empty directed graph
    constructor(nodes = [], type = "directed") {
        this.data = new Map()
        this.type = type
        for (let node of nodes)
            this.data.set(node, new Array())
    }

    // Inserts a node into the graph
    insert(node) {
        this.data.set(node, new Array())
    }

    // Returns whether nodeA is connected to nodeB
    // nodeA must be in the graph already.
    isConnected(nodeA, nodeB) {
        return this.data.get(nodeA).includes(nodeB)
    }

    // Connects nodeA to nodeB, in that order.
    connect(nodeA, nodeB) {
        if (!this.data.get(nodeA).includes(nodeB))
            this.data.get(nodeA).push(nodeB)

        if (this.type == "undirected") {
            if (!this.data.get(nodeB).includes(nodeA))
                this.data.get(nodeB).push(nodeA)
        }
    }
}
```

For a live demo, go [here](https://repl.it/@heyluis/GraphList).