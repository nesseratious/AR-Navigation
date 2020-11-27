### World mapping classes:

### [ARWorldBase](https://github.com/nesseratious/AR-Navigation/blob/master/API/ARWorldBase.md) 
 
The supplementary class that is used as a root to all [MapSegment](https://github.com/nesseratious/AR-Navigation/blob/master/API/MapSegment.md) classes and also stores references to them. Every new [MapSegment](https://github.com/nesseratious/AR-Navigation/blob/master/API/MapSegment.md) should be attached to the [ARWorldBase](https://github.com/nesseratious/AR-Navigation/blob/master/API/ARWorldBase.md) class.

### [MapSegment](https://github.com/nesseratious/AR-Navigation/blob/master/API/MapSegment.md) 

The class that is used to define segments of the target area. All [FloatingIcon](https://github.com/nesseratious/AR-Navigation/blob/master/API/FloatingIcon.md) , [Room](https://github.com/nesseratious/AR-Navigation/blob/master/API/Room.md), and [Vertex](https://github.com/nesseratious/AR-Navigation/blob/master/API/Vetrex.md) classes that are located in this segment should be attached to it.
  
### [Vertex](https://github.com/nesseratious/AR-Navigation/blob/master/API/Vetrex.md) 

The fundamental class that represents a single vertex used for building navigation paths in the target area.

### [FloatingIcon](https://github.com/nesseratious/AR-Navigation/blob/master/API/FloatingIcon.md) 

The class represents a floating icon that can be used to highlight points of interest.

### [Room](https://github.com/nesseratious/AR-Navigation/blob/master/API/Room.md) 

The class that represents a single room in the target area. It can be literally a room or just a small sub-area.
  
  
  
### Supplementary classes:
   
### [2DImageProvider](https://github.com/nesseratious/AR-Navigation/blob/master/API/2DImageProvider.md) 
    
The class is responsible for rendering the 2D minimap image.
    
### [Configuration](https://github.com/nesseratious/AR-Navigation/blob/master/API/Configuration.md) 

The supplementary class that stores lists of the possible user's initial positions.
    
### [Marker](https://github.com/nesseratious/AR-Navigation/blob/master/API/Marker.md) 

The class which represents a single custom marker.

### [NavigationPathSpline](https://github.com/nesseratious/AR-Navigation/blob/master/API/NavigationPathSpline.md) 

The class which is responsible for building a navigation path from the user's location to destination.

### [Arrow](https://github.com/nesseratious/AR-Navigation/blob/master/API/Arrow.md) 

The class which represents a single arrow used in [NavigationPathSpline](https://github.com/nesseratious/AR-Navigation/blob/master/API/NavigationPathSpline.md) .



### Structs:

#### CustomMarker
The struct is storing name and location data about a single custom marker placed on the map.

#### InitialPosition
The struct is storing displayed text and a vertex ID for a single predefined initial position.

#### InitialPositionPage
The struct is storing an array of InitialPosition structs.

#### QuickDestinationButton
The struct is storing displayed name, displayed floor and a vertex ID for a single predefined destination.

#### MainUI
The struct is storing an array of QuickDestinationButton structs.
