## Vetrex Class

#### The fundamental class that represents a single vertex used for building navigation paths in the target area. 

Usage: Place it anywhere on the [MapSegment](https://github.com/nesseratious/AR-Navigation/blob/master/API/MapSegment.md) and attach it to this segment. 

Public properties: 

- BilateralConnections: Array of Vetrex - An array of Vertex instances connected to this vertex bilaterally (Stair, Corridor, etc). The navigation path will be drawn in both directions. 

- LateralConnections: Array of Vertex - An array of Vertex instances connected to this vertex laterally (Turnstile, Escalator, etc). The navigation path will be drawn only in one direction. 

- ID: String - A unique identifier for this Vertex used for search algorithms. The default value is empty.
