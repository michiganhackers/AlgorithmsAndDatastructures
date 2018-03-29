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

let graph = new GraphList(["LAX", "JFK", "MCO"], "undirected")

console.log("Is LAX <-> JFK? ", graph.isConnected("JFK", "LAX"))

console.log("Connecting LAX to JFK")
graph.connect("LAX", "JFK")
console.log("Is LAX <-> JFK? ", graph.isConnected("JFK", "LAX"))

console.log("Inserting DTW and connecting to MCO")
graph.insert("DTW")
graph.connect("DTW", "MCO")
console.log("Is MCO <-> DTW? ", graph.isConnected("DTW", "MCO"))
