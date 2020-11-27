## MapSegment Class

#### The class that is used to define segments of the target area. All [FloatingIcon](https://github.com/nesseratious/AR-Navigation/blob/master/API/FloatingIcon.md) , [Room](https://github.com/nesseratious/AR-Navigation/blob/master/API/Room.md), and [Vertex](https://github.com/nesseratious/AR-Navigation/blob/master/API/Vetrex.md) classes that are located in this segment should be attached to it.

Usage: Place it anywhere on the map and attach it to the [ARWorldBase](https://github.com/nesseratious/AR-Navigation/blob/master/API/ARWorldBase.md) class. 

Public properties: 

- Floor: Integer - Stores floor number of the segment. The default value is zero.

- FloorDisplayedText: Text(Localized String) - Stores a localizable text that describes the segment's floor. Keep in mind that segments can be used not only to differentiate floors but also to divide a complex map into more small pieces in case the target area is big enough. The default value is "<Enter Floor Name>".
 
- SegmentMesh: StaticMesh - Fundamental mesh that defines the area of the segment. The default value is null.

- SegmentOffset: Vector2D - Stores the X,Y offset of the segment's mesh relative to the segment's origin. The default value is (0.0, 0.0).

- SegmentHeight: Float - Stores the height of the segment's mesh in meters. For this to work, the segment's mesh should be 1 meter in height. Alternatively, you can create a mesh with any height and set SegmentHeight to 1.0. The default value is 1.0.

- SegmentScale: Float - Stores all axes scale multiplier of the segments mesh. The default value is 1.0.

- SegmentMapMaterial: Material - A supplementary material that is used to show the floor plan. This is only needed to simplify the vertex and room arrangement on the segment. The material is only shown in the editor and is hidden in the game. The default value is null.

- SegmentMapScale: Float - Stores the X,Y scale of the SegmentMapMaterial. Use this to adjust the floor plan to match its real-world scale. The default value is 200.0.
