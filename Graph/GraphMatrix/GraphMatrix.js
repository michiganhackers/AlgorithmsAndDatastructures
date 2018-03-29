"use strict"

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

// Test program

let graph = new GraphMatrix(["SFO", "LAX", "MIA", "ORD", "MCO"], "undirected")

console.log("Connecting SFO to LAX")
graph.connect("SFO", "LAX")
console.log("Is SFO <-> LAX: ", graph.isConnected("LAX", "SFO"))

console.log("Is SFO <-> MCO: ", graph.isConnected("SFO", "MCO"))

console.log("Inserting JFK and connecting to MCO")
graph.insert("JFK")
graph.connect("MCO", "JFK")

console.log("Is MCO <-> JFK: ", graph.isConnected("MCO", "JFK"))
