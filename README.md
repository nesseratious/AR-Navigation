# AR-Navigation-Documentation

### AR Navigation allows creating apps for iOS and Android that uses AR to navigate within a given target area. 


<p align="center">
  <img src="https://github.com/nesseratious/AR-Navigation-Documentation/blob/master/Images/RPReplay_Final1579278581.gif" />
</p>


### Features:
- Automatic calculation of the optimal route.
- Dynamic minimap that shows user current location.
- Intuitive UI that shows users destination and has a list of quick buttons for predefined destinations.
- Floating Icons to hightlight possible points of interest.
- Custom markers that can snap to a detected surface.
- QRCode detection.

### How it works?
1. When the user launches your app, they will be prompted to scan the QR code used to download the app. This is 

### How to set it up?
1. Place an ARWorldBase instance anywhere on the map, it will serve as target areas origin. 
2. In ARWorldBase properties enter target areas rotation relative to the world true north.
3. Place one or multiple instances of MapSegment, they will serve as containers that represent each segments properties. Multiple segments are used to divide the map by floors or by some small sub-areas. Attach each MapSegment to the ARWorldBase.
4. For each MapSegment assign its floor map (used only for debuging purposses and will be hidden in the app) and a static mesh that represents segments map in the real world. 
5. Adjust scale of the segment to match its real world scale (it's very important!).
6. Build navigation graph by placing Vertex instances on your map segments and connecting them using BilateralConnections and LateralConnections arrays. Give an ID to every Vertex that represents a destination point (user will be able to perform search using this ID). Vertices that are used only to connect other vertices should have theirs ID field empty. Attach all placed vertices to the map segment they belong.

**Navigation is ready! The next steps are not required, but will greatly improve user experience.**

7. Place a FloatingIcon instance where there is a possible point of interest. Enter its name and a material containing its icon. Attach all placed FloatingIcon instances to the map segment they belong. 
8. Place all Room instances that represent each room. Set theirs size or leave it zero for automatic size detection. Rooms are not required and are not used by default. The main reason why you can use them is to get user location in real-time by using the room as a trigger. Attach all placed Room instances to the map segment they belong. 
9. In the Configuration class properties fill the InitialPositionPage and MainUIText arrays with your possible user initial positions and available destinations for the main UI.
10. Replace the default QR code texture that comes with the project with your own. Put a vertex where your QR code in located in the real world and set its ID to "QRCode".

### Demo Level
The pack comes with a demo level that represents the first floor of my university with an area of 80mx60m. It was tested on multiple iOS devices by multiple users, the feedback showed high level of interest in the product and its usefulness.

### Requirements:
- The device must support ARKit for iOS or ARCore for Android.
- Scale of each segment must match its real world scale with **the smallest possible error**. Even very small mismatches in scale will lead to big cascading increase in the error level depending on the distance traveled!

### The system contains the following classes: 

#### ARWorldBase

Supplementary class that is used as a root to all MapSegment classes and also stores references to them. Every new MapSegment should be attached to the ARWorldBase class and a reference to every MapSegment instance should be added to the MapSegments array. 

Usage: Place it anywhere on the map. 

Public properties: 

- WorldTrueNorthAngel: Float - Stores rotation shift of the target area relative to the true polar pole. You can get the rotation shift of yout target area using Google Maps and calculating angle of rotation relative to a latitude(any vertical line). The ARWorldBase class will rotate to the given angle with a short delay when the applications starts. The delay is needed to allow attached MapSegments and its Rooms to calculate their size and position using the provided model of the target area (Static Mesh). The default value is zero.

- MapSements: Array of MapSegment - Supplementary array that contains references to its segments in case you need it.

#### MapSegment

Class that is used to define a segments of the target areas map. All FloatingIcon, Room or Vertex classes that are located in thos segment should be attached to it.

Usage: Place it anywhere on the map and attach it to the ARWorldBase. 

Public properties: 

- Floor: Integer - Stores a floor number of the segment. The default value is zero.

- FloorDisplayedText: Text - Stores a localizable text that describes the segments floor. Keep in mind that segments can be used not only to differentiate floors, but also to divide a complex map into more small pieces in case the target area is big enoght. The default value is "<Enter Floor Name>".
 
- SegmentMesh: StaticMesh - Fundamental mesh that defines the area of the segment. It is used in the minimap (white colour material) and in the segment itsef (transparent material) in case you will want to do a turn-based navigation(described in the NAVIGATION section). The default value is null.

- SegmentOffset: Vector2D - Stores the X,Y offset of the segments mesh relative to the segmentss origin. The default value is (0.0, 0.0).

- SegmentHeight: Float - Stores the height of the segments mesh in metres. For this to work, the segments mesh should be 1 metre in height. Alternatively you can create a mesh with any height and set SegmentHeight to 1.0. The default value is 1.0.

- SegmentScale: Float - Stores all axes scale multiplier of the segments mesh. The default value is (1.0, 1.0, 1.0).

- SegmentMapMaterial: Material - A supplementary material that is used to show the targets floor plan. This is only need to simplify the vertex and room arrangement on the segment. The metarial is only shown in the editor and is hidden in the game. The default value is null.

- SegmentMapScale: Float - Stores the X,Y scale of the SegmentMapMaterial. Use this to adjust the floor plan to match its real world scale. The default value is 200.0.

#### FloatingIcon

Class that represents a floating icon which can be used to highligh points of interests.

Usage: Place it anywhere on the map segment and attach it to the segment. 

Public properties: 

- IconMaterial: Material - A material that contains the image for the floating icon. Can include a static picture (like in the demo) or anything else. The default value if null.

- Text: Text - A localizable text that describes this point of interest. Will be displayed on both sides of the floating icon.

#### Room

Class that represents a single room in the target area. It can be literally a room or just a small sub-area. 

Usage: Place it anywhere on the map segment and attach it to the segment. 

Public properties:  

- Size: Vector2D - Stores size of the room. Adjustable in design-time. If set to zero the room will set its size automatically depending on its surrounding. The default value is (0.0, 0.0).

- Height: Float - Defines height of the room. The default value is 3.0.

- Title: Text - Stores a localizable text that describes the room. The default value is "No Title".

- Floor: Text - Stores a localizable text that describes rooms floor. The default value is "First Floor".

- DebugMaterial: Material - Stores a material that will be applied to rooms mesh. For debuging purposes only, will be hidden in game. The default value is null.

- Type: Enum - Stores a type of the room. Can be "Room", "Corridor", "Staircase" or "Other". The default value is "Room".

#### Vetrex

Fundamental class that represents a single vertex used for builing navigation paths in the target area. 

Usage: Place it anywhere on the map segment and attach it to this segment. 

Public properties: 

- BilateralConnections: Array of Vetrex - An array of Vetrex instances connected to this vertex bilaterally (Stair, Corridor etc). Navigation path will be drawed in both directions. 

- LateralConenctions: Array of Vertex - An array of Vertex instances connected to this vertex laterally (Turnstile, Escalator etc). Navigation path will be drawed only in one direction. 

- ID: String - A unique identifier for this Vertex used for search algorithms. The default value in empty.

#### Configuration

Supplementary class that stores lists of the possible user initial positions.

Usage: Place it anywhere on the map. Use only one instance.

Public properties: 

- InitialPositionPage: Struct - Contains a struct "Initial Positions" that stores a the list of user possible initial positions. Each InitialPosition stores a "Text"(Localizable frendly name that will be displayed in the list) and "TeleportToVertexTag" (Vertex ID which coornidinates will be used to virtualy teleport the user to that Vertex). The default values are missing and are implemented directly in the demo level.

- MainUIText: Struct - Contains a struct "QuickButtons" that stores a list of user possible destinations which can be selected by the user from the main UI. Each QuickButton contains Text"(Localizable frendly name that will be displayed in the list), "Floor" Localizable frendly name of the floor that will be displayed in the main UI under the destination) and "DestinationTag" (destination Vertex ID).

#### 2DImageProvider

Class which is responsible for rendering the 2D minimap image. 

Usage: Place it anywhere on the map. Use only one instance. Do not edit or modify it somehow.

#### Marker

Class which represents a single custom marker. 

Usage: Not intended for direct usage. Will be spawned automatically.


## DEBUG MODE

To toggle debug mode tap on the "Debug" button located in the top left corner. The debug mode will display all vertices and their axes. This will allow you to test how virtual world matches the real one. 
 
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


If you want to opt out of this behaviour and hide all navigation arrows that are behind the walls, you can do so by adding built-in unreals function LineTraceByChannel to the Arrow class blueprint, where the start point will be players camera and the end point will be world location of the Arrow instance. Depending on whether the arrow instance was hit or not, you can call SetVisibility function to hide or unhide the arrow. Do not call LineTraceByChannel every frame as this will degrade performance. Put it on timer to call only 5 times per second, you can do so by wiring a CustomEvent to your functions and adding a built-in function SetTimerByFunctionName with your CustomEvent name. The visualization of such algorithm would look like this:

<p align="center">
  <img src="https://github.com/nesseratious/AR-Navigation-Documentation/blob/master/Images/111.png" />
</p>


And yet I do not recommend using this approach as my personal user surveys have shown that such behaviour may be confusing.
