### This page describes how to set up environment for **Dynamic AR Navigation** system.

### **Dynamic AR Navigation** system allows creating navigation apps on a mobile device directly in the app itself, so there is no default environment set up. Unlike the AR Navigation, this system allows any changes in the environment even after it was compiled and shipped to customers. 

1. Place an ARWorldBase instance anywhere on the map, it will serve as an origin for the target area.

2. In ARWorldBase properties enter rotation of thr target area relative to the world true north.

3. Place one or multiple instances of MapSegment, they will serve as containers that represent the properties of each segment. Multiple segments are used to divide the map by floors or by some small sub-areas. Attach each MapSegment to the ARWorldBase.

4. For each MapSegment assign its floor map (used only for debugging purposes, will be hidden in the app) and a static mesh that represents the segment's map in the real world.

5. Adjust the scale of the segment to match its real-world scale (it's very important!).

6. Build a navigation graph by placing Vertex instances on your map segments and connecting them using BilateralConnections and LateralConnections arrays. 

7. Give an ID to every Vertex that represents a destination point (user will be able to perform a search using this ID). Vertices that are used only to connect other vertices should have their ID field empty. 

8. Attach all placed vertices to the map segment they belong to.

9. [Optional] Place a FloatingIcon instance where there is a possible point of interest. Enter its name and a material containing its icon. 

10. Attach all placed FloatingIcon instances to the map segment they belong to.

11. [Optional] Place all Room instances that represent each room. Set their size or leave it zero for automatic size detection. Rooms are not required and are not used by default. The main reason why you can use them is to get user location in real-time by using the room as a trigger.

12. Attach all placed Room instances to the map segment they belong to.

13. In the Configuration class properties fill the InitialPositionPage and MainUIText arrays with your possible user's initial positions and available destinations for the main UI.

14. Replace the default QR code texture that comes with the project with your own. Put a vertex where your QR code is located in the real world and set its ID to "QRCode".
