## ARWorldBase

#### The supplementary class that is used as a root to all MapSegment classes and also stores references to them. Every new MapSegment should be attached to the ARWorldBase class. 

Usage: Place it anywhere on the map. 

Public properties: 

- WorldTrueNorthAngel: Float - Stores rotation shift of the target area relative to the true north. You can get the rotation shift of your target area using Google Maps and calculating the angle of rotation relative to a latitude(any vertical line). The ARWorldBase class will rotate to the given angle with a short delay when the application starts. The delay is needed to allow the attached MapSegments and their Rooms to calculate their sizes and positions using the provided model of the target area (Static Mesh). The default value is zero.

- MapSegments: Array of MapSegment - Supplementary array that contains references to its segments in case you need it.
