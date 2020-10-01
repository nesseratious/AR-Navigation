# AR-Navigation

### AR Navigation allows creating apps that use AR to navigate within a given target area. 

<p align="center">
  <img src="https://github.com/nesseratious/AR-Navigation-Documentation/blob/master/Images/RPReplay_Final1579278581.gif" />
</p>

### Features:
- Automatic calculation of the optimal route.
- Dynamic 3D minimap that shows user's current location and roration.
- Intuitive UI that shows user's destination, remained distance, and has a list of quick buttons for predefined destinations.
- Floating Icons to highlight possible points of interest.
- Custom markers that can snap to a detected surface.
- QRCode detection. 

### The system contains the following classes: 

#### ARWorldBase

The supplementary class that is used as a root to all MapSegment classes and also stores references to them. Every new MapSegment should be attached to the ARWorldBase class. 

Usage: Place it anywhere on the map. 

Public properties: 

- WorldTrueNorthAngel: Float - Stores rotation shift of the target area relative to the true north. You can get the rotation shift of your target area using Google Maps and calculating the angle of rotation relative to a latitude(any vertical line). The ARWorldBase class will rotate to the given angle with a short delay when the application starts. The delay is needed to allow the attached MapSegments and their Rooms to calculate their sizes and positions using the provided model of the target area (Static Mesh). The default value is zero.

- MapSegments: Array of MapSegment - Supplementary array that contains references to its segments in case you need it.

#### MapSegment

The class that is used to define segments of the target area. All FloatingIcon, Room, and Vertex classes that are located in this segment should be attached to it.

Usage: Place it anywhere on the map and attach it to the ARWorldBase. 

Public properties: 

- Floor: Integer - Stores floor number of the segment. The default value is zero.

- FloorDisplayedText: Text - Stores a localizable text that describes the segment's floor. Keep in mind that segments can be used not only to differentiate floors but also to divide a complex map into more small pieces in case the target area is big enough. The default value is "<Enter Floor Name>".
 
- SegmentMesh: StaticMesh - Fundamental mesh that defines the area of the segment. The default value is null.

- SegmentOffset: Vector2D - Stores the X,Y offset of the segment's mesh relative to the segment's origin. The default value is (0.0, 0.0).

- SegmentHeight: Float - Stores the height of the segment's mesh in meters. For this to work, the segment's mesh should be 1 meter in height. Alternatively, you can create a mesh with any height and set SegmentHeight to 1.0. The default value is 1.0.

- SegmentScale: Float - Stores all axes scale multiplier of the segments mesh. The default value is 1.0.

- SegmentMapMaterial: Material - A supplementary material that is used to show the floor plan. This is only needed to simplify the vertex and room arrangement on the segment. The material is only shown in the editor and is hidden in the game. The default value is null.

- SegmentMapScale: Float - Stores the X,Y scale of the SegmentMapMaterial. Use this to adjust the floor plan to match its real-world scale. The default value is 200.0.

#### FloatingIcon

The class represents a floating icon that can be used to highlight points of interest.

Usage: Place it anywhere on the map segment and attach it to the segment. 

Public properties: 

- IconMaterial: Material - A material that contains the image for the floating icon. It can include a static picture (like in the demo) or anything else. The default value is null.

- Text: Text - A localizable text that describes this point of interest. Will be displayed on both sides of the floating icon.

#### Room

The class that represents a single room in the target area. It can be literally a room or just a small sub-area. 

Usage: Place it anywhere on the map segment and attach it to the segment. 

Public properties:  

- Size: Vector2D - Stores size of the room. Adjustable in design-time. If set to zero the room will set its size automatically depending on its surroundings. The default value is (0.0, 0.0).

- Height: Float - Defines the height of the room. The default value is 3.0.

- Title: Text - Stores a localizable text that describes the room. The default value is "No Title".

- Floor: Text - Stores a localizable text that describes the floor of the room. The default value is "First Floor".

- DebugMaterial: Material - Stores a material that will be applied to room's mesh. For debugging purposes only, it will be hidden in game. The default value is null.

- Type: Enum - Stores a type of the room. Can be "Room", "Corridor", "Staircase" or "Other". The default value is "Room".

#### Vetrex

The fundamental class that represents a single vertex used for building navigation paths in the target area. 

Usage: Place it anywhere on the map segment and attach it to this segment. 

Public properties: 

- BilateralConnections: Array of Vetrex - An array of Vertex instances connected to this vertex bilaterally (Stair, Corridor, etc). The navigation path will be drawn in both directions. 

- LateralConnections: Array of Vertex - An array of Vertex instances connected to this vertex laterally (Turnstile, Escalator, etc). The navigation path will be drawn only in one direction. 

- ID: String - A unique identifier for this Vertex used for search algorithms. The default value is empty.

#### Configuration

The supplementary class that stores lists of the possible user's initial positions.

Usage: Place it anywhere on the map. Use only one instance.

Public properties: 

- InitialPositionPage: Struct - Contains a struct "Initial Positions" that stores a list of user's possible initial positions. Each InitialPosition stores a "Text"(Localizable friendly name that will be displayed in the list) and "TeleportToVertexTag" (Vertex ID which coordinates will be used to virtually teleport the user to that Vertex). The default values are missing and are implemented directly in the demo level.

- MainUIText: Struct - Contains a struct "QuickButtons" that stores a list of user's possible destinations which can be selected by the user from the main UI. Each QuickButton contains Text"(Localizable friendly name that will be displayed in the list), "Floor" Localizable friendly name of the floor that will be displayed in the main UI under the destination) and "DestinationTag" (destination Vertex ID).

#### 2DImageProvider

The class is responsible for rendering the 2D minimap image. 

Usage: Place it anywhere on the map. Use only one instance. Do not edit or modify it somehow.

#### Marker

The class which represents a single custom marker. 

Usage: Not intended for direct usage. Will be spawned automatically.


## DEBUG MODE

To toggle debug mode tap on the "Debug" button located in the top left corner. The debug mode will display all vertices and their axes. This will allow you to test how the virtual world matches the real one. 
 
<p align="center">
  <img src="https://github.com/nesseratious/AR-Navigation-Documentation/blob/master/Images/RPReplay_Final1579277884.gif" />
</p>

<p align="center">
  <img src="https://github.com/nesseratious/AR-Navigation-Documentation/blob/master/Images/Screen%20Shot%202020-04-20%20at%2010.13.37%20PM.png" />
</p>

## NAVIGATION

The navigation in this system is **not turn-based**, this means that the whole navigation path will be displayed once the user selects a destination. 

<p align="center">
  <img src="https://github.com/nesseratious/AR-Navigation-Documentation/blob/master/Images/RPReplay_Final1579278346.gif" />
</p>


If you want to opt-out of this behavior and hide all navigation arrows that are behind the walls, you can do so by adding built-in unreals function LineTraceByChannel to the Arrow class blueprint, where the start point will be player's camera and the endpoint will be world location of the Arrow instance. Depending on whether the arrow instance was hit or not, you can call SetVisibility function to hide or unhide the arrow. The visualization of such algorithm would look like this:

<p align="center">
  <img src="https://github.com/nesseratious/AR-Navigation-Documentation/blob/master/Images/111.png" />
</p>


And yet I do not recommend using this approach as my personal user surveys have shown that such behavior may be confusing.
