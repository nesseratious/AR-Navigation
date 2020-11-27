## ARWorldBase

#### The supplementary class that is used as a root to all [MapSegment](https://github.com/nesseratious/AR-Navigation/blob/master/API/MapSegment.md) classes and also stores references to them. Every new [MapSegment](https://github.com/nesseratious/AR-Navigation/blob/master/API/MapSegment.md) should be attached to the ARWorldBase class. 

Usage: Place it anywhere on the map. 

Public properties: 

- WorldTrueNorthAngel: Float - Stores rotation shift of the target area relative to the true north. You can get the rotation shift of your target area using Google Maps and calculating the angle of rotation relative to a latitude(any vertical line). The ARWorldBase class will rotate to the given angle with a short delay when the application starts. The delay is needed to allow the attached [MapSegments](https://github.com/nesseratious/AR-Navigation/blob/master/API/MapSegment.md) and their [Rooms](https://github.com/nesseratious/AR-Navigation/blob/master/API/Room.md) to calculate their sizes and positions using the provided model of the target area (Static Mesh). The default value is zero.

- MapSegments: Array of [MapSegment](https://github.com/nesseratious/AR-Navigation/blob/master/API/MapSegment.md) - Supplementary array that contains references to its segments in case you need it.
