## Room Class

#### The class that represents a single room in the target area. It can be literally a room or just a small sub-area. 

Usage: Place it anywhere on the map segment and attach it to the segment. 

Public properties:  

- Size: Vector2D - Stores size of the room. Adjustable in design-time. If set to zero the room will set its size automatically depending on its surroundings. The default value is (0.0, 0.0).

- Height: Float - Defines the height of the room. The default value is 3.0.

- Title: Text(Localized String) - Stores a localizable text that describes the room. The default value is "No Title".

- Floor: Text(Localized String) - Stores a localizable text that describes the floor of the room. The default value is "First Floor".

- DebugMaterial: Material - Stores a material that will be applied to room's mesh. For debugging purposes only, it will be hidden in game. The default value is null.

- Type: Enum - Stores a type of the room. Can be "Room", "Corridor", "Staircase" or "Other". The default value is "Room".
