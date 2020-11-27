###  To set it up follow this steps:

1. Place an [ARWorldBase](https://github.com/nesseratious/AR-Navigation/blob/master/API/ARWorldBase.md)  instance anywhere on the map, it will serve as an origin for the target area.

2. In [ARWorldBase](https://github.com/nesseratious/AR-Navigation/blob/master/API/ARWorldBase.md)  properties enter rotation of the target area relative to the world true north.

3. Place one or multiple instances of [MapSegment](https://github.com/nesseratious/AR-Navigation/blob/master/API/MapSegment.md), they will serve as containers that represent the properties of each segment. Multiple segments are used to divide the map by floors or by some small sub-areas. Attach each [MapSegment](https://github.com/nesseratious/AR-Navigation/blob/master/API/MapSegment.md) to the [ARWorldBase](https://github.com/nesseratious/AR-Navigation/blob/master/API/ARWorldBase.md).

4. For each [MapSegment](https://github.com/nesseratious/AR-Navigation/blob/master/API/MapSegment.md) assign its floor map (used only for debugging purposes, will be hidden in the app) and a static mesh that represents the segment's map in the real world.

5. Adjust the scale of the segment to match its real-world scale (it's very important!). *The scale of each segment must match its real-world scale with the smallest possible error. Even very small mismatches in scale will lead to a big cascading increase in the error level depending on the distance traveled.*

6. Build a navigation graph by placing [Vertex](https://github.com/nesseratious/AR-Navigation/blob/master/API/Vetrex.md) instances on your map segments and connecting them using BilateralConnections and LateralConnections arrays. 

7. Give an ID to every [Vertex](https://github.com/nesseratious/AR-Navigation/blob/master/API/Vetrex.md) that represents a destination point (user will be able to perform a search using this ID). Vertices that are used only to connect other vertices should have their ID field empty. 

8. Attach all placed vertices to the map segment they belong to.

9. [Optional] Place a [FloatingIcon](https://github.com/nesseratious/AR-Navigation/blob/master/API/FloatingIcon.md) instance where there is a possible point of interest. Enter its name and a material containing its icon. 

10. Attach all placed [FloatingIcon](https://github.com/nesseratious/AR-Navigation/blob/master/API/FloatingIcon.md) instances to the map segment they belong to.

11. [Optional] Place all [Room](https://github.com/nesseratious/AR-Navigation/blob/master/API/Room.md) instances that represent each room. Set their size or leave it zero for automatic size detection. Rooms are not required and are not used by default. The main reason why you can use them is to get user location in real-time by using the room as a trigger.

12. Attach all placed [Room](https://github.com/nesseratious/AR-Navigation/blob/master/API/Room.md) instances to the map segment they belong to.

13. In the [Configuration](https://github.com/nesseratious/AR-Navigation/blob/master/API/Configuration.md) class properties fill the InitialPositionPage and MainUIText arrays with your possible user's initial positions and available destinations for the main UI.

14. Replace the default QR code texture that comes with the project with your own. Put a vertex where your QR code is located in the real world and set its ID to "QRCode".
