# AR-Navigation-Documentation

### AR Navigation allows creating apps for iOS and Android that uses AR to navigate within a given target area. 


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

### How it works?

1. When the user launches your app, they will be prompted to scan the QR code used to download the app. This is needed to immediately set their position in the virtual world. Using such QR code is the most convenient way to ensure the accuracy of the user position. Also, you can use any image which can fit on an A4 sheet instead of a QR code.  

2. Alternatively, the user can select their position from a predefined list. In the demo level, this list contains 5 most popular positions for the chosen target area. Buttons are embedded into a scroll box, so you can add as many predefined positions as you want. Also, the user can select their position using manual input. In this scenario, the user's position will be set to a vertex with an ID that they have entered. To make this process easy and convenient for the user, set vertices ID to some friendly name (for example "Canteen" or "Assembly Hall").

3. After the initial position is set, the app starts the AR session. Now the app and its minimap will react to user's movements seamlessly using visual-inertial odometry provided by ARKit and ARCore runtimes.

4. The user can choose a destination point from a predefined menu or enter it manually. The app searches for a vertex with the given ID and marks it as a destination point.

5. The navigation path from the user's current location to the destination point will be calculated in real-time and displayed as a spline with animated arrows. Also, the app will display remained distance in real-time.

6. During the whole period of navigation, the app will show user's location and rotation relative to true north on the dynamic 3D minimap. 

7. The user can tap on any detected surface to place a custom marker. The marker will snap to the surface, and will show its given name and distance to the user.


### How to set it up?
1. Place an ARWorldBase instance anywhere on the map, it will serve as an origin for the target area. 
2. In ARWorldBase properties enter rotation of thr target area relative to the world true north.
3. Place one or multiple instances of MapSegment, they will serve as containers that represent the properties of each segment. Multiple segments are used to divide the map by floors or by some small sub-areas. Attach each MapSegment to the ARWorldBase.
4. For each MapSegment assign its floor map (used only for debugging purposes, will be hidden in the app) and a static mesh that represents the segment's map in the real world. 
5. Adjust the scale of the segment to match its real-world scale (it's very important!).
6. Build a navigation graph by placing Vertex instances on your map segments and connecting them using BilateralConnections and LateralConnections arrays. Give an ID to every Vertex that represents a destination point (user will be able to perform a search using this ID). Vertices that are used only to connect other vertices should have their ID field empty. Attach all placed vertices to the map segment they belong to.
7. [Optional] Place a FloatingIcon instance where there is a possible point of interest. Enter its name and a material containing its icon. Attach all placed FloatingIcon instances to the map segment they belong to. 
8. [Optional] Place all Room instances that represent each room. Set their size or leave it zero for automatic size detection. Rooms are not required and are not used by default. The main reason why you can use them is to get user location in real-time by using the room as a trigger. Attach all placed Room instances to the map segment they belong to. 
9. In the Configuration class properties fill the InitialPositionPage and MainUIText arrays with your possible user's initial positions and available destinations for the main UI.
10. Replace the default QR code texture that comes with the project with your own. Put a vertex where your QR code is located in the real world and set its ID to "QRCode".

### Demo Level
The pack comes with a demo level that represents the first floor of my university with an area of 80mx60m. It was tested on multiple iOS devices by multiple users, the feedback showed a high level of interest in the product and its usefulness.

### Requirements:
- The device must support ARKit for iOS or ARCore for Android.
- The scale of each segment must match its real-world scale with **the smallest possible error**. Even very small mismatches in scale will lead to a big cascading increase in the error level depending on the distance traveled!



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
